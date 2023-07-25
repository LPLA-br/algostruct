#include "arboribus.hpp"

Arbor::Arbor( unsigned int numerus )
{
	currens = new Nodus;
	currens->numerus = numerus;
	currens->sextra = nullptr;
	currens->dextra = nullptr;
	nodiNumeri = 1;
}

Arbo::~Arbor(void)
{}
