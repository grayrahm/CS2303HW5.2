/*
 * Tests.cpp
 *
 *  Created on: Sep 30, 2021
 *      Author: CyberPower
 */

#include "Tests.h"
#include <stdbool.h>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests() {
	bool answer = true;

	bool b1 = testReadFileAndPrintBoard();
	bool b2 = testGetPlayerMoveAndPerformMove();
	bool b3 = testCheckWin();
	bool b4 = testPossibleMove();
	bool b5 = testChangeturn();
	answer = b1 && b2 && b3 && b4 && b5;
	if (answer)
		puts( "+++ All Tests Passed! +++" );
	else
		puts( "--- Tests Failed ---" );
	return answer;
}

bool Tests::testReadFileAndPrintBoard() {
	puts("Starting testReadFileAndPrintBoard"); fflush(stdout);
	bool ok = false;

	Board *theBoard = new Board();
	Production *pP = new Production();
	char filename[20] = "testfile.txt";

	puts("Start readFile");
	ok = pP->readFile(filename, theBoard); //read the file
	puts("Back from readFile");
	puts( "Starting printBoard");
	theBoard->printBoard(); //print out the board
	puts("Back from printBoard");

	char YNstr[50] = "Does the board look right?"; //asks for user input
	ok = pP->getYesNo(YNstr); //takes in user input
	if(ok) {
		puts("++ testReadfileAndPrintBoard passed ++");
	}
	else {
		puts("-- testReadfileAndPrintBoard did not pass --");
	}

	return ok;
}

bool Tests::testGetPlayerMoveAndPerformMove() {
	puts( "Starting testGetPlayerMoveAndPerformMove"); fflush(stdout);
	bool ok = false;

	Board *theBoard = new Board();
	Production *pP = new Production();
	CheckerMove *move = new CheckerMove();
	char filename[20] = "testfile2.txt";

	pP->readFile(filename, theBoard); //read the file
	theBoard->printBoard(); //prints original board

	theBoard->setColor(1); //set player to make first move

	puts( "Start getPlayerMove");
	theBoard->getPlayermove(move); //get move from player
	puts( "Back from getPlayerMove");
	puts( "Start performMove" );
	theBoard->performMove(move); //updates board
	puts("Back from performMove");
	theBoard->printBoard(); //prints updated board

	char YNstr[50] = "Was the player move properly executed?"; //asks user for input
	ok = pP->getYesNo(YNstr); //takes in user input
	if (ok) {
		puts("++ testGetPlayerMoveAndPerformMove passed ++");
	}
	else {
		puts("-- testGetPlayerMoveAndPerformMove did not pass --");
	}

	return ok;
}

bool Tests::testCheckWin() {
	puts("Starting testCheckWin" );
	bool ok = false;

	Board *theBoard = new Board();
	Production *pP = new Production();
	char filename[] = "redwin.txt";
	pP->readFile(filename, theBoard);
	theBoard->printBoard();

	if (theBoard->checkWin() == 'b') {
		ok = true;
		puts("++ testCheckWin passes ++" );
	}
	else {
		puts( "++ testCheckWin did not pass ++");
	}

	return ok;
}

bool Tests::testPossibleMove() {
	puts( "Starting testPossibleMove");
	bool ok = false;

	Board *theBoard = new Board();
	theBoard->setColor(1);
	Production *pP = new Production();
	char filename[20] = "testfile2.txt";
	pP->readFile(filename, theBoard); //read the file
	CheckerMove *move = new CheckerMove(6, 2, 5, 1);

	puts( "Start performMove");
	ok = theBoard->possibleMove(move); //checks if move is possible
	puts( "Back from performMove");

	if (ok) {
		puts("++ testPossibleMove passed ++");
	}
	else {
		puts("-- testPossibleMove did not pass --");
	}

	return ok;
}
bool Tests::testChangeturn() {
	puts("Starting testChangeturn");
	bool ok = false;

	Board *theBoard = new Board();
	theBoard->setColor(1);

	puts( "Start testChangeturn");
	theBoard->changeTurn(); //switches turn from user to computer
	puts("Back from testChangeturn");

	ok = theBoard->getColor() == 0;

	if (ok) {
		puts("++ testChangeturn passed ++");
	}
	else {
		puts("-- testChangeturn did not pass --");
	}

	return ok;
}

/*
bool Tests::testPlayerJump(){
	std::cout <<"Start testPlayerJump" << endl;

}
*/
