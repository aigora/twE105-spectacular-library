//ES NECESARIO ESCOGER LA OPCION SALIR PARA QUE SE GUARDEN LOS DATOS
#define _CRT_SECURE_NO_WARNINGS
#define NALUMNOS 100 //Número total de alumnos que caben en la biblioteca
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include <conio.h>
#include <time.h> //Para el temporizador

struct Talumno { //Estructura que guarda los datos de cada alumno
	char matricula[5];
	int sesion; //1-ABIERTA 0-CERRADA

};

struct TAux { //Auxiliar para coger datos
	char matricula[5];
};

//FUNCIONES
//-> Funciones para actualizar ficheros:
void actualizarFicheroAlumnos(int dim, int alumno, struct Talumno alumnos[]);
//->Funciones para que los datos introducidos sean validos:
void matriculaValida(char matricula[5]);
//->Funciones que contienen menus y logotipos
int SesionAbierta(int dim, struct Talumno * alumnos); //1:ABIERTA 0:CERRADA
int LOGOTIPO(struct Talumno alumno[]); //Logotipo inicial que tambien lee el fichero alumnos
//Temporizador
void delay(int secs);
//Fecha y hora del sistema
void captar_tiempo(char fecha_hora[]);
//funcion del menu principal
void menu();
void menu2();
void menu3();

