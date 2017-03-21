cge_setup_build("Utilities")

set(UTILITIES_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

cge_list_source_files("${UTILITIES_HOME_DIR}/Source" SRC_FILES})

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
cge_setup_component_project(${PROJECT_NAME} "UTILITIES_API_EXPORT")
