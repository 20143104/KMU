uniform mat4 u_pvm_matrix;
uniform mat4 u_view_matrix;
uniform mat4 u_model_matrix;
uniform mat3 u_normal_matrix;

attribute vec3 a_vertex;
attribute vec3 a_normal;

varying vec4 v_vertex_wc;
varying vec4 v_normal_wc;


void main()
{
  v_vertex_wc = vec3(u_model_matrix * vec4(a_vertex, 1));
  v_normal_wc = normalize(u_normal_matrix * a_normal);

  gl_Position = u_pvm_matrix * vec4(a_vertex, 1);
}
