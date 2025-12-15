CC=gcc
CFLAGS=`pkg-config --cflags opencv`
LIBS=`pkg-config --libs opencv`

all:
	$(CC) *.c -o crosswalk $(CFLAGS) $(LIBS)

clean:
	rm -f crosswalk
