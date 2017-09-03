#include <iostream>

using namespace std;

string str;
int len, point, pow, beg, en;

int main()
{
    cin >> str;

    len = (int)str.length();
    point = len;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] != '0' && str[i] != '.')
        {
            beg = i;
            break;
        }
    }
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '.')
        {
            point = i;
            break;
        }
    }
    pow = point - beg;
    if (beg < point)
        --pow;
    cout << str[beg];
    for (int i = len - 1; i >= 0; --i)
    {
		if (str[i] != '0' && str[i] != '.')
		{
			en = i;
            break;
		}
	}
	if (en >= beg + 1)
    {
		cout << ".";
		for (int i = beg + 1; i <= en; ++i)
		{
			if (str[i] != '.')
                cout << str[i];
		}
	}
	if (pow != 0)
        cout << "E" << pow;

    return 0;
}
