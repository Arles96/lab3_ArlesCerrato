#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

//Funcion para ingresar minar a la matriz
char** MinesMatrix(char** , int);
//Funcion para llenar la matriz
void FillInMatrix(char** , int);
//Impresion de matriz
void PrintMatrix(char**, int);
//balanceo de la cadena
void BalanceWord(string);
//

int main ()
{
	//variable de respuesta de usuario
	char answer = 's';
	int option;
	while (answer=='s'){
		cout<<"MENU"<< endl;
		cout<<"1.- Ejercicio No.1" << endl;
		cout<<"2.- Ejercicio No.2" << endl;
		cout<<"Ingrese una opcion: ";
		cin>>option;
		while (option<1 || option>2){
			cout<<"Error en la opcion"<<endl;
			cout<<"Ingrese una option: " << endl;
			cin>>option; 
		}
		if (option==1){
			int n;
			cout<<"Ingrese un numero para el tamaño: ";
			cin>>n;
			while (n<9 || n>100){
				cout<<"Error en el tamaño" << endl;
				cout<<"Ingrese un numero para el tamaño: ";
				cin>>n;
			}
			//Declaracion de matriz
			char** matrix = new char*[n];
			for (int i=0; i<n; i++){
				matrix[i] = new char [n];
			}
			//llenado de matriz
			FillInMatrix(matrix,n);
			PrintMatrix(matrix,n);
			cout<< endl;
			//Ingreso de minas
			matrix = MinesMatrix(matrix,n);
			PrintMatrix(matrix,n);
			cout<< endl;
			
		}
		else {
			string word;
			cout<<"Ingrese una cadena de corchetes o parentesis: ";
			cin>>word;
			BalanceWord(word);				
		}
		cout<<"Desea continuar [s/n]: ";
		cin>>answer;
	}
	return 0;
}

void FillInMatrix(char** matrix, int n)
{
	for (int i=0; i<n; i++){
		for (int j=0; j<n;j++){
			matrix[i][j]= 'p';
		}
	}
}

char** MinesMatrix (char** matrix, int n)
{
	//Numeros aleatorios
	int r1, r2, mines;
	cout<<"Ingrese la cantidad de minas: ";
	cin>>mines;
	srand(time(NULL));
	while (mines<10 || mines>(n*n)){
		cout<<"Error hay muchas minas" << endl;
		cout<<"Ingrese una cantidad de minas: ";
		cin>>mines;
	}
	//contador de minas
	int counter = 0;
	while (counter<=mines){
		r1 = 1 + rand()%(10-1);
		r2 = 1 + rand()%(10-1);
		matrix[r1][r2] = '*';
		counter++;
	}
	return matrix;
}

void PrintMatrix(char** matrix, int n)
{
	for (int i = 0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<< matrix[i][j] << " ";
		}
		cout<< endl;
	}
}

void BalanceWord(string word)
{
	int n = word.length();
	if (n%2==1){
		cout<<"No es balanceado" << endl;
	}	
	else {
		string first, second;
		int d = word.length()/2;
		for (int i=0; i<n; i++){
			if (i<d){
				first += word[i];
			}
			else {
				second += word[i];
			}
		}
		cout<< first << endl;
		cout<< second << endl;
		int counter = d-1;
		bool comp;
		for (int i=0; i<d; i++){
			if (first[i]=='(' && second[counter]==')'){
				comp = true;
				counter--;
			}
			else if (first[i]=='{' && second[counter]=='}'){
				comp= true;
				counter--;
			}
			else if (first[i]=='[' && second[counter]==']'){
				comp = true;
				counter--;
			}
			else {
				comp = false;
				break;
			}
		}
		if (comp==false){
			cout<<"No esta balanceado" << endl;
		}
		else {
			cout<<"Esta banlaceado" << endl;
		}
	}
}
