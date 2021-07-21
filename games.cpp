#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "guessTheNumber.h"
#include "ticTacToe.h"
#include "hangman.h"
#include "highscores.h"


void resetInputStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int main()
{
	int choice;
		do
		{
			std::cout<<" Select Games \n\0"<<std::endl;
			std::cout<<" 1. guessTheNumber \0"<<std::endl;
			std::cout<<" 2. ticTacToe \0"<<std::endl;
			std::cout<<" 3. hangman \0"<<std::endl;
			std::cout<<" 4. Quit \0"<<std::endl;
			std::cout<<"\n Enter choice : \0";
			if(std::cin>>choice)
			{
				switch(choice)
				{
					case 1 :
						system("cls"); // not recommended as it gives admin privilage to the programs 
						guessTheNumber::gameMenu();
						system("cls"); // not recommended as it gives admin privilage to the programs
		 				break;
		 			case 2 :
		 				system("cls");
		 				ticTacToe::gameMenu();
		 				system("cls");
		 				break;
		 			case 3 :
		 				system("cls");
		 				hangman::gameMenu();
		 				system("cls");
		 				break;
					case 4 :
						std::cout<<" Thanks For Playing :)\0"<<std::endl;
						return 0;
					default :
						std::cout<<" Invalid Input!!\n\n\0"<<std::endl;
						break;
				}
			}
			else
				resetInputStream();
		}while(true);
	return 0;
}