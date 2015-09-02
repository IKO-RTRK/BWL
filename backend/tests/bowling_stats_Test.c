#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"

TEST_GROUP(bowling_stats);

TEST_SETUP(bowling_stats)
{
}

TEST_TEAR_DOWN(bowling_stats)
{
}

TEST_GROUP_RUNNER(bowling_stats)
{
	RUN_TEST_CASE(bowling_stats, SetScoreForOneThrow);
}

//Prvi test
TEST(bowling_stats, SetScoreForOneThrow)
{
	srusi(5);
	TEST_ASSERT_MESSAGE( skor()[0] == 5 , "Prvi test pao");
	printf("\n\nTEST 1 PROSAO");
}

