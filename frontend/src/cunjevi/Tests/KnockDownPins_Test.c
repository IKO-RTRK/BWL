#include "../unity/unity_fixture.h"

TEST_GROUP(KnockDownPins);

TEST_SETUP(KnockDownPins)
{
}

TEST_TEAR_DOWN(KnockDownPins)
{
}

TEST_GROUP_RUNNER(KnockDownPins)
{
	RUN_TEST_CASE(KnockDownPins, AllPinsDownOnHit);
}

TEST(KnockDownPins, AllPinsDownOnHit)
{
	uint KnockedPins = 0;
	TEST_ASSERT_EQUAL(10, KnockedPins);
}

