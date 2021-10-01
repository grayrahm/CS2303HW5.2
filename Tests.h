/*
 * Tests.h
 *
 *  Created on: Sep 30, 2021
 *      Author: CyberPower
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Production.h"
#include <stdio.h>
#include "Board.h"
#include "CheckerMove.h"

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:
	bool testReadFileAndPrintBoard();
	bool testGetPlayerMoveAndPerformMove();
	bool testCheckWin();
	bool testPossibleMove();
	bool testChangeturn();
};

#endif /* TESTS_H_ */

