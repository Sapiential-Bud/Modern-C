cmake_minimum_required(VERSION 3.30)
project(004_Modern_C LANGUAGES C CXX)

# C11 for C targets
set(CMAKE_C_STANDARD 11)

# C++11 for C++ targets
set(CMAKE_CXX_STANDARD 14)

# Include headers from src/
include_directories(${CMAKE_SOURCE_DIR}/src)

# C executables
add_executable(ex_01 src/1_sequential_sorting.c)
add_executable(ex_01a src/1_sequential_sorting_string.c)
add_executable(ex_02 src/2_numerical_derivatives.c)
add_executable(ex_02a src/2_numerical_derivatives_assert.cpp)
add_executable(ex_02b src/2_numerical_derivatives_try_catch.cpp)
add_executable(ex_03 src/3_pi.c)
add_executable(ex_03a src/3_pi_static.cpp)
add_executable(ex_04 src/4_union_find.c)
add_executable(ex_04a src/4_union_find_example.c)
add_executable(ex_05 src/5_complex_numbers.c)
add_executable(ex_06 src/6_linear_algebra.c)
add_executable(ex_07 src/7_adjacency_matrix.c)
add_executable(ex_08 src/8_shortest_path.c)
add_executable(ex_09 src/9_factorization.c)
add_executable(ex_10 src/10_performance_comparison_of_sorting_algorithm.c)
add_executable(ex_11 src/11_image_segmentation.c)
add_executable(ex_12 src/12_text_processor.c)
add_executable(ex_13 src/13_generic_derivative.c)
add_executable(ex_14 src/14_generic_sorting.c)
add_executable(ex_15 src/15_text_processing_in_strings.c)
add_executable(ex_16 src/16_text_processing_in_streams.c)
add_executable(ex_17 src/17_text_processor_sophistication.c)
add_executable(ex_18 src/18_parallel_sorting_with_threads.c)

# C++ executable using std::thread
add_executable(ex_19 src/19_ThreadExample.cpp)
add_executable(ex_20 src/20_ThreadExample_mutex.cpp)
add_executable(ex_21 src/21_pointer.cpp)
add_executable(ex_22 src/22_pointer_a.cpp)
add_executable(ex_23 src/23_c_mem_layout.cpp)


add_executable(ex_24 src/24_print_memory_map.cpp)
set_target_properties(ex_24 PROPERTIES LINK_FLAGS "-mconsole")
add_executable(ex_25 src/25_Stack_Start.cpp)
#set_target_properties(ex_25 PROPERTIES LINK_FLAGS "-Wl,--stack,4194304")
add_executable(ex_26 src/26_test_stack_depth.cpp)
set_target_properties(ex_26 PROPERTIES LINK_FLAGS "-Wl,--stack,4194304")

add_executable(ex_27 src/27_Check_Available_Memory.cpp)
add_executable(ex_28 src/28_trigger_actual_allocation.cpp)

