/**
�������:
  ����� - ���� �� ���������� ����������� ����������. �� ���� ������ ����� ������� ������, ������� ������ "������������".
  ��� ����� ���� �������� �� ����� �� 8 ����� � 8 ��������. � ������ ������ ���� �� ����� �������� ��������� ������ � ����� �����.
  ���������� ������ �����, ������������ �� �����, �� ����������� ��������� ���������� ������������ ����� �����.
  ����������� ������ � ������� ������ ������� �� 1 �� 8. ������ ������������� ������ ����, � �� ����� ��� ������� ������������� �����
  �������. ������ ��������� ��� (r, c) ������, ������������� � ������ r � ������� c.
  � ���� ������ ������ ��� ������, A � B. ����� A ����� ������ �������, � ����� B ����� �������. ���� ������ A - ��������� ����� �� �����
  ����� � ��� 1, � �� ����� ��� ����� B ��������� ��������� ����� �� ����� ����� � ��� 8. ��� ������ ���� �� ������� ��������� ���� ������,
  ���� ���������� �������������, � ��������� ���� ����� ����������� �����������.
  ������ ����� �� �������, �������� ����� �. �� ����� ���� ����� A ������ ������� ����� ���� ����� ����� � ����������� � �� ���� ������
  �����, � ����� B �� ����� ������ ���� ������ ������� ����� ���� ������ ����� � ����������� � �� ���� ������ ����. ����� ��� ��������
  ������ ���� ������, � ������� ��� �����, ������. �������������, ��� ��� ������ �������� �������� ���� ������� ������ ����� ��������
  ��� ������� ���� ���.
  �������� ����� ��������, ��� �����, ������������� � ������ (r, c), �������� � ������ (r-1, c), � �������� ���� ��������, ��� �����,
  ������������� � ������ (r, c), ������� � ������ (r+1, c). ��� ��� ��������, ��� ��������������� ������ ������ ���� ������, �� ���� ��
  ������ ��������� �����.
  �� ������� ������������ ������������ ����� �� �����, ����������, ��� �������� � ����, ���� ��� ������ ��������� ����������. ��������
  ��������, ��� ��������� �����������, ��� ��� ������ �������� �������� ���� � ����� ������� ������ ����� ��������� ����, ����
  ����������� ���������� ������� ������ �� ���.

����:
  ������� ������ �������� ������ ����� �� ������ �������� � ������, ����������� ��������� ����� ����� ������� ����. ������ �������������
  ����� � ������� � ������� �� ���� 1 �� ���� 8. ������ 'B' ������������ ��� ����������� ������ �����, � ������ 'W' ���������� �����
  �����. ������ ������ ������������ �������� '.'.
  �������������, ��� �� ���� ����� ����� �� ����������� � ������ ����, � �� ���� ������ ����� �� ����������� � ��������� ����.

�����:
  �������� 'A', ���� ����� A �������� ���� �� ������ ����� � 'B', ���� ������� ����� B. ��� ��� ��������, ��� �� ������ ����� ������
  ����� ����������.
*/

#include <iostream>
#include <cmath>

using namespace std;

char c;
int bMin(INFINITY), wMin(INFINITY);
char field[8][8];
int black[8] = {8, 8, 8, 8, 8, 8, 8, 8};
int white[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

int main()
{
    for (int i = 0; i < 8; ++ i)
        for (int j = 0; j < 8; ++j)
        {
            cin >> field[i][j];
            if (field[i][j] == 'W')
                white[j] = max(white[j], i);
            else if (field[i][j] == 'B')
                black[j] = min(black[j], i);
        }

    for (int i = 0; i < 8; ++ i)
        for (int j = 0; j < 8; ++j)
            if (field[i][j] == 'W' && i < black[j])
                wMin = min(wMin, i);
            else if (field[i][j] == 'B' && i > white[j])
                bMin = min(wMin, 7 - i);

    cout << (wMin <= bMin ? 'A' : 'B');
    return 0;
}
