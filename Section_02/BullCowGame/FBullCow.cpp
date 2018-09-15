#pragma once
#include "FBullCow.h"
#include <map>
#define TMap std::map


using int32 = int;

FBullCow::FBullCow()
{
	Reset();
}

FBullCow::~FBullCow()
{
}



//Getters on Top

int32 FBullCow::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCow::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCow::IsGameWon() const { return bGameIsWon; }

int32 FBullCow::GetMaxTries() const { 
	TMap <int32, int32> WordLengthToMaxTries{ {3,3},{4,4},{5,5},{6,5} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; }

void FBullCow::Reset()
{
	MyCurrentTry = 1;
	bGameIsWon = false;

	const FString HIDDEN_WORD = "rip"; //Must be isogram
	MyHiddenWord = HIDDEN_WORD;


	return;
}


EGuessStatus FBullCow::CheckGuessValidity(FString Guess) const
{
	//if the guess isnt isogram, return error
	if (!IsIsogram(Guess)) 
	{
		return EGuessStatus::Not_Isogram; 
	}
	//if guess isnt all lowercase, return error
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase; 
	}
	//if wordlength is wrong, error
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	//otherwise return OK
	else
	{
		return EGuessStatus::OK;
	}
}

//receive a VALID guess and increments try, returns count
FBullCowCount FBullCow::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	//setup return variable
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length();
	//loop through all letters in the hidden word
	for (int32 i = 0; i < WordLength; i++) 
	{
		//compare letters against guess
		for (int32 j = 0; j < WordLength; j++)
		{
			//if they match then
			if (Guess[i] == MyHiddenWord[j])
			{
				//increment bulls if they´re in the same place
				if (i == j) { BullCowCount.Bulls++;	}
				
				//increment Cows if they´re not in the same place
				else { BullCowCount.Cows++; } 
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) { bGameIsWon = true;};

	return BullCowCount;
}

bool FBullCow::IsIsogram(FString Word) const
{
	//treat 0 and 1 letters as isograms
	if (Word.length() <= 1) { return true; };
	
	//Setup the Map
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) //for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case

		//write loop to check letters on map
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
			
	}
	return true;
}

bool FBullCow::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) //if not lowercase letter
		{
			return false;
		}
	}
	return true;
}

