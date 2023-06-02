#NOME DO PROJETO
PROJ_NAME=dado

#COMPILADOR
CC=g++

#FLAGS DO COMPILADOR
CC_FLAGS=-fpermissive	\
	 -O0		\
	 -std=c++17

OBJS= fila.o pilha.o tad.o main.o

all: $(OBJS)
	g++ $(OBJS) -o $(PROJ_NAME) $(CC_FLAGS)

tad.o:
	$(CC) -c tad.cpp -o tad.o

pilha.o:
	$(CC) -c pilha.cpp -o pilha.o

fila.o:
	$(CC) -c fila.cpp -o fila.o

main.o:
	$(CC) -c main.cpp -o main.o

clean:
	rm ./dado *.o
