#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 vPosition;
IN vec4 vColor;

OUT vec4 color;

struct Material
{
 vec3 diffuse;
 vec3 specular;
 vec3 ambient;
 float shiness;

};
uniform Material BufferMaterial;

struct Light
{
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float a;
    float b;
    float c;
};
uniform Light lights[3];



void main()
{
    gl_Position = vPosition;

    color = vec4(BufferMaterial.diffuse,1.0f);
}
