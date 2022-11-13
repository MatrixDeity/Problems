/**
  LeetCode_901
  https://leetcode.com/problems/online-stock-span/
  MatrixDeity, 2022.
*/

package leetcode901

type Item struct {
	span  int
	price int
}

type StockSpanner struct {
	stack []Item
}

func Constructor() StockSpanner {
	return StockSpanner{
		stack: []Item{},
	}
}

func (this *StockSpanner) Next(price int) int {
	span := 1

	for len(this.stack) > 0 && this.stack[len(this.stack)-1].price <= price {
		n := len(this.stack)
		span += this.stack[n-1].span
		this.stack = this.stack[:n-1]
	}

	this.stack = append(this.stack, Item{span: span, price: price})

	return span
}
