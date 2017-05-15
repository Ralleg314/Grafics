#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 vPosition;
IN vec4 vNormal;

OUT vec4 color;

struct Material{
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float shiness;
};

struct Light{
    vec4 position;
    vec4 direction;
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float angle;
    vec3 attenuation;
};

vec4 getL(int);

vec4 getH(vec4);

uniform int llums;

uniform Material BufferMaterial;

uniform Light BufferLights[20];

uniform vec3 ambientGlobal;

uniform mat4 model_view;

void main(void)
{
    vec3 color_temp;
    vec3 tmpD,tmpS,tmpA;
    vec4 L,H,N=vNormal;
    for(int i=0;i<llums;i++){

        L=getL(i);
        tmpD=BufferMaterial.diffuse*BufferLights[i].diffuse*max(dot(L,N),0.0f);

        H=getH(L);
        tmpS=BufferMaterial.specular*BufferLights[i].specular*pow(max(dot(N,H),0.0f),BufferMaterial.shiness);

        tmpA=BufferLights[i].ambient*BufferMaterial.ambient;

        color_temp+=tmpD+tmpS+tmpA+ambientGlobal;
    }
    color = vec4(1,1,0,1.0f);
    gl_Position=model_view*vPosition;
}

vec4 getL(int i){
    if(BufferLights[i].position==vec4(0.0f)){
        return normalize(-BufferLights[i].direction);
    }else if(BufferLights[i].angle==0.0f){
        return normalize(BufferLights[i].position - vPosition);
    }else{
        vec4 dir=normalize(vPosition-BufferLights[i].position);
        if(acos(dot(dir,normalize(BufferLights[i].direction)))>BufferLights[i].angle){
            return vec4(0.0f);
        }else{
            return -dir;
        }
    }
    return vec4(0.0f);
}

vec4 getH(vec4 L){
    vec4 V=vec4(0.0f,0.0f,10.0f,1.0f)-vPosition;
    return normalize(L+V);
}
