#ifndef LINEA_H
#define LINEA_H

#include <string>

namespace App
{

class Linea
{
	public:

				Linea(const std::string&, float);

	const std::string&	acc_nombre() const {return nombre;}
	const float 		acc_precio_tramo() const {return precio_tramo;}

	private:

	std::string		nombre;
	float			precio_tramo;
};

}

#endif
