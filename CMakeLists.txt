cmake_minimum_required(VERSION 3.12)
project(Struktury_danych VERSION 1.0.0)

add_executable(${PROJECT_NAME} src/main.cpp src/stack_list.cpp src/singly_linked_list_node.cpp src/singly_linked_list.cpp src/stack_array.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/inc/
)
