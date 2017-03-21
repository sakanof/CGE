# Force static runtime library
macro(cge_force_static_runtime_library)
	FOREACH(flag
		CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_RELWITHDEBINFO
		CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_DEBUG_INIT
		CMAKE_CXX_FLAGS_RELEASE  CMAKE_CXX_FLAGS_RELWITHDEBINFO
		CMAKE_CXX_FLAGS_DEBUG  CMAKE_CXX_FLAGS_DEBUG_INIT)
		STRING(REPLACE "/MD"  "/MT" "${flag}" "${${flag}}")
		SET("${flag}" "${${flag}} /EHsc" CACHE INTERNAL "")
	ENDFOREACH()
endmacro()

# Basic setup for the given project
# PROJECTNAME - The name of the project being setup
function(cge_setup_build PROJECT_NAME)
	set(PROJECT_NAME ${PROJECT_NAME} PARENT_SCOPE)
	project(${PROJECT_NAME})
	message(STATUS "Processing ${PROJECT_NAME}")
endfunction()

# Function to setup some standard project items
# PROJECTNAME - The name of the project
# DEFINITIONS - The preprocessors definitions
# TARGETDIR - The target directory for output files (relative to CMAKE_SOURCE_DIR)
function(cge_setup_project_common PROJECTNAME DEFINITIONS TARGETDIR)
	# Set the Debug and Release names
	set_target_properties(${PROJECTNAME} PROPERTIES DEBUG_OUTPUT_NAME ${PROJECTNAME} RELEASE_OUTPUT_NAME ${PROJECTNAME})
	
	if(NOT(DEFINITIONS STREQUAL ""))
		set_target_properties(${PROJECTNAME} PROPERTIES COMPILE_DEFINITIONS "${DEFINITIONS}" OUTPUT_NAME ${PROJECTNAME})
	endif()

	#TODO: move it to a specific .cmake
	# Add a post-build step for MSVC to copy the output to the target directory
	if(MSVC)
		#add_custom_command(TARGET ${PROJECTNAME} POST_BUILD COMMAND copy "$(TargetPath)" "${CMAKE_SOURCE_DIR}/${TARGETDIR}")
		#set_target_properties( ${PROJECTNAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
		#set_target_properties( ${PROJECTNAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/DebugOut")
	        #set_target_properties( ${PROJECTNAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/Releaseblajnd")
	endif()

	# TODO: make it specific to each type of build
	# Setup install to copy the built output to the target directory (for compilers that don't have post build steps)
	install(
		TARGETS ${PROJECTNAME}
		LIBRARY DESTINATION "${CMAKE_SOURCE_DIR}/${TARGETDIR}"
		ARCHIVE DESTINATION "${CMAKE_SOURCE_DIR}/${TARGETDIR}"
		RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/${TARGETDIR}"
		)
endfunction()

# Function to setup some project items for static library
# PROJECTNAME - The name of the project being setup
# DEFINITIONS - The preprocessors definitions
function(cge_setup_component_project PROJECTNAME DEFINITIONS)
	cge_setup_project_common(${PROJECTNAME} ${DEFINITIONS} "Lib")
endfunction()

# Function to setup some project items for applications
# PROJECTNAME - The name of the project being setup
function(cge_setup_test_project PROJECTNAME)
	cge_setup_project_common(${PROJECTNAME} "" "Bin")
endfunction()

# Function to setup some project items for applications
# PROJECTNAME - The name of the project being setup
function(cge_setup_sample_project PROJECTNAME)
	cge_setup_project_common(${PROJECTNAME} "" "Bin")
endfunction()

# Function to list header files in the given directory, recursing into it's sub-directories
# HEADER_DIR	- Directory that the header files will be listed from 
# HEADER_FILES	- To be filled with the found header files
function(cge_list_header_files HEADER_DIR HEADER_FILES)
	file(GLOB_RECURSE HEADER_FILES_TMP "${HEADER_DIR}/*.h" "${HEADER_DIR}/*.hpp" "${HEADER_DIR}/*.inl" "${HEADER_DIR}/*.pch")
	set(HEADER_FILES ${HEADER_FILES_TMP} PARENT_SCOPE)
endfunction()

# Function to list source files in the given directory, recursing into it's sub-directories
# SOURCE_DIR - Directory that the header files will be listed from 
# SRC_FILES  - To be filled with the found source files
function(cge_list_source_files SOURCE_DIR SRC_FILES)
	file(GLOB_RECURSE SOURCE_FILES_TMP "${SOURCE_DIR}/*.c" "${SOURCE_DIR}/*.cpp")
	set(SRC_FILES ${SOURCE_FILES_TMP} PARENT_SCOPE)
endfunction()
