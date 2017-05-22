#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 p;
IN vec4 n;
IN vec2 coord;

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

float atenuate(int);

uniform int llums;

uniform Material BufferMaterial;

uniform Light BufferLights[20];

uniform sampler2D diffuseTexture;

uniform sampler2D normalTexture;

uniform vec3 ambientGlobal;

void main(void)
{

    float lamberFactor;
    vec3 diffuseMaterial;
    vec3 diffuseLight;
    vec3 specularMaterial;
    vec3 specularLight;
    vec3 temp;
            // lookup normal from normal map, move from [0,1] to  [-1, 1] range, normalize
            vec3 normal = 2.0 * texture2D(normalTexture, coord).rgb - 1.0;
            normal = normalize(normal);

            for(int i=0;i<llums;i++){
                // compute diffuse lighting
                lamberFactor += max(dot(getL(i),n),0.0);
            }
            // compute specular lighting


            // compute ambient

            vec3 ambientLight = ambientGlobal;

            if(lamberFactor>0.0f){
                for(int i=0;i<llums;i++){
                    diffuseMaterial = texture2D(diffuseTexture, coord);
                    diffuseLight = BufferLights[i].diffuse;


                    specularMaterial = BufferMaterial.specular;
                    specularLight = BufferLights[i].specular;
                    //shininess = pow (max (dot (halfVec, n), 0.0), 2.0);
                    temp += diffuseMaterial * diffuseLight * lamberFactor;
                    temp += specularMaterial * specularLight * BufferMaterial.shiness;
                }
            }
            temp += ambientLight;
            gl_FragColor = vec4(temp,1.0f);

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
    return normalize(L+V);
}

float atenuate(int i){
    vec4 rayDirection = BufferLights[i].position - p;
    float a = BufferLights[i].attenuation[0];
    float b = BufferLights[i].attenuation[1];
    float c = BufferLights[i].attenuation[2];
    float d = length(rayDirection);
    return 1.0/(a + b*d + c*d*d);
}
