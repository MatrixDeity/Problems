/**
  LeetCode_705
  https://leetcode.com/problems/design-hashset/
  MatrixDeity, 2023.
*/

package leetcode705

const (
	N int = 1e6 + 1
)

type MyHashSet struct {
	keys []bool
}

func Constructor() MyHashSet {
	return MyHashSet{
		keys: make([]bool, N),
	}
}

func (this *MyHashSet) Add(key int) {
	this.keys[key] = true
}

func (this *MyHashSet) Remove(key int) {
	this.keys[key] = false
}

func (this *MyHashSet) Contains(key int) bool {
	return this.keys[key]
}
