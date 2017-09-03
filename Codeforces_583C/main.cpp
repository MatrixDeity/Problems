/**
ЗАДАНИЕ:
  Таблица НОД G размера n * n для массива целых положительных чисел a длины n задается формулой
  Напомним, что наибольшим общим делителем (НОД) двух положительных целых чисел x и y называется наибольшее целое число, делящее одновременно и x и y, оно
  обозначается как . Например, для массива a = {4, 3, 6, 2} длины 4 таблица НОД будет выглядеть следующим образом:
    4 1 2 2
    1 3 3 1
    2 3 6 2
    2 1 2 2
  Зная все числа таблицы НОД G, восстановите массив a.

ВВОД:
  В первой строке содержится число n (1 <= n <= 500) - длина массива a. Во второй строке содержатся n2 чисел, разделенных пробелом - элементы таблицы НОД
  G для массива a. Все числа таблицы целые положительные и не превышают 10^9. Обратите внимание, что элементы заданы в произвольном порядке. Гарантируется,
  что набору входных данных соответствует некоторый массив a.

ВЫВОД:
  В единственную строку выведите n целых положительных чисел - элементы массива a. Если возможных решений несколько, разрешается вывести любое.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 500;

int gcd(int l, int r)
{
    return r > 0 ? gcd(r, l % r) : l;
}

int main()
{
    int n, counter(0);
    cin >> n;
    vector<int> arr(n * n);
    vector<int> ans;
    ans.reserve(N * N);
    unordered_map<int, int> m;
    unordered_map<int, int>::iterator fit, sit;
    for (int i = 0; i < n * n; ++i)
    {
        cin >> arr[i];
        ++m[arr[i]];
    }

    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < n * n; ++i)
    {
		fit = m.find(arr[i]);
		if (fit != m.end())
		{
			ans.push_back(fit->first);
			if (fit->second > 1)
				--fit->second;
			else
				m.erase(fit);
			for (int j = 0; j < counter; ++j)
            {
				sit = m.find(gcd(ans[j], arr[i]));
				if (sit->second > 2)
					sit->second -= 2;
				else
					m.erase(sit);
			}
			++counter;
		}
	}

    for (int x : ans)
        cout << x << ' ';
    return 0;
}
