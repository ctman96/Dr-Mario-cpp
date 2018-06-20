include(${PROJECT_SOURCE_DIR}/cmake/Modules/googletest.cmake)

fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake/Modules
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()

set(
        SOURCE_FILES
        main.cpp

        exampleTest.cpp

        ../main/Board/GameUtils.cpp ../main/Board/GameUtils.h
        GameUtilsTest.cpp)

add_executable(
        unit_tests
        ${SOURCE_FILES}
)

target_link_libraries(
        unit_tests
        gtest_main
        ${SDL2_LIBRARY}
)

add_test(
        NAME
            unit
        COMMAND
            ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)