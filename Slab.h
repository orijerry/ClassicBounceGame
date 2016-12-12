#ifndef SLAB_H_
#define SLAB_H_

#include "Box.h"

class Slab : public Box {
	int startposx, startposy;
public:
	Slab() : Box('='), startposx(0), startposy(0) { }
	void update(int sposx, int sposy) { startposx = sposx; startposy = sposy; }
	int getposx() const { return startposx; }
	int getposy() const { return startposy; }
	void setposx(int sposx2) { startposx = sposx2; }
};



#endif /* SLAB_H_ */
