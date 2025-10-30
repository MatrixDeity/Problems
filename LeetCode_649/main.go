/**
  LeetCode_649
  https://leetcode.com/problems/dota2-senate/
  MatrixDeity, 2023.
*/

package leetcode649

func predictPartyVictory(senate string) string {
	builder := []byte(senate)
	score := 0

	for i := 0; i < len(builder); i++ {
		if builder[i] == 'R' {
			if score < 0 {
				builder = append(builder, 'D')
			}
			score++
		} else {
			if score > 0 {
				builder = append(builder, 'R')
			}
			score--
		}
	}

	if score > 0 {
		return "Radiant"
	}
	return "Dire"
}
