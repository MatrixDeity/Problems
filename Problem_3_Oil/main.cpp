/**
  Задача "3. Нефтяные пятна". Решил Тетерин Денис, ИВБ-2-13.
  МИРЭА, 2015.
*/

#include "iostream"

#define MAX 100

using namespace std;

int field[MAX][MAX];
int m, n, count(0);

void checkCell(int i, int j);

//====================================================================================================

int main()
{
	cin >> m >> n;
	for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
      cin >> field[i][j];

	for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
    {
      if(field[i][j] == 1)
        ++count;
      checkCell(i, j);
    }

	cout << count;
	return 0;
}

//====================================================================================================

void checkCell(int i, int j)
{
	if(field[i][j] == 1)
	{
		field[i][j] = 0;
		if(i > 0)
			checkCell(i-1, j);
		if(i < m-1)
			checkCell(i+1, j);
		if(j > 0)
			checkCell(i, j-1);
		if(j < n-1)
			checkCell(i, j+1);
	}
}
