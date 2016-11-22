cge_setup_build("ResourceEngine")

set (RESOURCE_ENGINE_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Utilities and SME components
cge_setup_external_library("${CMAKE_CURRENT_SOURCE_DIR}/.."
			   "${RESOURCE_ENGINE_HOME_DIR}/../../../Bin/Libs/VS2013/Debug")
# FreeImage
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}"
			   "${CGE_THIRD_PARTY_DIR}/FreeImage/Lib/Win32")
# Assimp
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}"
			   "${CGE_THIRD_PARTY_DIR}/AssimpSDK/Lib/Win32")

cge_list_header_files("${RESOURCE_ENGINE_HOME_DIR}/Include" HEADER_FILES})
cge_list_source_files("${RESOURCE_ENGINE_HOME_DIR}/Source" SRC_FILES})

add_library (${PROJECT_NAME} SHARED ${HEADER_FILES} ${SRC_FILES})
cge_setup_project_lib(${PROJECT_NAME} "RESOURCE_ENGINE_API_EXPORT")

add_dependencies(${PROJECT_NAME} SME Utilities)
target_link_libraries(${PROJECT_NAME} Utilities SME FreeImage assimp)
