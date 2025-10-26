/**
  LeetCode_1575
  https://leetcode.com/problems/count-all-possible-routes/
  MatrixDeity, 2023.
*/

package leetcode1575

const (
	MOD = 1e9 + 7
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func countRoutes(locations []int, start int, finish int, fuel int) int {
	dp := make(map[[2]int]int)

	var impl func(currLoc, currFuel int) int
	impl = func(currLoc, currFuel int) int {
		if currFuel < 0 {
			return 0
		}

		key := [2]int{currLoc, currFuel}
		if val, ok := dp[key]; ok {
			return val
		}

		count := 0
		if currLoc == locations[finish] {
			count = 1
		}

		for _, loc := range locations {
			fuelCost := abs(loc - currLoc)
			if loc == currLoc || currFuel < fuelCost {
				continue
			}

			count = (count + impl(loc, currFuel-fuelCost)) % MOD
		}

		dp[key] = count
		return count
	}

	return impl(locations[start], fuel)
}
