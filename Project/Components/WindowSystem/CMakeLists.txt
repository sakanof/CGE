cge_setup_build("WindowSystem")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CGE_PROJECT_DIR}/cmake)

include(Util)
include(ThirdParty)
set(WINDOW_SYSTEM_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories("${CGE_COMPONENTS_DIR}")

cge_setup_external_libraries("glew glfw")

cge_list_source_files("${WINDOW_SYSTEM_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
cge_setup_component_project(${PROJECT_NAME} "WINDOW_SYSTEM_API_EXPORT")

add_dependencies(${PROJECT_NAME} SME Utilities)
message("GLEW: ${THIRD_PARTY_GLEW_LIB}")
message("GLFW: ${THIRD_PARTY_GLFW_LIB}")
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_GLEW_LIB} ${THIRD_PARTY_GLFW_LIB} SME Utilities)
#target_link_libraries(${PROJECT_NAME} GLEW glfw3 X11 Xrandr Xi Xxf86vm Xcursor Xinerama SME Utilities)
