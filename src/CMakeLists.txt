cmake_minimum_required(VERSION 3.21)

set(Target "open_project_in_vscode")

add_executable(${Target}
    main.cpp
)

add_custom_command(TARGET ${Target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/data/vscode_project" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/vscode_project
)
