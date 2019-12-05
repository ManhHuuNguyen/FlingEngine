#pragma once

#include "Subpass.h"
#include "NonCopyable.hpp"
#include <entt/entity/registry.hpp>

namespace Fling
{
	class CommandBuffer;
	class LogicalDevice;
	class Swapchain;
	class FrameBuffer;
	class MeshRenderer;

	/**
	* @brief	A render pipeline encapsulates the functionality of a 
	* 
	*/
	class RenderPipeline : public NonCopyable
	{
	public:

		RenderPipeline(entt::registry& t_Reg, LogicalDevice* t_dev, Swapchain* t_Swap, std::vector<std::unique_ptr<Subpass>>& t_Subpasses);
		~RenderPipeline();

		void Draw(CommandBuffer& t_CmdBuf, UINT32 t_ActiveFrameInFlight, entt::registry& t_Reg);

		/** Given a frame index, get any semaphores that the swap chain command buffer needs to wait for */
		void GatherPresentDependencies(std::vector<CommandBuffer*>& t_CmdBuffs, std::vector<VkSemaphore>& t_Deps, UINT32 t_ActiveFrameIndex);

	private:

		void OnMeshRendererAdded(entt::entity t_Ent, entt::registry& t_Reg, MeshRenderer& t_MeshRend);

		/**
		* @brief	Creates the descriptor pool and the descriptor sets for each sub pass to use
		*/
		void CreateDescriptors(entt::registry& t_Reg);

		std::vector<std::unique_ptr<Subpass>> m_Subpasses;

		VkDescriptorPool m_DescriptorPool = VK_NULL_HANDLE;

		const LogicalDevice* m_Device;

		/** Keep track of the swap chain so that we know how many frame buffers to create and what extents to use */
		const Swapchain* m_SwapChain;
	};
}	// namespace Fling