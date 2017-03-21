cge_setup_build("SME")

set (SME_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

cge_list_source_files("${SME_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
cge_setup_component_project(${PROJECT_NAME} "SIMPLE_MATH_ENGINE_API_EXPORT")
