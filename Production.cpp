/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"

Production::Production() {
}
Production::~Production() {
}

bool Production::prod(int argc, char *argv[]) {
	printf("Starting Production\n");
	bool answer = false;

	if (argc <= 1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	} else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc - 1);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char *eptr = (char*) malloc(sizeof(char*));
		int maxTurns;
		long aL = 0;

		for (int i = 1; i < argc; i++) //don't want to read argv[0]
		{ //argv[i] is a string

			switch (i) {
			case 1:
				//this is filename
				printf("The length of the filename is %d.\n",
						(int) strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if (strlen(argv[i]) >= FILENAMELENGTHALLOWANCE) {
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				} else {
					strcpy(filename, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 2:
				//this is maximum number of turns
				aL = strtol(argv[i], &eptr, 10);
				maxTurns = (int) aL;
				printf("Number of turns is %d\n", maxTurns);
				fflush(stdout);
				break;
			default:
				puts("Unexpected argument count.");
				fflush(stdout);
				answer = false;
				break;
			} //end of switch
		} //end of for loop on argument count
		puts("after reading arguments");
		fflush(stdout);

		//we'll want to read the file
		Board *theBoard = new Board();
		//		char turn = 'b';
		//		char* turnp = &turn;
		//theBoard->setColor(turnp);

		answer = readFile(filename, theBoard); //read the file

		// open output file
		FILE* fp = fopen("output.txt", "w"); //write this file


// here we are doing the game agent

		puts( "Input 1 for black and 0 for red to start.");
		int startteam;
		//		cin >> startteam;
		fscanf(fp,"%d", &startteam);
		theBoard->setColor(startteam);

		bool gameDone = false;
		int turnsPlayed = 0;
		while (!gameDone) {

			theBoard->printBoard(fp);
			CheckerMove *themove = new CheckerMove();
			printf ("Turn color : %d : (Black is 1, Red is 0)", theBoard->getColor());
			if (theBoard->getColor()) {
				puts( "Player move");
				theBoard->getPlayermove(themove);
				theBoard->performMove(themove);
				if (theBoard->checkWin() == 'r') {
					puts( "red has lost after :");
					puts( ": moves.");
					turnsPlayed++;
					theBoard->printBoard(fp);
					gameDone = true;
				} else if (theBoard->checkWin() == 'b') {
					printf( "black has lost after : %d moves. \n", turnsPlayed);
					turnsPlayed++;
					theBoard->printBoard(fp);
					gameDone = true;
				} else if (maxTurns < turnsPlayed) {
					turnsPlayed++;
					puts("Reached :");
					printf( ": turns. Game tie due to reaching max turns.");
					gameDone = true;
				} else {
					turnsPlayed++;
					printf( "Turn switch : total turns played -> %d \n", turnsPlayed);
					gameDone = false;
				}

			} else {
				puts( "Computers turn");
				theBoard->setrPlength( theBoard->updateRedlist());
				theBoard->getRandmove(themove);
				theBoard->performMove(themove);
				if (theBoard->checkWin() == 'r') {
					turnsPlayed++;
					printf( "red has lost after : %d \n" ,turnsPlayed);
					printf(": moves." );
					theBoard->printBoard(fp);
					gameDone = true;
				} else if (theBoard->checkWin() == 'b') {
					turnsPlayed++;
					printf( "black has lost after :%d moves: \n", turnsPlayed);
					theBoard->printBoard(fp);
					gameDone = true;
				} else if (maxTurns < turnsPlayed) {
					turnsPlayed++;
					printf( "Reached : %d turns. Game tie due to reaching max turns. \n", maxTurns);
					gameDone = true;
				} else {
					turnsPlayed++;
					printf ("Turn switch : total turns played -> : %d \n", turnsPlayed );
					gameDone = false;
				}
			}
			theBoard->changeTurn();
		}

	}
	return answer;
}

bool Production::readFile(char *filename, Board *theBoard) {
	bool ok = true;
	char temp = '=';
	FILE *fp = fopen(filename, "r"); //read the file
	puts( "Opened file");
	if (fp == NULL) {
		puts("Error! opening file");

	} else {

		puts( "Reading the board");
		for (int r = 0; r < 8; ++r) {
			for (int c = 0; c < 9; ++c) {
				fscanf(fp, "%c", &temp);

//				Space *s = new Space();
				//every time find checker in file of board we are going to update checker pointer on the board

				Checker** thatCellP = theBoard -> getCorner() + r * 8 + c;
				Checker* s = *thatCellP;
				if (temp == '-') {

					s->setC(c);
					s->setR(r);
					s->setType('e');
				} else if (temp == 'r') {
					s->setC(c);
					s->setR(r);
					s->setType('r');
				} else if (temp == 'b') {
					s->setC(c);
					s->setR(r);
					s->setType('b');
				}
			}
		}
	}
	fclose(fp);

	return ok;
}

bool Production::getYesNo(char *query) {
	bool answer = true; //so far
	char said = 'x';
	do {
		printf("%s (y/n):", query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c", &said);
	} while ((said != 'y') && (said != 'n'));
	if (said == 'n') {
		answer = false;
	}

	return answer;
}

