#version 460
in vec2 uv;
in vec3 vertexOut;
layout(location = 0) out vec4 fragCol;


void main(){

	fragCol = vec4(uv,0.,1.);
}