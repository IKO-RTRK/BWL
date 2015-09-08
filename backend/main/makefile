all: a b

a:
	ar -cvq libBackend.a ../build/bowling_stats.o ../build/users.o

b:
	gcc main.c -o main -L. -lBackend
