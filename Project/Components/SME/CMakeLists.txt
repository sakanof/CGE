cge_setup_build("SME")

set (SME_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

cge_list_header_files("${SME_HOME_DIR}/${CGE_INCLUDE_DIR_NAME}" HEADER_FILES})
cge_list_source_files("${SME_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_library (${PROJECT_NAME} SHARED ${HEADER_FILES} ${SRC_FILES})
cge_setup_project_lib(${PROJECT_NAME} "SIMPLE_MATH_ENGINE_API_EXPORT")
