/**
  LeetCode_134
  https://leetcode.com/problems/gas-station/
  MatrixDeity, 2023.
*/

package leetcode134

func canCompleteCircuit(gas []int, cost []int) int {
	totalGas, totalCost := 0, 0
	res := 0

	curr := 0
	for i := range gas {
		totalCost += cost[i]
		totalGas += gas[i]
		curr += gas[i] - cost[i]

		if curr < 0 {
			res = i + 1
			curr = 0
		}
	}

	if totalGas < totalCost {
		return -1
	}
	return res
}
