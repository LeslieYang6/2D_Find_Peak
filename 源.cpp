#include<iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

Point P;

int Find_Max(int array[])
{
	int length = 5;
	int count = length - 1;
	int j=0;
	for (int i = 0; i < count; i++)
		if (array[i] < array[i + 1])
			j = i + 1;
	return j;
}

Point Find_Peak(int array[][5], int start, int end)
{
	if (start == end)
	{   
		P.x = start;
		P.y = Find_Max(array[start]);
		return P;
	}
	int n = (start + end) / 2;
	if (n == 0)
		n++;
	int col = Find_Max(array[n]);
	if (array[n][col] >= array[n - 1][col] && array[n][col] >= array[n+1][col])
	{
		P.x = n;
		P.y = col;
		return P;
	}
	if (array[n][col] <= array[n - 1][col])
		return Find_Peak(array, start, n-1);
	if (array[n][col] <= array[n + 1][col])
		return Find_Peak(array, n, end);
}

int main()
{
	int array[5][5]=
	{
		{1, 2 , 3 ,4 ,5 },
		{2, 3 , 4 ,5 ,6 },
	    {3, 5 , 4, 6, 7 },
	    {4, 5,  4, 3, 2 },
	    {4, 6,  7, 3, 2 }
	};
	Point T = Find_Peak(array, 0, 4);
	cout << T.x << " " << T.y;
	system("pause");
	return 0;
}