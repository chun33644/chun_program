

CC=gcc
CFLAGS=`pkg-config --cflags protobuf-c` -I.
LDFLAGS=`pkg-config --libs protobuf-c` -lpaho-mqtt3c

OBJS=main.o sensor.pb-c.o

all: sender

sender: $(OBJS)
	$(CC) -o sender $(OBJS) $(LDFLAGS)

clean:
	rm -f sender *.o




