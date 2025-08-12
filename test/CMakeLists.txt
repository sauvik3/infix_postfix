project(test_calc LANGUAGES CXX)

include(FetchContent)

# Fetch GoogleTest v1.17.0
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

# Force GoogleTest to use the same runtime as the project (important for MSVC)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Download and make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Define test executable
add_executable(${PROJECT_NAME}
    src/test_calc.cpp
    src/test_tokenizer.cpp
)

# Link test executable with library and GoogleTest
target_link_libraries(${PROJECT_NAME} PRIVATE calc gtest_main)

# Make sure the binary ends up in the main build directory (so CTest finds it)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Enable testing
enable_testing()

# Register the test explicitly with CTest
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Also add a simple named test entry for coverage
add_test(NAME test_calc COMMAND ${PROJECT_NAME})
