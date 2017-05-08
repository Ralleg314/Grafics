#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

uniform sampler2D qt_Texture0;
varying vec4 qt_TexCoord0;

IN vec4 p;
IN vec4 n;

struct Material{
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float shiness;
};

struct Light{
    vec4 position;
    vec4 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float angle;
    vec3 atteuation;
};

vec4 getL(int);

vec4 getH(vec4);

uniform int llums;

uniform Material BufferMaterial;

uniform Light BufferLights[10];

uniform vec3 ambientGlobal;

void main(void)
{
    vec3 color;

    gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
}

vec4 getL(int i){
    if(BufferLights[i].position==vec4(0.0f)){
        return normalize(-BufferLights[i].direction);
    }else if(BufferLights[i].angle==0.0f){
        return normalize(BufferLights[i].position - p);
    }else{
        vec4 dir=normalize(p-BufferLights[i].position);
        if(acos(dot(dir,normalize(BufferLights[i].direction)))>BufferLights[i].angle){
            return vec4(0.0f);
        }else{
            return -dir;
        }
    }
    return vec4(0.0f);
}

vec4 getH(vec4 L){
    vec4 V=vec4(0.0f,0.0f,10.0f,1.0f)-p;
    return normalize(L+V);
}
