#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cmath>
#include "hangman.h"
#include "highscores.h"

namespace hangman{
	void display_emoji(int chances){
		if(chances==5){
			std::cout<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"  .               .  "<<std::endl;
			std::cout<<std::setw(110)<<" .     O     O     . "<<std::endl;
			std::cout<<std::setw(110)<<" .                 . "<<std::endl;
			std::cout<<std::setw(110)<<" .     .     .     . "<<std::endl;
			std::cout<<std::setw(110)<<"  .     . . .     .  "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::endl;
		}
		else if(chances ==4){
			std::cout<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"  .               .  "<<std::endl;
			std::cout<<std::setw(110)<<" .     O     O     . "<<std::endl;
			std::cout<<std::setw(110)<<" .                 . "<<std::endl;
			std::cout<<std::setw(110)<<" .   .         .   . "<<std::endl;
			std::cout<<std::setw(110)<<"  .     . . .     .  "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::endl;
		}
		else if(chances ==3){
			std::cout<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"  .               .  "<<std::endl;
			std::cout<<std::setw(110)<<" .     O     O     . "<<std::endl;
			std::cout<<std::setw(110)<<" .                 . "<<std::endl;
			std::cout<<std::setw(110)<<" .                 . "<<std::endl;
			std::cout<<std::setw(110)<<"  .     . . .     .  "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::endl;
		}
		else if(chances ==2){
			std::cout<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"  .               .  "<<std::endl;
			std::cout<<std::setw(110)<<" .    O     ___    . "<<std::endl;
			std::cout<<std::setw(110)<<" .           ||    . "<<std::endl;
			std::cout<<std::setw(110)<<" .           ||    . "<<std::endl;
			std::cout<<std::setw(110)<<"  .     . . .     .  "<<std::endl;
			std::cout<<std::setw(110)<<"    . .       . .    "<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::endl;
		}
		else if(chances ==1||chances ==0){
			std::cout<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::setw(110)<<"    .           .    "<<std::endl;
			std::cout<<std::setw(110)<<"  .               .  "<<std::endl;
			std::cout<<std::setw(110)<<" .    ___   ___    . "<<std::endl;
			std::cout<<std::setw(110)<<" .    ||     ||    . "<<std::endl;
			std::cout<<std::setw(110)<<" .    ||     ||    . "<<std::endl;
			std::cout<<std::setw(110)<<"  .     . . .     .  "<<std::endl;
			std::cout<<std::setw(110)<<"    . .       . .    "<<std::endl;
			std::cout<<std::setw(110)<<"       . . . .       "<<std::endl;
			std::cout<<std::endl;
		}
	}

	void display_bot_appreciation(int guess_streak){
		if(guess_streak == 1)
			std::cout<<std::setw(89)<<" Bot - Good ";
		else if(guess_streak == 2)
			std::cout<<std::setw(91)<<" Bot - Impressive ";
		else if(guess_streak == 3)
			std::cout<<std::setw(92)<<" Bot - Unbelievable ";
		else if(guess_streak >=4)
			std::cout<<std::setw(95)<<" Bot - Amazing (Ahee Boi..)";
	}
	bool createFile_movieName(void){
		
		std::ofstream oFile("movies.txt");

		if(oFile.is_open()){
			std::cout<<"\n A new text file named movies has been created. Kindly put Movie names there to enjoy the game"<<std::endl;
			oFile<<"Movie Name 1\nMovie Name 2\nMovie Name 3\n     .\n     .\n     .\n and so on";
			oFile.close();
		}
		else{
			std::cout<<"\n ERROR !! Unable to Access File"<<std::endl;
			return false;
		}
		return true;
	}

	bool readFile_movieName(std::vector<std::string> &movieNames){
		std::string movieName;

		std::ifstream inFile("movies.txt");

		if(!inFile){
			createFile_movieName();
			return false;
		}

		if(inFile.is_open()){
			while(getline(inFile,movieName)){
				movieNames.push_back(movieName);
			}

			inFile.close();
		}
		else{
			std::cout<<"\n ERROR !! Unable to read file ";
			return false;
		}

		return true;
	}
	void reset_inputStream(void){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	}

	int randomNumber(int total_movies){
		return rand()%total_movies;
	}

	void display_gameInterface(std::vector<char> guesses,int chances,bool wrong_guess,int guess_streak,double score){
		system("cls");
		std::cout<<std::setw(20)<<" Movie Name : ";
		for(auto guesses : guesses){
			std::cout<<guesses;
		}

		std::cout<<"\n Score : "<<score<<std::setw(95)<<" Chances Left : "<<chances<<std::endl;
		display_emoji(chances);
		std::cout<<" Guess streak : "<<guess_streak;
		display_bot_appreciation(guess_streak);

		/* 

		std::cout<<"\n Score : "<<score<<std::setw(70)<<" Guess streak : "<<guess_streak;
		display_bot_appreciation(guess_streak);
		std::cout<<"\n"<<std::setw(105)<<" Chances Left : "<<chances<<std::endl;


		if(wrong_guess)
			display_emoji(chances);
		*/
	}

