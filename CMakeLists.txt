cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(TCNProduction)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(TCNSim TCNSim.cc ${sources} ${headers})
target_link_libraries(TCNSim ${Geant4_LIBRARIES})

add_custom_target(TCNProduction DEPENDS TCNSim)