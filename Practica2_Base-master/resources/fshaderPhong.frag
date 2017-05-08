uniform sampler2D qt_Texture0;
varying vec4 qt_TexCoord0;

in vec4 p;
in vec4 n;

struct Material{
    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float shiness;
};

struct Light{
    bool active;
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 angle;
    float a;
    float b;
    float c;
};

uniform int llums;

uniform Material BufferMaterial;

uniform Light BufferLights[10];

uniform vec3 ambientGlobal;

void main(void)
{
    vec3 color;

    gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
}
