add_library(calc 
    src/add.cpp
    include/add.hpp
)

target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
