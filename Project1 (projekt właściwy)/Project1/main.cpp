/*This is the console ecectusane tehat meka edus nwsjdknadnajdaws
this acts adjfnaskakajdad
coœ tam coœ
losowy tekst

*/


#include <iostream>
#include "FBullCowGame.h"
#include <string>

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//the entry point3232 for app
int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		//todod
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	return 0; //exit the application
}  


//introduce the game
void PrintIntro() {


	constexpr int32 WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();


	//loop whsbdadsad
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess(); //TODO MAKE LOOP

		//submit valid guess
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//print32 namber od krwfnskd
		std::cout << "bulls = " << BullCowCount.Bulls;
		std::cout << "cows = " << BullCowCount.Cows << std::endl;
		
		std::cout << std::endl;
	}
}
//cpstam TODO


// get a guess form player
FText GetGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();
	
	std::cout << "Try" << CurrentTry << " enter your guess: ";
	FText Guess = "";
	
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Resoponse[0] == 'Y');
}
