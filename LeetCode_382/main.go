/**
  LeetCode_382
  https://leetcode.com/problems/linked-list-random-node/
  MatrixDeity, 2023.
*/

package leetcode382

import "math/rand"

type ListNode struct {
	Val  int
	Next *ListNode
}

type Solution struct {
	List *ListNode
	N    int
}

func Constructor(head *ListNode) Solution {
	res := Solution{
		List: head,
	}

	for ptr := head; ptr != nil; {
		ptr = ptr.Next
		res.N++
	}

	return res
}

func (this *Solution) GetRandom() int {
	rnd := rand.Intn(this.N)
	ptr := this.List

	for rnd > 0 {
		rnd--
		ptr = ptr.Next
	}

	return ptr.Val
}
