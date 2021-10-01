/*
 * Board.h
 *
 *  Created on: Sep 30, 2021
 *      Author: CyberPower
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "CheckerMove.h"
#include "Checker.h"
#include <cstdio>
#include <cstdlib>

class Board {
public:
	Board();
	virtual ~Board();
	bool getColor();
	void setColor(bool);
	void printBoard(FILE*);
	void printBoard();
	void getPlayermove(CheckerMove* );
	void performMove(CheckerMove* );
	char checkWin();
	int getrPlength();
	void setrPlength(int);
	int updateRedlist();
	void getRandmove(CheckerMove*);
	void changeTurn();
	bool possibleMove(CheckerMove*);
	Checker** getCorner();





private:
	bool color;
	int rPlength;
	bool turn;
	Checker** corner;


};

#endif /* BOARD_H_ */
