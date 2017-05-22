#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif
IN vec4 vPosition;
IN vec4 vNormal;
IN vec2 vCoords;

OUT vec4 p;
OUT vec4 n;
OUT vec2 coord;

uniform mat4 model_view;

uniform mat4 projection;

void main(void)
{
    gl_Position = projection*model_view*vPosition;
    p = vPosition;
    n = vNormal;
    coord = vCoords;
}
