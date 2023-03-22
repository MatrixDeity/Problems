/**
  LeetCode_1472
  https://leetcode.com/problems/design-browser-history/
  MatrixDeity, 2023.
*/

package leetcode1472

type BrowserHistory struct {
	buff []string
	idx  int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func Constructor(homepage string) BrowserHistory {
	return BrowserHistory{
		buff: []string{homepage},
		idx:  0,
	}
}

func (this *BrowserHistory) Visit(url string) {
	this.idx++

	if this.idx < len(this.buff) {
		this.buff = this.buff[:this.idx]
	}

	this.buff = append(this.buff, url)
}

func (this *BrowserHistory) Back(steps int) string {
	this.idx = max(this.idx-steps, 0)

	return this.buff[this.idx]
}

func (this *BrowserHistory) Forward(steps int) string {
	this.idx = min(this.idx+steps, len(this.buff)-1)

	return this.buff[this.idx]
}
