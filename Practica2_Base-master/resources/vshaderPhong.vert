#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif
IN vec4 posv;
IN vec4 norv;

OUT vec4 out_pos;
OUT vec4 out_norm;

void main(void)
{
    gl_Position = posv;
    out_pos = posv;
    out_norm = norv;
}
