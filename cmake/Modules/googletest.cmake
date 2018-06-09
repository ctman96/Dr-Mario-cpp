
# Download and unpack googletest at configure time
#configure_file(google googletest-download/CMakeLists.txt)
macro(fetch_googletest _download_module_path _download_root)


    set(GOOGLETEST_DOWNLOAD_ROOT ${_download_root})
    configure_file(
            ${_download_module_path}/googletest-download.cmake
            ${_download_root}/CMakeLists.txt
            @ONLY
    )
    unset(GOOGLETEST_DOWNLOAD_ROOT)

    execute_process(
            COMMAND
                ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
            RESULT_VARIABLE
                result
            WORKING_DIRECTORY
                ${_download_root}
    )
    if(result)
        message(FATAL_ERROR CMake step for googletest failed: ${result})
    endif()

    execute_process(
            COMMAND
                ${CMAKE_COMMAND} --build .
            RESULT_VARIABLE
                result
            WORKING_DIRECTORY
                ${_download_root}
    )
    if(result)
        message(FATAL_ERROR Build step for googletest failed: ${result})
    endif()

    # Add googletest directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(
            ${_download_root}/googletest-src
            ${_download_root}/googletest-build
            EXCLUDE_FROM_ALL
    )

    # The gtest/gtest_main targets carry header search path
    # dependencies automatically when using CMake 2.8.11 or
    # later. Otherwise we have to add them here ourselves.
    if (CMAKE_VERSION VERSION_LESS 2.8.11)
        include_directories(${gtest_SOURCE_DIR}/include)
    endif()
endmacro()