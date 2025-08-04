add_executable(main 
    src/main.cpp
)

target_link_libraries(main PRIVATE calc)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)
