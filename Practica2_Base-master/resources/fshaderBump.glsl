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
            // lookup normal from normal map, move from [0,1] to  [-1, 1] range, normalize
            vec3 normal = 2.0 * texture2D(normalTexture, coord[0].st).rgb - 1.0;
            normal = normalize(normal);

            float lamberFactor;
            vec4 diffuseMaterial;
            vec4 diffuseLight;

            for(int i=0;i<llums;i++){
                // compute diffuse lighting
                lamberFactor += max(dot(getL(i),n),0.0);
                diffuseMaterial = 0.0;
                diffuseLight = 0.0;
            }
            // compute specular lighting
            vec4 specularMaterial;
            vec4 specularLight;
            float shininess;

            // compute ambient
            //vec4 ambientLight = gl_LightSource[0].ambient;
            vec4 ambientLight = ambientGlobal;

            if(lamberFactor>0.0f){
                for(int i=0;i<llums;i++){
                    diffuseMaterial = texture2D (diffuseTexture, gl_TexCoord[0].st);
                    diffuseLight = BufferLights[i].diffuse;

                    // In doom3, specular value comes from a texture
                    specularMaterial = vec4(1.0);
                    specularLight = BufferLights[i].specular;
                    //shininess = pow (max (dot (halfVec, n), 0.0), 2.0);

                    gl_FragColor = diffuseMaterial * diffuseLight * lamberFactor;
                    //gl_FragColor +=	specularMaterial * specularLight * shininess ;
                    gl_FragColor += specularMaterial * specularLight * BufferMaterial.shiness;
                }
            }
            gl_FragColor += ambientLight;

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
