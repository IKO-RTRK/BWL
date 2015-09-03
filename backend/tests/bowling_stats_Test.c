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
	RUN_TEST_CASE(bowling_stats, SetScoresForOneThrowOnBoundaries);
	RUN_TEST_CASE(bowling_stats, SetNewGame);
	RUN_TEST_CASE(bowling_stats, SetScoresForMultipleThrows_WithoutRules);
}

//Prvi test
TEST(bowling_stats, SetScoreForOneThrow)
{
	srusi(5);
	TEST_ASSERT_MESSAGE( throws()[0] == 5 , "\n***Prvi test pao\n");
	printf("\n\n***TEST 1 PROSAO\n");
}
//Drugi test
TEST(bowling_stats, SetScoresForOneThrowOnBoundaries)
{
	srusi(511);
	TEST_ASSERT_MESSAGE( throws()[1] == 0 , "\n***Drugi test pao\n");
	srusi(-1);
	TEST_ASSERT_MESSAGE( throws()[2] == 0 , "\n***Drugi test pao\n");
	printf("\n\n***TEST 2 PROSAO\n");
}
//Treci test
TEST(bowling_stats, SetNewGame)
{
	srusi(511);
	TEST_ASSERT_MESSAGE( throws()[1] == 0 , "\n***Treci test pao\n");
	srusi(-1);
	TEST_ASSERT_MESSAGE( throws()[2] == 0 , "\n***Treci test pao\n");
	newGame();
	int i;
	for(i = 0; i < 21; i++)
	{
	  TEST_ASSERT_MESSAGE( throws()[i] == 0 , "\n***Treci test pao\n");
	}
	newGame();
	srusi(6);
	TEST_ASSERT_MESSAGE( throws()[0] == 6 , "\n***Treci test pao\n");
	printf("\n\n***TEST 3 PROSAO\n");
}
//Cetvrti test
TEST(bowling_stats, SetScoresForMultipleThrows_WithoutRules)
{
	newGame();
	int i;
	for (i = 0; i < 50 ; i++)
	{
	  srusi(i % 11);
	  TEST_ASSERT_MESSAGE( throws()[i % 20] == i % 11 , "***Cetvrti test pao");
	}
	
	printf("\n\n***TEST 4 PROSAO \n");
}