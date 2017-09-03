/**
�������:
  A � B ��������� � ���������� ��� ����������������.
  ����� ������� ���� ���������� �������� � ����� ������ ������, A � B ������ ������� � �������. �� ����� ���� A ���������, ��� �� ������� � ������ ������
  �������.
  ��� ������ ��������� ������ �������� �� ���:
    ��� ����� ����� 9,
    ��� ����� ����� 5,
    ��� ����� ����� 3,
    ��� ���� ����� 3,
    ��� ����� ����� 1,
    ��� ������ �� ����������� ��� ������ �������.
  ��� ������� ������ ����� ����� ����� ���� ��� ����� �� �����.
  ��� ��� A �� ����� �������, �� �������� ��� ������ ����������, ��� ������� ������ �� ���� ������� ������.

����:
  �� ���� �������� ������ �����, �� ������ �������� ������ - �������� �����.
  �� ����� ����� ������ ������������ ���������� �������, ������ ������ - ���������.
  ����� ������ ������������ ��������� �������: ����� ������������ �������� 'Q', ����� - 'R', ���� - 'B', ���� - 'N', ����� - 'P', ������ - 'K'.
  ������ ������ ������������, ��������������, 'q', 'r', 'b', 'n', 'p', 'k'.
  ������ ������ ����� ������������ �������� '.' (�����).

�����:
  �������� "White" (��� �������), ���� ��� ������� ����� ������ ���� ������� ������, "Black" ���� ��� ������� ������ ������ ���� ������� �����, � "Draw"
  ���� ���� ������� ����� � ������ �����.
*/

#include "iostream"
#include "cstring"

using namespace std;

int main()
{
  unsigned iBlack(0), iWhite(0);
  string s[8];
  for(int i = 0; i < 8; i++)
    cin >> s[i];
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      switch(s[i][j])
      {
        case 'q':
            iBlack += 9;
            break;
        case 'r':
            iBlack += 5;
            break;
        case 'b':
        case 'n':
            iBlack += 3;
            break;
        case 'p':
            iBlack += 1;
            break;

        case 'Q':
            iWhite += 9;
            break;
        case 'R':
            iWhite += 5;
            break;
        case 'B':
        case 'N':
            iWhite += 3;
            break;
        case 'P':
            iWhite += 1;
            break;
      }
  if(iWhite > iBlack)
    cout << "White";
  else
    if(iWhite < iBlack)
      cout << "Black";
    else
      cout << "Draw";
}
