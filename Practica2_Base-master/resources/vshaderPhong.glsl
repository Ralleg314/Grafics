#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif
IN vec4 posv;
IN vec4 norv;

OUT vec4 p;
OUT vec4 n;

void main(void)
{
    gl_Position = posv;
    p = posv;
    n = norv;
}
