/**
�������:
  ��, ��� �� ��� ��������� - ����� ����� ���� ����� �����, ������� ����� 1 � N ������������.

����:
  � ������������ ������ ����������� ����� N, �� ������ �� ������������� 10000.

�����:
  �������� ����� ����� - ����� ������.
*/

#include "stdio.h"

using namespace std;

typedef long long s64;

int main()
{
  s64 n, sum(0);
  scanf("%lli", &n);

  if(n < 1)
    for(s64 i = n; i <= 1; ++i)
      sum += i;
  else
    for(s64 i = n; i >= 1; --i)
      sum += i;

  printf("%lli", sum);
  return 0;
}
