CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ENABLE_LANGUAGE(CXX)
SET (PROJECT_NAME "copy_playlist_backend" CACHE STRING "Name of the project")
project(${PROJECT_NAME})
#Defines the version############################################################################################
SET (VERSION_x 0) # The MAJOR version number.
SET (VERSION_y 0) # The MINOR version number
SET (VERSION_z 0) 
SET(INSTALL "NO" CACHE STRING "If yes or no we should install the taret, default is no") 			#to be defined with cmake .. -DBUILD:STRING=YES to install in /usr/lib
SET(LIBRARY_OUTPUT_PATH ./../../lib)	##This is where I put the .so file for my own, local devel environement
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include)

SET (PROJECT_SRCS /src/copy_playlist_backend.cpp)
SET (PROJECT_HEADERS ./include/copy_playlist_backend.h)

MESSAGE( STATUS "sources:         " ${PROJECT_SRCS} )
MESSAGE( STATUS "headers:         " ${PROJECT_HEADERS} )

qt4_wrap_cpp(PROJECT_HEADERS_MOC ${PROJECT_HEADERS})   		#qt4 moc only if lib relies on qt4 in there you put the headers and ONLY the headers
#Create the.so file#############################################################################################
ADD_LIBRARY(${PROJECT_NAME} SHARED ${PROJECT_SRCS} ${PROJECT_HEADERS_MOC})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${QT_LIBRARIES})
SET_TARGET_PROPERTIES(
  ${PROJECT_NAME}
  PROPERTIES
  VERSION ${VERSION_x}.${VERSION_y}.${VERSION_z})
#If we want to install##########################################################################################
IF(${INSTALL} STREQUAL "YES")
INSTALL(TARGETS ${PROJECT_NAME}
        DESTINATION "lib"
        )
INSTALL(FILES ${PROJECT_HEADERS}
        DESTINATION "../include"
        )
ENDIF(${INSTALL} STREQUAL "YES")

        