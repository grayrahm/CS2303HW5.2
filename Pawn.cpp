/*
 * Pawn.cpp
 *
 *  Created on: Sep 25, 2021
 *      Author: theresesmith
 */

#include "Pawn.h"

Pawn::Pawn() {
	// TODO Auto-generated constructor stub
	puts("The pawn constructor");

}

Pawn::~Pawn() {
	// TODO Auto-generated destructor stub
}

LLNode* Pawn::getYourMoves()
{
	LLNode* ans = new LinkedList();
   puts("Asking pawn for moves");
   // nominally move forward to left and forward right
   if(movingForwardToHigherRows){
	   if(col >= 1){
		   CheckerMove* x = new CheckerMove();
		   x -> setStartCol(col);
		   x -> setEndCol(col - 1);
		   x -> setStartRow(r);
		   x-> setEndRow(r + 1);
		   ans-> savePayload(x);
	   }
	   if(col <= 6){
		   CheckerMove* x = new CheckerMove();
		   x -> setStartCol(col);
		   x -> setEndCol(col + 1);
		   x -> setStartRow(r);
		   x-> setEndRow(r + 1);
		   ans-> savePayload(x);
	   }
   }
   else{
	   if(col >= 1){
		   CheckerMove* x = new CheckerMove();
		   x -> setStartCol(col);
		   x -> setEndCol(col - 1);
		   x -> setStartRow(r);
		   x-> setEndRow(r - 1);
		   ans-> savePayload(x);
	   }
	   if(col <= 6){
		   CheckerMove* x = new CheckerMove();
		   x -> setStartCol(col);
		   x -> setEndCol(col + 1);
		   x -> setStartRow(r);
		   x-> setEndRow(r - 1);
		   ans-> savePayload(x);
	   }
   }
	return ans;
}
