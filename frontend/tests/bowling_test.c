#include "../unity/unity_fixture.h"
#include "../src/bowling_gui.h"

static int contains(int* arrayExpected,int* arrayReturned,int expectedLength,int returnedLength)
{
  int i,j;
  
  for (i = 0; i < returnedLength; i++)
  {
    for (j = 0; j < expectedLength; j++)
    {
      if (arrayReturned[i] == arrayExpected[j])
      {
	j = expectedLength;  //vidjeti break ili continue pa zamjeniti
      }
      else if (j == (expectedLength - 1))
	return 1;
      else
      {
	
      }
    }
  }
  return 0;
}

TEST_GROUP(BowlingTest);

TEST_GROUP_RUNNER(BowlingTest)
{
  
  RUN_TEST_CASE(BowlingTest, TestZeroKnockDown);
  RUN_TEST_CASE(BowlingTest, TestMax3PinsDown);
  RUN_TEST_CASE(BowlingTest, TestMax5PinsDown);
  RUN_TEST_CASE(BowlingTest, TestMax7PinsDown);
  RUN_TEST_CASE(BowlingTest, TestMax10PinsDown);
  RUN_TEST_CASE(BowlingTest, Test2PinsLeft);
  RUN_TEST_CASE(BowlingTest, Test4PinsLeft);
  RUN_TEST_CASE(BowlingTest, Test6PinsLeft);
  RUN_TEST_CASE(BowlingTest, Test8PinsLeft); 
 
 // RUN_TEST_CASE(BowlingTest, TestPosition5Throw);
  //RUN_TEST_CASE(BowlingTest, TestPosition11Throw);
  //RUN_TEST_CASE(BowlingTest, TestPosition6Throw);
  //RUN_TEST_CASE(BowlingTest, TestPosition10Throw);
  RUN_TEST_CASE(BowlingTest, TestPosition8Throw);

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

TEST(BowlingTest, Test2PinsLeft)
{
  TEST_ASSERT_TRUE(knockDownPins(11,2) <= 2);
}

TEST(BowlingTest, Test4PinsLeft)
{
  TEST_ASSERT_TRUE(knockDownPins(6,4) <= 4);
}

TEST(BowlingTest, Test6PinsLeft)
{
  TEST_ASSERT_TRUE(knockDownPins(7,6) <= 6);
}

TEST(BowlingTest, Test8PinsLeft)
{
  TEST_ASSERT_TRUE(knockDownPins(8,8) <= 8);
}

TEST(BowlingTest, TestPosition5Throw)
{
  int k = knockDownPins(5,10);
  int fallen[k];
  pinsDown(k,fallen,5);
  
  int expected[3] = {4,7,8};
  TEST_ASSERT_TRUE(contains(expected,fallen,3,k) == 0);
}

TEST(BowlingTest, TestPosition11Throw)
{
  int k = knockDownPins(11,10);
  int fallen[k];
  pinsDown(k,fallen,11);
  
  int expected[3] = {6,9,10};
  TEST_ASSERT_TRUE(contains(expected,fallen,3,k) == 0);
}

TEST(BowlingTest, TestPosition6Throw)
{
  int k = knockDownPins(6,10);
  int fallen[k];
  pinsDown(k,fallen,6);
  
  int expected[5] = {2,4,5,7,8};
  TEST_ASSERT_TRUE(contains(expected,fallen,5,k) == 0);
}

TEST(BowlingTest, TestPosition10Throw)
{
  int k = knockDownPins(10,10);
  int fallen[k];
  pinsDown(k,fallen,10);
  
  int expected[5] = {3,5,6,9,10};
  TEST_ASSERT_TRUE(contains(expected,fallen,5,k) == 0);
}

TEST(BowlingTest, TestPosition7Throw)
{
  int k = knockDownPins(7,10);
  int fallen[k];
  pinsDown(k,fallen,7);
  
  int expected[7] = {1,2,3,4,5,7,8};
  TEST_ASSERT_TRUE(contains(expected,fallen,7,k) == 0);
}

TEST(BowlingTest, TestPosition9Throw)
{
  int k = knockDownPins(9,10);
  int fallen[k];
  pinsDown(k,fallen,9);
  
  int expected[7] = {1,2,3,5,6,9,10};
  TEST_ASSERT_TRUE(contains(expected,fallen,7,k) == 0);
}


TEST(BowlingTest, TestPosition8Throw)
{
  int k = knockDownPins(8,10);
  int fallen[k];
  pinsDown(k,fallen,8);
  
  int expected[10] = {1,2,3,4,5,6,7,8,9,10};
  TEST_ASSERT_TRUE(contains(expected,fallen,10,k) == 0);
}