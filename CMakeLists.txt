CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT(cpp_practice)
set(CMAKE_CXX_FLAGS "-std=c++11")
find_package(OpenCV 3.3 REQUIRED)
INCLUDE_DIRECTORIES(
    include
    ${OpenCV_INCLUEDE_DIRS}
)
ADD_EXECUTABLE(find_var_from_vector src/find_var_from_vector.cpp)
ADD_EXECUTABLE(call_func src/call_func.cpp)
ADD_EXECUTABLE(static_class src/static_class.cpp)
ADD_EXECUTABLE(sizeof src/sizeof.cpp)
ADD_EXECUTABLE(ptr_opertor src/ptr_opertor.cpp)
ADD_EXECUTABLE(std_ref src/std_ref.cpp)
ADD_EXECUTABLE(vector_sort src/vector_sort.cpp)
TARGET_LINK_LIBRARIES(
    vector_sort 
    ${OpenCV_LIBRARIES} 
)

