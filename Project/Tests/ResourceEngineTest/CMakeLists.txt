cge_setup_build("ResourceEngineTest")

set (RESOURCE_ENGINE_TEST_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (THIRD_PARTY_LIB_GLFW "-lglfw -lrt -lm -ldl -lXrandr -lXinerama -lXxf86vm -lXext -lXcursor -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lXdmcp")
set (THIRD_PARTY_LIB_GLEW "-lGLEW")
set (THIRD_PARTY_LIB_OPENGL "-lGL")
set (THIRD_PARTY_LIB_GOOGLETEST "-lgtest")
set (THIRD_PARTY_LIB_FREEIMAGE "-lfreeimage")

if(MSVC)
	cge_force_static_runtime_library()
endif()

include_directories("${CGE_COMPONENTS_DIR}")

cge_setup_external_libraries("freeimage assimp glew glfw googletest")

cge_list_header_files("${RESOURCE_ENGINE_TEST_HOME_DIR}/${CGE_INCLUDE_DIR_NAME}" HEADER_FILES})
cge_list_source_files("${RESOURCE_ENGINE_TEST_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})
cge_setup_test_project(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} SME Utilities ResourceEngine WindowSystem)
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_GLEW_LIB} ${THIRD_PARTY_OPENGL_LIB} ${THIRD_PARTY_GLFW_LIB} ${THIRD_PARTY_FREEIMAGE_LIB} ${THIRD_PARTY_GOOGLETEST_LIB} SME Utilities ResourceEngine WindowSystem)

#${THIRD_PARTY_LIB_GLEW} ${THIRD_PARTY_LIB_OPENGL} ${THIRD_PARTY_LIB_GLFW} ${THIRD_PARTY_LIB_GOOGLETEST} ${THIRD_PARTY_LIB_FREEIMAGE} SME Utilities ResourceEngine WindowSystem)
#target_link_libraries(${PROJECT_NAME} GLEW GL glfw3 glfw rt m dl Xrandr Xinerama Xxf86vm Xext Xcursor Xrender Xfixes X11 pthread xcb Xau Xdmcp gtest freeimage SME Utilities ResourceEngine WindowSystem)
