cge_setup_build("BasicWindow")

set (BASIC_WINDOW_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories("${CGE_COMPONENTS_DIR}")

cge_setup_external_libraries("assimp freeimage glew glfw")

#cge_list_header_files("${BASIC_WINDOW_HOME_DIR}/${CGE_INCLUDE_DIR_NAME}" HEADER_FILES})
cge_list_source_files("${BASIC_WINDOW_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_executable(${PROJECT_NAME} ${SRC_FILES})
cge_setup_sample_project(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} SME Utilities ResourceEngine WindowSystem)
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_GLEW_LIB} ${THIRD_PARTY_GLFW_LIB} ${THIRD_PARTY_FREEIMAGE_LIB} SME Utilities ResourceEngine WindowSystem)
