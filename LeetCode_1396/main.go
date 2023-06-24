/**
  LeetCode_1396
  https://leetcode.com/problems/design-underground-system/
  MatrixDeity, 2023.
*/

package leetcode1396

type Route struct {
	start string
	end   string
}

type CheckIn struct {
	start string
	time  int
}

type UndergroundSystem struct {
	checkIn map[int]CheckIn
	total   map[Route]int
	count   map[Route]int
}

func Constructor() UndergroundSystem {
	return UndergroundSystem{
		checkIn: make(map[int]CheckIn),
		total:   make(map[Route]int),
		count:   make(map[Route]int),
	}
}

func (this *UndergroundSystem) CheckIn(id int, stationName string, t int) {
	this.checkIn[id] = CheckIn{
		start: stationName,
		time:  t,
	}
}

func (this *UndergroundSystem) CheckOut(id int, stationName string, t int) {
	r := Route{
		start: this.checkIn[id].start,
		end:   stationName,
	}

	this.total[r] += t - this.checkIn[id].time
	this.count[r]++
	delete(this.checkIn, id)
}

func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
	r := Route{
		start: startStation,
		end:   endStation,
	}

	return float64(this.total[r]) / float64(this.count[r])
}
