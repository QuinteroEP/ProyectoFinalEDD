#include <iostream>

using namespace std;

int main()
{
	string op;
	//op: operacion
	
	cout<<"\t--------------------\n";
	cout<<"\t|Bienvenidos a Risk|\n";
	cout<<"\t--------------------\n\n\n";
	
	while(true)
	{
		cout<<"Menu principal\n$ ";
		cin>>op;
		
		if(op == "Inicializar" || op == "inicializar" || op == "INICIALIZAR")
		{
			cout<<endl<<"1"<<endl;
		}
		
		else if(op == "turno" || op == "Turno" || op == "TURNO")
		{
			cout<<endl<<"2"<<endl;
		}
		
		else if(op == "Ayuda" || op == "ayuda" || op == "AYUDA")
		{
			cout<<endl<<"Comandos disponibles:"<<endl;
			cout<<"*Inicializar: Configurar una nueva partida.\n";
			cout<<"*Turno: Inicializa el turno del siguiente jugador.\n";
			cout<<"*salir: Terminar el programa.\n";
		}
		
		else if(op == "Salir" || op == "salir" || op == "SALIR")
		{
			return 0;
		}
		
		else
		{
			cout<<"Comando no reconocido, digite 'ayuda' para obtener una lista de comandos.\n";
		}
		
		cout<<endl<<endl;
		system("pause");
		system("cls");
		
	}
	
	return 0;
}
