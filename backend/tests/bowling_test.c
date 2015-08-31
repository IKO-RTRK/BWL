#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"

TEST_GROUP(BowlingTest);

TEST_GROUP_RUNNER(BowlingTest)
{
	RUN_TEST_CASE(BowlingTest, TestAllZeroes);
	RUN_TEST_CASE(BowlingTest, TestAllOnes);	

}

TEST_SETUP(BowlingTest)
{
	inicijalizacija();
}

TEST_TEAR_DOWN(BowlingTest)
{
}

// Prvi test - promasena sva bacanja
TEST(BowlingTest, TestAllZeroes)
{
	srusi(0);
	TEST_ASSERT_EQUAL(0, skor());
}

// Drugi test - srusen jedan cunj u svim bacanjima
TEST(BowlingTest, TestAllOnes)
{
	srusi(1);
	TEST_ASSERT_EQUAL(21, skor());
}
