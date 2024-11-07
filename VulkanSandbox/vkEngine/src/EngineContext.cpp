
#include <iostream>
#include "EngineContext.h"

namespace vkEngine
{
	EngineContext::EngineContext()
	{
		init();
	}

	EngineContext::~EngineContext()
	{
		cleanup();
	}

	void EngineContext::init()
	{
		initInstance();
	}

	void EngineContext::initInstance()
	{
		VkApplicationInfo applicationInfo = {};
		applicationInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo instanceCreateInfo = {};
		instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		instanceCreateInfo.pApplicationInfo = &applicationInfo;
		instanceCreateInfo.enabledLayerCount = 0;
		instanceCreateInfo.ppEnabledLayerNames = nullptr;
		instanceCreateInfo.enabledExtensionCount = 0;
		instanceCreateInfo.ppEnabledExtensionNames = nullptr;
		if (vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance) != VK_SUCCESS)
		{
			std::cout << "Failed to create instance!" << std::endl;
		}
		else
		{
			std::cout << "Instance created successfully!" << std::endl;
		}
	}

	void EngineContext::cleanup()
	{
		vkDestroyInstance(m_instance, nullptr);
	}
}