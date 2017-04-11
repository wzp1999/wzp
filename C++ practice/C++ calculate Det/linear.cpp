#include "linear.h"
#include <iostream>
using namespace std;

//定义det对象
det::det() {
	*p = NULL;
	r = c = 0;
}

det::det(int _r, int _c, int *_p) {
	p = new int[_r*_c];
	r = _r;
	c = _c;
	for (int i = 0; i < r; i++) {
		for (int t = 0; t < c; t++,p++,_p++) {
			*p = *_p;
		}
	}
	p -= r*c;
	_p -= r*c;
}

det::~det() {
	delete[] p;
}

void det::print() {
	for (int i = 0; i < r; i++) {
		for (int t = 0; t < c; t++, p++) {
			cout <<*p<<" ";
		}
	}
	p -= r*c;
}


//计算行列式的值
int det::calculate() {
	int sum = 0;
	if (4 == r*c) {
		return p[0] * p[3] - p[1] * p[2];
		//return p[0] * p[4] * p[8] + p[1] * p[5] * p[6] + p[2] * p[3] * p[7] - p[2] * p[4] * p[6] - p[0] * p[5] * p[7] - p[1] * p[3] * p[8];
	}
	for (int i = 0; i < c; i++) {
		if (0 == p[i]) {
			continue;
		}
		int *q = new int[(r - 1)*(c - 1)];
		p += c;
		for (int j = 1; j < r; j++) {
			for (int k = 0; k < c; k++,p++,q++) {
				if (i == k%c) {
					q--;
				}
				else {
					*q = *p;
				}
			}
		}
		p -= r*c;
		q -= (r - 1)*(c - 1);
		det c(r - 1, c - 1, q);
		delete[] q;
		q = NULL;
		if (0 == i % 2) {
			sum += p[i]*c.calculate();
		}
		else {
			sum -= p[i]*c.calculate();
		}
	}
	return sum;
}