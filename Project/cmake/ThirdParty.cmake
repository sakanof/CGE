if(WIN32)
	set(BUILD_TARGET "Debug")

	if(MSVC12)
		SET(ASSIMP_MSVC_VERSION "vc120")
	elseif(MSVC14)
		SET(ASSIMP_MSVC_VERSION "vc140")
	ENDIF(MSVC12)

	# done
	set(THIRD_PARTY_ASSIMP_LIB	   "assimp-${ASSIMP_MSVC_VERSION}-mt.lib")
	set(THIRD_PARTY_ASSIMP_LIB_DIR	   "${CGE_THIRD_PARTY_DIR}/assimp/build/code/${BUILD_TARGET}")
	set(THIRD_PARTY_ASSIMP_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/assimp/include")

	# done
	set(THIRD_PARTY_FREEIMAGE_LIB         "FreeImage.lib")
	set(THIRD_PARTY_FREEIMAGE_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/FreeImage/Dist")
	set(THIRD_PARTY_FREEIMAGE_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}")

	# done
	set(THIRD_PARTY_GLFW_LIB         "glfw3.lib")
	set(THIRD_PARTY_GLFW_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/glfw/src/${BUILD_TARGET}")
	set(THIRD_PARTY_GLFW_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/glfw/include")

	# WIP
	set(THIRD_PARTY_GLEW_LIB         "glew32.lib")
	set(THIRD_PARTY_GLEW_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/glew/build/cmake/lib/${BUILD_TARGET}")
	set(THIRD_PARTY_GLEW_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/glew/include")

	set(THIRD_PARTY_OPENGL_LIB         "opengl32.lib")

	# done
	set(THIRD_PARTY_GOOGLETEST_LIB         "gtest.lib")
	set(THIRD_PARTY_GOOGLETEST_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/googletest/googletest/build/${BUILD_TARGET}")
	set(THIRD_PARTY_GOOGLETEST_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/googletest/googletest/include")
else()
	# done
	set(THIRD_PARTY_ASSIMP_LIB         "-lassimp")
	set(THIRD_PARTY_ASSIMP_LIB_DIR	   "${CGE_THIRD_PARTY_DIR}/assimp/build/code")
	set(THIRD_PARTY_ASSIMP_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/assimp/include")

	# done
	set(THIRD_PARTY_FREEIMAGE_LIB         "-lfreeimage-3.17.0")
	set(THIRD_PARTY_FREEIMAGE_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/FreeImage/Dist")
	set(THIRD_PARTY_FREEIMAGE_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}")

	# done
	set(THIRD_PARTY_GLEW_LIB         "-lGLEW")
	set(THIRD_PARTY_GLEW_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/glew/build/cmake/lib/${BUILD_TARGET}")
	set(THIRD_PARTY_GLEW_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/glew/include")

	set(THIRD_PARTY_OPENGL_LIB "-lGL")

	# done
	set(THIRD_PARTY_GLFW_LIB         "-lglfw -lrt -lm -ldl -lXrandr -lXinerama -lXxf86vm -lXext -lXcursor -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lXdmcp")
	set(THIRD_PARTY_GLFW_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/glfw/src")
	set(THIRD_PARTY_GLFW_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/glfw/include")

	# done 
	set(THIRD_PARTY_GOOGLETEST_LIB         "-lgtest -lpthread")
	set(THIRD_PARTY_GOOGLETEST_LIB_DIR     "${CGE_THIRD_PARTY_DIR}/googletest/googletest/build")
	set(THIRD_PARTY_GOOGLETEST_INCLUDE_DIR "${CGE_THIRD_PARTY_DIR}/googletest/googletest/include")
endif()

function(cge_print_third_party)
	message("Assimp: ${THIRD_PARTY_ASSIMP_LIB}")
	message("Assimp: ${THIRD_PARTY_ASSIMP_LIB_DIR}")
	message("Assimp: ${THIRD_PARTY_ASSIMP_INCLUDE_DIR}")

	message("FreeImage: ${THIRD_PARTY_FREEIMAGE_LIB}")
	message("FreeImage: ${THIRD_PARTY_FREEIMAGE_LIB_DIR}")
	message("FreeImage: ${THIRD_PARTY_FREEIMAGE_INCLUDE_DIR}")

	message("FreeImage: ${THIRD_PARTY_FREEIMAGE_LIB}")
	message("FreeImage: ${THIRD_PARTY_FREEIMAGE_LIB_DIR}")
	message("FreeImage: ${THIRD_PARTY_FREEIMAGE_INCLUDE_DIR}")

	message("GLFW: ${THIRD_PARTY_GLFW_LIB}")
	message("GLFW: ${THIRD_PARTY_GLFW_LIB_DIR}")
	message("GLFW: ${THIRD_PARTY_GLFW_INCLUDE_DIR}")

	message("GLEW: ${THIRD_PARTY_GLEW_LIB}")
	message("GLEW: ${THIRD_PARTY_GLEW_LIB_DIR}")
	message("GLEW: ${THIRD_PARTY_GLEW_INCLUDE_DIR}")

	message("GoogleTest: ${THIRD_PARTY_GOOGLETEST_LIB}")
	message("GoogleTest: ${THIRD_PARTY_GOOGLETEST_LIB_DIR}")
	message("GoogleTest: ${THIRD_PARTY_GOOGLETEST_INCLUDE_DIR}")
endfunction()

function(add_assimp_dependency)
	include_directories("${CGE_THIRD_PARTY_DIR}/assimp/include")
	link_directories("${CGE_THIRD_PARTY_DIR}/assimp/build/code")
endfunction()

function(add_freeimage_dependency)
	include_directories("${CGE_THIRD_PARTY_DIR}")
	link_directories("${CGE_THIRD_PARTY_DIR}/FreeImage/Dist")
endfunction()

function(add_googletest_dependency)
	include_directories("${CGE_THIRD_PARTY_DIR}/googletest/googletest/include")
	link_directories("${CGE_THIRD_PARTY_DIR}/googletest/googletest/build")
endfunction()

function(add_glew_dependency)
	include_directories("${CGE_THIRD_PARTY_DIR}/glew/include")
	link_directories("${CGE_THIRD_PARTY_DIR}/glew/build/lib")
endfunction()

function(add_glfw_dependency)
	include_directories("${CGE_THIRD_PARTY_DIR}/glfw/include")
	link_directories("${CGE_THIRD_PARTY_DIR}/glfw/src")
endfunction()

function(add_dependency INCLUDE_DIR LIB_DIR)
	message("add_dependency")
	message("	Include: ${INCLUDE_DIR}")
	message("	lib_dir: ${LIB_DIR}")
	include_directories(${INCLUDE_DIR})
	link_directories(${LIB_DIR})
endfunction()

function(cge_setup_external_libraries LIBS)
	separate_arguments(LIBS)

	FOREACH(LIB ${LIBS})
		if(LIB STREQUAL "assimp")
			add_dependency(${THIRD_PARTY_ASSIMP_INCLUDE_DIR} ${THIRD_PARTY_ASSIMP_LIB_DIR})
			#add_assimp_dependency()
		elseif(LIB STREQUAL "freeimage")
			add_dependency(${THIRD_PARTY_FREEIMAGE_INCLUDE_DIR} ${THIRD_PARTY_FREEIMAGE_LIB_DIR})
			#add_freeimage_dependency()
		elseif(LIB STREQUAL "googletest")
			add_dependency(${THIRD_PARTY_GOOGLETEST_INCLUDE_DIR} ${THIRD_PARTY_GOOGLETEST_LIB_DIR})
			#add_googletest_dependency()
		elseif(LIB STREQUAL "glew")
			add_dependency(${THIRD_PARTY_GLEW_INCLUDE_DIR} ${THIRD_PARTY_GLEW_LIB_DIR})
			#add_glew_dependency()
		elseif(LIB STREQUAL "glfw")
			add_dependency(${THIRD_PARTY_GLFW_INCLUDE_DIR} ${THIRD_PARTY_GLFW_LIB_DIR})
			#add_glfw_dependency()
		endif()
	ENDFOREACH()
endfunction()