int main()
{
	system("color 7C");
	
	int n, t, secs, alumno, opcion;
	int j, k = 0, i, comp1, comp2, auxx = 0, nusu = 0; // case 'E': variables para el registro y entrada de usuarios
	int r, permanecer;
	char A, a, B, b, op1, op2, op3;
	//Siendo A entrada, B salida.
	char E, e, L, l, D, d, C, c;
	//Siendo E estudio, L coger o dejar libro, D descanso, I información.
	struct Talumno usu[NALUMNOS];
	struct TAux aux; //Aux para el registro de entrada y salida de los usuarios
	int salida = 2;//Salir del programa
	
	char fecha_hora[128];
 	captar_tiempo(fecha_hora);
 	printf("%s\n",fecha_hora);
 	system ("pause");
 	
	nusu = LOGOTIPO(usu); //Logotipo y obtenemos toda la informacion del fichero alumnos
	
	do {
	
	system("cls");
	k = SesionAbierta(nusu, usu); //Obtenemos el alumno que tiene sesión iniciada o un -1 que indica que no hay ningun usuario con sesion
	menu();
	scanf("%c", &op1);
	getchar();

	switch(op1) //Entrada, salida o salir del programa
	{
	    case '0':
	    	printf("Has salido del programa.\n");
		    return 0;
		    break;
		    
		case 'A':
		case 'a':
			system("cls");			
			k = SesionAbierta(nusu, usu);
			menu2();
			scanf(" %c", &op2);
			getchar();
			
			do {
				
			switch(op2)
			{
				case 'E':
				case 'e':
					system("cls");
					k = SesionAbierta(nusu, usu);
					if(usu[k].sesion != 1) {
							printf("Ya hay una sesion abierta. La sesion de %d esta abierta\n", usu[k].matricula);
							Sleep(800);
							usu[k].sesion = 1;
					}					
					else {
						printf("Para entrar necesitamos sus datos.\n");
						do {
			
						printf("Introduzca su numero de matricula\n"); //Hay que introducir 2 veces la matrícula para que la tenga en cuenta, no entendemos por qué
						scanf_s(" %d", &aux.matricula, 5);
						matriculaValida(aux.matricula);
						for (k = 0; k < nusu; k++) { //La k se queda como la variable del usuario que está dentro
							comp1 = strcmp(aux.matricula, usu[k].matricula); //Compara entre todos los usuarios ya registrados
							if (comp1 == 0) {
								break;
							}
						}
		
						if (comp1 != 0) {//Si no coincide con ningun nombre
							if(nusu == NALUMNOS) { //Si el número de alumnos es igual al número máximo de ellos
									printf("\tNo queda sitio en la biblioteca, no pueden entrar mas alumnos\n");
									printf("\tLos alumnos suelen estar un promedion de 3 horas. Intentelo mas tarde. Disculpe las molestias.\n");
								}
							else {
								strcpy_s(usu[nusu].matricula, 5, aux.matricula); //guarda la matrícula nueva en alumnos
								printf("Usted ha sido registradx como: %d\n");
								scanf(" %d", &usu[nusu].matricula);
								system("pause");
								usu[nusu].sesion = 1;
								k = nusu;						
								nusu = nusu++; //Como se ha registrado un alumno aumentamos uno el número de alumnos
								for (i = 0; i < nusu; i++) {
									actualizarFicheroAlumnos(nusu, i, usu);
								}
							}
						}
						else {
							printf("Lo sentimos, ya hay un alumno registrado con ese numero de matricula.\n");

						}
					}
						while(comp1 == 0);
				}
				break;
	
				case 'L':
				case 'l':
					printf("Mas adelante encontrara un ordenador para devolver, renovar o buscar libros.\n");
					Sleep(1200);
					break;
				case 'C':
				case 'c':
					printf("Mas adelante encontrara un puesto de informacion.\n");
					Sleep(1200);
					break;
				case 0: 
					Sleep(1200);
					system("cls");
					break;//Se sale de este menú
				default:
					printf("Lo siento, esa opcion no esta disponible.\n");
					break;
				
			}
			
			break;
			
			}
			
			while(salida == 2);
				printf("Elija de nuevo una opcion:\n");
				break;
									
		case 'B':
		case 'b':
			menu3();
			scanf(" %c", &op3);
			do {
				
			switch(op3)
			{
				case 'E':
				case 'e':
					system("cls");
					k = SesionAbierta(nusu, usu);
					if (usu[k].sesion != 1) {
						printf("La sesion de %d esta abierta, salga para iniciar sesion.\n", usu[k].matricula);
						Sleep(1200);
					}
				
					else {
						printf("Para salir necesitamos sus datos.\n");

						do {
							printf("Introduzca su numero de matricula:\n");
							matriculaValida(aux.matricula);
							getchar();
							for (k = 0; k < nusu; k++) { //La k se queda como la variable del usuario que está dentro
								comp1 = strcmp(aux.matricula, usu[k].matricula); //Compara entre todos los usuarios ya registrados
								if (comp1 != 0) {
									break;
								}
							}
								
							if(comp1 == 0) { //Si no hay alguien registrado con ese número de matrícula
		
									strcpy_s(usu[nusu].matricula, 5, aux.matricula); //Guarda la matrícula nueva en alumnos
									printf("Usted ha sido registradx como: %d\n", usu[nusu].matricula);
									printf("Esperamos que haya aprovechado su estudio.\n");
									system("pause");
									usu[nusu].sesion = 0;
									nusu = k;	
									k = k--; //Como se ha registrado un alumno aumentamos uno el número de alumnos
									for (i = k; i > nusu; i--) {
										actualizarFicheroAlumnos(k, i, usu);
									}
							}
							else {
								printf("No existe un alumno con ese numero de matricula, intente con otro.\n");
							}	
						}
						while (comp1 != 0);//Se repite mientras que se introduzcan nombres ya registrados

					}
					
					Sleep(1200);
		
					break;
	
				case 'D':
				case 'd':
					do {
						printf("Introduzca su numero de matricula:\n");
						matriculaValida(aux.matricula);
						getchar();
						for (k = 0; k < nusu; k++) { //La k se queda como la variable del usuario que está dentro
								comp1 = strcmp(aux.matricula, usu[k].matricula); //Compara entre todos los usuarios ya registrados
								if (comp1 != 0) {
									break;
								}
							}
							
						if(comp1 == 0) { //Si hay alguien registrado con ese número de matrícula
				
							strcpy_s(usu[nusu].matricula, 5, aux.matricula); //guarda la matrícula nueva en alumnos
							printf("Usted ha sido registrado como: %i\n", usu[nusu].matricula);
							printf("Tiene 20 minutos de descanso. Procure cumplirlo o su sitio quedará liberado y deberá volver a registrarse.\n");
							system("pause");
							delay(secs); //Función para contabilizar 20 minutos
							if(secs = 1200000) { 
								usu[k].sesion = 1;
								nusu = k;									
								k = k--; //Como se ha registrado un alumno aumentamos uno el número de alumnos
								for (i = k; i > nusu; i--) {
									actualizarFicheroAlumnos(k, i, usu);
								}
				
							}
						}
						else {
							printf("No hay nadie dentro con este numero de matricula, vuelva a intentarlo:\n");
						}
					}
					while (comp1 != 0); //Se repite mientras se introduzcan matrículas ya registrada
				
					Sleep(10);
		
					break;
	
				case 'L':
				case 'l':
					printf("Esperamos haberle servido de ayuda.\n");
					Sleep(1200);
					break;
				case 'C':
				case 'c':
					printf("Esperamos haberle servido de ayuda.\n");
					Sleep(1200);
					break;
				case 0: 
					Sleep(1200);
					system("cls");
					break;//Se sale de este menú
				default:
					printf("Lo siento, esa opcion no esta disponible.\n");
					break;
			}
			
			break;
			
			}
			
			while(salida == 2);
				printf("Elija de nuevo una opcion:\n");
				break;
	
		default:
			printf("Lo siento, esa opcion no esta disponible.\n");
			break;
			
	}
			
}
			
while(salida == 2); //Se repite hasta que se decida salir del programa
	printf("Elija de nuevo una opcion:\n");
	for (i = 0; i < nusu; i++) {
		actualizarFicheroAlumnos(nusu, i, usu);
		
}

}

			
//FUNCIONES
void matriculaValida(char matricula[]) {
	int i, contador, longitud, final;

	do {
		scanf("%s", matricula, 5);
		longitud = strlen(matricula);
		if (longitud != 5) { //Si no tiene 5 números
			final = -2;
		}
		else {
			for (i = 0; matricula[i] != '\0'; i++) {
				
				if ((matricula[i]< 'a' || matricula[i]> 'z') && (matricula[i]< 'A' || matricula[i]> 'Z')) { //No hay letras
					final = -1;
				}
				else {
					final = 1;
					break;
				}
			}
		}

		if (final == -2) {
			printf("La matricula debe tener de 5 caracteres, introduzca de nuevo un numero de matricula:\n");
		}
		else if (final == 1) {
			printf("La matricula no puede contener letras, introduzca de nuevo un numero de matricula:\n");
		}

	} while (final != -1);
}
//PARA QUE FUNCIONE 
/*for (i = 0; i < nusu; i++) {
		actualizarFicheroAlumnos(nusu, i, usu);
	}
*/
void actualizarFicheroAlumnos(int dim, int alumno, struct Talumno alumnos[]) { //dim numero de alumnos
	FILE*fichero;
	errno_t error;
	
	int i;
	if (alumno == 0) {
		error = fopen_s(&fichero, "alumnos.txt", "w");//Abrir reescribiendo
		if (error == 0) {//Si no hay error
			printf("Guardando datos...\n");
		}
		else {//Si hay error
			printf("Ha habido un error %d para guardar los datos.\n", error);
			return; // return sale del programa
		}

		fprintf(fichero, "%d\n", dim);//Imprime el número de alumnos alcanzado

		fclose(fichero);
    }
	error = fopen_s(&fichero, "alumnos.txt", "a");//Abrir añadiendo
	if (error == 0) {//Si no hay error
		//printf("Guardando datos...\n");
	}
	else {//Si hay error
		printf("Ha habido un error %d para guardar los datos.\n", error);
		return; // return sale del programa
	}
		fprintf(fichero, "%d\t", alumnos[alumno].matricula);
		fprintf(fichero, "%d\t", alumnos[alumno].sesion);
	
	fclose(fichero);

}

