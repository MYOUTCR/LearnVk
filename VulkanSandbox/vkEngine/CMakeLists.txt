cmake_minimum_required(VERSION 3.10)
project(vkEngine)

# 设置C++标准为C++20
set(CMAKE_CXX_STANDARD 20)

# 如果需要，设置为必需，这样CMake会报错如果编译器不支持C++20
set(CMAKE_CXX_STANDARD_REQUIRED YES)

#包含头文件;
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
#include_directories(${INCLUDES})

#包含的源码;
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
 "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCES})

#Vulkan
set(VULKAN_SDK "D:/CommonLib/VulkanSDK/1.3.283.0") 
find_package(Vulkan REQUIRED)

if(VULKAN_FOUND)
  target_include_directories(${PROJECT_NAME} PUBLIC ${VULKAN_SDK}/include)
  target_link_libraries(${PROJECT_NAME} ${VULKAN_SDK}/Lib/vulkan-1.lib)
else()
  message(FATAL_ERROR "Vulkan SDK not found.")
endif()



#install(TARGETS ${PROJECT_NAME}
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION bin
#        ARCHIVE DESTINATION lib
#)

# 假设Vulkan SDK安装在C:/VulkanSDK/1.2.162.1或通过环境变量设置
#set(VULKAN_SDK "D:/CommonLib/VulkanSDK/1.3.283.0") 
#set(VULKAN_SDK_BINARY_PATH "C:/VulkanSDK/1.2.162.1/Bin")
#find_package(Vulkan REQUIRED)
#
#if(VULKAN_FOUND)
#  include_directories(${VULKAN_INCLUDE_DIRS})  # 包含Vulkan头文件目录
#  message(STATUS "Vulkan Include Directories: ${VULKAN_INCLUDE_DIRS}")  # 打印Vulkan头文件目录
#  target_link_libraries(${PROJECT_NAME} ${VULKAN_LIBRARIES})
#else()
#  message(FATAL_ERROR "Vulkan SDK not found.")
#endif()