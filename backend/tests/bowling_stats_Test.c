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

TEST(bowling_stats, SetScoreForOneThrow)
{
	//uint16_t virtualLeds = 0xffff;
	//LedDriver_Create(&virtualLeds);
	//TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