	void initialize_newMovie(std::vector<std::string> &movieNames,std::string &movieName,int &correct_guesses,std::vector<char> &guesses){
		int random_movie_number=0;

		correct_guesses=0;
		guesses.clear();

		random_movie_number = randomNumber(movieNames.size());
		movieName=movieNames[random_movie_number];
		movieNames.erase(movieNames.begin()+random_movie_number); //ensuring that same name doesn't come up again

		for(int i=0;i<movieName.length();i++){
			guesses.push_back('-');
		}
	}

	int game_logic(const std::string &movieName,const char &guess,std::vector<char> &guesses,int &correct_guesses){

		int guess_not_matched=0;

		for(int i=0;i<movieName.length();i++){
			if(movieName[i]==guess){
				correct_guesses++;
				guesses[i] = movieName[i];
			}
			else if(isalpha(movieName[i])&&isalpha(guess)){
				if((movieName[i]==guess-32)||(movieName[i]==guess+32)){
					correct_guesses++;
					guesses[i] = movieName[i];
				}
				else
					guess_not_matched++;
			}
			else
				guess_not_matched++;
		}

		return guess_not_matched;
	}

	void guess_input(char &guess){
		std::cout<<"\n\n Your Guess : ";
		guess = _getch();
		std::cout<<guess;
	}

	double game_score(int guess_streak,int bonus_score){
		double score =0;
		if(guess_streak>0&&guess_streak<5){
			score = 20 + pow(4,guess_streak);
		}
		else if(guess_streak>=5){
			score = 20 + pow(4,4);
		}
		score += bonus_score;

		return score;
	}

	bool check_result(std::vector<std::string> &movieNames,std::string &movieName,int &correct_guesses,std::vector<char> &guesses,int chances,bool wrong_guess,int guess_streak,double &score){
		if(correct_guesses == movieName.length()){
			int correct_guess_bonus =300;
			score += game_score(0,correct_guess_bonus);
			if(movieNames.empty()){
				std::cout<<" You successfully Guessed all the Movie Names !! Well Played "<<std::endl;
				return true;
			}
			std::cout<<"\n\n\a Won !!\n\n Movie Name was : "<<movieName<<"\n\n Press any key to guess next Movie Name : "<<std::endl;
			_getch();
			initialize_newMovie(movieNames,movieName,correct_guesses,guesses);	
			display_gameInterface(guesses,chances,wrong_guess,guess_streak,score);
		}
		else if(chances==0){
			std::cout<<"\n\a Game Over !!\n\n Movie Name was : "<<movieName<<"\n"<<std::endl;
			return true;
		}

		return false;
	}

	bool check_duplicate_guess(const std::vector<char> &guesses,char guess){
		for(int i=0;i<guesses.size();i++){
			if(guess==guesses[i])
				return true;
			else if(isalpha(guesses[i])&&isalpha(guess)){
				if((guesses[i]==guess-32)||guesses[i]==guess+32)
					return true;
			}
		}
		return false;
	}

	int play_hangman(void){
		std::vector<std::string> movieNames;
		std::vector<char> guesses;
		std::string movieName;
		char guess;
		bool wrong_guess = true,game_over=false;
		int chances = 5,correct_guesses,guess_not_matched,guess_streak=0;
		double score=0;
		

		if(!readFile_movieName(movieNames)){
			std::cout<<"\n Press any Key to go Main Menu....\n\0"<<std::endl;
			_getch();
			system("cls"); // not recommended as it gives admin privilage to the programs
			return 0;
		}

		initialize_newMovie(movieNames,movieName,correct_guesses,guesses);
		display_gameInterface(guesses,chances,wrong_guess,guess_streak,score);

		while(!game_over){
			wrong_guess = false;

		  	guess_input(guess);
		  	if(check_duplicate_guess(guesses,guess)){
		  		std::cout<<std::endl;
		  		continue;
		  	}

			guess_not_matched = game_logic(movieName,guess,guesses,correct_guesses);
			if(guess_not_matched>=movieName.length()){
				chances--;
				std::cout<<"\a";
				wrong_guess = true;
				guess_streak=0;
			}
			else
				guess_streak++;
			
			score += game_score(guess_streak);
			display_gameInterface(guesses,chances,wrong_guess,guess_streak,score);
			game_over = check_result(movieNames,movieName,correct_guesses,guesses,chances,wrong_guess,guess_streak,score);
		}

		reset_inputStream(); //clearing stream so that no unwated input is left inside
		highscore::highscore(score,"hangman");
		std::cout<<"\n Press any Key to go Main Menu....\n\0"<<std::endl;
		_getch();
		system("cls"); // not recommended as it gives admin privilage to the programs

		return 0;
	}

	int gameMenu(void){

		srand(time(NULL));
		int choice;

		do{
			std::cout<<" hangman's Game Menu : \n\0"<<std::endl;
				std::cout<<" 1. Play Game\0"<<std::endl;
				std::cout<<" 2. Quit Game\0"<<std::endl;
				std::cout<<"\n Enter choice : \0";
			if(std::cin>>choice){
				switch(choice){
					case 1 : play_hangman();
							 break;
					case 2 : std::cout<<"\n Thanks for playing :) ";
							 return 0;
					default : std::cout<<"\n Invalid input";
							  break;
				} 
			}
			else
				reset_inputStream();
		}while(true);

		return 0;
	}
}