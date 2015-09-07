#include "../unity/unity_fixture.h"
#include "../src/users.h"

TEST_GROUP(UsersTest);

TEST_GROUP_RUNNER(UsersTest)
{
	RUN_TEST_CASE(UsersTest, TestValidNumberOfLanes);
	RUN_TEST_CASE(UsersTest, TestNonvalidNumberOfLanes);
	RUN_TEST_CASE(UsersTest, TestNonvalidNumberOfPlayers);
	RUN_TEST_CASE(UsersTest, TestValidNumberOfPlayers);
}

TEST_SETUP(UsersTest)
{
	initialise();
}

TEST_TEAR_DOWN(UsersTest)
{
	
}

TEST(UsersTest, TestValidNumberOfLanes)
{
	TEST_ASSERT_EQUAL(0, numberOfLanesValidation(1));
}

TEST(UsersTest, TestNonvalidNumberOfLanes)
{
	TEST_ASSERT_EQUAL(1, numberOfLanesValidation(5));
}

TEST(UsersTest, TestNonvalidNumberOfPlayers)
{
	TEST_ASSERT_EQUAL(1, numberOfPlayersValidation(-6));
}

TEST(UsersTest, TestValidNumberOfPlayers)
{
	TEST_ASSERT_EQUAL(0, numberOfPlayersValidation(3));
}