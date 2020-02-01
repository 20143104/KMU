uniform sampler2D u_texid;
uniform sampler2D u_texid_frame;

uniform mat4 u_view_matrix;

uniform vec3 u_light_vector;
uniform vec4 u_light_ambient;
uniform vec4 u_light_diffuse;
uniform vec4 u_light_specular;

uniform vec4 u_material_ambient;
uniform vec4 u_material_diffuse;
uniform vec4 u_material_specular;
uniform float u_material_shininess;

varying vec3 v_vertex_wc;
varying vec3 v_normal_wc;
varying vec2 v_texcoord;

vec4 directional_light(){
  vec4 color = vec4(0);
  vec3 vertex_wc = v_vertex_wc;
  vec3 normal_wc = normalize(v_normal_wc);
  //interpolation 되서 들어오기 떄문이 길이가 1이 아닐수 잇다.

  vec3 light_vector_wc = normalize(u_light_vector);
  vec3 light_incident_vector_wc = - light_vector_wc; // 들어오는 빛이니까?
  vec3 reflect_vector_wc = reflect(light_incident_vector_wc, normal_wc);

  vec3 view_position_wc = vec3(u_view_matrix * vec4(0,0,0,1)); //
  vec3 view_vector_wc = view_position_wc - vertex_wc;
  view_vector_wc = normalize(view_vector_wc);

  float ndotl = max(0.1, dot(normal_wc, light_vector_wc));
  color += (ndotl * vec4(1.0));



  return color;
}
void main()
{
  vec4 color1 = texture2D(u_texid, v_texcoord);
  vec4 color2 = texture2D(u_texid_frame, v_texcoord);

  gl_FragColor = (color1*0.5 + color2*0.5) * directional_light() *1.5;
}
