#ifndef HANGMAN_H
#define HANGMAN_H

namespace hangman{
	void display_emoji(int chances);
	void display_bot_appreciation(int guess_streak);
	bool createFile_movieName(void);
	bool readFile_movieName(std::vector<std::string> &movieNames);
	void reset_inputStream(void);
	int randomNumber(int total_movies);
	void display_gameInterface(std::vector<char> guesses,int chances,bool wrong_guess);
	void initialize_newMovie(std::vector<std::string> &movieNames,std::string &movieName,int &correct_guesses,std::vector<char> &guesses);
	int game_logic(const std::string &movieName,const char &guess,std::vector<char> &guesses,int &correct_guesses);
	void guess_input(char &guess);
	double game_score(int guess_streak = 0,int bonus_score = 0);
	bool check_result(std::vector<std::string> &movieNames,std::string &movieName,int &correct_guesses,std::vector<char> &guesses,int chances,bool wrong_guess,int guess_streak,double &score);
	bool check_duplicate_guess(const std::vector<char> &guesses,char guess);
	int play_hangman(void);
	int gameMenu(void);
}

#endif