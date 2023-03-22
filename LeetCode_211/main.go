/**
  LeetCode_211
  https://leetcode.com/problems/design-add-and-search-words-data-structure/
  MatrixDeity, 2023.
*/

package leetcode211

type Node struct {
	children map[byte]*Node
	isWord   bool
}

func NewNode() *Node {
	return &Node{
		children: map[byte]*Node{},
		isWord:   false,
	}
}

type WordDictionary struct {
	root *Node
}

func Constructor() WordDictionary {
	return WordDictionary{
		root: NewNode(),
	}
}

func (this *WordDictionary) AddWord(word string) {
	ptr := this.root

	for i := range word {
		char := word[i]

		if ptr.children[char] == nil {
			ptr.children[char] = NewNode()
		}

		ptr = ptr.children[char]
	}

	ptr.isWord = true
}

func (this *WordDictionary) Search(word string) bool {
	return searchImpl(word, this.root)
}

func searchImpl(word string, root *Node) bool {
	ptr := root

	for i := range word {
		char := word[i]

		if char == '.' {
			for _, child := range ptr.children {
				if searchImpl(word[i+1:], child) {
					return true
				}
			}

			return false
		} else {
			if _, ok := ptr.children[char]; !ok {
				return false
			}

			ptr = ptr.children[char]
		}
	}

	return ptr.isWord
}
