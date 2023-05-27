#NOME DO PROJETO
PROJ_NAME=dado

#COMPILADOR
CC=g++

#FLAGS DO COMPILADOR
CC_FLAGS=-fpermissive	\
	 -O0

OBJS= dado.o main.o

all: $(OBJS)
	g++ $(OBJS) -o $(PROJ_NAME) $(CC_FLAGS)

dado.o:
	$(CC) -c dado.cpp -o dado.o

main.o:
	$(CC) -c main.cpp -o main.o

clean:
	rm ./dado *.o
