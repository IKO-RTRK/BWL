all: x y a b c 

x:
	$(MAKE) -k -C backend all

y:
	$(MAKE) -k -C frontend all
	
a:
	find main | grep ".*\.a" | xargs rm -f

b:
	ar -cvq main/libBackend.a backend/build/bowling_stats.o backend/build/users.o
	ar -cvq main/libFrontend.a frontend/build/bowling_gui.o

c:
	gcc main/main.c -o main1 -Lmain -lBackend -lFrontend
