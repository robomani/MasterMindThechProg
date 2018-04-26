// MasterMind.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void Compare(char rep[5], char board[5],int (&right)[2],int& victoire)
{
	int tempRight = 0;
	int tempMR = 0;
	char tempRep[5];
	char tembBoard[5];

	for (int i = 0; i < 5; i++)
	{
		tempRep[i] = rep[i];
		tembBoard[i] = board[i];
	}

	for (int i = 0; i < 5; i++)
	{
		if (tempRep[i] == tembBoard[i])
		{
			tempRight++;
			tempRep[i] = 'z';
			tembBoard[i] = 'y';
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (tempRep[i] != 'z' && tembBoard[j] != 'y' && tempRep[i] == tembBoard[j])
			{
				tempMR++;
				tempRep[i] = 'z';
				tembBoard[i] = 'y';
			}
		}	
	}

	if (tempRight == 5)
	{
		victoire = 1;
	}
	right[0] = tempRight;
	right[1] = tempMR;
}

void ShowBoard(char a_Board[][5], int a_right[][2])
{
	std::string ligne;
	std::string gameBoard;
	for (int i = 0; i < 8; i++)
	{
		ligne = "";
		gameBoard = "";
		for (int j = 0; j<5; j++)
		{
			gameBoard = gameBoard + a_Board[i][j] + " ";
			ligne += "--";
		}
		gameBoard += "| B " + std::to_string(a_right[i][0]) + " " + "| PB " + std::to_string(a_right[i][1]);
		std::cout << gameBoard << std::endl;
		std::cout << ligne << std::endl;
	}
}

void Regle()
{
	std::cout << "Vous devez entrer 5 lettres parmis celles-ci :(a/b/c/d/e/f/g/h) sans espaces" << std::endl;
	std::cout << "Laissez un espace entre chacune de vos lettres" << std::endl;
	std::cout << "Vous avez 8 essais pour trouver la combinaison secrete" << std::endl;
	std::cout << "Après chaque essais vous aurez 2 informations :  " << std::endl;
	std::cout << "1) Le nombre de bonne lettres au [B]on endroit" << std::endl;
	std::cout << "2) Le nombre de bonne lettres au mauvais endroit donc [PB] presque bon" << std::endl;
}

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

	Regle();

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
			Compare(rep, board[i], right[i], victoire);
			ShowBoard(board, right);
			if (i != sizeof(board) / sizeof(board[0]))
			{
				Regle();
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



