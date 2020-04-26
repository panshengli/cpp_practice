CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT(cpp_practice)
set(CMAKE_CXX_FLAGS "-std=c++11")
INCLUDE_DIRECTORIES(
    include
)
ADD_EXECUTABLE(find_var_from_vector src/find_var_from_vector.cpp)
ADD_EXECUTABLE(call_func src/call_func.cpp)
ADD_EXECUTABLE(static_class src/static_class.cpp)
ADD_EXECUTABLE(sizeof src/sizeof.cpp)
ADD_EXECUTABLE(ptr_opertor src/ptr_opertor.cpp)
TARGET_LINK_LIBRARIES(
    cpp_practice 
)

