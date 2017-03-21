cge_setup_build("ResourceEngine")

set (RESOURCE_ENGINE_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories("${CGE_COMPONENTS_DIR}")

cge_setup_external_libraries("freeimage assimp")

cge_list_source_files("${RESOURCE_ENGINE_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_library (${PROJECT_NAME} SHARED ${SRC_FILES})
cge_setup_component_project(${PROJECT_NAME} "RESOURCE_ENGINE_API_EXPORT")

add_dependencies(${PROJECT_NAME} SME Utilities)
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_FREEIMAGE_LIB} ${THIRD_PARTY_ASSIMP_LIB} Utilities SME)
