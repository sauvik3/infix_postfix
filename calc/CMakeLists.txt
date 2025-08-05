project(calc)

add_library(${PROJECT_NAME}
    src/tokenize.cpp
    src/operators.cpp
    src/calc.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
