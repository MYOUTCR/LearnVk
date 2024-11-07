
#include <iostream>
#include "EngineContext.h"

namespace vkEngine
{
	EngineContext::EngineContext()
	{
		initVulkan();
	}

	EngineContext::~EngineContext()
	{
		cleanup();
	}

	void EngineContext::initVulkan()
	{
		createInstance();
	}

	void EngineContext::createInstance()
	{
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "vkEngine";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledLayerCount = 0;
		createInfo.ppEnabledLayerNames = nullptr;
		createInfo.enabledExtensionCount = 0;
		createInfo.ppEnabledExtensionNames = nullptr;

		if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create instance!");
		}
	}

	void EngineContext::cleanup()
	{
		vkDestroyInstance(m_instance, nullptr);
	}
}