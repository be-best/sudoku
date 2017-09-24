#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;
int sudo[9][9];
int out = 0;
int num;
bool judge(int a, int b, int c)
{
	int i, j;
	int m, n;
	//���ж� 
	for (i = 0; i<a; i++)
	{
		if (c == sudo[i][b])
		{
			return false;
		}

	}
	//���ж� 
	for (j = 0; j<b; j++)
	{
		if (c == sudo[a][j])
		{
			return false;
		}
	}
	//���ж� 
	m = (a / 3) * 3;
	n = (b / 3) * 3;
	for (i = m; i<m + 3; i++)
	{
		for (j = n; j<n + 3; j++)
		{
			if (c == sudo[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void set(int i, int j)
{
	int b;
	if (out == num)
	{
		return;   //���������ﵽnumʱֹͣ 
	}
	for (b = 1; b<10; b++)
	{

		if (judge(i, j, b))
		{
			sudo[i][j] = b;
			if (j<8)
				set(i, j + 1);
			if (j == 8 && i<8)
				set(i + 1, 0);
			if (i == 8 && j == 8) {
				for (i = 0; i<9; i++)
				{
					for (j = 0; j<9; j++)
					{
						putchar(sudo[i][j] + 48);
						putchar(' ');

					}
					putchar('\n');
				}
				putchar('\n');
				out++;
			}

		}
		sudo[i][j] = 0;
	}

}

int main(int argc,char* argv[])
{

	//cin>>num;
	if(argc == 1)
	{
		return 0;
	}
	
	//strcmp  ���  argv[1] == "-c" ����0 
	
	if(strcmp(argv[1],"-c"))
	{   
		puts("Error");
		return 0;
	}
	else if(!strcmp(argv[1],"-c"))
	{
		for(int i=0;i < strlen(argv[2]);i++)
		{
			if(argv[2][i] < '0' || argv[2][i] > '9')
			{
				puts("Error");
				return 0;
			}
		}
	}	
	freopen(".\\sudoku.txt", "w", stdout);
    num = atoi(argv[2]);
    sudo[0][0]=3;
	int i = 0, j = 1, x = 2, b = 0;
	set(i, j);
	for (x = 2; x <= num; x++)
	{
		for (i = 8; i >= 0; i--)
		{
			for (j = 8; j >= 0; j--)
			{
				for (b = sudo[i][j] + 1; b<10; b++)
				{
					sudo[i][j] = b;
					if (judge(i, j, b))
						set(i, j);
					break;
				}
			}
		}
	}
	return 0;
}

