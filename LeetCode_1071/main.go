/**
  LeetCode_1071
  https://leetcode.com/problems/greatest-common-divisor-of-strings/
  MatrixDeity, 2023.
*/

package leetcode1071

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func gcdOfStrings(str1 string, str2 string) string {
	if str1+str2 != str2+str1 {
		return ""
	}
	return str1[:gcd(len(str1), len(str2))]
}
