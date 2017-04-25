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

struct Comp
{
 vec3 diffuse;
 vec3 specular;
 vec3 ambient;
 float shiness;

};
uniform Comp material;

void main()
{
    gl_Position = vPosition;

    color = vColor;
}
