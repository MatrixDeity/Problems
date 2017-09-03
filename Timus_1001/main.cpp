/**
ЗАДАНИЕ:
  Эта задача настолько проста, что авторы даже поленились сочинить для нее условие!

ВВОД:
  Входной поток содержит набор целых чисел Ai (0 <= Ai <= 1018), отделённых друг от друга произвольным количеством пробелов и переводов строк.
  Размер входного потока не превышает 256 КБ.

ВЫВОД:
  Для каждого числа Ai, начиная с последнего и заканчивая первым, в отдельной строке вывести его квадратный корень не менее чем с четырьмя
  знаками после десятичной точки.
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
