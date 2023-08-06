#NOME DO PROJETO
PROJ_NAME=arvore

#COMPILADOR
CC=g++

#FLAGS DO COMPILADOR
CC_FLAGS=-O0		\

#GBC DEGUG FLAG
CC_DFLAG=-g

#DEBUG COMPILAÇÃO
SRCS= arvore.cpp main.cpp

OBJS= arvore.o main.o 

all: $(OBJS)
	$(CC) $(OBJS) -o $(PROJ_NAME).out $(CC_FLAGS)

debug: $(OBJS)
	$(CC) $(CC_DFLAG) $(SRCS) -o $(PROJ_NAME).gdb $(CC_FLAGS) 

arvore.o:
	$(CC) -c arvore.cpp -o arvore.o

main.o:
	$(CC) -c main.cpp -o main.o

clean:
	rm ./${PROJ_NAME}.out *.o 

debugclean:
	rm ./${PROJ_NAME}.gdb *.o
