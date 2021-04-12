#include<iostream>


char x = '1'; // Para incrementarlo y llenar la matriz


//Funci�n que inicializa la matriz con los 9 alores
void inicializar(char matriz[3][3])
{
	for(int i = 0; i<3; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			matriz[i][j] = x;
			x++; // Aumentando el char
		}

	}	
}

//Funci�n que recoje la opci�n de 'x' u 'o'
char escojaX_u_O()
{
	while(true){ //Bucle que funciona hasta que se ingrese las opciones correctas
		char opcion;
		std::cout << "Escoja ser X u O: ";
		std::cin>>opcion;
		if( opcion != 'X' && opcion != 'x' && opcion != 'o' && opcion != 'O')
		{
			std::cout<<"Debe escoger X u O" << std::endl;
		}
		else
		{
			std::cout<<"Usted ha elegido ser " << opcion << "\n";
			return opcion; //Se retorna la opci�n escogida
		}
	}
	
	return 'a';
}


//Funci�n que crea un tablero impreso en la pantalla
void mostrar_tablero(char matriz[3][3]){
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0 ; j < 3; j++)
		{
			if(j != 2)
			{
				std::cout << matriz[i][j] << " | ";
			}
			else{
				std::cout << matriz[i][j];
			}
		}
		
		if(i != 2) //Para que solo imprima los '---' dos veces
		{
			std::cout << "\n-----------\n";
		}
	}
	std::cout<<std::endl;
}


//Funci�n que genera un tablero con la opci�n en la posici�n escogida
void colocar(char matriz[3][3], int num, char opcion)
{
	for(int i = 0 ; i < 3; i ++)
	{
		for(int j = 1; j < 4; j++)
		{
			if(i*3 + j  == num)
			{
				matriz[i][j-1] = opcion;
				i = 5;
			}
		}
	}
	
	mostrar_tablero(matriz); //Llama a la funci�n de crear tablero y pasa la matriz modificada
}

int main(){
	
	char matriz[3][3];
	inicializar(matriz);
	char opcion = escojaX_u_O(); //guardando la opci�n
	
	int posicion;
	std:: cout << "Por favor, introduzca una posicion del tablero: ";
	std:: cin>>posicion;
	
	colocar(matriz, posicion, opcion);
	
	
	return 0;
}
