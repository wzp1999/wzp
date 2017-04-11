#ifndef LINEAR_H
#define LINEAR_H

class det {
public:
	det();
	det(int _r, int _c, int *_p);
	~det();
	void print();
	int calculate();
private:
	int r, c;
	int *p;
};

#endif