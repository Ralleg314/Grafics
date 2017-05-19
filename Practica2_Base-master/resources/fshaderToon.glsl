#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 p;
IN vec4 n;

struct Light{
    vec4 position;
    vec4 direction;
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float angle;
    vec3 attenuation;
};

struct Material{
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float shiness;
    float alpha;
};

uniform Material BufferMaterial;
uniform Light BufferLights[20];
uniform int llums;

vec4 getL(int);

void main()
{

    float intensity;
    vec3 color=vec3(0.0);

    for(int i=0;i<llums;i++){
        intensity = dot(getL(i), n);
        if (intensity > 0.95)
                color += BufferMaterial.diffuse+vec3(1.0,0.5,0.5);
        else if (intensity > 0.5)
                color += BufferMaterial.diffuse+vec3(0.6,0.3,0.3);
        else if (intensity > 0.25)
                color += BufferMaterial.diffuse+vec3(0.4,0.2,0.2);
        else
                color += BufferMaterial.diffuse+vec3(0.2,0.1,0.1);
    }
    gl_FragColor = vec4(color,BufferMaterial.alpha);

}

vec4 getL(int i){
    if(BufferLights[i].position==vec4(0.0f)){
        return normalize(-BufferLights[i].direction);
    }else if(BufferLights[i].angle==0.0f){
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
