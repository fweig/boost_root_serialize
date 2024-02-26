cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)
cmake_policy(VERSION 3.14...3.23)

project(boost_root_serialize LANGUAGES CXX)

# set some sane defaults
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type" FORCE)

# TODO: switch to jan24 release, once it's available on fles
set(FAIRSOFT_PATH "/scratch/cbmsoft/fairsoft_nov22p1_root6/installation" CACHE PATH "Path to FairSoft installation")
list(PREPEND CMAKE_PREFIX_PATH ${FAIRSOFT_PATH})

find_package(Boost REQUIRED COMPONENTS serialization program_options)
find_package(ROOT REQUIRED COMPONENTS RIO Core Tree)

set(HEADERS
  Digi.h
)

set(SRCS
  main.cxx
)

add_executable(boost_root_serialize ${SRCS})
target_include_directories(boost_root_serialize PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) # for the generated dictionary
ROOT_GENERATE_DICTIONARY(boost_root_serialize_dict ${HEADERS} LINKDEF LinkDef.h MODULE boost_root_serialize)
target_link_libraries(boost_root_serialize PRIVATE
  Boost::serialization
  Boost::program_options
  ROOT::RIO
  ROOT::Core
  ROOT::Tree
)
