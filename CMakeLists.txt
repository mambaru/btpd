cmake_minimum_required(VERSION 3.1)

project(btpd)

include(cmake/ci.cmake)
ogenc_warning(-Wunused-const-variable "" OFF)
set(ENV{ENABLE_STAT} ON)
wci_submodule(NAME wfcroot SUPERMODULE)
wci_submodule(NAME wfc_btp)

add_subdirectory(daemon)
add_subdirectory(utils)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
  if ( EXISTS ${CMAKE_SOURCE_DIR}/configurations)
    add_subdirectory(configurations)
  endif()
endif()
