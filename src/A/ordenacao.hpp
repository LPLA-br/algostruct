#ifndef ORDENCACAO_HPP_INCLUDED
#define ORDENCACAO_HPP_INCLUDED

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

		void mescla( int* matriz, int primeiroIndex, int ultimoIndex, int meio);
		int* ordenacaoMescla( int* matriz, int primeiroIndex, int ultimoIndex );

		int particaoQS( int* m, int pi, int ui );
		int* ordenacaoRapida( int* matriz, unsigned int primeiroIndex, unsigned int ultimoIndex );

		//teste de particionamento

		int* particionamento( int matriz[], unsigned int primeiroIndex, unsigned int ultimoIndex );
};

#endif //ORDENCACAO_HPP_INCLUDED
