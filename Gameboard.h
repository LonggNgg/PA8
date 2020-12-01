/*
	Name: Long Nguyen
	Assignment: PA8
*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <time.h>
using namespace std;

class Gameboard
{
protected: 
	char gameboard[10][10];
public:
	Gameboard();
	void static GameRules();
	virtual void isHit(int ver, int hor);
	void printBoard();
	void randomlyInitBoard();
	void purposelyInitBoard();
};


#endif