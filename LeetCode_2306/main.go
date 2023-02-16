/**
  LeetCode_2306
  https://leetcode.com/problems/naming-a-company/
  MatrixDeity, 2023.
*/

package leetcode2306

func distinctNames(ideas []string) int64 {
	ideasCounter := make([]map[string]struct{}, 26)
	var res int64

	for i := range ideasCounter {
		ideasCounter[i] = make(map[string]struct{})
	}

	for _, idea := range ideas {
		ideasCounter[idea[0]-'a'][idea[1:]] = struct{}{}
	}

	for i := 0; i < 25; i++ {
		for j := i + 1; j < 26; j++ {
			mutCount := 0

			for idea := range ideasCounter[i] {
				if _, ok := ideasCounter[j][idea]; ok {
					mutCount++
				}
			}

			res += int64(2 * (len(ideasCounter[i]) - mutCount) * (len(ideasCounter[j]) - mutCount))
		}
	}

	return res
}
