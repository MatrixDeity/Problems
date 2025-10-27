/**
  LeetCode_2043
  https://leetcode.com/problems/simple-bank-system/
  MatrixDeity, 2025.
*/

package leetcode2043

type Bank struct {
	Balances []int64
}

func Constructor(balance []int64) Bank {
	return Bank{
		Balances: balance,
	}
}

func (b *Bank) Transfer(account1 int, account2 int, money int64) bool {
	if account1 > len(b.Balances) || account2 > len(b.Balances) {
		return false
	}

	if b.Balances[account1-1]-money < 0 {
		return false
	}

	b.Balances[account1-1] -= money
	b.Balances[account2-1] += money

	return true
}

func (b *Bank) Deposit(account int, money int64) bool {
	if account > len(b.Balances) {
		return false
	}

	b.Balances[account-1] += money

	return true
}

func (b *Bank) Withdraw(account int, money int64) bool {
	if account > len(b.Balances) {
		return false
	}

	if b.Balances[account-1]-money < 0 {
		return false
	}

	b.Balances[account-1] -= money

	return true
}
