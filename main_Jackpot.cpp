#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Start();
void GetResults();

int i, j, life, maxrand;
char c;

void Start() {
	i = 0;
	j = 0;
	life = 0;
	maxrand = 6;
	
	cout << "Selecciona el modo de dificultad:\n"; // the user has to select a difficutly level
	cout << "1 : Facil (0-15)\n";
	cout << "2 : Medio (0-30)\n";
	cout << "3 : Dificil (0-50)\n";
	cout << "o escriba una letra para salir\n";
	c = 30;

	cin >> c;                   // read the user's choice
	cout << "\n";

	switch (c) {
		case '1':
			maxrand = 15;  // the random number will be between 0 and maxrand
			break;
		case '2':
			maxrand = 30;
			break;
		case '3':
			maxrand = 50;
			break;
		default:
			exit(0);
		break;
	}

	life = 6;         // number of lifes of the player
	srand((unsigned)time(NULL)); // init Rand() function
	j = rand() % maxrand;  // j get a random value between 0 and maxrand
	
	GetResults();
}

void GetResults() {
	if (life <= 0) { // if player has no more life then he loses
		cout << "Tu pierdes !\n\n";
		Start();
	}

	cout << "Escribe un numero: \n";
	cin >> i;
	
	if((i>maxrand) || (i<0)) { // if the user number isn't correct, restart
		cout << "Error: solo numeros entre 0 y \n" << maxrand<<endl;
		GetResults();
	}

	if(i == j) {
		cout << "TU GANAS!\n\n"; // the user found the secret number
		Start();
	} else if(i>j) {
		cout << "Demasiado grande\n";
		life = life - 1;
		cout << "Vidas restantes: " << life << "\n\n";
		GetResults();
	} else if(i<j) {
		cout << "Demasiado pequenio\n";
		life = life - 1;
		cout << "Vidas restantes: " << life << "\n\n";
		GetResults();
	}
}

int main() {
	cout << "** Jackpot game **\n";
	cout << "El objetivo de este juego es adivinar un numero.\n";
	cout << "Jackpot te dira si el numero es demasiado grande o demasiado\n";
	cout << "pequenio en comparacion con el numero secreto a encontrar.\n\n";
	Start();
	return 0;
}
