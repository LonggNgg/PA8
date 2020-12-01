/*
	Name: Long Nguyen
	Assignment: PA8
*/

#include "Player.h"

void Player::isHit(int ver, int hor)
{
	if (gameboard[ver][hor] != '~')
		Gameboard::isHit(ver, hor);
}

void Player::shot_randomly(Player& p1)
{
	int rows_choice, cols_choice;
check_shot1:
	rows_choice = rand() % 10;
	cols_choice = rand() % 10;

	if (p1.gameboard[rows_choice][cols_choice] != 'm'
		&& p1.gameboard[rows_choice][cols_choice] != '*')
	{
		if (p1.gameboard[rows_choice][cols_choice] == '~')
		{
			//cout << "Row: " << rows_choice << "Column: " << cols_choice << " is a miss\n";
			p1.gameboard[rows_choice][cols_choice] = 'm';
		}
		else
		{
			//cout << "Row: " << rows_choice << "Column: " << cols_choice << " is a hit\n";
			p1.gameboard[rows_choice][cols_choice] = '*';
		}
	}
	else
	{
		goto check_shot1;
	}
}

void Player::shot_manually(Player& p2)
{
	int rows_choice, cols_choice;
check_shot1:
	do
	{
		cout << "Please enter coordinates to shoot.\n";
		cout << "Note: Enter #row first, #column second\n";
		cin >> rows_choice >> cols_choice;
	} while (rows_choice < 0 || rows_choice > 9 || cols_choice < 0 || cols_choice > 9);

	if (p2.gameboard[rows_choice][cols_choice] != 'm'
		&& p2.gameboard[rows_choice][cols_choice] != '*')
	{
		if (p2.gameboard[rows_choice][cols_choice] == '~')
		{
			p2.gameboard[rows_choice][cols_choice] = 'm';
			/*player_hidden_board[rows_choice][cols_choice] = 'm';
			*miss = *miss + 1;*/
		}
		else
		{
			p2.gameboard[rows_choice][cols_choice] = '*';
			/*player_hidden_board[rows_choice][cols_choice] = '*';
			*hit = *hit + 1;*/
		}
	}
	else
	{
		system("cls");
		cout << "You have fired at this coordinates.\n";
		printBoard();
		goto check_shot1;
	}
}

int Player::who_win(Player p1, Player p2)
{
	int index_rows = 0, index_cols = 0, count1 = 0, count2 = 0, rows = 10, cols = 10;

	for (index_rows = 0; index_rows < rows; ++index_rows)
	{
		for (index_cols = 0; index_cols < cols; ++index_cols)
		{
			if (p1.gameboard[index_rows][index_cols] == '*')
			{
				++count1;
			}
			if (p2.gameboard[index_rows][index_cols] == '*')
			{
				++count2;
			}
		}
	}
	if (count1 == 17)
		{
			system("cls");
			cout << "\n****COMPUTER WINS!****\n";
			return 0;
		}
		else if (count2 == 17)
		{
			system("cls");
			cout << "\n****YOU WIN!****\n";
			return 0;
		}
	return 1;
}

void gameplay()
{
	Player p1, com;
	int choice;
	Gameboard::GameRules();
	cout << endl << "Do you want (1) a randomly generated board or (2) a purposely generated board?\n";
	cout << "Select (1) or (2)";
	cin >> choice;
	if (choice == 1)
		p1.randomlyInitBoard();
	else if (choice == 2)
		p1.purposelyInitBoard();
	com.randomlyInitBoard();
	while (Player::who_win(p1, com))
	{
		p1.printBoard();
		cout << endl;
		com.printBoard();
		p1.shot_manually(com);
		com.shot_randomly(p1);
		system("cls");
	}
}