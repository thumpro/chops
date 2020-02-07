cmake_minimum_required(VERSION 3.12)
project(chops VERSION 1.0.0 LANGUAGES CXX)

if(MSVC)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(chops INTERFACE)
add_library(chops::chops ALIAS chops)

target_compile_features(chops INTERFACE cxx_std_17)
target_include_directories(chops INTERFACE
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

if(chops_BUILD_TESTS)
  add_subdirectory(tests)
endif()

configure_package_config_file(chopsConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/chopsConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/chops)

install(TARGETS chops EXPORT chopsTargets)
install(EXPORT chopsTargets
        FILE chopsTargets.cmake
        NAMESPACE chops::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/chops)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/chopsConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/chops)
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/chops
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        USE_SOURCE_PERMISSIONS
        PATTERN "*.hpp")