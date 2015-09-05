#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"


static void throwTheBall(int num,int pins)
{
	int i;
	for(i=0;i<num;i++)
		knockDown(pins);
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
	RUN_TEST_CASE(BowlingTest, UnallowedMemoryAccess);
}

TEST_SETUP(BowlingTest)
{
  char argv[] = {"1","1","ime"};
  int argc = 4;
  initialise(argc,argv);
}

TEST_TEAR_DOWN(BowlingTest)
{
}

// Prvi test - promasena sva bacanja
TEST(BowlingTest, TestAllZeroes)
{
	throwTheBall(MAX_NUM_OF_THROWS,0);
	TEST_ASSERT_EQUAL(0, score());
}

// Drugi test - srusen jedan cunj u svim bacanjima
TEST(BowlingTest, TestAllOnes)
{
	throwTheBall(MAX_NUM_OF_THROWS,1);
	TEST_ASSERT_EQUAL(20, score());
}

// Treci test - spare u drugom bacanju (5+5), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestSpare)
{
	throwTheBall(2,5);
	throwTheBall(MAX_NUM_OF_THROWS-2,1);
	TEST_ASSERT_EQUAL(29, score());
}

// Cetvrti test - strike u prvom bacanju (10), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestStrike)
{

	knockDown(10);
	throwTheBall(MAX_NUM_OF_THROWS-3,1);
	TEST_ASSERT_EQUAL(30, score());
}

// Peti test - strike u prvom i drugom bacanju, ostala bacanja po 1 cunj 
TEST(BowlingTest, TwoStrikesInRow)
{
	throwTheBall(2,10);
	throwTheBall(MAX_NUM_OF_THROWS-5,1);
	TEST_ASSERT_EQUAL(49, score());
}
// Sesti test -strike u svakom bacanju(svaki put po 10 poena)
TEST(BowlingTest, TenStrikesInRow)
{
	throwTheBall(MAX_NUM_OF_THROWS-9,10);
 	TEST_ASSERT_EQUAL(300, score());
}

//Sedmi test - poslednje bacanje strike 
TEST(BowlingTest, LastStrike)
{
	throwTheBall(MAX_NUM_OF_THROWS-3,0);	
	knockDown(1);
	knockDown(9);
	knockDown(10);
 	TEST_ASSERT_EQUAL(20, score());
}


//Osmi test - malo strike malo spare 

TEST(BowlingTest, SparesAndStrikes)
{

	throwTheBall(2,10);
	throwTheBall(2,5);
	knockDown(6);
	knockDown(4);
	throwTheBall(MAX_NUM_OF_THROWS-9,1);
	TEST_ASSERT_EQUAL(84,score());

}
// Deveti test - bez strikeova i spareova
TEST(BowlingTest, NoStrikesNoSpares)
{

	knockDown(2);
	knockDown(7);
	knockDown(3);
	knockDown(4);
	knockDown(5);
	knockDown(1);
	throwTheBall(MAX_NUM_OF_THROWS-7,2);
	TEST_ASSERT_EQUAL(50,score());
}
//Deseti test - prvo bacanje u svakom frejmu promasaj
TEST(BowlingTest, FirstAttemptAlwaysMiss)
{
	
	int i = 0;
	do
	{
	if(i%2==0)
	knockDown(0);
	else knockDown(1);
	i++;
	}while(i<MAX_NUM_OF_THROWS-1);
	knockDown(1);
	
	TEST_ASSERT_EQUAL(10,score());
}
//Jedanaesti test - pokusaj nedozvoljenog pristupa memorijskim lokacijama
TEST(BowlingTest, UnallowedMemoryAccess)
{
	int pointsCheck[24]={};
	throwTheBall(MAX_NUM_OF_THROWS-3,0);
	throwTheBall(3,10);
	testMemory(pointsCheck);
 	TEST_ASSERT_EQUAL(0, pointsCheck[22]);
}


