cge_setup_build("WindowSystem")

set (WINDOW_SYSTEM_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Utilities and SME components
cge_setup_external_library("${CMAKE_CURRENT_SOURCE_DIR}/.."
			   "${WINDOW_SYSTEM_HOME_DIR}/../../../Bin/Libs/VS2013/Debug")
# Glew and OpenGL
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}/glew/include"
			   "${CGE_THIRD_PARTY_DIR}/glew/build/cmake/lib")
# GLFW
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}/glfw/include"
			   "${CGE_THIRD_PARTY_DIR}/glfw/src")

cge_list_header_files("${WINDOW_SYSTEM_HOME_DIR}/${CGE_INCLUDE_DIR_NAME}" HEADER_FILES})
cge_list_source_files("${WINDOW_SYSTEM_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_library (${PROJECT_NAME} SHARED ${HEADER_FILES} ${SRC_FILES})
cge_setup_project_lib(${PROJECT_NAME} "WINDOW_SYSTEM_API_EXPORT")

add_dependencies(${PROJECT_NAME} SME Utilities)
target_link_libraries(${PROJECT_NAME} glew32d opengl32 glfw3dll Utilities SME)
