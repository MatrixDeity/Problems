/**
  LeetCode_2654
  https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
  MatrixDeity, 2025.
*/

package leetcode2654

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	if a < 0 {
		return -a
	}
	return a
}

func minOperations(nums []int) int {
	n := len(nums)

	ones := 0
	for _, x := range nums {
		if x == 1 {
			ones++
		}
	}
	if ones > 0 {
		return n - ones
	}

	g := 0
	for _, x := range nums {
		g = gcd(g, x)
	}
	if g > 1 {
		return -1
	}

	const MAX = int(1e9)
	best := MAX
	for i := 0; i < n; i++ {
		cur := 0
		for j := i; j < n; j++ {
			cur = gcd(cur, nums[j])
			if cur == 1 {
				if length := j - i + 1; length < best {
					best = length
				}
				break
			}
		}
	}

	return (best - 1) + (n - 1)
}
