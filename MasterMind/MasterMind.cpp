// MasterMind.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void Initialisation(char(&a_Rep)[5])
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		int temp = rand() % 8;
		if (temp == 0)
		{
			a_Rep[i] = 'a';
		}
		else if (temp == 1)
		{
			a_Rep[i] = 'b';
		}
		else if (temp == 2)
		{
			a_Rep[i] = 'c';
		}
		else if (temp == 3)
		{
			a_Rep[i] = 'd';
		}
		else if (temp == 4)
		{
			a_Rep[i] = 'e';
		}
		else if (temp == 5)
		{
			a_Rep[i] = 'f';
		}
		else if (temp == 6)
		{
			a_Rep[i] = 'g';
		}
		else if (temp == 7)
		{
			a_Rep[i] = 'h';
		}
	}
}


int main()
{
	char rep[5] = {};
	char board[8][5] = {};
	int right[8][2] = {};
	int victoire = 0;
	std::string playerRep;

	Initialisation(rep);

	std::cout << "Voici un jeu de Mastemind!" << std::endl;

	//Regle();

	for (int i = 0; i < 8; i++)
	{
		if (victoire == 0)
		{
			std::cout << "entrez votre reponse : ";
			std::cin >> playerRep;
			int tempRep = 0;
			for (int j = 0; j < 5; j++)
			{
				if (tempRep < 5 && (playerRep[j] == 'a' || playerRep[j] == 'b' || playerRep[j] == 'c' || playerRep[j] == 'd' || playerRep[j] == 'e' || playerRep[j] == 'f' || playerRep[j] == 'g' || playerRep[j] == 'h'))
				{
					board[i][tempRep] = playerRep[j];
					tempRep++;
				}
			}
			tempRep = 0;
			//Compare(rep, board[i], right[i], victoire);
			//ShowBoard(board, right);
			if (i != sizeof(board) / sizeof(board[0]))
			{
				//Regle();
			}
			
		}
		else
		{
			std::cout << "Victoire!!!!" << std::endl;
		}
	}

	if (victoire == 0)
	{
		std::cout << "Defaite!!!!" << std::endl;
	}
}



