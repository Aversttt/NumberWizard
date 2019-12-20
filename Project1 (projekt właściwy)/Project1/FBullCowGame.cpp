#pragma once
#include "FBullCowGame.h"
#include <map>

#define TMap std::map
using int32 = int;


FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const;
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };		
	return WordLengthToMaxTries[MyHiddenWord.length()];		
}	


void FBullCowGame::Reset();{
	const FString HIDDEN_WORD = "plane";
	MyHiddenWord = HIDDEN_WORD;		


	MyCurrentTry = 1;
	bGameIsWon = false;
	return;		
}





EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.Length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}
//awsdawdawd
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLenght; MHWChar++) {
		for (int32 GChar = 0; GChar < WordLenght; GChar++) {
			if (Guess[MHWChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar); {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLenght) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString) const
{
	if (Word.Length() <= 1) {
		return true;
	}
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;

		}
		else {
			LetterSeen[Letter] = true;
		}
	}

		return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
