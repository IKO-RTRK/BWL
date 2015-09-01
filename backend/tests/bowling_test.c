#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"

TEST_GROUP(BowlingTest);

TEST_GROUP_RUNNER(BowlingTest)
{
	RUN_TEST_CASE(BowlingTest, TestAllZeroes);
	RUN_TEST_CASE(BowlingTest, TestAllOnes);	
	RUN_TEST_CASE(BowlingTest, TestSpare);	
	RUN_TEST_CASE(BowlingTest, TestStrike);
	RUN_TEST_CASE(BowlingTest, TwoStrikesInRow);
	RUN_TEST_CASE(BowlingTest, TenStrikesInRow);
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
	int i;
	for (i = 0; i < MAX_BROJ_BACANJA; i++)
	srusi(0);
	TEST_ASSERT_EQUAL(0, skor());
}

// Drugi test - srusen jedan cunj u svim bacanjima
TEST(BowlingTest, TestAllOnes)
{
	int i;
	for (i = 0; i < MAX_BROJ_BACANJA; i++)
	srusi(1);
	TEST_ASSERT_EQUAL(21, skor());
}

// Treci test - spare u drugom bacanju (5+5), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestSpare)
{
	int i;
	srusi(5);
	srusi(5);
	for (i = 0; i < MAX_BROJ_BACANJA - 2; i++)
	srusi(1);
	TEST_ASSERT_EQUAL(30, skor());
}

// Cetvrti test - strike u prvom bacanju (10), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestStrike)
{
	int i;
	srusi(10);
	for (i = 0; i < MAX_BROJ_BACANJA - 2; i++)
	srusi(1);
	TEST_ASSERT_EQUAL(31, skor());
}

// Peti test - strike u prvom i drugom bacanju, ostala bacanja po 1 cunj 
TEST(BowlingTest, TwoStrikesInRow)
{
	int i;
	srusi(10);
	srusi(10);
	for (i = 0; i < MAX_BROJ_BACANJA - 4; i++)
	srusi(1);
	TEST_ASSERT_EQUAL(50, skor());
}
// Sesti test -strike u svakom bacanju(svaki put po 10 poena)
TEST(BowlingTest, TenStrikesInRow)
{
	int i;
	for(i = 0; i < BROJ_FREJMOVA; i++)
	{
	 srusi(10);	
	}
 	TEST_ASSERT_EQUAL(300, skor());
}
