find_package(GTest CONFIG REQUIRED)

set(TARGET open_project_in_vscode_test)

add_executable(${TARGET}
    project_test.cpp
    $<TARGET_OBJECTS:project>
)

target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${TARGET} PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${TARGET})
