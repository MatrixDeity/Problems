/**
  LeetCode_1011
  https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
  MatrixDeity, 2023.
*/

package leetcode1011

func shipWithinDays(weights []int, days int) int {
	isOK := func(capacity int) bool {
		currCapacity := capacity
		currDays := 1

		for _, weight := range weights {
			if currCapacity-weight < 0 {
				currDays++
				currCapacity = capacity
			}
			currCapacity -= weight
		}

		return currDays <= days
	}

	down, up := 0, 0

	for _, weight := range weights {
		if weight > down {
			down = weight
		}
		up += weight
	}

	for down <= up {
		capacity := down + (up-down)/2
		if isOK(capacity) {
			up = capacity - 1
		} else {
			down = capacity + 1
		}
	}

	return down
}
