/**
  LeetCode_1146
  https://leetcode.com/problems/snapshot-array/
  MatrixDeity, 2023.
*/

package leetcode1146

import "sort"

type Snapshot struct {
	value  int
	snapID int
}

type SnapshotArray struct {
	data [][]Snapshot
	snap int
}

func Constructor(length int) SnapshotArray {
	data := make([][]Snapshot, length)

	for i := range data {
		data[i] = make([]Snapshot, 1)
	}

	return SnapshotArray{
		data: data,
	}
}

func (a *SnapshotArray) Set(index int, val int) {
	bucket := a.data[index]
	lastIdx := len(bucket) - 1

	if bucket[lastIdx].snapID < a.snap && bucket[lastIdx].value != val {
		a.data[index] = append(bucket, Snapshot{val, a.snap})
	} else {
		a.data[index][lastIdx].value = val
	}
}

func (a *SnapshotArray) Snap() int {
	a.snap++
	return a.snap - 1
}

func (a *SnapshotArray) Get(index int, snapID int) int {
	bucket := a.data[index]
	lastIdx := len(bucket) - 1

	idx := sort.Search(len(bucket), func(i int) bool {
		return (i < lastIdx && bucket[i+1].snapID > snapID) || i == lastIdx
	})

	return bucket[idx].value
}
