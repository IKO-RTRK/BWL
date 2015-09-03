#include "../unity/unity_fixture.h"
#include "../src/bowling_gui.h"

TEST_GROUP(BowlingTest);

TEST_GROUP_RUNNER(BowlingTest)
{
  RUN_TEST_CASE(BowlingTest, TestZeroKnockDown);
  RUN_TEST_CASE(BowlingTest, TestMax3PinsDown);
  RUN_TEST_CASE(BowlingTest, TestMax5PinsDown);
  RUN_TEST_CASE(BowlingTest, TestMax7PinsDown);
  RUN_TEST_CASE(BowlingTest, TestMax10PinsDown);
}

TEST_SETUP(BowlingTest)
{
}

TEST_TEAR_DOWN(BowlingTest)
{
}

TEST(BowlingTest, TestZeroKnockDown)
{
  
  TEST_ASSERT_EQUAL_INT(0,knockDownPins(4,10));
}

TEST(BowlingTest, TestMax3PinsDown)
{
  TEST_ASSERT_TRUE(knockDownPins(5,10) <= 3);
}

TEST(BowlingTest, TestMax5PinsDown)
{
  TEST_ASSERT_TRUE(knockDownPins(10,10) <= 5);
}

TEST(BowlingTest, TestMax7PinsDown)
{
  TEST_ASSERT_TRUE(knockDownPins(9,10) <= 7);
}

TEST(BowlingTest, TestMax10PinsDown)
{
  TEST_ASSERT_TRUE(knockDownPins(8,10) <= 10);
}