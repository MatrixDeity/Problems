/**
  LeetCode_2442
  https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
  MatrixDeity, 2022.
*/

package leetcode2442

func reverseInteger(n int) int {
	res := 0

	for n > 0 {
		res *= 10
		res += n % 10
		n /= 10
	}

	return res
}

func countDistinctIntegers(nums []int) int {
	set := map[int]struct{}{}

	for _, num := range nums {
		set[num] = struct{}{}
		revNum := reverseInteger(num)
		set[revNum] = struct{}{}
	}

	return len(set)
}
