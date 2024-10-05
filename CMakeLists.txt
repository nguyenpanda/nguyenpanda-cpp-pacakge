if (NOT WIN32)
    # ASCII escape sequence for terminal color output
    #@formatter:off
    string(ASCII 27 Esc)
    set(reset   "${Esc}[0m")    # Reset to default color
    set(red     "${Esc}[1;91m") # Red color
    set(green   "${Esc}[1;92m") # Green color
    set(yellow  "${Esc}[1;93m") # Yellow color
    set(blue    "${Esc}[1;94m") # Blue color
    set(magenta "${Esc}[1;95m") # Magenta color
    set(cyan    "${Esc}[1;96m") # Cyan color
    set(white   "${Esc}[1;97m") # White color
    #@formatter:on
endif ()


########### Project Metadata ###########
CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(nguyenpanda_cpp
        VERSION 0.0.0
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/nguyenpanda?tab=repositories"
        DESCRIPTION "nguyenpanda in cpp"
)
SET(CMAKE_CXX_STANDARD 17)
SET(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
SET(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(INCLUDE_DIR)
MESSAGE("${green}Complete section 'CMakeLists meta data'${reset}")


########### Library Setup ###########
ADD_LIBRARY(nguyenpanda SHARED
        ${SRC_DIR}/nguyenpanda.cpp
        ${SRC_DIR}/swan/color.cpp
)
TARGET_INCLUDE_DIRECTORIES(nguyenpanda
        PUBLIC
        $<BUILD_INTERFACE:${INCLUDE_DIR}>    # During build
        $<INSTALL_INTERFACE:include>         # Post-install
)
MESSAGE("${green}Complete section '`nguyenpanda.h` library'${reset}")


########### Installation ###########
INSTALL(TARGETS nguyenpanda
        EXPORT nguyenpandaTargets
        LIBRARY DESTINATION share            # Install shared libraries
        ARCHIVE DESTINATION share            # Install static libraries
        RUNTIME DESTINATION bin              # Install executables
        INCLUDES DESTINATION include         # Install headers
)
INSTALL(DIRECTORY ${INCLUDE_DIR}/ DESTINATION include)
INSTALL(EXPORT nguyenpandaTargets
        FILE nguyenpandaTargets.cmake
        DESTINATION share/cmake/nguyenpanda
)


########### Package Configuration ###########
INCLUDE(CMakePackageConfigHelpers)
WRITE_BASIC_PACKAGE_VERSION_FILE(
        "${CMAKE_CURRENT_BINARY_DIR}/nguyenpandaConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)
CONFIGURE_PACKAGE_CONFIG_FILE(
        "${CMAKE_SOURCE_DIR}/nguyenpandaConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/nguyenpandaConfig.cmake"
        INSTALL_DESTINATION share/cmake/nguyenpanda
)
INSTALL(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/nguyenpandaConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/nguyenpandaConfigVersion.cmake"
        DESTINATION share/cmake/nguyenpanda
)
MESSAGE("${green}Complete setup for `nguyenpandaConfig` and `nguyenpandaTargets`.")


########### Executable Setup ###########
SET(MAIN_EXE "main")
ADD_EXECUTABLE(MAIN_EXE
        main.cpp
        ${INCLUDE_DIR}/nguyenpanda.h
        ${INCLUDE_DIR}/swan/swan.h
        ${INCLUDE_DIR}/swan/color.h
)
TARGET_LINK_LIBRARIES(MAIN_EXE nguyenpanda)
MESSAGE("${green}Complete section 'Target execute named `${MAIN_EXE}`'${reset}")
