CC = g++

CPPFLAGS = -Wall

TARGET = memsim

SRC = memsim.cpp fifo.cpp lru.cpp vms.cpp dataStructures.cpp

HEADER = dataStructures.hpp policies.hpp

OBJ = memsim.o fifo.o lru.o vms.o dataStructures.o

$(TARGET) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJ)