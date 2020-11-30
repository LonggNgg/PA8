/*
	Name: Long Nguyen
	Assignment: PA8
*/

#include "Gameboard.h"

Gameboard::Gameboard()
{
	int index_rows = 0, index_cols = 0;

	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		for (index_cols = 0; index_cols < 10; ++index_cols)
		{
			gameboard[index_rows][index_cols] = '~';
		}
	}
}

void Gameboard::GameRules()
{
	std::cout << "*****Welcome to Battleship!*****\n\n";
	std::cout << "Rules of the game\n Battleship is a two player Navy game\n The objective of the game is to sink all ships in your enemy's fleet.\n";
	std::cout << "The Player to sink his / her enemy's fleet first wins.\n Both players' fleets consist of 5 ships that are hidden from the enemy.\n";
	std::cout << "Ships include: The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.\n";
	std::cout << "You have the option to either manually place each of the 5 ships or to have them randomly placed on the board.\n";
	std::cout << "Each cell on the board that contains part of the ship must be indicated by 'c' for Carrier, 'b' for Battleship, 'r' for Cruiser, 's' for Submarine, or 'd' for Destroyer.\n";
	std::cout << "Note that ships cannot be placed diagonally on the board, they can only be placed vertically or horizontally.\n";
	std::cout << "Ships must be placed inside the boudaries and cannot be on top of the ship that has already been placed.\n";
}

void Gameboard::printBoard()
{
	int index_rows = 0, index_cols = 0;
	int ver_coor[10] = { 0, 1,2,3,4,5,6,7,8,9 };
	std::cout << "  ";
	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		std::cout << ver_coor[index_rows];
		putchar('\0');
	}
	putchar('\n');
	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		std::cout << ver_coor[index_rows];
		putchar('\0');
		for (index_cols = 0; index_cols < 10; ++index_cols)
		{
			std::cout << gameboard[index_rows][index_cols];
			putchar('\0');
		}
		putchar('\n');
	}
}

void Gameboard::isHit(int ver, int hor)
{
	gameboard[hor][ver] = 'x';
}

void Gameboard::randomlyInitBoard()
{
	int count, index_rows = 0, index_cols = 0, random;
	int rows_choice, cols_choice;
	do
	{
		rows_choice = rand() % 10;
		cols_choice = rand() % 10;
		random = rand() % 2;
	} while (rows_choice + 4 > 9 || cols_choice + 4 > 9);
	if (random == 1)
	{
		for (count = 0; count < 5; ++count)
		{
			gameboard[rows_choice][cols_choice + count] = 'c';
		}
	}
	else
	{
		for (count = 0; count < 5; ++count)
		{
			gameboard[rows_choice + count][cols_choice] = 'c';
		}
	}
Battleship:
	do
	{
		rows_choice = rand() % 10;
		cols_choice = rand() % 10;
		random = rand() % 2;
	} while (rows_choice + 3 > 9 || cols_choice + 3 > 9);
	if (random == 1)
	{
		for (count = 0; count < 4; ++count)
		{
			if (gameboard[rows_choice][cols_choice + count] == '~')
			{
				gameboard[rows_choice][cols_choice + count] = 'b';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 'b')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Battleship;
			}
		}
	}
	else
	{
		for (count = 0; count < 4; ++count)
		{
			if (gameboard[rows_choice + count][cols_choice] == '~')
			{
				gameboard[rows_choice + count][cols_choice] = 'b';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 'b')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Battleship;
			}
		}
	}
Cruiser:
	do
	{
		rows_choice = rand() % 10;
		cols_choice = rand() % 10;
		random = rand() % 2;
	} while (rows_choice + 2 > 9 || cols_choice + 2 > 9);
	if (random == 1)
	{
		for (count = 0; count < 3; ++count)
		{
			if (gameboard[rows_choice][cols_choice + count] == '~')
			{
				gameboard[rows_choice][cols_choice + count] = 'r';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 'r')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Cruiser;
			}
		}
	}
	else
	{
		for (count = 0; count < 3; ++count)
		{
			if (gameboard[rows_choice + count][cols_choice] == '~')
			{
				gameboard[rows_choice + count][cols_choice] = 'r';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 'r')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Cruiser;
			}
		}
	}
Submarine:
	do
	{
		rows_choice = rand() % 10;
		cols_choice = rand() % 10;
		random = rand() % 2;
	} while (rows_choice + 2 > 9 || cols_choice + 2 > 9);
	if (random == 1)
	{
		for (count = 0; count < 3; ++count)
		{
			if (gameboard[rows_choice][cols_choice + count] == '~')
			{
				gameboard[rows_choice][cols_choice + count] = 's';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 's')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Submarine;
			}
		}
	}
	else
	{
		for (count = 0; count < 3; ++count)
		{
			if (gameboard[rows_choice + count][cols_choice] == '~')
			{
				gameboard[rows_choice + count][cols_choice] = 's';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 's')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Submarine;
			}
		}
	}
Destroyer:
	do
	{
		rows_choice = rand() % 10;
		cols_choice = rand() % 10;
		random = rand() % 2;
	} while (rows_choice + 1 > 9 || cols_choice + 1 > 9);
	if (random == 1)
	{
		for (count = 0; count < 2; ++count)
		{
			if (gameboard[rows_choice][cols_choice + count] == '~')
			{
				gameboard[rows_choice][cols_choice + count] = 'd';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 'd')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Destroyer;
			}
		}
	}
	else
	{
		for (count = 0; count < 2; ++count)
		{
			if (gameboard[rows_choice + count][cols_choice] == 'd')
			{
				gameboard[rows_choice + count][cols_choice] = 's';
			}
			else
			{
				for (index_rows = 0; index_rows < 10; ++index_rows)
				{
					for (index_cols = 0; index_cols < 10; ++index_cols)
					{
						if (gameboard[index_rows][index_cols] == 'd')
						{
							gameboard[index_rows][index_cols] = '~';
						}
					}
				}
				goto Destroyer;
			}
		}
	}
}

void Gameboard::purposelyInitBoard()
{
	int count, index_rows = 0, index_cols = 0;
	int rows_choice, cols_choice;
	int true_false = 0;
	std::cout << "You are placing your Carrier (5 cells).\n";
Carrier:
	count = 0;
	while (count < 5)
	{
		do
		{
			std::cout << "Please enter coordinates to place your Carrier.\n";
			std::cout << "Note: Enter #row first, #column second\n";
			std::cout << "Cell: " << count + 1 << std::endl;
			std::cin >> rows_choice >> cols_choice;
		} while (rows_choice < 0 || rows_choice > 9 || cols_choice < 0 || cols_choice > 9);
		gameboard[rows_choice][cols_choice] = 'c';
		++count;
	}
	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		for (index_cols = 0; index_cols < 10; ++index_cols)
		{
			if (gameboard[index_rows][index_cols] == 'c')
			{
				if (index_cols + 4 <= 9 && gameboard[index_rows][index_cols + 1] == 'c' && gameboard[index_rows][index_cols + 2] == 'c'
					&& gameboard[index_rows][index_cols + 3] == 'c' && gameboard[index_rows][index_cols + 4] == 'c')
				{
					goto Carrier1;
				}

				else if (index_rows + 4 <= 9 && gameboard[index_rows + 1][index_cols] == 'c' && gameboard[index_rows + 2][index_cols] == 'c'
					&& gameboard[index_rows + 3][index_cols] == 'c' && gameboard[index_rows + 4][index_cols] == 'c')
				{
					goto Carrier1;
				}
				else
				{
					system("cls");
					Gameboard();
					printBoard();
					std::cout << "your Carrier's placement is invalid.\n";
					goto Carrier;
				}
			}
		}
	}
Carrier1:
	system("cls");
	// 
	printBoard();
	std::cout << "You are placing your Battleship (4 cells).\n";
Battleship:
	for (count = 0; count < 4; ++count)
	{
		true_false = 0;
		while (true_false == 0)
		{
			cout << "Please enter coordinates to place your Battleship.\n";
			cout << "Note: Enter #row first, #column second\n";
			cout << "Cell: " << count + 1;
			cin >> rows_choice >> cols_choice;
			if (rows_choice >= 0 && rows_choice <= 9 && cols_choice >= 0 && cols_choice <= 9)
			{
				if (gameboard[rows_choice][cols_choice] == '~')
				{
					gameboard[rows_choice][cols_choice] = 'b';
					true_false = 1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 'b')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Battleship's placement is invalid.\n";
					goto Battleship;
				}
			}
		}
	}
	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		for (index_cols = 0; index_cols < 10; ++index_cols)
		{
			if (gameboard[index_rows][index_cols] == 'b')
			{
				if (index_cols + 3 <= 9 && gameboard[index_rows][index_cols + 1] == 'b' && gameboard[index_rows][index_cols + 2] == 'b'
					&& gameboard[index_rows][index_cols + 3] == 'b')
				{
					goto Battleship1;
				}

				else if (index_rows + 3 <= 9 && gameboard[index_rows + 1][index_cols] == 'b' && gameboard[index_rows + 2][index_cols] == 'b'
					&& gameboard[index_rows + 3][index_cols] == 'b')
				{
					goto Battleship1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 'b')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Battleship's placement is invalid.\n";
					goto Battleship;
				}
			}
		}
	}
Battleship1:
	system("cls");
	printBoard();
	cout << "You are placing your Cruiser (3 cells).\n";
