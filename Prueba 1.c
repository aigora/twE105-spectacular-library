#include <stdio.h>
#include <stdlib.h>


int main()
{
	system("color 7C");
	int n;
	char A, B, op1, op2, op3;
	//Siendo A entrada, B salida.
	char E, L, D, I;
	//Siendo E estudio, L coger o dejar libro, D descanso, I información.
	
	printf("Elige una opcion.\n");
	printf("A - entrar	B - salir\n");
	scanf("%c", &op1);
	switch(op1)
	{
		case 'A':
			printf("Bienvenidx, que vienes a hacer?\n");
			printf("E - Estudio   L - Libro   I - Informacion\n");
			scanf(" %c", &op2);
			switch(op2)
			{
				case 'E':
					printf("Quedan %d plazas disponibles.\n", n);
					if(n == 0)
					{
						printf("Los alumnos suelen estar un promedio de 3 horas. Disculpe las molestias.\n");
					}
					else
					{
						printf("Introduzca su numero de matricula.\n");
						//Guardar los números de matrícula en un fichero.
						//Habría un for para contabilizar el número de plazas ocupadas.
						printf("Esperamos que aproveche su estudio.\n");
					}
					break;
				case 'L':
					printf("Mas adelante encontrara un ordenador para devolver, renovar o buscar libros.\n");
					break;
				case 'I':
					printf("Mas adelante encontrara un puesto de informacion.\n");
					break;
				default:
					printf("Lo siento, esa opcion no esta disponible.\n");
					break;
				
			}
			break;
		
			
		case 'B':
			printf("Que deja de hacer?\n");
			printf("E - Estudio   D - Descanso de estudio   L - Libro   I - Informacion\n");
			scanf(" %c", &op3);
			switch(op3)
			{
				case 'E':
					printf("Introduzca su numero de matricula.\n");
					//Quitar su numero de matricula del fichero.
					printf("Esperamos que haya aprovechado su dia\n");
					//Habría un for para contabilizar el número de plazas disponibles.
					break;
				case 'D':
					printf("Introduzca su numero de matricula.\n");
					//Guardar los numeros de matricula en otro fichero.
					printf("Procura no tardar mas de 30 minutos, es posible que su sitio quede libre en caso contrario.\n");
					//Podríamos añadir un temporizador, es opcional.
					//Si no regresa en 30 minutos, se quitará su matrícula del fichero. Así se desocupará su sitio.
					break;
				case 'L':
					printf("Esperamos haberle servido de ayuda.\n");
					break;
				case 'I':
					printf("Esperamos haberle servido de ayuda.\n");
					break;
				default:
					printf("Lo siento, esa opcion no esta disponible.\n");
					break;
				
			printf("Gracias por su visita, esperamos verle pronto\n");
			}
			break;	
	
		default:
			printf("Lo siento, esa opcion no esta disponible.\n");
			break;
	}

	
}
