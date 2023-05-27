#Makefile para algoritmos

#NOME DO PROJETO
PROJ_NAME=algostruct

#COMPILADOR
CC=g++

#FLAGS DO COMPILADOR
CC_FLAGS=-fpermissive	\
	 -O0

OBJS= ordenacao.o busca.o dado.o main.o matematica.o utilitarios.o

all: $(OBJS)
	g++ $(OBJS) -o $(PROJ_NAME) $(CC_FLAGS)

ordenacao.o:
	$(CC) -c ordenacao.cpp -o ordenacao.o

busca.o:
	$(CC) -c busca.cpp -o busca.o

#dado.o:
#	$(CC) -c dado.cpp -o dado.o

main.o:
	$(CC) -c main.cpp -o main.o

matematica.o:
	$(CC) -c matematica.cpp -o matematica.o

utilitarios.o:
	$(CC) -c utilitarios.cpp -o utilitarios.o

clean:
	rm ./algostruct *.o
