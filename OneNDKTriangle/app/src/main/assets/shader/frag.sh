#version 300 es
precision mediump float;
in vec4 DestinationColor; //接收从顶点着色器过来的参数
out float vColor1;
out vec4 fragColor;
void main()
{
    //fragColor = DestinationColor; //给此片元从顶点着色器传过来的颜色值
    //fragColor=vec4(vColor1,vColor1,vColor1,1.0);
    fragColor=vec4(1.0,1.0,1.0,1.0);
}