#version 400

layout(location = 0) in vec3 vertex_position;
layout (location=1) in vec2 st; // per-vertex texture co-ords
out vec2 texture_coordinates;

uniform mat4 model, proj, view; // our matrix

void main () {
	texture_coordinates = st;
    gl_Position =  proj * view * model * vec4(vertex_position, 1.0);
}
