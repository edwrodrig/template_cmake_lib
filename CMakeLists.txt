# Define library. Only source files here!
project(libtpl_project_tpl VERSION 0.1 LANGUAGES CXX)

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include(GNUInstallDirs)

add_library(libtpl_project_tpl
    src/Element.cpp
    src/Util.cpp)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(libtpl_project_tpl PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

# If we have compiler requirements for this library, list them
# here
target_compile_features(libtpl_project_tpl
        PUBLIC cxx_auto_type
        PRIVATE cxx_variadic_templates)

# Depend on a library that we defined in the top-level file
#include(${wxWidgets_USE_FILE})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#target_link_libraries(libtpl_project_tpl PRIVATE ${wxWidgets_LIBRARIES})
#target_link_libraries(libtpl_project_tpl PRIVATE nlohmann_json::nlohmann_json)


# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS libtpl_project_tpl EXPORT Libtpl_project_uc_first_tplConfig
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
#install(EXPORT libtpl_project_tpl DESTINATION share/Libtpl_project_uc_first_tpl/cmake)

# This makes the project importable from the build directory
#export(TARGETS libtpl_project_tpl FILE Libtpl_project_uc_first_tpl.cmake)

# Every library has unit tests, of course
add_executable(testtpl_project_tpl
        tests/ElementTest.cpp
        tests/UtilTest.cpp)

target_link_libraries(testtpl_project_tpl
        libtpl_project_tpl
        gtest_main)

enable_testing()
add_test(testtpl_project_tpl testtpl_project_tpl)



