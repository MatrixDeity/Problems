/**
ЗАДАНИЕ:
  Назовем число k-хорошим, если оно содержит все цифры, не превосходящие k (0, ..., k). Вам дано число k и массив a из n чисел. Найдите количество k-хороших
  чисел в a (каждое число нужно посчитать столько раз, сколько оно входит в массив a).

ВВОД:
  В первой строке записаны целые числа n и k (1 <= n <= 100, 0 <= k <= 9). В i-й из следующих n строк записано без ведущих нулей целое число
  ai (1 <= ai <= 10^9).

ВЫВОД:
  Выведите единственное целое число - количество k-хороших чисел в a.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int DIGITS = 10;

bool digits[DIGITS];
int n, k, a, ans(0);

bool isGood(int a, int k)
{
    fill(digits, digits + DIGITS, false);
    while (a != 0)
    {
        digits[a % 10] = true;
        a /= 10;
    }
    for (int i = 0; i <= k; ++i)
        if (!digits[i])
            return false;
    return true;
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (isGood(a, k))
            ++ans;
    }

    cout << ans;
    return 0;
}
