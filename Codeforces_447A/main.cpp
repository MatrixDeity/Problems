/**
�������:
  � DZY ���� ���-������� � p ��������, ���������������� �� 0 �� p - 1. �� ����� �������� � ���-������� n ����� � �������� �������: i-� ����� xi DZY �����
  �������� � ������ ���-������� � ������� h(xi), ��� h(x) - ���-�������. � ���� ������ �� ����� �������, ��� h(x) = x mod p. �������� a mod b ��������
  ������ ������� �� ������� a �� b.
  ������ ������ ������ ���-������� ����� ��������� �� ����� ������ ��������. ���� DZY ����� �������� ����� � ��� ������� ������, �� ���������� "��������".
  ��� ����� ����� ����� ������� ��������, ��� ������� �������� ���������� ��������.
  ���� ������ �������� ���������� ����� ����� ������� i-�� ��������, ���� ������� i. ���� �������� ����� �� ����������, �������� -1.

����:
  � ������ ������ �������� ��� ����� ����� p � n (2 <= p, n <= 300). ����� ������� n �����. � i-� ������ �������� ����� ����� xi (0 <= xi <= 10^9).

�����:
  �������� ������������ ����� ����� - ����� �� ������.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 300;

bool table[N];
int n, p, x, ans(-1);

int main()
{
    cin >> p >> n;
    fill(table, table + N, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        int pos = x % p;
        if (ans == -1 && table[pos])
        {
            ans = i + 1;
        }
        table[pos] = true;
    }

    cout << ans;
    return 0;
}
