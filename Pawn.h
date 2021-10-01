/*
 * Pawn.h
 *
 *  Created on: Sep 25, 2021
 *      Author: theresesmith
 */

#ifndef PAWN_H_
#define PAWN_H_

#include "Checker.h"
#include "LinkedList.h"
#include "CheckerMove.h"

class Pawn: public Checker {
public:
	Pawn();
	virtual ~Pawn();
	virtual LLNode* getYourMoves();

	int getRow();
	void setRow(int);
	int getCol();
	void setCol();
	bool getMovingForwardToHigherRows();
	void setMovingForwardToHigherRows(bool);

private:
	int row;
	int col;
	bool movingForwardToHigherRows;
};

#endif /* PAWN_H_ */
