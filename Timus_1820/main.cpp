/**
�������:
  ����� ������� ���������� ���������, �� �������� ������������ ����� � �������� ���������� ���������� � �������� ���� n ��������� ����������. ��� ����
  ����� ����������� ��������, ����� ������ ��������� ������ �� ��� ������ �� ��������� � ������� ����� ������.
  � ���������, � ������ ���� ������ ���� ���������, � �� ��� ����� ������������ ������ �� ����� k ����������. ����������, ������� ����� ����������� ������,
  ����� ��������� ����� �������������.

����:
  � ������������ ������ ����� ������ �������� ����� ����� n � k (1 <= n, k <= 1000).

�����:
  �������� ����������� ���������� �����, �� ������� ����� ������ ����������� n ����������.
*/

#include "iostream"
#include "cmath"

using namespace std;

int main()
{
  unsigned short n, k;
  cin >> n >> k;
  if(n > k) cout << ceil(n*2.f/k);
  else cout << 2;
  return 0;
}
