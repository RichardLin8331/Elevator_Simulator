#include <gtest/gtest.h>
#include "lib.h"

class ElevatorTest : public ::testing::Test {
protected:
    Elevator e;
};


TEST_F(ElevatorTest, MoveUpward) {
    int final_floor = e.move(5);
    EXPECT_EQ(final_floor, 5);
}

TEST_F(ElevatorTest, MoveDownward) {
    e.move(6);
    int final_floor = e.move(3);
    EXPECT_EQ(final_floor, 3);
}
