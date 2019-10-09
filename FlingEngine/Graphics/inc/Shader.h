#pragma once

#include "spirv_cross.hpp"
#include "spirv_glsl.hpp"

#include "Resource.h"
#include "FlingVulkan.h"
#include "Sampler.hpp"

#include <fstream>
#include <vector>

namespace Fling
{

    struct DescriptorSetLayout
    {
        uint32_t sampled_image_mask = 0;
        uint32_t storage_image_mask = 0;
        uint32_t uniform_buffer_mask = 0;
        uint32_t storage_buffer_mask = 0;
        uint32_t sampled_buffer_mask = 0;
        uint32_t input_attachment_mask = 0;
        uint32_t sampler_mask = 0;
        uint32_t separate_image_mask = 0;
        uint32_t fp_mask = 0;
        uint32_t immutable_sampler_mask = 0;
        uint64_t immutable_samplers = 0;
        uint8_t array_size[VULKAN_NUM_BINDINGS] = {};
    };

    enum class ShaderStage
    {
        Vertex          = 0,
        TessControl     = 1,
        TessEvaluation  = 2,
        Geometry        = 3,
        Fragment        = 4,
        Compute         = 5,
        Count
    };

    struct ResourceLayout
    {
        uint32_t input_mask = 0;
        uint32_t output_mask = 0;
        uint32_t push_constant_size = 0;
        uint32_t spec_constant_mask = 0;
        DescriptorSetLayout sets[VULKAN_NUM_DESCRIPTOR_SETS];
    };

    struct ResourceBinding
    {
        union 
        {
            VkDescriptorBufferInfo buffer;
            struct
            {
                VkDescriptorImageInfo fp;
                VkDescriptorImageInfo integer;
            } image;

            VkBufferView buffer_view;
        };
        VkDeviceSize dynamic_offset;
    };

    struct ResourceBindings
    {
        ResourceBinding bindings[VULKAN_NUM_DESCRIPTOR_SETS][VULKAN_NUM_BINDINGS];
        uint64_t cookies[VULKAN_NUM_DESCRIPTOR_SETS][VULKAN_NUM_BINDINGS];
        uint64_t secondary_cookies[VULKAN_NUM_DESCRIPTOR_SETS][VULKAN_NUM_BINDINGS];
        uint8_t push_constant_data[VULKAN_PUSH_CONSTANT_SIZE];
    };

    /**
     * @brief   Class that represents what a shader is in the Fling engine.
     *          Performs shader reflection and provides some helper functionality
     *          for creating the Vk resources needed(descriptor sets, bindings, etc)
     */
    class Shader : public Resource
    {
    public:

		static std::shared_ptr<Fling::Shader> Create(Guid t_ID);

        /**
         * @brief Construct a new Shader object. Loads from disk and compiles the shader
         * 
         * @param t_ID  The GUID that represents the file path to this file.
         */
        explicit Shader(Guid t_ID);

        ~Shader();

        /**
         * @brief Create a Shader Module object
         * 
         * @return VkShaderModule 
         */
        VkShaderModule GetShaderModule() const { return m_Module; }

        /**
         * @brief Compiles this shader with SPRIV-Cross
         */
        void ParseReflectionData();

    private:

        /** Creates the shade rmodules  */
        VkResult CreateShaderModule();

        /**
         * @brief Load the raw shader code in off-disk
         */
        void LoadRawBytes();

        void update_array_info(const spirv_cross::SPIRType& type, unsigned set, unsigned binding);

        /** The shader module created by this shader */
        VkShaderModule m_Module = VK_NULL_HANDLE;

        /** Resource layout that represents this shader */
        ResourceLayout m_Layout;

        std::vector<char> m_RawShaderCode;
    };
}   // namespace Fling