int SesionAbierta(int dim, struct Talumno * alumnos)  {
	int opcion = 0, i;
	if (dim == 0) {//Si no hay alumnos registrados
		opcion = -1;
	}
	else {
		for (i = 0; i < dim; i++) {
			if (alumnos[i].sesion == 1) {//Cuando hay una sesion abierta se guarda en opcion que es lo que devuelve la funcion y se sale de bucle
				opcion = i;
				break;
			}
			else {
				opcion = -1;
			}
		}
	}
	return opcion;
}
//Fecha y hora del sistema
void captar_tiempo(char * fecha)
{
 time_t tiempo = time(0);
 struct tm *tlocal = localtime(&tiempo);
 strftime(fecha,128,"%d/%m/%y %H:%M:%S",tlocal);
}

//Temporizador
void delay(int secs) {
	int t;
	for(t = (time(NULL) + secs); time(NULL) != t; time(NULL));
}

void menu(){
    
	printf("Elige una opcion.\n");
	printf("A - Entrar\n");	
	printf("B - Salir\n");
	printf("0 - Salir del programa\n");
 }
 
void menu2(){                        
printf("Que vienes a hacer?\n");
			printf("E - Sala de estudio\n"); 
			printf("L - Dejar, coger o renovar un libro\n");
			printf("C - Solicitar informacion\n");
			printf("0 - Volver al menu principal\n");
}

