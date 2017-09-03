/**
�������:
  A � B ��������� � ���������� ��� ����������������.
  B ����� ����� ���������� ���� ���. �� ����� ���, ��� ��������� ������� � ������ �������, ��� ����� ������� ��������������.
  ���������� ���������� ������� n ������ ����������, ������ �� ������� ������������ ������������� ����� ������. ����� ��������� ������, B ������� ���������
  ������� ����, � ����� ��� ���� ������.
  ������, �������� �� ��, ��� B ������, ��� �������� ��� ������, �� �� ����� ������, ����� ������ ������ ���������� ������� - ���������� �����, �� �������
  ����� B, ������ ��� ������ ������ � ����� �������! B ������, ��� � ������� �� ������ ������ ������ ����������������, ������ ���������� ��� ��� �����
  ���������������� �� ������� ���� �� �����, �. �. �� ����������� ����� ������, ��������� ��������� ������ �� ����������.
  � �� ������ ������ B ������, ����� ������ ��� ������ �� ��������?

����:
  ������ ������ ������� ������ �������� ����� ����� n (3 <= n <= 10^5) - ����������� ���������� ������ ����������.
  ������ ������ �������� n ����� ����� ����� ������ a1, a2, ..., an (1 <= ai <= 10^9) - ������ ������, �������� ������������ � ������ ���.
  ������ ������ �������� n-1 ����� ����� ����� ������ b1, b2, ..., bn-1 - ������ ������, �������� ��� ������ ����������. �������������, ���
  ������������������ � ������� ������ �������� ��� ����� ������ ������, �� ����������� ����� ������.
  ��������� ������ �������� n-2 ����� ����� ����� ������ �1, �2, ..., �n-2 - ������ ������, �������� ��� ������� ����������. �������������, ���
  ������������������ � ��������� ������ �������� ��� ����� ������� ������, �� ����������� ����� ������.

�����:
  �������� ��� ����� �� ��������� ������: ������ ������ ����������, ����������� ����� ���� ��� B ���� ������ � ������ ����������� ��������������.
*/

#include "iostream"
#include "map"

using namespace std;

typedef unsigned long long u64;

int main()
{
  map<u64, u64> uMap1, uMap2, uMap3, uMapTemp;
  u64 count, k;
  cin >> count;
  for(u64 i = 0; i < count; i++)
  {
    cin >> k;
    uMap1[k]++;
  }

  for(u64 i = 0; i < count-1; i++)
  {
    cin >> k;
    uMap2[k]++;
  }

  for(u64 i = 0; i < count-2; i++)
  {
    cin >> k;
    uMap3[k]++;
  }

  for(auto mapNode : uMap1)
    if(mapNode.second != uMap2[mapNode.first])
    {
      cout << mapNode.first << endl;
      break;
    }

  for(auto mapNode : uMap2)
    if(mapNode.second != uMap3[mapNode.first])
    {
      cout << mapNode.first << endl;
      break;
    }

  return 0;
}
