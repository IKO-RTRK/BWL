#include "../unity/unity_fixture.h"
#include "../src/users.h"
#include <string.h>

TEST_GROUP(UsersTest);

TEST_GROUP_RUNNER(UsersTest)
{
	RUN_TEST_CASE(UsersTest, TestValidNumberOfLanes);
	RUN_TEST_CASE(UsersTest, TestNonvalidNumberOfLanes);
	RUN_TEST_CASE(UsersTest, TestNonvalidNumberOfPlayers);
	RUN_TEST_CASE(UsersTest, TestValidNumberOfPlayers);
	RUN_TEST_CASE(UsersTest, TestTwoNamesOnSameLane);
	RUN_TEST_CASE(UsersTest, TestDiffNamesOnLane);
	RUN_TEST_CASE(UsersTest, TestNoPlayersOnLane);
}

TEST_SETUP(UsersTest)
{
	//initialise();
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

TEST(UsersTest, TestTwoNamesOnSameLane)
{
	allLanes = (lane*) calloc(1, sizeof(lane));
	allLanes[0].laneId = 0;
	allLanes[0].numberOfPlayers = 3;
	allLanes[0].playersOnLane = (player*) calloc(allLanes[0].numberOfPlayers, sizeof(player));
	allLanes[0].playersOnLane[0].name = (char*) malloc (5 * sizeof(char));
	allLanes[0].playersOnLane[1].name = (char*) malloc (5 * sizeof(char));
	strcpy(allLanes[0].playersOnLane[0].name, "ime1");
	strcpy(allLanes[0].playersOnLane[1].name, "ime2");
	TEST_ASSERT_EQUAL(1, playerNameValidation(0,2,"ime2"));
	
	free(allLanes[0].playersOnLane[0].name);
	free(allLanes[0].playersOnLane[1].name);
	free(allLanes[0].playersOnLane);
	free(allLanes);
}

TEST(UsersTest, TestDiffNamesOnLane)
{
	allLanes = (lane*) calloc(1, sizeof(lane));
	allLanes[0].laneId = 0;
	allLanes[0].numberOfPlayers = 3;
	allLanes[0].playersOnLane = (player*) calloc(allLanes[0].numberOfPlayers, sizeof(player));
	allLanes[0].playersOnLane[0].name = (char*) malloc (5 * sizeof(char));
	allLanes[0].playersOnLane[1].name = (char*) malloc (5 * sizeof(char));
	strcpy(allLanes[0].playersOnLane[0].name, "ime1");
	strcpy(allLanes[0].playersOnLane[1].name, "ime2");
	TEST_ASSERT_EQUAL(0, playerNameValidation(0,2,"ime3"));
	
	free(allLanes[0].playersOnLane[0].name);
	free(allLanes[0].playersOnLane[1].name);
	free(allLanes[0].playersOnLane);
	free(allLanes);
}

TEST(UsersTest, TestNoPlayersOnLane)
{
	allLanes = (lane*) calloc(1, sizeof(lane));
	allLanes[0].laneId = 0;
	allLanes[0].numberOfPlayers = 3;
	allLanes[0].playersOnLane = (player*) calloc(allLanes[0].numberOfPlayers, sizeof(player));
	TEST_ASSERT_EQUAL(0, playerNameValidation(0,0,"ime3"));
	
	free(allLanes[0].playersOnLane);
	free(allLanes);
}