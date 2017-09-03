/**
�������:
  � ������������� ���������� ������������� ���������� ����. �� ��������� ������ ����� ������� ����� ��� ������ ���������. �������, ��� �� ����� ��������
  ������ ������ ������������. ����� ��������� ���� ������ ������ ����� ������������� ���. ������ ����� � ���� ��������� ������ - ������ ����� ������������
  �����, �� � ���� ������ ������, �� �� ����� �������: �� ������������������ �������, � ����������� �������.
  ������ � ������ ��������� ����� �������� �� ������ ������. �����������, ��������� �������� �������� - �������� ������� ���� - ������� ������ � ������,
  � ���� �������. ���� ������� ����������� �� ������� ��������, ������, �� 80 ��/�, � ����� ����� �������� ����� ����������, �� �� ��������� ���������
  ������� ����. ��� �������� �� ������ � ����� �������, �� � � �������� ����� � ����� �� ������������ � ��������. �� ������� ���������� ������� ������� -
  ��� ���������� �������. �� ������� �������� � ����� �����, ����������� ������ � ��� ������� ����� �������.
  ����������� ����������� ���� ������ �������� �������� � �������� ��������������� ���� �������� � ��������� �� �������. ��� ���� ����� �������������
  �������, �������� ���� ���������� �� ����������� ������. ������ ����� ���� ��� ���� ����������� �� ������ �������, �� ������ ���� ����� �����������
  ��-�������. ����� ��������� �������� ���� �����, ���������� ������ ������� ������ �������� ���� (������ ������� �� � ������) � ���������� ���������.
  ���������� ��������� ������� ���� �����. ��������� �� ��� ����������� ���������, ��� ����� ���������� ��� �������������. ����� ������ ���� �� ����������.
  ������ ��� ����� ��������������� ������� �������� ���, ���������� �� ��������� �������. ���������� �������� ��� �������� ����, ������� ����� �������������
  �� ������, � ������ ����� ������, �� ������� ������� �� ������.

����:
  � ������ ������ �������� ����� ����� n - ���������� ��������� �������� ��� (1 <= n <= 150).
  � ��������� ������ ����� ������ �������� n ����� - �������� ����� � ����������� (����� ����� �� 600 �� 700).

�����:
  �������� ���������� �������, ������� ������� ��������� ��������� ������ �� ���������� ������.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 101;

int arr[N];
int n, a, ans(0);

int main()
{
    fill(arr, arr + N, 0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (++arr[a - 600] == 4)
        {
            arr[a - 600] -= 4;
            ++ans;
        }
    }

    cout << ans;
    return 0;
}
