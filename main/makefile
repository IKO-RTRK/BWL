all: a b c

a:
	ls | grep *\.a | xargs rm -f

b:
	ar -cvq libBackend.a ../backend/build/bowling_stats.o ../backend/build/users.o
	ar -cvq libFrontend.a ../frontend/build/bowling_gui.o

c:
	gcc main.c -o main -L. -lBackend -lFrontend
