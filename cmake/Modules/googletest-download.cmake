cmake_minimum_required(VERSION 3.10)

project(googletest-download NONE)

MESSAGE("Adding googletest git")

include(ExternalProject)

ExternalProject_Add(
        googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "@GOOGLETEST_DOWNLOAD_ROOT@/googletest-src"
        BINARY_DIR        "@GOOGLETEST_DOWNLOAD_ROOT@/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
)