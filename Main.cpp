#include "Board.h"
#include "Ball.h"
#include "Slab.h"
#include <ncurses.h>
#include <cstdlib> 

int slabspositions(int);
void modifyboard(int, int, Board *, Ball *, Slab *);
void printboard(Board *, int, int);

int main() {
	initscr(); raw(); noecho(); nodelay(stdscr, TRUE);
	int maxrows = 20, maxcols = 15; bool gameloop = true;
	Board board(maxrows, maxcols); Ball ball(0, maxcols / 2); Slab slabs[3];
	int slabsize = slabspositions(maxcols);
	slabs[0].update(8, 0); slabs[1].update(14, maxcols - slabsize); slabs[2].update(19, 0);
	printw("Score: 0\n"); modifyboard(maxrows, slabsize, &board, &ball, slabs);
	printboard(&board, maxrows, maxcols); refresh();

	int input = 0, score = 0, speed = 0;
	do { input = getch();
			if(input == 'i' || input == 'I') {
					if(ball.getposx() == 0) ball.update(maxrows - 1, ball.getposy());
					else ball.update(ball.getposx() - 2, ball.getposy());
			} else if(input == 'k' || input == 'K') {
					if(ball.getposx() == maxrows - 1) ball.update(0, ball.getposy());
					else ball.update(ball.getposx() + 2, ball.getposy());
			} else if(input == 'j' || input == 'J') {
					if(ball.getposy() == 0) ball.update(ball.getposx(), maxcols - 1);
					ball.update(ball.getposx(), ball.getposy() - 2);
			} else if(input == 'l' || input == 'L') {
					if(ball.getposy() == maxcols - 1) ball.update(ball.getposx(), 0);
					else ball.update(ball.getposx(), ball.getposy() + 2);
			}

			for (int i = 0; i < 3; ++i)
				if (slabs[i].getposx() == ball.getposx()
						&& ball.getposy() >= slabs[i].getposy()
						&& ball.getposy() < slabs[i].getposy() + slabsize) { gameloop = false; break; }
				else if(speed % 300 == 0) score++;

			if(speed == 1000) { modifyboard(maxrows, slabsize, &board, &ball, slabs); speed = 0; }
			else speed++;

			clear(); printw("\n\n"); printboard(&board, maxrows, maxcols);
			printw("Score: %d\tSpeed %d", score, speed); refresh();
	} while (gameloop); clear();
	printw("\n\n\nFinished with score: %d.\n\nPress any key to continue...", score); refresh();
	nodelay(stdscr, FALSE); getch(); endwin(); return 0;
}

int slabspositions(int maxcols) { return int((60 * maxcols) / 100.0); }
void modifyboard(int maxrows, int slabsize, Board * boardptr, Ball * ballptr, Slab * slabsptr) {
	boardptr -> refresh();
	for(int i = 0; i < 3; ++i) {
		if(slabsptr[i].getposx() == 0) slabsptr[i].setposx(maxrows - 1);
		else slabsptr[i].setposx(slabsptr[i].getposx() - 1);
		for(int j = 0; j < slabsize; ++j)
			boardptr -> update(&slabsptr[i], slabsptr[i].getposx(), slabsptr[i].getposy() + j);
	} boardptr -> update(ballptr, ballptr -> getposx(), ballptr -> getposy());
}

void printboard(Board * board, int rowsx, int colsy) {
	for(int i = 0; i < rowsx; ++i) {
		for(int j = 0; j < colsy; ++j)
			printw("%c ", board -> getboard()[i][j].getmark());
		printw("\n");
	}
}
