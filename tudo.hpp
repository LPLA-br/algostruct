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
		int* gerarmatrizaleatoria( int tamanho, int maxnum );
		int* gerarmatrizordendadadecrescente( int tamanho, int maxnum );
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

		int* ordenacaoInsercao( int matriz[], unsigned int tamanho );

		int* ordenacaoSelecao( int matriz[], unsigned int tamanho );

		int* ordenacaoShell( int matriz[], unsigned int tamanho );

		//emprego de recursividade - algoritmos eficientes

		// MESCLA
		int* ordenacaoMesclaA( int matriz[], unsigned int comesso, unsigned int fim );

		void mescla( int matriz[], int primeiroIndex, int ultimoIndex, int meio);
		int* ordenacaoMescla( int matriz[], int primeiroIndex, int ultimoIndex );
		// MESCLA

		int particaoQS( int m[], int pi, int ui );
		int* ordenacaoRapida( int matriz[], unsigned int primeiroIndex, unsigned int ultimoIndex );


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
