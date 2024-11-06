
# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(SandBox)

# 设置C++标准为C++20
set(CMAKE_CXX_STANDARD 20)

# 如果需要，设置为必需，这样CMake会报错如果编译器不支持C++20
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# 添加 vkEngine 的库目录
set(VK_ENGINE_PROJECT_PATH "D:/Engineering/VulkanSandbox/vkEngine")
# 假设 vkEngine 的库文件在 D:/Engineering/VulkanSandbox/vkEngine 目录下
#link_directories(D:/Engineering/VulkanSandbox/vkEngine)
link_directories(${VK_ENGINE_PROJECT_PATH})

# 添加可执行文件或库
add_executable(${PROJECT_NAME} main.cpp)  # 假设你的源文件是 main.cpp

# 链接 vkEngine 库
target_link_libraries(${PROJECT_NAME} PRIVATE vkEngine)

# 如果需要包含头文件目录
#target_include_directories(${PROJECT_NAME} PRIVATE D:/Engineering/VulkanSandbox/vkEngine/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${VK_ENGINE_PROJECT_PATH}/include)

# 设置 vkEngine DLL 的源路径
#set(VK_ENGINE_DLL_PATH "${CMAKE_SOURCE_DIR}/../vkEngine/Debug/vkEngine.dll")  # 根据你的实际路径调整
set(VK_ENGINE_DLL_PATH "D:/Engineering/VulkanSandbox/out/build/x64-Debug/vkEngine/vkEngine.dll") 

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
