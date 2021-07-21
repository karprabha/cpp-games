Games: games.o guessTheNumber.o ticTacToe.o hangman.o highscores.o
	g++ -std=c++14 games.o guessTheNumber.o ticTacToe.o hangman.o highscores.o -o Games

games.o: games.cpp
	g++ -std=c++14 -c games.cpp

guessTheNumber.o: guessTheNumber.cpp
	g++ -std=c++14 -c guessTheNumber.cpp

ticTacToe.o: ticTacToe.cpp
	g++ -std=c++14 -c ticTacToe.cpp

hangman.o: hangman.cpp
	g++ -std=c++14 -c hangman.cpp

highscores.o: highscores.cpp
	g++ -std=c++14 -c highscores.cpp

clean:
	-del *.o Games.exe *.txt