//! Runs GoogleTest unit tests
/*!
 * @author: Cody Newman
 *
 * Created on: 20/06/2018
 */

#include "gtest/gtest.h"

int main(int argv, char** args) {
    testing::InitGoogleTest(&argv, args);
    return RUN_ALL_TESTS();
}