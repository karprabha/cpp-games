#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <iomanip>
#include "highscores.h"

namespace highscore
{
	void fileRead(std::vector<std::string> &names,std::vector<double> &scores,std::string gameName)
	{
		std::string name;
		double score;

		std::ifstream inFile(gameName+"highscores.txt");

		if(!inFile)
		{
			inFile.open(gameName+"highscores.txt",std::ios::app);
		}

		if(inFile.is_open())
	    {
			while(getline(inFile,name))
			{
				name.erase(0,8); //length of " Name : " is  8 characters (names are stored as - Name : XYZ)
				names.push_back(name);
				inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //ignoring scores (data is stored as - name ,score alternatively)
			}
		
			inFile.clear(); //setting eof to goodbit
		    inFile.seekg(0, std::ios::beg); // putting cursor at begining 
		
		    while(!inFile.eof())
			{
				if(inFile>>score)
				{
					scores.push_back(score);
				}
				else
				{
					inFile.clear(); //removing error flag 
					inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//clearing invalid characters from stream
				}
			}
		}
		else
		{
			std::cout<<" ERROR !! System is unable to read file "<<std::endl;
		}	

		inFile.close();
	}

	void highscoreBoard(std::vector<std::string> &names,std::vector<double> &scores)
	{
		for(int i=0;i<scores.size()-1;i++)
		{
		    int minIndex=i;
		   	for(int j=i+1;j<scores.size();j++)
		   	{
		   		if(scores[j]>scores[minIndex])
		   			minIndex=j;
	    	}
		   	double tempScore = scores[i];
		   	scores[i]=scores[minIndex];
	    	scores[minIndex]=tempScore;

		   	std::string tempName = names[i];
	    	names[i]=names[minIndex];
	    	names[minIndex]=tempName;
		}
	}

	void fileWrite(std::vector<std::string> &names,std::vector<double> &scores,std::string gameName)
	{
		int highscoreIndex;
		scores.size()<=10?highscoreIndex = scores.size():highscoreIndex =10;

		std::ofstream oFile(gameName+"highscores.txt");

		if(oFile.is_open())
		{
			for(int i=0;i<highscoreIndex;i++)
			{
				oFile<<" Name : "<<names[i]<<std::endl;
		        oFile<<"\t"<<scores[i]<<" Points"<<std::endl;
			}
		}
		else
		{
			std::cout<<" ERROR !! System is unable to write file"<<std::endl;
		}

		oFile.close();
	}

	void displayHighscores(std::vector<std::string> &names,std::vector<double> &scores)
	{
		int highscoreIndex;
		scores.size()<=10?highscoreIndex = scores.size():highscoreIndex =10;

		std::cout<<"\n Highscores : \n"<<std::endl;

		for(int i=0;i<highscoreIndex;i++)
		{
			std::cout<<std::setw(3)<<i+1<<")"<<std::setw(20)<<names[i]<<std::setw(2)<<" : "<<std::setw(15)<<scores[i]<<" Points"<<std::endl;
		}
	}

	int highscore(double score ,std::string gameName)
	{
		std::vector<std::string> names;
		std::vector<double> scores;
		std::string name;
		bool validName;

		fileRead(names,scores,gameName);

		std::cout<<" Enter Your Name : ";

		do
		{
			getline(std::cin,name);
			validName = true; 
			for(std::string existingName : names)
		    {
		    	if(name==existingName)
		    	{
		    		std::cout<<"\n "<<name<<" is already an existing name.\n Enter different name : ";
		    		validName = false;
		    		break;
		    	}
			}
		}while(!validName);

		names.push_back(name);	

	    scores.push_back(score);

	    if(score>scores[0]||scores.size()==1)
	    {
	    	std::cout<<"\n\a New highscore !!  \n Name : "<<name<<"\n Score : "<<score<<" Points \n\0"<<std::endl;
	    	highscoreBoard(names,scores);
	    	fileWrite(names,scores,gameName);
	    }
	    else if(score==scores[0])
	    {
	    	std::cout<<"\n\a Highscore Tied :)\0"<<std::endl;
	    	highscoreBoard(names,scores);
	    	fileWrite(names,scores,gameName);
	    }
	    else if(score>scores[scores.size()-2]||(scores.size()<10)) // extra -1 because excluding itself from vector length
	    {
	    	std::cout<<"\n\a Congratulations you made it to the TOP 10 "<<std::endl;
	    	highscoreBoard(names,scores);
	    	fileWrite(names,scores,gameName);
	    }

	    displayHighscores(names,scores);
	    return 0;
	}
}