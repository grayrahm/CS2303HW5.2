/*
 * Board.cpp
 *
 *  Created on: Sep 30, 2021
 *      Author: CyberPower
 */

#include "Board.h"

Board::Board() {
	// TODO Auto-generated constructor stub
	corner =(Checker**) malloc(8 * 8 *sizeof(Checker*));
	for(int row = 0; row<8; row++)
	{
		for(int col = 0; col<8; col++)
		{
			Checker** thatCellP = corner + 8 * row + col;
			*(thatCellP) = new Checker();
		}

	}

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

bool Board::getColor(){
	return color;
}
void Board::setColor(bool s){
	color = s;
}
void Board::printBoard(FILE* f){
	// print the board onto file f
	//use fprint f
}

void Board::getPlayermove(CheckerMove* ){

}
void Board::performMove(CheckerMove* ){

}

int Board::getrPlength(){
	return this->rPlength;
}
void Board::setrPlength(int x){
	this->rPlength = x;

}
int Board::updateRedlist(){
	int ans = false;
	// I wonder what going to do to update
	return ans;
}
void Board::getRandmove(CheckerMove*){

}
void Board::changeTurn(){
	turn = !turn;
}
void Board::printBoard(){

}
char Board::checkWin(){
	char ans = 'x';
	return ans;
}
Checker** Board::getCorner(){
	return corner;
}

bool Board::possibleMove(CheckerMove* m){
	bool ans = false;
	//TODO
	return ans;


}

