#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <vector>
#include "conexion.h"


namespace App
{

class Zona
{
	public:

					Zona(const std::string&);

	const std::string&		acc_nombre() const {return nombre;}
	const std::vector<Conexion>&	acc_conexiones() const {return conexiones;}

	void				insertar_conexion(const Conexion& c);

	private:

	std::string			nombre;
	std::vector<Conexion>		conexiones;

};

void conectar_zonas(Zona& zona_a, Zona& zona_b, const Linea& linea, int tiempo);

}

#endif
