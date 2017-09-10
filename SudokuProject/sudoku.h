#include<iostream>
#include<vector>
#include <cmath>
#include <cstdlib>
#include<algorithm>
#define N 9 
#define M 3
using namespace std;
class Sudoku
{
private:
	int matrix[N][N];
	int count;
	FILE *fp;
public:
	void openfile();
	void closefile();
	void generator(int);
	void init_generator();
	void print(int mx[][N]);
	void exchange_row(int n);
	void print_Mrows(int exchange_ways[M], int mx[][N]);
};