project(test_calc)

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
add_executable(${PROJECT_NAME} src/test_calc.cpp)

# Link test executable with add library and GoogleTest (auto main)
target_link_libraries(${PROJECT_NAME} PRIVATE calc gtest_main)

# Enable automatic test discovery
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
