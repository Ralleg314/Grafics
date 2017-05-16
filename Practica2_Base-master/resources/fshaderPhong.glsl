#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

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
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float angle;
    vec3 attenuation;
};

vec4 getL(int);

vec4 getH(vec4);

float atenuate(int);

uniform int llums;

uniform Material BufferMaterial;

uniform Light BufferLights[20];

uniform vec3 ambientGlobal;

void main(void)
{
    vec3 color=vec3(0.0f);
    vec3 tmpD,tmpS,tmpA;
    vec4 L,H,N=normalize(n);
    for(int i=0;i<llums;i++){

        L=getL(i);
        tmpD=BufferMaterial.diffuse*BufferLights[i].diffuse*max(dot(L,N),0.0f);

        H=getH(L);
        tmpS=BufferMaterial.specular*BufferLights[i].specular*pow(max(dot(N,H),0.0f),BufferMaterial.shiness);

        tmpA=BufferLights[i].ambient*BufferMaterial.ambient;

        color+=atenuate(i)*(tmpD+tmpS+tmpA)+ambientGlobal*BufferMaterial.ambient;

    }
    gl_FragColor = vec4(color[0],color[1],color[2],1.0f);
}

vec4 getL(int i){
    if(BufferLights[i].position==vec4(0.0)){
        return normalize(-BufferLights[i].direction);
    }else if(BufferLights[i].angle==0.0){
        return normalize(BufferLights[i].position - p);
    }else{
        vec4 dir=normalize(p-BufferLights[i].position);
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
    vec4 V=normalize(vec4(0.0f,0.0f,10.0f,1.0f)-p);
    return L+V;
}

float atenuate(int j){
    vec4 rayDirection = BufferLights[j].position - p;
    float a = BufferLights[j].attenuation[0];
    float b = BufferLights[j].attenuation[1];
    float c = BufferLights[j].attenuation[2];
    float d = length(rayDirection);
    return 1.0/(a + b*d + c*pow(d,2));
}
