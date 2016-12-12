#ifndef BOARD_H_
#define BOARD_H_

#include "Box.h"
#define NULL 0

class Board {
	Box **board;
	int rowsx, colsy;
public:
	Board(int = 100, int = 100);
	~Board();
	void refresh();
	void update(Box *, int, int);
	Box ** getboard() const;
};

#endif /* BOARD_H_ */
