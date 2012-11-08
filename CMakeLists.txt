# CMakeLists Pour creer une library (.a ou .so)
#NOTE
# DIR TREE
# Library
#	/libname/
# 		/Include/
#			headers.h
#		/src/
#			sources.cpp
#		CMakeLists.txt
#	/Lib/
#		lib_libname.so         <- This is the generated file
#	Point d' execution de cmake libname et make libname

cmake_minimum_required(VERSION 2.6)
project(copy_playlist_backend)
set(LIBRARY_OUTPUT_PATH lib)
find_package(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

SET (copy_playlist_backend_SRCS /home/max/Documents/C/Library/copy_playlist_backend/src/copy_playlist_backend.cpp)
SET (copy_playlist_backend_HEADERS /home/max/Documents/C/Library/copy_playlist_backend/include/copy_playlist_backend.h)

MESSAGE( STATUS "sources:         " ${copy_playlist_backend_SRCS} )
MESSAGE( STATUS "headers:         " ${copy_playlist_backend_HEADERS} )

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include)

file(GLOB_RECURSE source_files ${copy_playlist_backend_SRCS})

qt4_wrap_cpp(copy_playlist_backend_HEADERS_MOC ${copy_playlist_backend_HEADERS})
qt4_automoc(${copy_playlist_backend_SRCS}${copy_playlist_backend_HEADERS_MOC})


add_library(copy_playlist_backend SHARED ${source_files} )


