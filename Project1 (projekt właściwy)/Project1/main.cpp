/*This is the console ecectusane tehat meka edus nwsjdknadnajdaws
this acts adjfnaskakajdad
coœ tam coœ
losowy tekst

*/

#pragma once
#include <iostream>
#include "FBullCowGame.h"
#include <string>

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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


	
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "tu jest byk                         a tu krowka" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();


	//loop whsbdadsad
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess(); //TODO MAKE LOOP

		
		//submit valid guess
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//print32 namber od krwfnskd


		std::cout << "bulls = " << BullCowCount.Bulls;
		std::cout << "cows = " << BullCowCount.Cows << "\n\n";
		
	}
	
	PrintGameSummary();
	
	return;
}
//cpstam TODO


// get a guess form player
FText GetValidGuess() {
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try" << CurrentTry << "of" << BCGame.GetMaxTries(); 
		std::cout << "wpisz odpowiez";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "please enter a " << BCGame.GetHiddenWordLength() << "letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "please a enter without powtarzania liter\n.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "wez pisz malymi literami.\n.\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK); //keep looping adnjandasd
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary(); {
	if (BCGame.IsGameWon()) {
		std::cout << "no dobrze\n";
	}
	else {
		std::cout << "przegranko\n";
	}
}