#include "zona.h"

using namespace App;
Zona::Zona(const std::string& nombre)
	:nombre(nombre)
{

}

/**
* Insertar una conexión implicaría insertar la conexión en los dos sentidos...
* Esto mejor lo hacemos con una que esté fuera de la clase: no me gusta como 
* está.
*/

void Zona::insertar_conexion(const Conexion& c)
{
	//TODO: Comprobar si la conexión ya existe.
	conexiones.push_back(Conexion(c));
}

/*********
* Funciones libres...
*/

void App::conectar_zonas(Zona& zona_a, Zona& zona_b, const Linea& linea, int tiempo)
{
	zona_a.insertar_conexion(Conexion(zona_b, linea, tiempo));
	zona_b.insertar_conexion(Conexion(zona_a, linea, tiempo));
}
