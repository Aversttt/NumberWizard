#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

//the entry point for app
int main()
{
	PrintIntro();
	PlayGame();
	cout << AskToPlayAgain();
	return 0; //exit the application
}  


//introduce the game
void PrintIntro() {


	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}


// get a guess form player
string GetGuess() {
	
	cout << "enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	//print the guess back to them
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "do you want to play again?";
	string Response - "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Resoponse[0] == 'Y');
}