Cruiser:
	for (count = 0; count < 3; ++count)
	{
		true_false = 0;
		while (true_false == 0)
		{
			cout << "Please enter coordinates to place your Cruiser.\n";
			cout << "Note: Enter #row first, #column second\n";
			cout << "Cell: " <<  count + 1;
			cin >> rows_choice >> cols_choice;
			if (rows_choice >= 0 && rows_choice <= 9 && cols_choice >= 0 && cols_choice <= 9)
			{
				if (gameboard[rows_choice][cols_choice] == '~')
				{
					gameboard[rows_choice][cols_choice] = 'r';
					true_false = 1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 'r')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Cruiser's placement is invalid.\n";
					goto Cruiser;
				}
			}
		}
	}
	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		for (index_cols = 0; index_cols < 10; ++index_cols)
		{
			if (gameboard[index_rows][index_cols] == 'r')
			{
				if (index_cols + 2 <= 9 && gameboard[index_rows][index_cols + 1] == 'r' && gameboard[index_rows][index_cols + 2] == 'r')
				{
					goto Cruiser1;
				}

				else if (index_rows + 2 <= 9 && gameboard[index_rows + 1][index_cols] == 'r' && gameboard[index_rows + 2][index_cols] == 'r')
				{
					goto Cruiser1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 'r')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Cruiser's placement is invalid.\n";
					goto Cruiser;
				}
			}
		}
	}
Cruiser1:
	system("cls");
	printBoard();

	cout << "You are placing your Submarine (3 cells).\n";
Submarine:
	for (count = 0; count < 3; ++count)
	{
		true_false = 0;
		while (true_false == 0)
		{
			cout << "Please enter coordinates to place your Submarine.\n";
			cout << "Note: Enter #row first, #column second\n";
			cout << "Cell: ", count + 1;
			cin >> rows_choice >> cols_choice;
			if (rows_choice >= 0 && rows_choice <= 9 && cols_choice >= 0 && cols_choice <= 9)
			{
				if (gameboard[rows_choice][cols_choice] == '~')
				{
					gameboard[rows_choice][cols_choice] = 's';
					true_false = 1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 's')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Submarine's placement is invalid.\n";
					goto Submarine;
				}
			}
		}
	}
	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		for (index_cols = 0; index_cols < 10; ++index_cols)
		{
			if (gameboard[index_rows][index_cols] == 's')
			{
				if (index_cols + 2 <= 9 && gameboard[index_rows][index_cols + 1] == 's' && gameboard[index_rows][index_cols + 2] == 's')
				{
					goto Submarine1;
				}

				else if (index_rows + 2 <= 9 && gameboard[index_rows + 1][index_cols] == 's' && gameboard[index_rows + 2][index_cols] == 's')
				{
					goto Submarine1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 's')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Submarine's placement is invalid.\n";
					goto Submarine;
				}
			}
		}
	}
Submarine1:
	system("cls");
	printBoard();
	cout << "You are placing your Destroyer (2 cells).\n";
Destroyer:
	for (count = 0; count < 2; ++count)
	{
		true_false = 0;
		while (true_false == 0)
		{
			cout << "Please enter coordinates to place your Destroyer.\n";
			cout << "Note: Enter #row first, #column second\n";
			cout << "Cell: " << count + 1;
			cin >> rows_choice >> cols_choice;
			if (rows_choice >= 0 && rows_choice <= 9 && cols_choice >= 0 && cols_choice <= 9)
			{
				if (gameboard[rows_choice][cols_choice] == '~')
				{
					gameboard[rows_choice][cols_choice] = 'd';
					true_false = 1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 'd')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Destroyer's placement is invalid.\n";
					goto Submarine;
				}
			}
		}
	}
	for (index_rows = 0; index_rows < 10; ++index_rows)
	{
		for (index_cols = 0; index_cols < 10; ++index_cols)
		{
			if (gameboard[index_rows][index_cols] == 'd')
			{
				if (index_cols + 1 <= 9 && gameboard[index_rows][index_cols + 1] == 'd')
				{
					goto Destroyer1;
				}

				else if (index_rows + 1 <= 9 && gameboard[index_rows + 1][index_cols] == 'd')
				{
					goto Destroyer1;
				}
				else
				{
					system("cls");
					for (index_rows = 0; index_rows < 10; ++index_rows)
					{
						for (index_cols = 0; index_cols < 10; ++index_cols)
						{
							if (gameboard[index_rows][index_cols] == 'd')
							{
								gameboard[index_rows][index_cols] = '~';
							}
						}
					}
					printBoard();
					cout << "your Destroyer's placement is invalid.\n";
					goto Destroyer;
				}
			}
		}
	}
Destroyer1:
	system("cls");
}