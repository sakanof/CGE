cge_setup_build("SMEUnitTesting")

set (SME_UNIT_TESTING_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

cge_force_static_runtime_library()

# SME component
cge_setup_external_library("${CGE_PROJECT_DIR}/Components"
			   "${CGE_HOME_DIR}/Bin/Libs/VS2013/Debug")
# googletest
cge_setup_external_library("${CGE_THIRD_PARTY_DIR}/googletest/googletest/include"
			   "${CGE_THIRD_PARTY_DIR}/googletest/googletest/build")

cge_list_header_files("${SME_UNIT_TESTING_HOME_DIR}/${CGE_INCLUDE_DIR_NAME}" HEADER_FILES})
cge_list_source_files("${SME_UNIT_TESTING_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})
cge_setup_project_app(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} SME)
target_link_libraries(${PROJECT_NAME} SME gtest)
