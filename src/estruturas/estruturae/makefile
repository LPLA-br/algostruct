#NOME DO PROJETO
PROJ_NAME=estruturas

#COMPILADOR
CC=g++

#FLAGS DO COMPILADOR
CC_FLAGS=-O0		\
	 -std=c++17

#GBC DEGUG FLAG
CC_DFLAG=-g

#DEBUG COMPILAÇÃO
SRCS= est.cpp main.cpp

OBJS= est.o main.o 

all: $(OBJS)
	$(CC) $(OBJS) -o $(PROJ_NAME).out $(CC_FLAGS)

debug: $(OBJS)
	$(CC) $(CC_DFLAG) $(SRCS) -o $(PROJ_NAME).gdb $(CC_FLAGS) 

est.o:
	$(CC) -c est.cpp -o est.o

main.o:
	$(CC) -c main.cpp -o main.o

clean:
	rm ./estruturas.out *.o 

debugclean:
	rm ./estruturas.gdb *.o
