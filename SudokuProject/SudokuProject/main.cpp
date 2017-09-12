#include "sudoku.h"
int main(int argc, char *argv[])
{
	Sudoku sudoku;

	int len = strlen(argv[2]);
	for (int i = 0; i < len;i++)
	if (argv[2][i]<'0' || argv[2][i]>'9')
	{
		cout << "input error!"<<endl;
		return 0;
	}

	sudoku.openfile();
	sudoku.generator(atoi(argv[2]));
	sudoku.closefile();
	return 0;
}