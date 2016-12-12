#include "Board.h"

Board :: Board(int rowsx2, int colsy2) : rowsx(rowsx2), colsy(colsy2) {
	board = new Box * [rowsx];
	for(int i = 0; i < rowsx; ++i)
		board[i] = new Box[i];
}

Board :: ~Board() {
	for(int i = 0; i < rowsx; ++i)
		delete [] board[i];
	delete [] board;
}

void Board :: refresh() {
	for(int i = 0; i < rowsx; ++i)
		for(int j = 0; j < colsy; ++j)
			board[i][j].setmark(' ');
}

void Board :: update(Box *other, int posx, int posy) {
	if (!other) board[posx][posy].setmark(' ');
	else board[posx][posy].setmark(other -> getmark());
}

Box ** Board :: getboard() const { return board; }
