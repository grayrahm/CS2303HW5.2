/*
 * King.h
 *
 *  Created on: Sep 25, 2021
 *      Author: theresesmith
 */

#ifndef KING_H_
#define KING_H_

#include "Pawn.h"
#include "LinkedList.h"

class King: public Pawn {
public:
	King();
	virtual ~King();
	LLNode* getYourMoves();
};

#endif /* KING_H_ */
