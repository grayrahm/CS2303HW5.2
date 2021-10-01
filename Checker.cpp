/*
 * Checker.cpp
 *
 *  Created on: Sep 25, 2021
 *      Author: theresesmith
 */

#include "Checker.h"

Checker::Checker() {
	// TODO Auto-generated constructor stub
	puts("Checker constructor was called");

}

Checker::~Checker() {
	// TODO Auto-generated destructor stub
}

LLNode* Checker::getYourMoves(){
	LLNode* ans = new LinkedList();
	//my moves are pawn moves and poss king moves
	return ans;
}
int Checker::getC(){
	return c;
}
void Checker::setC(int p){
	c = p;
}
int Checker::getR(){
	return r;
}
void Checker::setR(int q ){
	r = q;
}

char Checker::getType(){
	return Type;
}
void Checker::setType(char E){
	Type = E;
}
