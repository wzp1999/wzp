#include <iostream>
#include <time.h>
#include <iomanip>

#include "linear.h"

using namespace std;

int main() {
	clock_t start, finish;
	double t;
	start = clock();
	int det1[6][6] = {
		{ 0,10,0,8,0,2 },
		{ 10,-10,-4,0,0,0 },
		{ 0,0,4,-8,8,0 },
		{ 1,1,0,0,0,-1 },
		{ 0,1,-1,-1,0,0 },
		{1,0,1,0,-1,0}
	};
	int det2[4][4] = {
		{1,2,3,4},
		{-2,1,-4,3},
		{3,-4,-1,2},
		{4,3,-2,-1}
	};
	det a(6, 6, &det1[0][0]);
	int b = a.calculate();
	cout << b << endl;

	finish = clock();
	t = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "此程序的运行时间为" << setprecision(8) << t << "秒！" << endl;
	system("pause");
	return 0;
}