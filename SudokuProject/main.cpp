#include "sudoku.h"
int main(int argc, char *argv[])
{
	int n;
	Sudoku sudoku;
	sudoku.openfile();
	cin >> n;
	/*if(argc!=3)
	{
	return 0;
	}
	if(argv[1]!="-c")
	return 0;
	int n=atoi(argv[2]);
	cout<<n<<endl;*/
	sudoku.generator(n);
	sudoku.closefile();
	return 0;
}