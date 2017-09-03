/**
�������:
  ������� ����� k-�������, ���� ��� �������� ��� �����, �� ������������� k (0, ..., k). ��� ���� ����� k � ������ a �� n �����. ������� ���������� k-�������
  ����� � a (������ ����� ����� ��������� ������� ���, ������� ��� ������ � ������ a).

����:
  � ������ ������ �������� ����� ����� n � k (1 <= n <= 100, 0 <= k <= 9). � i-� �� ��������� n ����� �������� ��� ������� ����� ����� �����
  ai (1 <= ai <= 10^9).

�����:
  �������� ������������ ����� ����� - ���������� k-������� ����� � a.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int DIGITS = 10;

bool digits[DIGITS];
int n, k, a, ans(0);

bool isGood(int a, int k)
{
    fill(digits, digits + DIGITS, false);
    while (a != 0)
    {
        digits[a % 10] = true;
        a /= 10;
    }
    for (int i = 0; i <= k; ++i)
        if (!digits[i])
            return false;
    return true;
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (isGood(a, k))
            ++ans;
    }

    cout << ans;
    return 0;
}
