#Makefile para algoritmos

all: 
	g++ -O0 est.cpp ordenacao.cpp ordenacaoPura.cpp utilitarios.cpp matematica.cpp busca.cpp -o est.out -fpermissive

clean:
	rm ./est.out
