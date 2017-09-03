/**
�������:
  ��� ������ ��������� ������, ��� ������ ���� ���������� �������� ��� ��� �������!

����:
  ������� ����� �������� ����� ����� ����� Ai (0 <= Ai <= 1018), ��������� ���� �� ����� ������������ ����������� �������� � ��������� �����.
  ������ �������� ������ �� ��������� 256 ��.

�����:
  ��� ������� ����� Ai, ������� � ���������� � ���������� ������, � ��������� ������ ������� ��� ���������� ������ �� ����� ��� � ��������
  ������� ����� ���������� �����.
*/

#include "iostream"
#include "iomanip"
#include "vector"
#include "cmath"

using namespace std;

int main()
{
  vector<unsigned long long> v;
  unsigned long long l;
  while(cin >> l)
    v.push_back(l);
  cout.setf(ios::fixed);
  for(int i = v.size()-1; i >= 0; i--)
    cout << setprecision(4) << sqrt(v[i]) << endl;
}
