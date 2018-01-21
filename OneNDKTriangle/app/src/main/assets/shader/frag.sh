#version 300 es
precision mediump float;
in vec4 DestinationColor; //接收从顶点着色器过来的参数
in vec4 vColor1;
in vec4 vColor2;
out vec4 fragColor;
void main()
{
    fragColor=vColor2;
}