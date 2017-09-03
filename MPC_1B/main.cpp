/**
�������:
  ������������ �������� ���������� �������� ������� ������� 4*4 ������, � ������� �������� ������ ������-������. ������� ������� �� ������ ������, �������
  ����� �� ������, ����� � � ������� ������ ������ ������� ������ (��. �������). ����� ����� ������� ������������ �� ������� ������� �� 90 ��������. ���
  ����� ������������ ��� ����� ���������� ����� ����������� ��� ��������, � � ������� ���������� ������ ������. ����� � ������� ������������ ���������
  ������ ������� ������, ����� ���� ����� ������������ ������� �� 90 ��������. ������� ��������� ������ �������, �������� ��� ���� ������� ������� � �����
  ����� ����� ��������� ������ ������� ������. ������, �� ���� ����� �� ������������ �������, ����� ������ ������������ ������ �� ������������� �������� �
  16 ���������. ����� �������, ����� ���� ��������� � ������������� �������� ������.
  �����������, � ���� ���� ������ �������, ������� ����������� �������, �������� ����������� ���� ������, � ������������ � ���������� ���������� ������� �
  16 ���������. ���� ������ - ������������ ������.

����:
  � ������ ������ ������� ���� ������������ �������. ������ � ��� ���������� ��������� "X", � ������ - ��������� "." (������� ��������� ���������).
  ��������� ���� ������� ������������� ���� ���������, � �������� ���������� ����������� ������. �������������, ��� ������ ������� ���������, �� ���� �
  �������� ���������� � ������� ������ ����� ���������� ������, � ������� ��� ������ �� ��������. ����� ����, ��������, ��� ������� ������, �� ���� ��������
  ����� ������ ������.
  � ��������� ������ ������� ��� ������� � ������������� �������. ��� ���������� � �������� ������� - �������� � ��������� ��������� �����. ������� �
  ������������� ������� ����� ������� ��������� ����� ������.

�����:
  �������� ������ ������ 16 �������� - �������� ������.
*/


#include <iostream>

using namespace std;

const int N = 4;

string ans;
bool holes[N][N];
char letters[N][N];
char c;

int main()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N;)
        {
            cin >> c;
            if (c == 'X')
                holes[i][j++] = true;
            else if (c == '.')
                holes[i][j++] = false;
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N;)
        {
            cin >> c;
            if (c != ' ')
                letters[i][j++] = c;
        }

    for (int k = 0; k < 4; ++k)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (holes[i][j])
                    ans.push_back(letters[i][j]);
        for (int i = 0; i < N / 2; ++i)
            for (int j = i; j < N-i-1; ++j)
            {
                bool temp = holes[i][j];
                holes[i][j] = holes[N-j-1][i];
                holes[N-j-1][i] = holes[N-i-1][N-j-1];
                holes[N-i-1][N-j-1] = holes[j][N-i-1];
                holes[j][N-i-1] = temp;
            }
    }
    cout << ans;
    return 0;
}

/*
. . . .
X . . X
. X . .
. . . X
P w o o
K h a a
s m r s
o d b k
*/
