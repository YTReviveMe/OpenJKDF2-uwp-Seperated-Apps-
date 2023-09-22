# CMake toolchain file
set(ANDROID_ABI arm64-v8a)
set(ANDROID_PLATFORM android-31)
set(ANDROID_NDK $ENV{ANDROID_NDK_HOME})

include("$ENV{ANDROID_NDK_HOME}/build/cmake/android.toolchain.cmake")

#set(CMAKE_SYSTEM_NAME Android)
#set(CMAKE_SYSTEM_VERSION 1)
#set(CMAKE_SYSTEM_PROCESSOR x86)

#set(CMAKE_C_COMPILER   "aarch64-linux-android31-clang" CACHE STRING "C compiler" FORCE)
#set(CMAKE_CXX_COMPILER "aarch64-linux-android31-clang++" CACHE STRING "C++ compiler" FORCE)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(PLAT_ANDROID_ARM64 TRUE)
set(ANDROID TRUE)

message( STATUS "Android AArch64/ARMv8a toolchain invoked" )
