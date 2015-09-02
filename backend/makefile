all: unity bowling_stats bowling_stats_Test main

.PHONY: all unity bowling_stats bowling_stats_Test

unity:
	$(MAKE) -C unity all

bowling_stats_Test:
	$(MAKE) -C tests all

bowling_stats:
	$(MAKE) -C src all

main:
	$(MAKE) -C build all

