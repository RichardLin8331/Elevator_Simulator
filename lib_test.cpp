#include <gtest/gtest.h>
#include "lib.h"

class ElevatorTest : public ::testing::Test {
protected:
    Elevator e;
    channel sc;
};


TEST_F(ElevatorTest, MoveUpward) {
    int final_floor = e.move(2, 5, sc);
    EXPECT_EQ(final_floor, 5);
}

TEST_F(ElevatorTest, MoveDownward) {
    int final_floor = e.move(9,3, sc);
    EXPECT_EQ(final_floor, 3);
}
