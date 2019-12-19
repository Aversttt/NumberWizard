#include <iostream>
#include <std::string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//the entry point for app
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	return 0; //exit the application
}  


//introduce the game
void PrintIntro() {


	constexpr int WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << endl;

	//loop whsbdadsad
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}


// get a guess form player
std::string GetGuess() {

	int CurrentTry = BCGame.GetCurrentTry();
	
	std::cout << "Try" << CurentTry << " enter your guess: ";
	std::string Guess = "";
	
	std::std::getline(std::cin, Guess);

	//print the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl;
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again? (y/n) ";
	std::string Response - "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Resoponse[0] == 'Y');
}
