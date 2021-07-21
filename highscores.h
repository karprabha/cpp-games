#ifndef HIGHSCORES

#define HIGHSCORES
namespace highscore
{
	void fileRead(std::vector<std::string> &names,std::vector<double> &scores,std::string gameName ="");
	void fileWrite(std::vector<std::string> &names,std::vector<double> &scores,std::string gameName = "");
	void highscoreBoard(std::vector<std::string> &names,std::vector<double> &scores);
	void displayHighscores(std::vector<std::string> &names,std::vector<double> &scores);
	int highscore(double score = 0,std::string gameName ="");
}
#endif