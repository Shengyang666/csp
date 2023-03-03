#include <cmath>
#include <iostream>

/*
16 11 10 16 24 40 51 61
12 12 14 19 26 58 60 55
14 13 16 24 40 57 69 56
14 17 22 29 51 87 80 62
18 22 37 56 68 109 103 77
24 35 55 64 81 104 113 92
49 64 78 87 103 121 120 101
72 92 95 98 112 100 103 99
26
2
-26 -3 0 -3 -2 -6 2 -4 1 -3 1 1 5 1 2 -1 1 -1 2 0 0 0 0 0 -1 -1
*/
using namespace std;
class Direction
{
public:
	int RowAdd;
	int ColAdd;
	Direction(int  RowAdd, int ColAdd);

	Direction& operator=(Direction p);
	bool operator==(Direction p);
};
double a(int i)
{
	if (i == 0)
		return sqrt(0.5);
	else
		return 1;
}
double rCalculate(int M[8][8], int row, int col)
{
	double ret = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ret += a(i) * a(j) * M[i][j] * cos(acos(-1) / 8 * (row + 0.5) * i) * cos(acos(-1) / 8 * (col + 0.5) * j) / 4;
		}
	}
	return ret;
}

int main()
{
	int Q[8][8] = { 0 };
	int M[8][8] = { 0 };
	int n = 0;
	int T;
	int data[64] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> Q[i][j];
		}
	}
	cin >> n;
	cin >> T;
	for (int i = 0; i < n; i++)
	{

		cin >> data[i];

	}
	Direction dir1(0, 1);
	Direction dir2(1, -1);
	Direction dir3(1, 0);
	Direction dir4(-1, 1);
	Direction CurDir(0, 1);
	int i = 0;
	int row = 0;
	int col = 0;
	while (i < n)
	{
		if (CurDir == dir1)
		{
			if (row == 0)
			{
				if (col == 0);
				else
				{
					CurDir = dir2;
				}

			}
			else
			{
				if (row == 7)
				{
					CurDir = dir4;
				}
			}

		}
		else
		{
			if (CurDir == dir2)
			{
				if (col == 0&&row!=7)
					CurDir = dir3;
				else
				{
					if (row == 7)
						CurDir = dir1;
				}

			}
			else
			{
				if (CurDir == dir3)
				{
					if (col == 0&&row!=7)
						CurDir = dir4;
					else
					{
						if (col == 7)
							CurDir = dir2;
					}
				}
				else
				{
					if (row == 0)
						CurDir = dir1;
					else
					{
						if (col == 7)
							CurDir = dir3;
					}
				}
			}
		}
		M[row][col] = data[i];
		row += CurDir.RowAdd;
		col += CurDir.ColAdd;
		i++;
	}
	if (T == 0)
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << M[i][j] << "\t";
			}
			cout << M[i][7];
			if (i != 7)
				cout << endl;
		}
		return 0;
	}


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			M[i][j] *= Q[i][j];
		}
	}
	if (T == 1)
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << M[i][j] << "\t";
			}
			cout << M[i][7];
			if (i != 7)
				cout << endl;
		}
		return 0;
	}

	double m[8][8] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m[i][j] = rCalculate(M, i, j);
			m[i][j] += 128;
			m[i][j] = round(m[i][j]);
			if (m[i][j] > 255)m[i][j] = 255;
			if (m[i][j] < 0)m[i][j] = 0;
		}
	}

	if (T == 2)
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << m[i][j] << "\t";
			}
			cout << m[i][7];
			if (i != 7)
				cout << endl;
		}
		return 0;
	}
	std::cout << "Hello World!\n";
}


Direction::Direction(int RowAdd, int ColAdd)
{
	this->RowAdd = RowAdd;
	this->ColAdd = ColAdd;
}



Direction& Direction::operator=(Direction p)
{
	this->ColAdd = p.ColAdd;
	this->RowAdd = p.RowAdd;
	return *this;

	// TODO: 在此处插入 return 语句
}

bool Direction::operator==(Direction p)
{
	if (this->ColAdd == p.ColAdd && this->RowAdd == p.RowAdd)
		return true;
	else
		return false;
	// TODO: 在此处插入 return 语句
}
