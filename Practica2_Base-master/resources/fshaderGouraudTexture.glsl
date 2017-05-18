#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 color;
IN vec2 coord;

uniform sampler2D texture;

void main()
{
    gl_FragColor = /*0.25 * color + 0.75 * */texture2D(texture, coord);
}

