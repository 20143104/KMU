uniform mat4 u_view_matrix;

uniform vec3 u_light_vector;
uniform vec4 u_light_ambient;
uniform vec4 u_light_diffuse;
uniform vec4 u_light_specular;

uniform vec4 u_material_ambient;
uniform vec4 u_material_diffuse;
uniform vec4 u_material_specular;
uniform float u_material_shininess;

varying vec3 v_ertex_wc;
varying vec3 v_normal_wc;

vec4 directional_light()
{
  vec4 color = vec4(0);

  vec3 vertex_wc = (u_model_matrix * vec4(a_vertex, 1.0)).xyz;

  vec3 normal_wc = u_normal_matrix * a_normal;
  normal_wc = normalize(normal_wc);

  vec3 light_vector_wc = normalize(u_light_vector);
  vec3 light_incident_vector_wc = -light_vector_wc;
  vec3 reflect_vector_wc = reflect(light_incident_vector_wc, normal_wc);

  vec3 view_position_wc = vec3(u_view_matrix * vec4(0,0,0,1));
  vec3 view_vector_wc = view_position_wc - vertex_wc;
  view_vector_wc = normalize(view_vector_wc);

  color += u_material_ambient * u_light_ambient;

  float ndotl = max(0.0, dot(normal_wc, light_vector_wc));
  color += u_material_diffuse * ndotl * u_light_diffuse;

  float rdotv = max(0.0, dot(reflect_vector_wc, view_vector_wc));
  color += u_material_specular * pow(rdotv, u_material_shininess) * u_light_specular;


  return color;

}

void main()
{
  gl_FragColor= directional_light();
}