void menu3(){                        
printf("Que dejas de hacer?\n");
			printf("E - Sala de estudio\n"); 
			printf("L - Dejar, coger o renovar un libro\n");
			printf("D - Descanso de estudio\n");
			printf("C - Solicitar informacion\n");
			printf("0 - Volver al menu principal\n");

}

int LOGOTIPO(struct Talumno alumno[])
{

printf(" ______  _________ ______   _       _________ _______ _________ _______  _______  _______        _______ _________ _______ _________ ______  _________\n");
printf("(  ___ )  __   __/(  ___ ) ( )       __   __/(  ___  ) __   __/(  ____/ (  ____/ (  ___  )      (  ____/  __   __/(  ____/  __   __/(  __     __   __/\n");
printf("| (   ) )   ) (   | (   ) )| |         ) (   | (   ) |   ) (   | (      | (      | (   ) |      | (         ) (   | (         ) (   | (     )   ) (   \n");
printf("| (__/ /    | |   | (__/ / | |         | |   | |   | |   | |   | (__    | |      | (___) |      | (__       | |   | (_____    | |   | |   ) |   | |   \n");
printf("|  __ (     | |   |  __ (  | |         | |   | |   | |   | |   |  __)   | |      |  ___  |      |  __)      | |   (_____  )   | |   | |   | |   | |   \n");
printf("| (    )    | |   | (    ) | |         | |   | |   | |   | |   | (      | |      | (   ) |      | (         | |         ) |   | |   | |   ) |   | |   \n");
printf("| )___) )___) (___| )___) )| (_____ ___) (___| (___) |   | |   | (_____ | (_____ | )   ( |      | (_____    | |    _____) |___) (___| (__/  )___) (___\n");
printf("|/  ___/  _______/|/  ___/ (_______/ _______/(_______)   )_(   (_______/(_______/|/      |      (_______/   )_(   /_______) _______/(______/  _______/\n");
	
	int i, dim;
	
	FILE*fichero;
	errno_t error;
	printf("\n\t~~Bienvenido a la biblioteca de la ETSIDI~~\n\n");

	printf("...Estamos cargando los datos del sistema\n");
	error = fopen_s(&fichero, "alumno.txt", "r");//Error al abrir el fichero?
	Sleep(2000);

	if (error == 0) {
		printf("Alunos cargados!\n");
		Sleep(1500);
	}
	else {
		printf("Ha habido un error %d al cargar los datos\n", error);
		return; // return sale del programa
	}
	fscanf_s(fichero, "%d", &dim);//Lee del fichero el numero de usuarios
	if (dim != 0) {//Si no es 0, lee el fichero completo
		for (i = 0; i < dim; i++) {
			fscanf_s(fichero, "%d\t", alumno[i].matricula, 5);
			fscanf_s(fichero, "%d\t", &alumno[i].sesion);
		}
	}
	fclose(fichero);

	return dim;

}
