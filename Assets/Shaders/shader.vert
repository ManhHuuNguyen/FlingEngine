#version 450
#extension GL_ARB_separate_shader_objects : enable

// Bindings -------------------
layout (binding = 0) uniform UboView 
{
	mat4 model;
	mat4 projection;
	mat4 view;
} uboView;

// Inputs --------------
layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 inTangent;
layout(location = 3) in vec2 inTexCoord;
layout(location = 4) in vec3 inNormal;

// Outputs ------------
layout (location = 0) out vec3 outColor;
layout (location = 1) out vec2 fragTexCoord;
layout (location = 2) out vec3 outTanget;
layout (location = 3) out vec3 outNormal;

out gl_PerVertex 
{
	vec4 gl_Position;
};

void main() 
{
	mat4 modelView = uboView.view * uboView.model;
	vec3 worldPos = vec3(modelView * vec4(inPosition, 1.0));
	gl_Position = uboView.projection * modelView * vec4(inPosition, 1.0);

    // Setup fragment shader outputs
	outColor = inColor;
	outTanget = inTangent;
	outNormal = inNormal;
    fragTexCoord = inTexCoord;
}
