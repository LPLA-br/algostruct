#ifndef TUDO_HPP_INCLUDED
#define TUDO_HPP_INCLUDED

class Utilitarios
{
	private:
	protected:
	public:
		void escreverMatriz( int* m, unsigned int tamanho );
		unsigned int mediaEntreDoisNumeros( int a, int b );
		void swap( int* a, int* b );
		void escreverMatrizEntreValores( int* m, unsigned int comesso, unsigned int fim );
		int* gerarmatrizaleatoria( int tamanho, int maxnum = 10 );
};

class Matematica
{
	private:
	protected:
	public:
		void fibonatiA(void);
		void eprimo( int num );
};


class Ordenacao
{
	private:
	protected:
	public:

		int* ordenacaoBolha( int matriz[], unsigned int tamanho );
		void ordenacaoBolhaPura( int matriz[], unsigned int tamanho );

		int* ordenacaoInsercao( int matriz[], unsigned int tamanho );
		int* ordenacaoSelecao( int matriz[], unsigned int tamanho );

		//emprego de recursividade - algoritmos eficientes
		void ordenacaoMescla( int matriz[], unsigned int comesso, unsigned int fim );

		int* ordenacaoRapida( int matriz[], unsigned int tamanho );

		//estrambólico
		int* ordencaoShell( int matriz[], unsigned int tamanho );

		//teste de particionamento
		int* particionamento( int matriz[], unsigned int primeiroIndex, unsigned int ultimoIndex );
};

class Busca
{
	private:
	protected:
	public:
		unsigned int buscaLinear( int alvo, int matriz[] );
		void buscaBinariaAlfabeto( char caractereAlvo, unsigned int tamanhoAbs, const char* alfabeto );
		void buscaBinariaNumerica( int numalvo, unsigned int tamanhoAbs, const int* matriz);
};

#endif // TUDO_HPP_INCLUDED
