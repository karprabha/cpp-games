#ifndef GUESS_THE_NUMBER
#define GUESS_THE_NUMBER

namespace guessTheNumber{
	int random();
	void resetInputStream();
	void showGuesses(std::vector<int> &guesses);
	double scoreCalculator(int chances);
	void guessTheNumber();
	int gameMenu();
}

#endif