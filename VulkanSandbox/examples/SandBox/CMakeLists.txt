
# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(SandBox)

# 设置C++标准为C++20
set(CMAKE_CXX_STANDARD 20)

# 如果需要，设置为必需，这样CMake会报错如果编译器不支持C++20
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(${PROJECT_NAME} main.cpp)

#vkEngine
#添加vkEngine的库目录
set(VK_ENGINE_PROJECT_PATH "D:/Engineering/LearnVK/VulkanSandbox/vkEngine")
# 设置 vkEngine DLL 的源路径
set(VK_ENGINE_DLL_PATH "D:/Engineering/LearnVK/VulkanSandbox/out/build/x64-Debug/vkEngine/vkEngine.dll") 
link_directories(${VK_ENGINE_PROJECT_PATH})
target_include_directories(${PROJECT_NAME} PRIVATE ${VK_ENGINE_PROJECT_PATH}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE vkEngine)

# 添加自定义命令以复制 DLL
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${VK_ENGINE_DLL_PATH}"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
)


#cmake_minimum_required(VERSION 3.10)
#project(SandBox)
#
# 设置C++标准为C++20
#set(CMAKE_CXX_STANDARD 20)
#
# 如果需要，设置为必需，这样CMake会报错如果编译器不支持C++20
#set(CMAKE_CXX_STANDARD_REQUIRED YES)
#
# 查找 vkEngine 库
#find_package(vkEngine REQUIRED)
#
#add_executable(${PROJECT_NAME} main.cpp)
#
# 链接 vkEngine 库
#target_link_libraries(${PROJECT_NAME} PRIVATE vkEngine)
