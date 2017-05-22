#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif


IN vec4 vPosition;
IN vec4 vNormal;

OUT vec4 p;
OUT vec4 n;

uniform mat4 model_view;

uniform mat4 projection;

void main()
{
    gl_Position=projection*model_view*vPosition;
    n = vNormal;
    p = vPosition;

}
