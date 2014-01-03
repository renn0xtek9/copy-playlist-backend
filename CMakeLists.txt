CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ENABLE_LANGUAGE(CXX)
SET (PROJECT_NAME "copy-playlist-backend" CACHE STRING "Name of the project")
project(${PROJECT_NAME})
#Defines the version############################################################################################
SET (VERSION_x 1) # The MAJOR version number.
SET (VERSION_y 0) # The MINOR version number
SET (VERSION_z 0) 
SET(CMAKE_INSTALL_PREFIX "/usr" CACHE INTERNAL "Prefix prepended to install directories" )
SET(INSTALL "NO" CACHE STRING "If yes or no we should install the taret, default is no") 			#to be defined with cmake .. -DINSTALL:STRING=YES to install in /usr/lib
# IF(${INSTALL} STREQUAL "NO")
# SET(LIBRARY_OUTPUT_PATH ./../../lib)	##This is where I put the .so file for my own, local devel envmt (only if we selec no)
# ENDIF(${INSTALL} STREQUAL "NO")
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include)

SET (PROJECT_SRCS ./src/copy_playlist_backend.cpp)
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
  VERSION ${VERSION_x}.${VERSION_y}.${VERSION_z}
  SOVERSION ${VERSION_x}.${VERSION_y}.${VERSION_z})
#If we want to install##########################################################################################
# IF(${INSTALL} STREQUAL "YES")
INSTALL(TARGETS ${PROJECT_NAME}
        DESTINATION "lib"
        )
INSTALL(FILES ${PROJECT_HEADERS}
        DESTINATION "include"
        )
# ENDIF(${INSTALL} STREQUAL "YES")

########### Add uninstall target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake") 

        
