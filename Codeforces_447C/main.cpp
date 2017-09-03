/**
�������:
  � DZY ���� ������������������ a, ��������� �� n ����� �����.
  ������� ������������������ ai, ai+1, ..., aj (1 <= i <= j <= n) ����������� ������������������ a. �������� (j - i + 1) ���������� ����� ����������.
  DZY ����� ����� ������������ �� ����� ���������� a, ���������� ��������� ���������. �� ���������� ����� �������� ������ ������������ ������������������,
  �������� ��������� �� ����� ������ �������� ���������� (����������� �������� �������� ������ �������� ���������� �� ����� ����� ��������).
  ���� ������ - ������� ����� �������� ������������ ����������.

����:
  � ������ ������ �������� ����� ����� n (1 <= n <= 10^5). � ��������� ������ �������� n ����� ����� a1, a2, ..., an (1 <= ai <= 10^9).

�����:
  � ������������ ������ �������� ����� �� ������ - ������������ ����� ����������.
*/

#include <iostream>

using namespace std;

const int N = 1e5;

int arr[N], directSums[N], backSums[N];
int n, ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    directSums[0] = backSums[n - 1] = 1;

    for (int i = 1; i < n; ++i)
        if (arr[i] > arr[i - 1])
            directSums[i] = directSums[i - 1] + 1;
        else
            directSums[i] = 1;
    for (int i = n - 2; i >= 0; --i)
        if (arr[i] < arr[i + 1])
            backSums[i] = backSums[i + 1] + 1;
        else
            backSums[i] = 1;
    ans = max(directSums[n - 2] + 1, backSums[1] + 1);
    for (int i = 1; i < n - 1; ++i)
    {
        ans = max(ans, max(directSums[i - 1] + 1, backSums[i + 1] + 1));
        if (arr[i - 1] + 1 < arr[i + 1])
            ans = max(ans, directSums[i - 1] + backSums[i + 1] + 1);
    }

    cout << ans;
    return 0;
}
