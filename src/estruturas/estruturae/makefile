#NOME DO PROJETO
PROJ_NAME=estruturas

#COMPILADOR
CC=g++

#FLAGS DO COMPILADOR
CC_FLAGS=-fpermissive	\
	 -O0		\
	 -std=c++17

OBJS= est.o main.o 

all: $(OBJS)
	g++ $(OBJS) -o $(PROJ_NAME) $(CC_FLAGS)

est.o:
	$(CC) -c est.cpp -o est.o

main.o:
	$(CC) -c main.cpp -o main.o

clean:
	rm ./estruturas *.o
