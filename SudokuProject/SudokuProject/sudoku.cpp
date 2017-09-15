#include"sudoku.h"
void Sudoku::print(int mx[][N]) //����������� 
{
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			fprintf(fp, "%d ", mx[i][j]);
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
}
void Sudoku::print_Mrows(int exchange_ways[M], int mx[][N])//���������M�� 
{
	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
		{

			fprintf(fp, "%d ", mx[exchange_ways[i]][j]);
		}
		fprintf(fp, "\n");
	}
}
void Sudoku::exchange_row(int n)//�ֱ𽻻���3��5�к� ��6��8�� 
{
	int exchange_ways[2][5][3] = { { { 3, 5, 4 },
	{ 4, 3, 5 },
	{ 4, 5, 3 },
	{ 5, 3, 4 },
	{ 5, 4, 3 } },
  { { 6, 8, 7 },
	{ 7, 6, 8 },
	{ 7, 8, 6 },
	{ 8, 6, 7 },
	{ 8, 7, 6 } } };
	int first_to_third[3] = { 0, 1, 2 };
	for (int k = 0; k<5; k++)
	{
		for (int t = 0; t<5; t++)
		{
			print_Mrows(first_to_third, matrix);
			print_Mrows(exchange_ways[0][k], matrix);
			print_Mrows(exchange_ways[1][t], matrix);
			fprintf(fp, "\n");
			if (++count == n)
			{
				closefile();
				exit(0);
			}
		}
	}

}
void Sudoku::generator(int n)
{
	int arr[] = { 6, 1, 2, 3, 4, 5, 7, 8, 9 };
	for (int i = 0; i < N; i++)
		matrix[0][i] = arr[i];
	bool flag = true;
	count = 0;
	while (next_permutation(matrix[0] + 1, matrix[0] + N))//�Ե�һ�еĵ�1��N-1��������ȫ���� 
	{
		//for(int i=0;i<N;i++)
		//	printf("%d\t",matrix[0][i]); 
		//printf("\n");
		init_generator();//��������һ�в����������� 
		print(matrix);
		++count;
		if (count == n)
			break;
		//cout<<count<<endl;
		if (n<40320)		//���������С��ȫ���и�����һ�򲻽��н����в��� 
			continue;
		exchange_row(n);
	}
}
void Sudoku::init_generator()
{
	int i, j;
	for (i = 1; i < N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (i<M)
			{
				matrix[i][j] = matrix[i - 1][(j + M) % N];
			}
			else
			{
				matrix[i][j] = matrix[i - M][(j + 1) % N];
			}
		}
	}

}
void Sudoku::openfile()
{
	fp = fopen("sudoku.txt", "w");
}
void Sudoku::closefile()
{
	fclose(fp);
}