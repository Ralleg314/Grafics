#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif
IN vec4 vPosition;
IN vec4 vNormal;

OUT vec4 p;
OUT vec4 n;

void main(void)
{
    gl_Position = vPosition;
    p = vPosition;
    n = vNormal;
}
