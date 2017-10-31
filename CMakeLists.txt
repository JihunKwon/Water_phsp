CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)

PROJECT(Wphsp)

FIND_PACKAGE(Geant4 REQUIRED ui_all vis_all)
IF(NOT Geant4_FOUND)
    MESSAGE(FATAL_ERROR "Geant4 not found!")
ENDIF(NOT Geant4_FOUND)

INCLUDE(${Geant4_USE_FILE})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
#  ${CMAKE_CURRENT_BINARY_DIR})

FILE(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
FILE(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

ADD_EXECUTABLE(Wphsp Wphsp.cc ${sources} ${headers})
TARGET_LINK_LIBRARIES(Wphsp ${Geant4_LIBRARIES})

set(Wphsp_SCRIPTS
    init_vis.mac
    220kVp.txt
    mesh.mac
)

foreach(_script ${Wphsp_SCRIPTS})
    configure_file(
        ${PROJECT_SOURCE_DIR}/${_script}
        ${PROJECT_BINARY_DIR}/${_script}
        COPYONLY)
endforeach()




