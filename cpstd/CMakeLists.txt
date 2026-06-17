cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cpstd VERSION 1.0.0 LANGUAGES C)

# Too lazy but not recommended at all 
file(GLOB CPSTD_SOURCES "*.c")
file(GLOB CPSTD_HEADERS "*.h")

add_library(cpstd STATIC ${CPSTD_SOURCES} ${CPSTD_HEADERS})
target_include_directories(cpstd PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
set_target_properties(cpstd PROPERTIES
    PUBLIC_HEADER "${CPSTD_HEADERS}"
)

install(TARGETS cpstd
    EXPORT cpstdTargets
    ARCHIVE DESTINATION lib          
    LIBRARY DESTINATION lib          
    PUBLIC_HEADER DESTINATION include/cpstd 
)

install(EXPORT cpstdTargets
    FILE cpstdTargets.cmake
    NAMESPACE cpstd::
    DESTINATION lib/cmake/cpstd
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cpstdConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cpstdConfig.cmake"
    INSTALL_DESTINATION lib/cmake/cpstd
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cpstdConfig.cmake"
    DESTINATION lib/cmake/cpstd
)

configure_file(cpstd.pc.in cpstd.pc @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cpstd.pc"
    DESTINATION lib/pkgconfig
)
