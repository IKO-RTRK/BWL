#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"

static void rollMany(int n, int pins) // helper funkcija umjesto beskonacnog pisanja iste for petlje :)
{
	int i;
	for(i = 0; i < n; i++)
	{
	knockDown(pins);
	}
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
	initialise();
}

TEST_TEAR_DOWN(BowlingTest)
{
}

// Prvi test - promasena sva bacanja
TEST(BowlingTest, TestAllZeroes)
{
	rollMany(MAX_NUM_OF_THROWS, 0);
	TEST_ASSERT_EQUAL(0, score());
}

// Drugi test - srusen jedan cunj u svim bacanjima
TEST(BowlingTest, TestAllOnes)
{
	rollMany(MAX_NUM_OF_THROWS, 1);
	TEST_ASSERT_EQUAL(21, score());
}

// Treci test - spare u drugom bacanju (5+5), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestSpare)
{
	knockDown(5);
	knockDown(5);
	rollMany(MAX_NUM_OF_THROWS - 2, 1);
	TEST_ASSERT_EQUAL(30, score());
}

// Cetvrti test - strike u prvom bacanju (10), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestStrike)
{
	knockDown(10);
	rollMany(MAX_NUM_OF_THROWS - 2, 1);
	TEST_ASSERT_EQUAL(31, score());
}

// Peti test - strike u prvom i drugom bacanju, ostala bacanja po 1 cunj 
TEST(BowlingTest, TwoStrikesInRow)
{
	knockDown(10);
	knockDown(10);
	rollMany(MAX_NUM_OF_THROWS - 4, 1);
	TEST_ASSERT_EQUAL(50, score());
}
// Sesti test -strike u svakom bacanju(svaki put po 10 poena)
TEST(BowlingTest, TenStrikesInRow)
{
	rollMany(MAX_NUM_OF_THROWS - 9, 10);
 	TEST_ASSERT_EQUAL(300, score());
}

//Sedmi test - poslednje bacanje strike 
TEST(BowlingTest, LastStrike)
{
	rollMany(MAX_NUM_OF_THROWS - 3, 0);
	knockDown(1);
	knockDown(9);
	knockDown(10);
 	TEST_ASSERT_EQUAL(20, score());
}


//Osmi test - malo strike malo spare 

TEST(BowlingTest, SparesAndStrikes)
{
	knockDown(10);
	knockDown(10);
	knockDown(5);
	knockDown(5);
	knockDown(6);
	knockDown(4);
	rollMany(MAX_NUM_OF_THROWS - 8, 1);
	TEST_ASSERT_EQUAL(85, score());

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
	rollMany(MAX_NUM_OF_THROWS - 6, 2);
	TEST_ASSERT_EQUAL(52,score());
}
//Deseti test - prvo bacanje u svakom frejmu promasaj
TEST(BowlingTest, FirstAttemptAlwaysMiss)
{
	
	int i = 0;
	do
	{
	if(i % 2 == 0)
	knockDown(0);
	else knockDown(1);
	i++;
	}while(i < MAX_NUM_OF_THROWS-1);
	knockDown(1);
	
	TEST_ASSERT_EQUAL(11,score());
}
//Jedanaesti test - pokusaj nedozvoljenog pristupa memorijskim lokacijama
TEST(BowlingTest, UnallowedMemoryAccess)
{
	int pointsCheck[24]={};
	rollMany(MAX_NUM_OF_THROWS - 3, 0);
	knockDown(10);	
	knockDown(10);	
	knockDown(10);	
	testMemory(pointsCheck);
 	TEST_ASSERT_EQUAL(0, pointsCheck[22]);
}


