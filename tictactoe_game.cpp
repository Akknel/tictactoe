#include <iostream>
#include <cstdlib>
using namespace std;

//Check for full field
int dots(int square[][3], int N) {
	int dot = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (char(square[i][j]) != '.') dot++;
		}
		if (dot == N * N) return true;
	}
	return false;
}
//Horizontal and vertical lines
int horver(int square[][3], int player, int N) {
	for (int i = 0; i < N; i++) {
		int counter1 = 0;
		for (int j = 0; j < N; j++) {
			if (char(square[i][j]) == player) counter1++;
		}
		if (counter1 == N) {
			return true;
		}
	}
	for (int i = 0; i < N; i++) {
		int counter2 = 0;
		for (int j = 0; j < N; j++) {
			if (char(square[j][i]) == player) counter2++;
		}
		if (counter2 == N) {
			return true;
		}
	}
	return false;
}
//Diagonal 1 and 2
int diag(int square[][3], int player, int N) {
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (square[i][i] == player) counter++;
	}
	if (counter == N) return true;
	else counter = 0;
	for (int i = 0; i < N; i++) {
		if (square[i][N - 1 - i] == player) counter++;
	}
	if (counter == N) return true;
	else return false;
}
//Show field
void field(int square[][3], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << char(square[i][j]) << " ";
		}
		cout << endl;
	}
}

int main() {
	const int N = 3;
	int square[N][N];
	//We create field
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			square[i][j] = '.';
		}
	}
	char player1 = 'x', player2 = 'o';
	int a1, a2, b1, b2;
	while (true) {
		//Player 1 makes move
		while (true) {
			cout << "Player No 1 movement: ";
			cin >> a1 >> b1;
			if (char(square[a1][b1]) == '.') {
				square[a1][b1] = player1;
				system("cls");
				break;
			}
			else cout << "This field is already used!" << endl;
		}
		//Show field
		field(square, N);
		//Diagonal 1 and 2
		if (diag(square, player1, N) == true) {
			cout << "Player No 1 wins!!!";
			return 0;
		}
		//Horizontal and vertical lines
		if (horver(square, player1, N) == true) {
			cout << "Player No 1 wins!!!";
			return 0;
		}
		//Check for full field
		if (dots(square, N) == true) {
			cout << "Draw.";
			return 0;
		}
		//Player 2 makes move
		while (true) {
			cout << "Player No 2 movement: ";
			cin >> a2 >> b2;
			if (square[a2][b2] == '.') {
				square[a2][b2] = player2;
				system("cls");
				break;
			}
			else cout << "This field is already used!" << endl;
		}
		//Show field
		field(square, N);
		//Diagonal 1 and 2
		if (diag(square, player2, N) == true) {
			cout << "Player No 2 wins!!!";
			return 0;
		}
		//Horizontal and vertical lines
		if (horver(square, player2, N) == true) {
			cout << "Player No 2 wins!!!";
			return 0;
		}
		//Check for full field
		if (dots(square, N) == true) {
			cout << "Draw.";
			return 0;
		}
	}
}