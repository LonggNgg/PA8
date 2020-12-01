/*
	Name: Long Nguyen
	Assignment: PA8
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Gameboard.h"

class Player : public Gameboard
{
private:
	typedef struct coorshoot
	{
		int ver;
		int hor;
	}CoorShoot;

	CoorShoot shot;
public:
	Player()
	{
		shot.hor = -1;
		shot.ver = -1;
	}
	void set_shot_coor(int ver, int hor)
	{
		shot.ver = ver;
		shot.hor = hor;
	}
	int getVer()
	{
		return shot.ver;
	}
	int getHor()
	{
		return this->shot.hor;
	}
	void isHit(int ver, int hor);
	void shot_manually(Player& p2);
	void shot_randomly(Player& p1);

	static int who_win(Player p1, Player p2);
};

void gameplay();

#endif