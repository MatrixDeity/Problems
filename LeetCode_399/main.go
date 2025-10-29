/**
  LeetCode_399
  https://leetcode.com/problems/evaluate-division/
  MatrixDeity, 2023.
*/

package leetcode399

type Node struct {
	Name  string
	Value float64
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	graph := make(map[string][]Node)
	res := make([]float64, len(queries))

	for i, equation := range equations {
		from := equation[0]
		to := equation[1]

		graph[from] = append(graph[from], Node{to, values[i]})
		graph[to] = append(graph[to], Node{from, 1.0 / values[i]})
	}

	var impl func(from, to string, visited map[string]bool) (float64, bool)
	impl = func(from, to string, visited map[string]bool) (float64, bool) {
		if from == to {
			return 1.0, true
		}

		for _, next := range graph[from] {
			if visited[next.Name] {
				continue
			}

			visited[next.Name] = true
			if value, ok := impl(next.Name, to, visited); ok {
				return value * next.Value, true
			}
		}

		return -1.0, false
	}

	for i, query := range queries {
		from := query[0]
		to := query[1]
		visited := make(map[string]bool)

		if _, ok := graph[from]; !ok {
			res[i] = -1.0
		} else {
			res[i], _ = impl(from, to, visited)
		}
	}

	return res
}
