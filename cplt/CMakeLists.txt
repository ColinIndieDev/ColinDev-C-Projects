cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cplt VERSION 1.0.0 LANGUAGES C)

set(CPLT_HEADER
    include/cplt/cplt.h
)

add_library(cplt STATIC 
    ${CPLT_HEADER}
    src/cplt.c
)

install(FILES ${CPLT_HEADER} DESTINATION include/cplt)

target_include_directories(cplt PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
set_target_properties(cplt PROPERTIES
    PUBLIC_HEADER "${CPLT_HEADER}"
)

install(TARGETS cplt 
    EXPORT cpltTargets
    ARCHIVE DESTINATION lib          
    LIBRARY DESTINATION lib          
    PUBLIC_HEADER DESTINATION include/cplt
)

install(EXPORT cpltTargets
    FILE cpltTargets.cmake
    NAMESPACE cplt::
    DESTINATION lib/cmake/cplt
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cpltConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cpltConfig.cmake"
    INSTALL_DESTINATION lib/cmake/cplt
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cpltConfig.cmake"
    DESTINATION lib/cmake/cplt
)

configure_file(cplt.pc.in cplt.pc @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cplt.pc"
    DESTINATION lib/pkgconfig
)
