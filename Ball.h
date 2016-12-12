#ifndef BALL_H_
#define BALL_H_

#include "Box.h"

class Ball : public Box {
	int posx, posy;
public:
	Ball(int posx2 = 0, int posy2 = 0) : Box('O'), posx(posx2), posy(posy2) { }
	void update(int posx2, int posy2) { posx = posx2; posy = posy2; }
	int getposx() const { return posx; }
	int getposy() const { return posy; }
};

#endif /* BALL_H_ */
