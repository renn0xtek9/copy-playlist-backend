cmake_minimum_required(VERSION 2.6)
project(copy_playlist_backend)
set(LIBRARY_OUTPUT_PATH lib)
find_package(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include)

SET (copy_playlist_backend_SRCS src/copy_playlist_backend.cpp)
SET (copy_playlist_backend_HEADERS include/copy_playlist_backend.h)

MESSAGE( STATUS "sources:         " ${copy_playlist_backend_SRCS} )
MESSAGE( STATUS "headers:         " ${copy_playlist_backend_HEADERS} )

qt4_wrap_cpp(copy_playlist_backend_HEADERS_MOC ${copy_playlist_backend_HEADERS}) #in there you put the headers and ONLY the headers

add_library(copy_playlist_backend SHARED ${copy_playlist_backend_SRCS} ${copy_playlist_backend_HEADERS_MOC} )
target_link_libraries(copy_playlist_backend ${QT_LIBRARIES})



