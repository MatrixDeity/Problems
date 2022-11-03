/**
  LeetCode_49
  https://leetcode.com/problems/group-anagrams/
  MatrixDeity, 2022.
*/

package leetcode49

func groupAnagrams(strs []string) [][]string {
	m := map[[26]int][]string{}

	for _, str := range strs {
		counter := [26]int{}
		for i := range str {
			counter[str[i]-'a']++
		}

		m[counter] = append(m[counter], str)
	}

	res := make([][]string, 0, len(m))
	for _, strs := range m {
		res = append(res, strs)
	}

	return res
}
