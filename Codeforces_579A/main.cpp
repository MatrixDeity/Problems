/**
�������:
  �� - ������� �������� ��������. ��� ������� ��������� ������� �������� � ���������.
  ���������� ��������� �����. ������ ���� ����� �������� ����� ���������� �������� � ���������. ������ ���� ������ �������� ������� �� ��� ��������.
  �����-������ �� ��������� ������� ����� x �������� � ���������.
  ����� ����������� ���������� �������� ��� �������� ���� �������� � ��������� ��� ���������� ���� ����?

����:
  � ������������ ������ �������� ���� ����� ����� x (1 <= x <= 10^9) - ���������� ��������.

�����:
  ������������ ������, ���������� ���� ����� ����� - ����� �� ������.
*/

#include <iostream>

using namespace std;

long long x, total(0), ans(0);

int main()
{
    cin >> x;

    do
    {
        if (x % 2)
            ++ans;
    } while (x /= 2);

    cout << ans;
    return 0;
}
