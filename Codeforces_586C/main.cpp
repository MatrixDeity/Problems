/**
�������:
  �������� - ���� �� ������ ������� ������������ ���������. ������� � ���� �� ����� ���������� n �������, ������� ����������� � ������� ����� ��� ���������.
  ��� ���� ����� ������ ������� �� ������ � ������� �����. ������������ ������� ������ ������� �� 1 �� n � ������� �������. ������ ������� ���������������
  ��������� ��������� pi. ���� �� ������� ���� �� ������ ������� � �������; ������ ��� � ����� ������� ������ ������� �� �������.
  ���� �������� ����� ���� i-�� �������, ������� ������ � ���������� vi. ��� ���� ��������� ������� ������� � ������� ����������� �� �������� vi,
  ������� - �� �������� vi-1, � ��� �����. ����, ����������� � ������� ����� vi-�� �������, ����������� �� ������ �����, ������� �� ��������� ��������
  ����������.
  ���� � �����-�� ������ ������� ��������� j-�� ������� ������ ������ ����, �� �� �������� ������� � ���������� dj �, ������� �������, ����� � ������,
  �� ������ � ������� �����. ��� ���� ��������� ���� �����, ����������� ����� j-�� � �������, ���������� �� �������� dj.
  ��� ��� ������� ���������� ���������, ���� �� ������ � �����-�� �������. ���� ����� ����� ����� �������� ������, ���������� "������ �������". ��� ������
  � �������� ���������� ����, � ������� ������� �������, ����������� � ������� ������.
  �������� ����������� �������� ���������� ������ �������, ������� �� ������� �����. ����� �������� � ��������������� �������.

����:
  � ������ ������ ������� ������ ��������� ����� ������������� ����� n (1 <= n <= 4000) - ���������� ������� � �������.
  � ��������� n ������� ��������� �� ��� ����� ����� vi, di, pi (1 <= vi, di, pi <= 10^6) - ��������� ����� � ��������, ��������� ����� � �������� �
  ��������� i-�� �������.

�����:
  � ������ ������ �������� ����� k - ���������� �������, ������� �������� ������� �����.
  �� ������ ������ �������� k ����� ����� - ������ �������, ������� �������� ����� �������, � ������� �����������.
*/

#include <stdio.h>
#include <list>

using namespace std;

typedef long long s64;

const int N = 4000;

struct Child
{
    s64 v, d, p;
};

int main()
{
    int n;
    Child arr[N];
    list<int> ans;

    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%I64i%I64i%I64i", &arr[i].v, &arr[i].d, &arr[i].p);

    for (int i = 0; i < n; ++i)
    {
        if (arr[i].p >= 0)
        {
            s64 v = arr[i].v;
            s64 d = 0;
            for (int j = i+1; j < n; ++j)
            {
                if (arr[j].p >= 0)
                {
                    arr[j].p -= (v > 0 ? v : 0) + d;
                    if (arr[j].p < 0)
                        d += arr[j].d;
                    --v;
                }

            }
            ans.push_back(i+1);
        }
    }

    printf("%i\n", ans.size());
    for (s64 x : ans)
        printf("%I64i ", x);

    return 0;
}
