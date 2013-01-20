CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(copy_playlist_backend)

# The version number.
SET (copy_playlist_backend_VERSION_x 0)
SET (copy_playlist_backend_VERSION_y 0)
SET (copy_playlist_backend_VERSION_z 1)


SET(LIBRARY_OUTPUT_PATH lib)
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include)

SET (copy_playlist_backend_SRCS src/copy_playlist_backend.cpp)
SET (copy_playlist_backend_HEADERS include/copy_playlist_backend.h)

MESSAGE( STATUS "sources:         " ${copy_playlist_backend_SRCS} )
MESSAGE( STATUS "headers:         " ${copy_playlist_backend_HEADERS} )

QT4_WRAP_CPP(copy_playlist_backend_HEADERS_MOC ${copy_playlist_backend_HEADERS}) #in there you put the headers and ONLY the headers

ADD_LIBRARY(copy_playlist_backend SHARED ${copy_playlist_backend_SRCS} ${copy_playlist_backend_HEADERS_MOC} )
TARGET_LINK_LIBRARIES(copy_playlist_backend ${QT_LIBRARIES})

SET_TARGET_PROPERTIES(
    copy_playlist_backend
    PROPERTIES
    VERSION ${copy_playlist_backend_VERSION_x}.${copy_playlist_backend_VERSION_y}.${copy_playlist_backend_VERSION_z}
    SOVERSION ${copy_playlist_backend_VERSION_x}.${copy_playlist_backend_VERSION_y}.${copy_playlist_backend_VERSION_z})


INSTALL(TARGETS copy_playlist_backend
        DESTINATION "lib"
        )
INSTALL(FILES include/copy_playlist_backend.h
        DESTINATION "include"
        )


