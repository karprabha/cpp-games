#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <iomanip>
#include "ticTacToe.h"

namespace ticTacToe{
	
	char mark = 'X';
	char box[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	int count=0,gameMode,playerX_Wins=0,playerO_Wins=0;
	std::string playerX_Name="Player",playerO_Name="Player";
	bool gameOver=false,playerX_Turn=true;

	void resetInputStream()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	} 

	int randomNumber()
	{
		return rand()%9 + 1;
	}

	void gameIntro()
	{
		std::cout<<"\n\t\t _______    _____      _______        _____      _______  _____   _____"<<std::endl;
		std::cout<<"\t\t    |    | |              |     /\\   |              |    |     | | "<<std::endl;
		std::cout<<"\t\t    |    | |       --     |    /--\\  |       --     |    |     | |----"<<std::endl;
		std::cout<<"\t\t    |    | |_____         |   /    \\ |_____         |    |_____| |_____"<<std::endl;
		std::cout<<"\n How to play : \n\n To Mark your option press respective number given in each slot of the Board (Tip : Use Numpad) \n"<<std::endl;
		std::cout<<"       |       |       "<<std::endl;
		std::cout<<"   7   |   8   |   9   "<<std::endl;
		std::cout<<"_______|_______|_______"<<std::endl;
		std::cout<<"       |       |       "<<std::endl;
		std::cout<<"   4   |   5   |   6   "<<std::endl;
		std::cout<<"_______|_______|_______"<<std::endl;
		std::cout<<"       |       |       "<<std::endl;
		std::cout<<"   1   |   2   |   3   "<<std::endl;
		std::cout<<"       |       |       "<<std::endl;
	}

	void boardRefresh()
	{
		int i;
		for(i=0;i<10;i++)
		{
			box[i]=' ';
		}
	}

	void boardDisplay()
	{
		system("cls"); //Use of system("cls") is not recomended as it gives program admin privilage.
		if(gameMode==1)
			std::cout<<" "<<playerX_Name<<" : "<<playerX_Wins<<" wins "<<std::setw(10)<<playerO_Name<<" : "<<playerO_Wins<<" wins"<<std::endl;

		std::cout<<"       |       |       "<<std::endl;
		std::cout<<"   "<<box[7]<<"   |   "<<box[8]<<"   |   "<<box[9]<<"   "<<std::endl;
		std::cout<<"_______|_______|_______"<<std::endl;
		std::cout<<"       |       |       "<<std::endl;
		std::cout<<"   "<<box[4]<<"   |   "<<box[5]<<"   |   "<<box[6]<<"   "<<std::endl;
		std::cout<<"_______|_______|_______"<<std::endl;
		std::cout<<"       |       |       "<<std::endl;
		std::cout<<"   "<<box[1]<<"   |   "<<box[2]<<"   |   "<<box[3]<<"   "<<std::endl;
		std::cout<<"       |       |       "<<std::endl;
	}

	void result(char gameDecision)
	{
		if(gameDecision == 'D')
		{
			std::cout<<"\n Draw !!"<<std::endl;
		    gameOver = true;
		}
		else if(gameDecision == 'W')
		{
			if(gameMode == 1){
				if(mark=='X')
				{
					std::cout<<playerX_Name<<" is winner!!"<<std::endl;
					playerX_Wins++;
				}
				else
				{
					std::cout<<playerO_Name<<" is winner!!"<<std::endl;
					playerO_Wins++;
				}
			}
				
			else
			{
				if(mark == 'X') 
					std::cout<<"\n You\a are winner !!"<<std::endl;
				else
					std::cout<<"\n Sorry, Computer\a is winner !!"<<std::endl; 
			}
			gameOver = true;
		}
	}

	void gameLogic()
	{
		if(box[1]==mark&&box[2]==mark&&box[3]==mark)
			result('W');
		else if(box[4]==mark&&box[5]==mark&&box[6]==mark)
			result('W');
		else if(box[7]==mark&&box[8]==mark&&box[9]==mark)
			result('W');
		else if(box[1]==mark&&box[4]==mark&&box[7]==mark)
			result('W');
		else if(box[2]==mark&&box[5]==mark&&box[8]==mark)
			result('W');
		else if(box[3]==mark&&box[6]==mark&&box[9]==mark)
			result('W');
		else if(box[1]==mark&&box[5]==mark&&box[9]==mark)
			result('W');
		else if(box[3]==mark&&box[5]==mark&&box[7]==mark)
			result('W');
		else if(count==9)
			result('D');
	}

	void assignMark(int choice)
	{
		if(choice==1)
			box[1]=mark;
		else if(choice==2)
			box[2]=mark;
		else if(choice==3)
			box[3]=mark;
		else if(choice==4)
			box[4]=mark;
		else if(choice==5)
			box[5]=mark;
		else if(choice==6)
			box[6]=mark;
		else if(choice==7)
			box[7]=mark;
		else if(choice==8)
			box[8]=mark;
		else if(choice==9)
			box[9]=mark;
	}

