#ifndef ARBORIBUS_HPP_INCLUDED
#define ARBORIBUS_HPP_INCLUDED

struct Nodus
{
	unsigned int numerus;

	Dados* sextra;
	Dados* dextra;
};

class Arbor
{
	private:
		Nodus* currens;
		unsigned short int nodiNumeri;

	protected:
		/* usuarii auxiliares functiones motús */
		void iDextra( void );
		void iSextra( void );

	public:
		/* constructor primum nodum arboris aedificat... */
		Arbor( unsigned int numerus );

		/* ... et arbor a destructor demolitur */
		~Arbor( void );

		/* lux functionis infra hoc nodus et alius nodi illustráre potest */
		void arboremMonstra( void );

		/* prudentia usuarii necesse est. is per arborem cum libertate se movere potest*/
		void inArboremPone( char dextraAutSextra );

		unsigned int profunditasArborisMonstra( void );

		void inOrdinemCurre( void );
		void preOrdinemCurre( void );
		void postOrdinemCurre( void );
};

#endif // ARBORIBUS_HPP_INCLUDED
