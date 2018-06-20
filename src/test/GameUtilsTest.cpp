//! Handles tests for the GameUtils namespace
/*!
 * @author: Cody Newman
 *
 * Created on: 20/06/2018
 */

#include <gtest/gtest.h>
#include <set>
#include "../main/Board/GameUtils.h"

using namespace std;
using namespace GameUtils;

class GameUtilsTest : public ::testing::Test {
protected:
    //! Sets up the test
    GameUtilsTest() {

    }

    //! Cleans up after the test
    ~GameUtilsTest() {

    }

    set<Virus> viruses;
    set<DrawableObject*> blocks;
};

TEST_F(GameUtilsTest, GameUtilsTest_GenerateLevel_Test){
    viruses = generateLevel(0);
    EXPECT_FALSE(viruses.empty());
}

//TODO
