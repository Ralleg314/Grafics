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
    //float alpha;
};

uniform Material BufferMaterial;
uniform Light BufferLights[20];
uniform int llums;

void main()
{

        float intensity;
        vec4 color;

        for(int i=0;i<llums;i++){
        intensity = dot(BufferLights[i].direction, vNormal);
        if (intensity > 0.95)
                color += vec4(BufferMaterial.diffuse,1.0f)+vec4(1.0,0.5,0.5,1.0);
        else if (intensity > 0.5)
                color += vec4(BufferMaterial.diffuse,1.0f)+vec4(0.6,0.3,0.3,1.0);
        else if (intensity > 0.25)
                color += vec4(BufferMaterial.diffuse,1.0f)+vec4(0.4,0.2,0.2,1.0);
        else
                color += vec4(BufferMaterial.diffuse,1.0f)+vec4(0.2,0.1,0.1,1.0);
        }
        gl_FragColor = color;

}
