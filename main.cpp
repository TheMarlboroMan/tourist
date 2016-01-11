#include "app/class/conexion.cpp"
#include "app/class/linea.cpp"
#include "app/class/zona.cpp"	

#include <iostream>

void listar_conexiones_zona(const Zona&);

int main(int argc, char ** argv)
{
	using namespace App;

	//Crear tres zonas...
	Zona 	inicial("Inicial"),
		zona_a("Zona a"),
		zona_b("Zona b"),
		terminus("Terminus");

	//Vamos a crear dos líneas que empiezan en "inicial" y acaban en "terminus".
	Linea 	linea_a("Linea A", 120.0f),
		linea_b("Linea B", 130.0f);

	//Vamos a conectar las líneas...
	conectar_zonas(inicial, zona_a, linea_a, 5);
	conectar_zonas(zona_a, terminus, linea_a, 5);
	conectar_zonas(inicial, zona_b, linea_b, 5);
	conectar_zonas(zona_b, terminus, linea_b, 5);

	//En este momento tendríamos ya algo sencillo...

	const Zona * zona_actual=&inicial;

	int menu=0;
	
	do
	{
		listar_conexiones_zona(*zona_actual);
		std::cout<<"0) Salir"<<std::endl<<">>";
		std::cin>>menu;

		const auto& conexiones=zona_actual->acc_conexiones();
		if(menu <= (int)conexiones.size())
		{
			zona_actual=&conexiones[menu-1].acc_destino();
		}

	}while(menu);

	return 0;
}

void listar_conexiones_zona(const Zona& zona)
{
	std::cout<<"Estás en "<<zona.acc_nombre()<<std::endl;

	int opciones=1;
	const auto& conexiones=zona.acc_conexiones();

	for(const auto& c : conexiones)
	{
		std::cout<<opciones<<") Montarse en "<<c.acc_linea().acc_nombre()<<" en dirección "<<c.acc_destino().acc_nombre()<<std::endl;
		++opciones;
	}

}
