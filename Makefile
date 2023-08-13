OBJS	= throwaway_password.o
SOURCE	= throwaway_password.cpp
HEADER	= 
OUT	= pass_gen
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

throwaway_password.o: throwaway_password.cpp
	$(CC) $(FLAGS) throwaway_password.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)