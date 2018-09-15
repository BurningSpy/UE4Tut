/* This is the console executable that makes use of the BUllCow class
This acts as the view in a MVC Pattern and it ´s responsible for all user interaction
for game logic, see the FBullCow Class*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCow.h"

//to make Syntax Unreal friendly
using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCow BCGame;

int main()
{
	bool bWantsToPlay = false;
	do 
	{
		
		//introduce the game
		PrintIntro();
		PlayGame();


		bWantsToPlay = AskToPlayAgain();

	} while (bWantsToPlay);

	/*int32 pause = 0;
	std::cin >> pause;*/

	return 0;
}

void PlayGame()
{

	int32 MaxTries = BCGame.GetMaxTries();


	//loop while game is NOT won and there are tries remaining

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
		{
		FText Guess = GetValidGuess();

		//submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//Check & Print Bulls and Cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << "your guess was: " << Guess << "\n";
		}

	PrintGameSummary();
	BCGame.Reset(); // TODO Make game summary
	return;
}

//Intro to the game
void PrintIntro()
{
	std::cout << std::endl << "Welcome to B&C\n" << std::endl;
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "\nCan you guess the " << BCGame.GetHiddenWordLength() << " letter isogram?" << std::endl;
	return;
}

//get a guess from player
//loop until user gives valid guess, then return guess
FText GetValidGuess()
{ 
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	//keep looping until we get no errors
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try" << CurrentTry << " of " << BCGame.GetMaxTries() << " Please enter a guess!\n";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter isogram.\n\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (no repeated letters). \n\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please write all in lowercase.\n\n";
			break;

		default:
			//assume valid guess
			break;
		}
	} while (Status != EGuessStatus::OK);

	return Guess;
}


bool AskToPlayAgain()
{
	FText Answer = "";
	std::cout << "\nWould you like to play again? (y/n) \n";
	std::getline(std::cin, Answer);

	if (Answer[0] == 'y' || Answer[0] == 'Y')
	{
		return true;
	}
	else if (Answer[0] == 'n' || Answer[0] == 'N')
	{
		return false;
	}
	else if ((Answer[0] != 'n' || Answer[0] != 'N')&& (Answer[0] != 'y' || Answer[0] != 'Y'))
	{
		std::cout << "Y= Yes, N = No \n";
		
	}
	return AskToPlayAgain();
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon() == true)
	{
		std::cout << "\nCongrats, You won the game! \n";
	}
	else 
	{ 
		std::cout << "\nHaha! You suck! Try again! \n";
	}
	return;
}