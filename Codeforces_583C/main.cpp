/**
�������:
  ������� ��� G ������� n * n ��� ������� ����� ������������� ����� a ����� n �������� ��������
  ��������, ��� ���������� ����� ��������� (���) ���� ������������� ����� ����� x � y ���������� ���������� ����� �����, ������� ������������ � x � y, ���
  ������������ ��� . ��������, ��� ������� a = {4, 3, 6, 2} ����� 4 ������� ��� ����� ��������� ��������� �������:
    4 1 2 2
    1 3 3 1
    2 3 6 2
    2 1 2 2
  ���� ��� ����� ������� ��� G, ������������ ������ a.

����:
  � ������ ������ ���������� ����� n (1 <= n <= 500) - ����� ������� a. �� ������ ������ ���������� n2 �����, ����������� �������� - �������� ������� ���
  G ��� ������� a. ��� ����� ������� ����� ������������� � �� ��������� 10^9. �������� ��������, ��� �������� ������ � ������������ �������. �������������,
  ��� ������ ������� ������ ������������� ��������� ������ a.

�����:
  � ������������ ������ �������� n ����� ������������� ����� - �������� ������� a. ���� ��������� ������� ���������, ����������� ������� �����.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 500;

int gcd(int l, int r)
{
    return r > 0 ? gcd(r, l % r) : l;
}

int main()
{
    int n, counter(0);
    cin >> n;
    vector<int> arr(n * n);
    vector<int> ans;
    ans.reserve(N * N);
    unordered_map<int, int> m;
    unordered_map<int, int>::iterator fit, sit;
    for (int i = 0; i < n * n; ++i)
    {
        cin >> arr[i];
        ++m[arr[i]];
    }

    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < n * n; ++i)
    {
		fit = m.find(arr[i]);
		if (fit != m.end())
		{
			ans.push_back(fit->first);
			if (fit->second > 1)
				--fit->second;
			else
				m.erase(fit);
			for (int j = 0; j < counter; ++j)
            {
				sit = m.find(gcd(ans[j], arr[i]));
				if (sit->second > 2)
					sit->second -= 2;
				else
					m.erase(sit);
			}
			++counter;
		}
	}

    for (int x : ans)
        cout << x << ' ';
    return 0;
}
