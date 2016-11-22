cge_setup_build("ResourceEngineTest")

set (RESOURCE_ENGINE_TEST_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

cge_force_static_runtime_library()

# SME component
cge_setup_external_library("${CGE_PROJECT_DIR}/Components"
			   "${CGE_HOME_DIR}/Bin/Libs/VS2013/Debug")
# FreeImage
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}"
			   "${CGE_THIRD_PARTY_DIR}/FreeImage/Lib/Win32")
# Assimp
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}"
			   "${CGE_THIRD_PARTY_DIR}/AssimpSDK/Lib/Win32")
# Glew and OpenGL
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}/glew/include"
			   "${CGE_THIRD_PARTY_DIR}/glew/build/cmake/lib")
# GLFW
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}/glfw/include"
			   "${CGE_THIRD_PARTY_DIR}/glfw/src")
# googletest
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}/googletest/googletest/include"
			   "${CGE_THIRD_PARTY_DIR}/googletest/googletest/build")

cge_list_header_files("${RESOURCE_ENGINE_TEST_HOME_DIR}/${CGE_INCLUDE_DIR_NAME}" HEADER_FILES})
cge_list_source_files("${RESOURCE_ENGINE_TEST_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})
cge_setup_project_app(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} SME Utilities ResourceEngine WindowSystem)
target_link_libraries(${PROJECT_NAME} glew32d opengl32 glfw3dll FreeImage Utilities SME ResourceEngine WindowSystem gtest)
