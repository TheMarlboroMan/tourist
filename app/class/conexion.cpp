#include "conexion.h"

using namespace App;

Conexion::Conexion(const Zona& destino, const Linea& linea, int tiempo)
	:destino(destino),
	linea(linea), tiempo(tiempo)
{

}

Conexion::Conexion(const Conexion& c)
	:destino(c.destino), 
	linea(c.linea), tiempo(c.tiempo)
{

}
