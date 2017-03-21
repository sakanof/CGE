project("CGE")
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
message(STATUS "Processing ${PROJECT_NAME}")

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
set(CGE_HOME_DIR	"${CMAKE_CURRENT_SOURCE_DIR}/..")
set(CGE_PROJECT_DIR	"${CGE_HOME_DIR}/Project")
set(CGE_COMPONENTS_DIR	"${CGE_PROJECT_DIR}/Components")
set(CGE_THIRD_PARTY_DIR	"${CGE_HOME_DIR}/Utilities/ThirdParty")

set(CGE_INCLUDE_DIR_NAME "Include")
set(CGE_SOURCE_DIR_NAME	 "Source")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CGE_PROJECT_DIR}/cmake)

include(Util)
include(ThirdParty)

#####################################################################
# Set up the basic build environment
#####################################################################
if(CMAKE_BUILD_TYPE STREQUAL "")
	# CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up differentiation between debug and release builds.
	set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

# Set compiler specific build flags
if(CMAKE_COMPILER_IS_GNUCXX)
	add_definitions(-msse)
endif()

if(MSVC)
	if(CMAKE_BUILD_TOOL STREQUAL "nmake")
		# Set variable to state that we are using nmake makefiles
		set(NMAKE TRUE)
	endif()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:fast")
	# Enable intrinsics on MSVC in debug mode
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Oi")
	if(CMAKE_CL_64)
		# Visual Studio bails out on debug builds in 64bit mode unless this flag is set
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
		set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /bigobj")
	endif()
endif()

#TODO: is it really necessary?
if(MINGW)
	add_definitions(-D_WIN32_WINNT=0x0500)
endif()

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG(-std=c++11 COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG(-std=c++0x COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	message(STATUS "CMAKE_CXX_FLAGS CXX11 ${CMAKE_CXX_FLAGS}")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	message(STATUS "CMAKE_CXX_FLAGS CXX0X ${CMAKE_CXX_FLAGS}")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

if(CMAKE_COMPILER_IS_GNUCXX AND NOT MINGW)
	# Test for GCC visibility
	include(CheckCXXCompilerFlag)
	check_cxx_compiler_flag(-fvisibility=hidden SDK_GCC_VISIBILITY)
	if(SDK_GCC_VISIBILITY)
		# Determine gcc version
		execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE SDK_GCC_VERSION)
		message(STATUS "Detected g++ ${SDK_GCC_VERSION}")
		message(STATUS "Enabling GCC visibility flags")
		set(SDK_GCC_VISIBILITY_FLAGS "-DSDK_GCC_VISIBILITY -fvisibility=hidden")
  
		# Check if we can safely add -fvisibility-inlines-hidden
		string(TOLOWER "${CMAKE_BUILD_TYPE}" SDK_BUILD_TYPE)
		if(SDK_BUILD_TYPE STREQUAL "debug" AND SDK_GCC_VERSION VERSION_LESS "4.2")
			message(STATUS "Skipping -fvisibility-inlines-hidden due to possible bug in g++ < 4.2")
		else()
			set(SDK_GCC_VISIBILITY_FLAGS "${SDK_GCC_VISIBILITY_FLAGS} -fvisibility-inlines-hidden")
		endif()
	endif()
  
	# Fix x64 issues on Linux
	if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" AND NOT APPLE)
		add_definitions(-fPIC)
	endif()  
endif()

#####################################################################
# Add the SDK projects
#####################################################################
add_subdirectory(Components)
add_subdirectory(Samples)
add_subdirectory(Tests)
