CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT(cpp_practice)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
# find_package(OpenCV 3.3 REQUIRED)
INCLUDE_DIRECTORIES(
    include
    # ${OpenCV_INCLUEDE_DIRS}
)
ADD_EXECUTABLE(find_var_from_vector src/find_var_from_vector.cpp)
ADD_EXECUTABLE(call_func src/call_func.cpp)
ADD_EXECUTABLE(static_class src/static_class.cpp)
ADD_EXECUTABLE(sizeof src/sizeof.cpp)
ADD_EXECUTABLE(ptr_opertor src/ptr_opertor.cpp)
ADD_EXECUTABLE(std_ref src/std_ref.cpp)
# ADD_EXECUTABLE(vector_sort src/vector_sort.cpp)
ADD_EXECUTABLE(const_ptr src/const_ptr.cpp)
ADD_EXECUTABLE(this_ptr src/this_ptr.cpp)
ADD_EXECUTABLE(ptr_array src/ptr_array.cpp)
ADD_EXECUTABLE(crtp_class src/crtp_class.cpp)
ADD_EXECUTABLE(crtp_class1 src/crtp_class1.cpp)
ADD_EXECUTABLE(static_polymorhism src/static_polymorhism.cpp)
ADD_EXECUTABLE(malloc_new src/malloc_new.cpp)
ADD_EXECUTABLE(new_delete src/new_delete.cpp)
ADD_EXECUTABLE(strcpy src/strcpy.cpp)
ADD_EXECUTABLE(memcpy src/memcpy.cpp)
ADD_EXECUTABLE(get16string src/get16string.cpp)
ADD_EXECUTABLE(strcat src/strcat.cpp)
ADD_EXECUTABLE(construct src/construct.cpp)
ADD_EXECUTABLE(copy_constructure src/copy_constructure.cpp)
ADD_EXECUTABLE(class_func src/class_func.cpp)
ADD_EXECUTABLE(class_deconstruction src/class_deconstruction.cpp)
ADD_EXECUTABLE(overload src/overload.cpp)
ADD_EXECUTABLE(test_logger src/test_logger.cpp src/logger.cpp)
ADD_EXECUTABLE(template_funct src/template_funct.cpp)
ADD_EXECUTABLE(vector_iterator src/vector_iterator.cpp)
ADD_EXECUTABLE(stack_queue src/stack_queue.cpp)
ADD_EXECUTABLE(rabin_karp src/rabin_karp.cpp)
ADD_EXECUTABLE(atom_thread src/atom_thread.cpp)
ADD_EXECUTABLE(str_compare src/str_compare.cpp)
ADD_EXECUTABLE(class_output src/class_output.cpp)
ADD_EXECUTABLE(ptr_release src/ptr_release.cpp)
ADD_EXECUTABLE(class_sizeof src/class_sizeof.cpp)
ADD_EXECUTABLE(auto_reference src/auto_reference.cpp)
ADD_EXECUTABLE(auto src/auto.cpp)
ADD_EXECUTABLE(singleton1 src/singleton.cpp src/singleton1_main.cpp)
ADD_EXECUTABLE(singleton2 src/singleton.cpp src/singleton2_main.cpp)
ADD_EXECUTABLE(bind_test src/bind_test.cpp)
ADD_EXECUTABLE(multi_thread_notify_all src/multi_thread_notify_all.cpp)
# TARGET_LINK_LIBRARIES(
#     vector_sort 
#     ${OpenCV_LIBRARIES} 
# )

# TARGET_LINK_LIBRARIES(
#     vector_sort 
#     pthread
# )