	int input()
	{
		switch(_getch())
		{
			case '1': return 1;
			case '2': return 2;
			case '3': return 3;
			case '4': return 4;
			case '5': return 5;
			case '6': return 6;
			case '7': return 7;
			case '8': return 8;
			case '9': return 9;
			default : return 0;
		}
	}

	void ticTacToe()
	{
		int choice;

		if(playerX_Turn==true)
		{
			std::cout<<"\n "<<playerX_Name<<", It's your Turn : ";
			choice=input();
		}
		else
		{
			if(gameMode==1)
			{
				std::cout<<"\n "<<playerO_Name<<", It's your Turn : ";
			    choice=input();
			}
			else
			{
				std::cout<<"\n Computer's Turn "<<mark<<" : ";
				choice=randomNumber();
			}
		}

		std::cout<<"\n"<<std::endl;

		if(box[choice]==' '&&choice!=0)
		{
			count++;
			assignMark(choice);
			boardDisplay();
			if(count>=5)
				gameLogic();
	        if(playerX_Turn==true)
	        {
	        	playerX_Turn=false;
	        	mark='O';
	        }
	        else
	        {
	        	playerX_Turn=true;
	        	mark='X';
	        }
		}
	}

	void gameModes()
	{
		if(gameMode==1)
		{
			int choice,totalRounds;
			std::cout<<" Select Number of Rounds for Match : \n 1. 3 Rounds\n 2. 5 Rounds\n 3. 10 Rounds\n 4. 20 Rounds\n\n Enter Choice : \0";
			if(std::cin>>choice)
			{
				switch(choice)
				{
					case 1 : totalRounds = 3;
							 break;
					case 2 : totalRounds = 5;
							 break;
					case 3 : totalRounds = 10;
							 break;
					case 4 : totalRounds = 20;
							 break;
				}
				resetInputStream();//making sure no garbage is there in inputstream
				std::cout<<"\n Player X Enter Your Name : ";
				getline(std::cin,playerX_Name);
				std::cout<<"\n Player O Enter Your Name : ";
				getline(std::cin,playerO_Name);

				for(int i=0;i<totalRounds;i++)
				{
					char markCopy=mark;
					boardDisplay();
					while(!gameOver)
	  		    	{
			    		ticTacToe();
			    	}
			    	std::cout<<"\n Press any key to continue..."<<std::endl;
			    	_getch();
			    	boardRefresh();
					if(markCopy=='X'){
						mark='O';
						playerX_Turn=false;
					}
					else{
						mark='X';
						playerX_Turn=true;
					}
			    	count=0;
			    	gameOver=false;
				}

				system("cls");
				std::cout<<"\n Results : \n\t"<<playerX_Name<<" : "<<playerX_Wins<<" wins "<<std::setw(10)<<playerO_Name<<" : "<<playerO_Wins<<" wins"<<std::endl;
				if(playerX_Wins>playerO_Wins)
					std::cout<<"\n\a "<<playerX_Name<<" won the series !!"<<std::endl;
				else if(playerX_Wins<playerO_Wins)
					std::cout<<"\n\a "<<playerO_Name<<" won the series !!"<<std::endl;
				else
					std::cout<<"\n Series Tied"<<std::endl;

				mark='X';
				playerX_Turn=true;
				playerX_Wins=0;
				playerO_Wins=0;
				playerO_Name="Player";
				playerX_Name="Player";
			}
			else
			{
				std::cout<<"\n Invalid Choice !!"<<std::endl;
				resetInputStream();
			}
		}
		else
		{
			boardDisplay();
			while(!gameOver)
		 	{
				ticTacToe();
			}
			boardRefresh();
			mark='X';
			count=0;
			gameOver=false;
			playerX_Turn=true;
		}
	}

	int gameMenu()
	{
		bool menu = true;
		srand(time(NULL));

		gameIntro();

		while(menu)
		{
			std::cout<<"\n\n Select Game Mode : \n\n 1. Player Vs Player (Press 1) \n 2. Computer Vs Player (Press 2) \n\n Exit Game (Press 3) \n\n Enter Choice : ";
		    
		    if(std::cin>>gameMode)
		    {
		    	switch(gameMode)
		    	{
		    		case 1 :
		    		case 2 : 
		    				system("cls");// Not recommended as it gives admin privilage to program
		    				gameModes();
					    	break;
					case 3 : 
							std::cout<<"\n Thanks For Playing :)";
							menu=false;
		    				break;
		    		default :
		    				std::cout<<"\n Invalid Input !!";
		    				break;
		        }
		    }
		    else
		    	resetInputStream();	
		}
		_getch();
		
		return 0;
	}
}