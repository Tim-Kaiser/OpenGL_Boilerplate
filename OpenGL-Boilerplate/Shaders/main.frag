#version 460
in vec2 vUv;
in vec3 vertexOut;

uniform float time;

 out vec4 fragCol;

void main(){

	vec2 st = vUv - 0.5 * tan(time);

	fragCol = vec4(st,0.,1.);
}