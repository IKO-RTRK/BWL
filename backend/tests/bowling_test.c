#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"

player p;

static void throwTheBall(int num, int pins)
{
	int i;
	for(i = 0; i < num; i++)
	knockDown(&p, pins);
}


TEST_GROUP(BowlingTest);

TEST_GROUP_RUNNER(BowlingTest)
{
	RUN_TEST_CASE(BowlingTest, TestAllZeroes);
	RUN_TEST_CASE(BowlingTest, TestAllOnes);	
	RUN_TEST_CASE(BowlingTest, TestSpare);	
	RUN_TEST_CASE(BowlingTest, TestStrike);
	RUN_TEST_CASE(BowlingTest, TwoStrikesInRow);
	RUN_TEST_CASE(BowlingTest, TenStrikesInRow);
	RUN_TEST_CASE(BowlingTest, LastStrike);
	RUN_TEST_CASE(BowlingTest, SparesAndStrikes);
	RUN_TEST_CASE(BowlingTest, NoStrikesNoSpares);
	RUN_TEST_CASE(BowlingTest, FirstAttemptAlwaysMiss);
}

TEST_SETUP(BowlingTest)
{
	int i;
  	for (i = 0; i < MAX_NUM_OF_THROWS; i++)
	p.points[i] = 0;
	
	for (i = 0; i < NUM_OF_FRAMES; i++)
	p.frames[i] = 0;

	p.numOfThrow = 0;
	p.totalScore = 0;
	 
}

TEST_TEAR_DOWN(BowlingTest)
{
}

// Prvi test - promasena sva bacanja
TEST(BowlingTest, TestAllZeroes)
{
	throwTheBall(MAX_NUM_OF_THROWS,0);
	TEST_ASSERT_EQUAL(0, p.totalScore);
}

// Drugi test - srusen jedan cunj u svim bacanjima
TEST(BowlingTest, TestAllOnes)
{
	throwTheBall(MAX_NUM_OF_THROWS,1);
	TEST_ASSERT_EQUAL(20, p.totalScore);
}

// Treci test - spare u drugom bacanju (5+5), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestSpare)
{
	throwTheBall(2,5);
	throwTheBall(MAX_NUM_OF_THROWS-2,1);
	TEST_ASSERT_EQUAL(29, p.totalScore);
}

// Cetvrti test - strike u prvom bacanju (10), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestStrike)
{

	knockDown(&p, 10);
	throwTheBall(MAX_NUM_OF_THROWS-3,1);
	TEST_ASSERT_EQUAL(30, p.totalScore);
}

// Peti test - strike u prvom i drugom bacanju, ostala bacanja po 1 cunj 
TEST(BowlingTest, TwoStrikesInRow)
{
	throwTheBall(2,10);
	throwTheBall(MAX_NUM_OF_THROWS-5,1);
	TEST_ASSERT_EQUAL(49, p.totalScore);
}
// Sesti test -strike u svakom bacanju(svaki put po 10 poena)
TEST(BowlingTest, TenStrikesInRow)
{
	throwTheBall(MAX_NUM_OF_THROWS-9,10);
 	TEST_ASSERT_EQUAL(300, p.totalScore);
}

//Sedmi test - poslednje bacanje strike 
TEST(BowlingTest, LastStrike)
{
	throwTheBall(MAX_NUM_OF_THROWS-3,0);	
	knockDown(&p, 1);
	knockDown(&p, 9);
	knockDown(&p, 10);
 	TEST_ASSERT_EQUAL(20, p.totalScore);
}


//Osmi test - malo strike malo spare 

TEST(BowlingTest, SparesAndStrikes)
{

	throwTheBall(2,10);
	throwTheBall(2,5);
	knockDown(&p, 6);
	knockDown(&p, 4);
	throwTheBall(MAX_NUM_OF_THROWS-9,1);
	TEST_ASSERT_EQUAL(84,p.totalScore);

}
// Deveti test - bez strikeova i spareova
TEST(BowlingTest, NoStrikesNoSpares)
{

	knockDown(&p, 2);
	knockDown(&p, 7);
	knockDown(&p, 3);
	knockDown(&p, 4);
	knockDown(&p, 5);
	knockDown(&p, 1);
	throwTheBall(MAX_NUM_OF_THROWS-7,2);
	TEST_ASSERT_EQUAL(50,p.totalScore);
}
//Deseti test - prvo bacanje u svakom frejmu promasaj
TEST(BowlingTest, FirstAttemptAlwaysMiss)
{
	
	int i = 0;
	do
	{
		if(i%2==0)
		knockDown(&p, 0);
		else 
		knockDown(&p, 1);
		i++;
	}while(i<MAX_NUM_OF_THROWS-1);
	knockDown(&p, 1);
	
	TEST_ASSERT_EQUAL(10,p.totalScore);
}


