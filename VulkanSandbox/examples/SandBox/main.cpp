#include<iostream>

#include "EngineContext.h"

int main()
{
	vkEngine::EngineContext engineContext;

	//std::cout << "Hello World" << std::endl;
	//vkEngine::EngineContext::EngineContextTest();
	getchar();
	return 0;
}


// main.cpp
//#include <vkEngine/EngineContext.h>
//#include <vkEngine/Renderer.h>
//#include <vkEngine/Window.h>
//#include <iostream>
//
//int main() {
//    vkEngine::EngineContext engineContext;
//
//    try {
//        engineContext.init();
//
//        vkEngine::Window window("My Vulkan Window", 800, 600);
//        vkEngine::Renderer renderer(&engineContext);
//
//        // Ö÷Ñ­»·
//        while (!window.shouldClose()) {
//            window.pollEvents();
//            renderer.render();
//        }
//
//        engineContext.cleanup();
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    return EXIT_SUCCESS;
//}