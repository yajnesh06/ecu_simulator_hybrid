CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2
LDFLAGS = -shared
TARGET = ecu/libecu.so

SRC = ecu/ecu_logic.c
HDR = ecu/ecu_logic.h

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
