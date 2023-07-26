#ifndef ARBORIBUS_HPP_INCLUDED
#define ARBORIBUS_HPP_INCLUDED

struct Nodum
{
	std::string rota;

	Nodum* pater;

	Nodum* sinister;
	Nodum* dexter;
};

class Arbor
{
	private:
		Nodum* currens;
		unsigned short int nodiNumeri;

	protected:
		Nodum* novusNodum( bool estneDexter );

		void ls( void );
		void mknode( char ds );
		void cnode( char dsp );
		void pwd( void );
		void rm( char ds );


	public:
		/* constructor primum nodum arboris aedificat... */
		Arbor();

		/* ... et arbor a destructor demolitur */
		~Arbor( void );

		unsigned int profunditasArborisMonstra( void );

		void inOrdinemCurre( void );
		void preOrdinemCurre( void );
		void postOrdinemCurre( void );

		/* prudentia usuarii necesse est. is per arborem cum libertate se movere potest*/
		void testa( void );
};

#endif // ARBORIBUS_HPP_INCLUDED
