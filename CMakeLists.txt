# project(cbs)

# cmake_minimum_required (VERSION 2.6)

# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -Wall")
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# include_directories("inc")
# file(GLOB SOURCES "src/cbs/*.cpp")
# file(GLOB STP_SOURCES "src/stp/*.cpp")

# # Find Boost
# find_package( Boost 1.49.0 REQUIRED COMPONENTS program_options system filesystem)
# include_directories( ${Boost_INCLUDE_DIRS} )

# add_library( MAPF_PC_LIB STATIC ${SOURCES} ${STP_SOURCES} )


# add_executable(cbs  "src/cbs.cpp" )
# add_executable(pbs  "src/pbs.cpp" )
# add_executable(task_assignment  "src/task_assignment.cpp" )

# set_property(
#   TARGET cbs
#   PROPERTY COMPILE_DEFINITIONS IL_STD
#   )

# set_property(
#   TARGET pbs
#   PROPERTY COMPILE_DEFINITIONS IL_STD
#   )

# set_property(
#   TARGET task_assignment
#   PROPERTY COMPILE_DEFINITIONS IL_STD
#   )

# target_link_libraries(cbs MAPF_PC_LIB)
# target_link_libraries(pbs MAPF_PC_LIB)
# target_link_libraries(task_assignment MAPF_PC_LIB)

# target_link_libraries(cbs ${Boost_LIBRARIES})
# target_link_libraries(pbs ${Boost_LIBRARIES})
# target_link_libraries(task_assignment ${Boost_LIBRARIES})

cmake_minimum_required (VERSION 2.6)

project(mgpbs)
set(CMAKE_CXX_STANDARD 20)
set(PYBIND11_PYTHON_VERSION 3.12)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")

find_package(pybind11 REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories("inc")
include_directories("src")
file(GLOB SOURCES "src/*.cpp")

ADD_LIBRARY(LibsModule
    inc/common.h
    inc/Conflict.h
    inc/ConstraintTable.h
    inc/ConstraintPropagation.h
    inc/ConstraintTable.h
    inc/CorridorReasoning.h
    inc/IncrementalPairwiseMutexPropagation.hpp
    inc/MDD.h
    inc/MultiLabelSpaceTimeAStar.h
    inc/MutexReasoning.h
    inc/PBS.h
    inc/Instance.h
    inc/CBS.h
    inc/CBSNode.h
    inc/CBSHeuristic.h
    inc/PBS.h
    inc/RectangleReasoning.h
    inc/ReservationTable.h
    inc/SingleAgentSolver.h
    inc/SpaceTimeAStar.h
    inc/STPHelper.h
    inc/TaskAssignment.h

    src/cbs/common.cpp
    src/cbs/Conflict.cpp
    src/cbs/ConstraintTable.cpp
    src/cbs/Instance.cpp
    src/cbs/CBS.cpp
    src/cbs/CBSHeuristic.cpp
    src/cbs/CBSNode.cpp
    src/cbs/CGHeuristic.cpp
    src/cbs/ConstraintPropagation.cpp
    src/cbs/ConstraintTable.cpp
    src/cbs/CorridorReasoning.cpp
    src/cbs/DGHeuristic.cpp
    src/cbs/ILPforWMVC.cpp
    src/cbs/IncrementalPairwiseMutexPropagation.cpp
    src/cbs/MDD.cpp
    src/cbs/MutexReasoning.cpp
    src/cbs/PBS_naive.cpp
    src/cbs/PBS.cpp
    src/cbs/RectangleReasoning.cpp
    src/cbs/ReservationTable.cpp
    src/cbs/SingleAgentSolver.cpp
    src/cbs/SpaceTimeAStar.cpp
    src/cbs/STPHelper.cpp
    src/cbs/TaskAssignment.cpp
    src/cbs/WDGHeuristic.cpp
)

pybind11_add_module(${PROJECT_NAME} src/pywrap.cpp)
target_link_libraries(${PROJECT_NAME} LibsModule)

target_compile_definitions(${PROJECT_NAME} PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
target_include_directories(${PROJECT_NAME} PRIVATE ${PYBIND11_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

# Find Boost
find_package(Boost REQUIRED COMPONENTS program_options system filesystem)
include_directories( ${Boost_INCLUDE_DIRS} )
target_link_libraries(mgpbs ${Boost_LIBRARIES})
