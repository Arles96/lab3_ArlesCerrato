#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

//Funcion para ingresar minar a la matriz
char** MinesMatrix(char** , int);
//Funcion para llenar la matriz
void FillInMatrix(char** , int);
//Funcion para llenar la matriz de juego
void FillInMatrix2(char**, int);
//Impresion de matriz
void PrintMatrix(char**, int);
//balanceo de la cadena
void BalanceWord(string);
//funcion para los 0 y los 1
char** NumberMatrix(char**, int);
//Liberar Memoria
void DeleteMemory(char**, int);

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
			char** matrixGame = new char*[n];
			for (int i=0; i<n; i++){
				matrixGame[i] = new char [n];
			}
			//llenado de matriz
			FillInMatrix(matrix,n);
			FillInMatrix(matrixGame, n);
			//PrintMatrix(matrix,n);
			//cout<< endl;
			//Ingreso de minas
			matrix = MinesMatrix(matrix,n);
			//PrintMatrix(matrix,n);
			//cout<< endl;
			matrix = NumberMatrix(matrix,n);
			//PrintMatrix(matrix,n);
			//cout<< endl;
			cout<<"Comienza el juego" << endl;
			int x,y;
			//Verificador del juego si gano el usuario
			bool v;
			while (true){
				cout<<"Ingrese la posicion x: ";
				cin>>x;
				while (x<0 || x>n-1){
					cout<<"Error" << endl;
					cout<<"Ingrese la posicion x: ";
					cin>>x;
				}
				cout<<"Ingrese la posicion y: ";
				cin>>y;
				while (y<0 || y>n-1){
					cout<<"Error" << endl;
					cout<<"Ingrese la posicion y: ";
					cin>>y;
				}
				if (matrix[x][y]=='1'){
					matrixGame[x][y] = '1';
					PrintMatrix(matrixGame,n);
				}
				else if (matrix[x][y]=='*'){
					matrixGame[x][y]='*';
					PrintMatrix(matrix, n);
					cout<<"Has Perdido" << endl;
					break;
				}
				else if (matrix[x][y]=='0'){
					
				}
				for (int i=0;i<n;i++){
					for (int j=0; j<n;j++){
						if (matrixGame[i][j]=='s'){
							v = true;
							break;
						}
						else {
							v = false;
						}
					}
					if (v==true){
						break;
					}
				}
				if (v==false){
					cout<<"Has ganado el juego" << endl;
					break;
				}
				
			}
			DeleteMemory(matrix,n);
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
			matrix[i][j]= '0';
		}
	}
}

void FillInMatrix2(char** matrix, int n)
{
	for (int i=0; i<n; i++){
		for (int j=0; j<n;j++){
			matrix[i][j]='s';
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
	cout<< endl;
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

char** NumberMatrix(char** matrix, int n)
{
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (matrix[i][j]=='*'){
				//primer esquina
				int f11 = i-1;
				int f12 = j-1;
				if ((f11>=0 && f11<n) && (f12>=0 &&f12<n))
					matrix[f11][f12] = '1';
				//arriba
				int f2 = i-1;
				if (f2>=0 && f2<n)
					matrix[f2][j]='1';
				//Segunda esquina
				int f31 = i-1;
				int f32 = j+1;
				if ((f31>=0 && f31<n) && (f32>=0 && f32<n))
					matrix[f31][f32]='1';
				//lado izquierdo
				int f4 = j-1;
				if (f4>=0 && f4<n)
					matrix[i][f4] = '1';
				//lado derecho
				int f5 = j+1;
				if (f5>=0 && f5<n)
					matrix[i][f5]='1';
				//tercera esquina
				int f61 = i+1;
				int f62 = j-1;
				if ((f61>=0 && f61<n) && (f62>=0 && f62<n))
					matrix[f61][f62]='1';
				//abajo
				int f7 = i+1;
				if (f7>=0 && f7<n)
					matrix[f7][j] = '1';
				//cuarta esquina
				int f81 = i+1;
				int f82 = j+1;
				if ((f81>=0 && f81<n) && (f82>=0 && f82<n))
					matrix[f81][f82]='1';
			}
		}
	}
	return matrix;
}

void DeleteMemory(char** matrix, int n)
{
	for (int i=0;i<n; i++){
		delete [] matrix[i];
		matrix[i] = NULL;
	}
	delete [] matrix;
}
