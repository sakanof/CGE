# Git Submodules build reference 

This is a basic reference on how to build the third party libs, for a complete reference please consult the project's documentation.

## Dependencies

To build the submodules you will need to install the following dependencies:

 - [CMake](https://cmake.org/)
 - [MinGW](http://www.mingw.org/)

## GLEW

### Windows ###
Generate the MSVS files and its dependencies:
#### 
	$ cd auto/ && mingw32-make.exe
	$ cd build/ && cmake ./cmake/
	
That done you just need to open the `glew.sln` file, located on build/vsXX, where `XX` is the VC++ version, and build it.

For a complete reference please visit: http://glew.sourceforge.net/build.html

  
## GLFW
Generate the MSVS files and its dependencies:
#### 
	$ cmake .
	
That done you just need to open the `GLFW.sln` file and build it.

For a complete reference please visit: http://www.glfw.org/docs/latest/compile.html

## Google Test
Generate the MSVS files and its dependencies:
#### 
	$ mkdir build;
	$ cd build && cmake ../
	
That done you just need to open the `gtest.sln` file and build it.

For a complete reference please visit: https://github.com/google/googletest/blob/master/googletest/README.md
