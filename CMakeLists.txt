cmake_minimum_required(VERSION 3.14)
project(cpp_template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CTEST_TESTING_ROOT "${CMAKE_BINARY_DIR}/Testing")

enable_testing()

# Add subdirectories
add_subdirectory(calc)
add_subdirectory(main)
add_subdirectory(test)

# Coverage Target (OpenCppCoverage + MSVC)
if (MSVC)
    find_program(OPENCPPCOVERAGE_PATH OpenCppCoverage REQUIRED)

    # Convert paths to Windows-style with backslashes
    file(TO_NATIVE_PATH "${CMAKE_SOURCE_DIR}/calc" LIB_PATH_NATIVE)
    file(TO_NATIVE_PATH "${CMAKE_SOURCE_DIR}/test" TEST_PATH_NATIVE)
    file(TO_NATIVE_PATH "${CMAKE_SOURCE_DIR}/main" MAIN_PATH_NATIVE)
    file(TO_NATIVE_PATH "C:/Program Files (x86)/Microsoft Visual Studio" MSVC_PATH_NATIVE)
    file(TO_NATIVE_PATH "${CMAKE_BINARY_DIR}/coverage.xml" COVERAGE_XML_NATIVE)

    add_custom_target(coverage
        COMMAND "${OPENCPPCOVERAGE_PATH}"
            --cover_children
            --export_type=cobertura:"${COVERAGE_XML_NATIVE}"
            --sources "${LIB_PATH_NATIVE}"
            --excluded_sources "${TEST_PATH_NATIVE}"
            --excluded_sources "${MAIN_PATH_NATIVE}"
            --excluded_sources "${MSVC_PATH_NATIVE}"
            -- "$<TARGET_FILE:test_calc>"
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        DEPENDS test_calc
        COMMENT "Generating coverage report (Cobertura XML) with OpenCppCoverage"
    )
else()
    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E echo "Coverage only supported on MSVC + OpenCppCoverage in this config."
        COMMENT "Coverage target is a placeholder for non-MSVC builds"
    )
endif()
