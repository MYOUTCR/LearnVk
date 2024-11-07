
#ifndef _VK_ENGINE_CONTEXT_H
#define _VK_ENGINE_CONTEXT_H

#include "vkEngine_Global.h"
#include <vulkan/vulkan.h>

namespace vkEngine
{
	class VK_ENGINE_API_EXPORT EngineContext
	{
	public:
		EngineContext();
		~EngineContext();

	protected:
		void initVulkan();
		void createInstance();
		

		void cleanup();
	private:
		VkInstance m_instance;
	};
}

#endif // !_VK_ENGINE_CONTEXT_H

