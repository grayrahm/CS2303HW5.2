/*
 * Checker.h
 *
 *  Created on: Sep 25, 2021
 *      Author: theresesmith
 */

#ifndef CHECKER_H_
#define CHECKER_H_
#include <stdio.h>
#include "LinkedList.h"

class Checker {
public:
	Checker();
	virtual ~Checker();
	virtual LLNode* getYourMoves();
	int getC();
	void setC(int);
	int getR();
	void setR(int);
	char getType();
	void setType(char);
private:
	int c;
	int r;
	char Type;

};

#endif /* CHECKER_H_ */
