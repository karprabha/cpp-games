 #include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "highscores.h"
#include "guessTheNumber.h"

namespace guessTheNumber{
	int random()
	{
		int randomNumber;
		randomNumber = rand()%101; // for 0 to 100 numbers
		return randomNumber;
	}

	void resetInputStream()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	}

	void showGuesses(std::vector<int> &guesses)
	{
		for(int i=0;i<guesses.size();i++)
		{
			std::cout<<" "<<guesses[i]<<"\t";
		}
		std::cout<<"\n"<<std::endl;
	}

	double scoreCalculator(int chances)
	{
		return 1000.0/chances;
	}

	void guessTheNumber()
	{
		std::vector<int> guesses;
		int answer,guess;
		double score;
		bool gameOver = false;
		answer=random();
		std::cout<<"\n Guess the Number \"X\"\0"<<std::endl;
		while(!gameOver)
		{
			std::cout<<" Guess : \0";
			if(std::cin>>guess)
			{
				guesses.push_back(guess);
				if(guess>answer)
					std::cout<<" "<<guess<<" is greater than \"X\"\0"<<std::endl;
				else if(guess<answer)
					std::cout<<" "<<guess<<" is less than \"X\"\0"<<std::endl;
				else if(guess==answer)
				{
					std::cout<<" Correct Answer!!. You took "<<guesses.size()<<" chances to guess it right\0"<<std::endl;
					std::cout<<"\n Your Guesses were : \0"<<std::endl;
					showGuesses(guesses);
					score=scoreCalculator(guesses.size());
					resetInputStream(); //clearing stream so that no unwated input is left inside
					highscore::highscore(score,"guessTheNumber");
					guesses.clear();
					std::cout<<"\n Press any Key to go Main Menu....\n\0"<<std::endl;
					_getch();
					system("cls"); // not recommended as it gives admin privilage to the programs
					gameOver=true;
				}
			}
			else
				resetInputStream();
		}
	}

	int gameMenu()
	{
		srand(time(NULL));

		int choice;
		do
		{
			std::cout<<" guessTheNumber's Game Menu : \n\0"<<std::endl;
			std::cout<<" 1. Play Game\0"<<std::endl;
			std::cout<<" 2. Quit Game\0"<<std::endl;
			std::cout<<"\n Enter choice : \0";
			if(std::cin>>choice)
			{
				switch(choice)
				{
					case 1 : 
						guessTheNumber();
		 				break;
					case 2 :
						std::cout<<" Thanks For Playing :)\0"<<std::endl;
						return 0;
					default :
						std::cout<<" Invalid Input!!\n\n\0"<<std::endl;
						break;
				}
			}
			else
				resetInputStream();
		}
		while(true);

		return 0;
	}
}