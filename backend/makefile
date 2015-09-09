all: unity bowling_stats bowling_test main

.PHONY: all unity bowling_stats bowling_test

unity:
	$(MAKE) -C unity all

bowling_test:
	$(MAKE) -C tests all

bowling_stats:
	$(MAKE) -C src all

main:
	$(MAKE) -C build all
