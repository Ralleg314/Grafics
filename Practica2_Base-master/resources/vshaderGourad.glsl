#if __VERSION__<130
#define IN attribute
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
    //float alpha;
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

float atenuate(int j);

uniform int llums;

uniform Material BufferMaterial;

uniform Light BufferLights[20];

uniform vec3 ambientGlobal;

uniform mat4 model_view;

void main(void)
{
    gl_Position=model_view*vPosition;
    vec3 color_temp=vec3(0.0f);
    vec3 tmpD,tmpS,tmpA;
    vec4 L,H,N=normalize(vNormal);
    for(int i=0;i<llums;i++){

        L=getL(i);
        tmpD=BufferMaterial.diffuse*BufferLights[i].diffuse*max(dot(L,N),0.0f);

        H=getH(L);
        tmpS=BufferMaterial.specular*BufferLights[i].specular*pow(max(dot(N,H),0.0f),BufferMaterial.shiness);

        tmpA=BufferLights[i].ambient*BufferMaterial.ambient;

        color_temp+=(tmpD+tmpS+tmpA)*atenuate(i)+ambientGlobal*BufferMaterial.ambient;
    }
    color = vec4(color_temp,1.0f);
}

vec4 getL(int i){
    if(BufferLights[i].position==vec4(0.0f)){
        return normalize(-BufferLights[i].direction);
    }else if(BufferLights[i].angle==0.0f){
        return normalize(BufferLights[i].position - vPosition);
    }else{
        vec4 dir=normalize(vPosition-BufferLights[i].position);
        float angle = dot(dir,normalize(BufferLights[i].direction));
        if(acos(angle)>BufferLights[i].angle){
            return vec4(0.0f);
        }else{
            return -dir;
        }
    }
    return vec4(0.0f);
}

vec4 getH(vec4 L){
    vec4 V=normalize(vec4(0.0f,0.0f,10.0f,1.0f)-vPosition);
    return normalize(L+V);
}

float atenuate(int j){
    vec4 rayDirection = BufferLights[j].position - vPosition;
    float a = BufferLights[j].attenuation[0];
    float b = BufferLights[j].attenuation[1];
    float c = BufferLights[j].attenuation[2];
    float d = length(rayDirection);
    return 1.0/(a + b*d + c*d*d);
}
