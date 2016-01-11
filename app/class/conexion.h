#ifndef CONEXION_H
#define CONEXION_H

#include <string>

namespace App
{

class Zona;
class Linea;

class Conexion
{
	public:

			Conexion(const Zona& destino, const Linea& linea, int tiempo);
			Conexion(const Conexion&);

	const Zona&	acc_destino() const {return destino;}
	const Linea&	acc_linea() const {return linea;}
	int		acc_tiempo() const {return tiempo;}

	private:

	const Zona&	destino;
	const Linea&	linea;
	int		tiempo;
};

}

#endif
