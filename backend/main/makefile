all: a b c

a:
	ls | grep *\.a | xargs rm -f

b:
	ar -cvq libBackend.a ../build/bowling_stats.o ../build/users.o

c:
	gcc main.c -o main -L. -lBackend
