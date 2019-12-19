
#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;


	constexpr FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;


	int MyCurrentTry = 1;
	
	return;
}



bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
//awsdawdawd
FBullCowCount FBullCowGame::SubmitGuess(FString) {
	//jasdasda
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLenght = MyHiddenWord.lenght();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) {

		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) {
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

	return BullCowCount;
}
