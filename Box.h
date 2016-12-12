#ifndef BOX_H_
#define BOX_H_

class Box {
protected:
	char mark;
public:
	Box(char mark2 = ' ') { mark = mark2; }
	char getmark() const { return mark; }
	void setmark(char mark2) { mark = mark2; }
};


#endif /* BOX_H_ */
