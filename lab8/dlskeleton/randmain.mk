OPTIMIZE = -O2
CC = gcc
CFLAGS = $(OPTIMIZE) -g3 -Wall -Wextra -march=native -mtune=native -mrdrnd

randlibhw.so: randlibhw.c
	$(CC) $(CFLAGS) -fPIC -c randlibhw.c -o randlibhw.o
	$(CC) $(CFLAGS) -shared -o randlibhw.so randlibhw.o

randlibsw.so: randlibsw.c
	$(CC) $(CFLAGS) -fPIC -c randlibsw.c -o randlibsw.o
	$(CC) $(CFLAGS) -shared -o randlibsw.so randlibsw.o

randmain: randcpuid.c randmain.c
	$(CC) $(CFLAGS) -c randmain.c -o randmain.o
	$(CC) $(CFLAGS) -c randcpuid.c -o randcpuid.o
	$(CC) $(CFLAGS) randcpuid.o randmain.o -ldl -lm -Wl,-rpath,$(PWD) -o randmain
