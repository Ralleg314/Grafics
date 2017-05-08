in vec4 posv;
in vec4 norv;

out vec4 out_pos;
out vec4 out_norm;

void main(void)
{
    gl_Position = posv;
    out_pos = posv;
    out_norm = norv;
}
