add_library(calc
    include/tokens.hpp
    src/tokenize.cpp
    include/tokenize.hpp
    src/calc.cpp
    include/calc.hpp
)

target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
