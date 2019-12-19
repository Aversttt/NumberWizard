#pragma once
#include <string>




class FBullCowGame {
public:
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	bool CheckGuessValidity(std::string);
	void Reset(); //todo make a more rich return value.
 


//inore this, focus this^^^^
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	

};