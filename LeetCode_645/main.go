/**
  LeetCode_645
  https: //leetcode.com/problems/set-mismatch/
  MatrixDeity, 2022.
*/

package leetcode645

type nothing struct{}

func findErrorNums(nums []int) []int {
	set := map[int]nothing{}
	sum := 0
	bad, good := -1, -1
	for _, num := range nums {
		sum += num
		if _, ok := set[num]; ok {
			bad = num
		}
		set[num] = nothing{}
	}

	badSum := sum - bad
	n := int64(len(nums))
	var rightSum int64
	if n%2 == 0 {
		rightSum = n / 2 * (n + 1)
	} else {
		rightSum = (n + 1) / 2 * n
	}

	good = int(rightSum) - badSum

	return []int{bad, good}
}
