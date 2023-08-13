#include <iostream>

using namespace std;

int main()
{
	string op;
	char conf;
	bool loop = true;
	//op: operacion; conf: confirmacion
	
	cout<<"\t\t--------------------\n";
	cout<<"\t\t|Bienvenidos a Risk|\n";
	cout<<"\t\t--------------------\n";
	cout<<"\t>Digite 'ayuda' para una lista de comandos\n\n\n";
	
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
		
		else if(op == "Guardar" || op == "guardar" || op == "GUARDAR")
		{
			while(loop == true)
			{
				cout<<endl<<"Comrpimir el archivo? (Y/N)"<<endl;
				cin>>conf;
				if(conf == 'y' || conf == 'Y')
				{
					cout<<endl<<"3 (comprimir)"<<endl;
					loop = false;
				}
			
				else if(conf == 'n' || conf == 'N')
				{
					cout<<endl<<"3"<<endl;
					loop = false;
				}
			
				else
				{
					cout<<endl<<"Opcion invalida.";
				}
			}
		}
		
		else if(op == "Cargar" || op == "cargar" || op == "CARGAR")
		{
			cout<<endl<<"4"<<endl;
		}
		
		
		else if(op == "Ayuda" || op == "ayuda" || op == "AYUDA")
		{
			cout<<endl<<"Comandos disponibles:"<<endl;
			cout<<"*Inicializar: Configurar una nueva partida.\n";
			cout<<"*Turno: Inicializa el turno del siguiente jugador.\n";
			cout<<"*Guardar: Guardar la partida con el nombre que se elija.\n";
			cout<<"*Cargar: Cargar una partida desde un archivo guardado.\n";
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
