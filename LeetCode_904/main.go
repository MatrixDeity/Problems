/**
  LeetCode_904
  https://leetcode.com/problems/fruit-into-baskets/
  MatrixDeity, 2023.
*/

package leetcode904

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func totalFruit(fruits []int) int {
	res := 0
	i, j := 0, 0
	counter := make(map[int]int)

	for j = range fruits {
		counter[fruits[j]]++
		for len(counter) > 2 {
			counter[fruits[i]]--
			if counter[fruits[i]] == 0 {
				delete(counter, fruits[i])
			}
			i++
		}

		res = max(j-i+1, res)
	}

	return res
}
