#include "../unity/unity_fixture.h"

static void RunAllTests(void)
{
	RUN_TEST_GROUP(bowling_stats);
}

int main(int argc, char *argv[])
{
	return UnityMain(argc, (const char **)argv, RunAllTests);
}


