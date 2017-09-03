/**
«¿ƒ¿Õ»≈:
  Today Berland holds a lottery with a prize - a huge sum of money! There are k persons, who attend the lottery. Each of them will receive a unique integer
  from 1 to k.
  The organizers bought n balls to organize the lottery, each of them is painted some color, the colors are numbered from 1 to k. A ball of color C
  corresponds to the participant with the same number. The organizers will randomly choose one ball - and the winner will be the person whose color will be
  chosen!
  Five hours before the start of the lottery the organizers realized that for the lottery to be fair there must be an equal number of balls of each of k
  colors. This will ensure that the chances of winning are equal for all the participants.
  You have to find the minimum number of balls that you need to repaint to make the lottery fair. A ball can be repainted to any of the k colors.

¬¬Œƒ:
  The first line of the input contains two integers n and k (1 <= k <= n <= 100) - the number of balls and the number of participants. It is guaranteed
  that n is evenly divisible by k.
  The second line of the input contains space-separated sequence of n positive integers ci (1 <= ci <= k), where ci means the original color of the i-th
  ball.

¬€¬Œƒ:
  In the single line of the output print a single integer - the minimum number of balls to repaint to make number of balls of each color equal.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, n, k, max, ans(0);
	cin >> n >> k;
	vector<int> arr(k, 0);
	for (int i = 0; i < n; ++i)
		cin >> a, ++arr[a-1];

	max = n / k;
	for (int x : arr)
		if (x < max)
			ans += max - x;

	cout << ans;
	return 0;
}

