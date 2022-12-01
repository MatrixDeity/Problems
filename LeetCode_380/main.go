/**
  LeetCode_380
  https://leetcode.com/problems/insert-delete-getrandom-o1/
  MatrixDeity, 2022.
*/

package leetcode380

import "math/rand"

type RandomizedSet struct {
	set map[int]int
	vec []int
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		set: map[int]int{},
		vec: []int{},
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.set[val]; ok {
		return false
	}

	this.set[val] = len(this.vec)
	this.vec = append(this.vec, val)
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.set[val]; !ok {
		return false
	}

	n := len(this.vec)
	lastVal := this.vec[n-1]
	this.vec[this.set[val]], this.vec[n-1] = this.vec[n-1], this.vec[this.set[val]]
	this.vec = this.vec[:n-1]
	this.set[lastVal] = this.set[val]
	delete(this.set, val)
	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.vec[rand.Intn(len(this.vec))]
}
