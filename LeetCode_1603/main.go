/**
  LeetCode_1603
  https://leetcode.com/problems/design-parking-system/
  MatrixDeity, 2023.
*/

package leetcode1603

type ParkingSystem struct {
	Big    int
	Medium int
	Small  int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{
		Big:    big,
		Medium: medium,
		Small:  small,
	}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	if carType == 1 {
		this.Big--
		return this.Big >= 0
	}

	if carType == 2 {
		this.Medium--
		return this.Medium >= 0
	}

	this.Small--
	return this.Small >= 0
}
