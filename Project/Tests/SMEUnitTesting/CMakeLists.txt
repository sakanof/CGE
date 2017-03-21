cge_setup_build("SMEUnitTesting")

set (SME_UNIT_TESTING_HOME_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
	cge_force_static_runtime_library()
endif()

include_directories("${CGE_COMPONENTS_DIR}")

cge_setup_external_libraries("googletest")

cge_list_header_files("${SME_UNIT_TESTING_HOME_DIR}/${CGE_INCLUDE_DIR_NAME}" HEADER_FILES})
cge_list_source_files("${SME_UNIT_TESTING_HOME_DIR}/${CGE_SOURCE_DIR_NAME}" SRC_FILES})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})
cge_setup_test_project(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} SME)
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_GOOGLETEST_LIB} SME)
