all: x y a b c 

x:
	$(MAKE) -k -C backend all

y:
	$(MAKE) -k -C frontend all
	
a:
	find main | grep ".*\.a" | xargs rm -f
	find main | grep ".*\.so" | xargs rm -f

b:
	ar -cvq main/libBackend.a backend/build/bowling_stats.o backend/build/users.o
	ar -cvq main/libFrontend.a frontend/build/bowling_gui.o

	gcc --shared -o main/libBackendSh.so backend/build/bowling_stats.o backend/build/users.o
	gcc --shared -o main/libFrontendSh.so frontend/build/bowling_gui.o
c:
	gcc main/main.c -o main1 -Lmain -lBackend -lFrontend
