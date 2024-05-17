cmake_minimum_required (VERSION 3.28)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

SET (CMAKE_C_COMPILER             "/usr/bin/clang")
set (CMAKE_C_STANDARD 17)
SET (CMAKE_C_FLAGS                "-Wall -static -std=c++17 -lm -lc")
SET (CMAKE_C_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")


SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
set (CMAKE_CXX_STANDARD 17)
SET (CMAKE_CXX_FLAGS                "-Wall -static -std=c++17 -lm -lc")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")

SET (CMAKE_AR      "/usr/bin/llvm-ar")
SET (CMAKE_LINKER  "/usr/bin/llvm-ld")
SET (CMAKE_NM      "/usr/bin/llvm-nm")
SET (CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
SET (CMAKE_RANLIB  "/usr/bin/llvm-ranlib")
	
set(CMAKE_DEBUG_POSTFIX "_D")
set(CMAKE_RELEASE_POSTFIX "_R")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/out/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/out/lib)

set(CMAKE_LIBRARY_PATH ${LIBRARY_OUTPUT_PATH};${CMAKE_CURRENT_LIST_DIR}/lib)


project(U1Server)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/AllObject allobject_source_list)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src source_list)
#message(STATUS "source_list: ${source_list}")

#add_library(${PROJECT_NAME} STATIC ${source_list})
IF (CMAKE_BUILD_TYPE MATCHES Debug)
	set(CMAKE_EXECUTABLE_SUFFIX "_D")
ELSE()
	set(CMAKE_EXECUTABLE_SUFFIX "_R")
ENDIF()

add_executable(${PROJECT_NAME} ${source_list} ${allobject_source_list})
