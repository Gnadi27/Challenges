#include <iostream>

using namespace std;

void check_guess(const int secret_number, const int guess, bool* checker);

int main() {
	int secret_number;
	int guess;
	char cont; //Ask Guesser if he wants to continue
	bool checker[3] = { 0,0,0 }; //Übereinstimmende Stellen
	int i=0; //Anzahl der Versuche

	cout << "Input your secret number (3 digits)" << endl;
	cin >> secret_number; //better: check for correct input
	cout << endl;

	do {
		cout << "Input your guess number: " << i << " (3 digits)" << endl; //beter: 1st 2nd 3rd
		cin >> guess;

		check_guess(secret_number, guess, checker);
		cout << checker[0] << checker[1] << checker[2] << endl;

		cout << "Wanna Continue(y/n)?\n" << "You have " << 10 - i << " trys left\n"; // check for correct input
		cin >> cont;
		i++;
	} while (i <= 10 && cont);

	system("pasue");
	return 0;
}

void check_guess(const int secret_number, const int guess, bool* checker){
	int i = 100;
	while (i > 0) {
		switch (i){
			case 100:
				checker[0] = (guess / i == secret_number / i);
				break;
			case 10:
				checker[1] = (guess / i == secret_number / i);
				break;
			case 1:
				checker[2] = (guess / i == secret_number / i);
				break;
		}
		i = i / 10;
	}
}