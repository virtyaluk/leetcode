package main
func findLadders(beginWord string, endWord string, wordList []string) [][]string {

	buildReverseDict := func() map[string][]string {
		adjacencyList := make(map[string][]string)
		for _, word := range wordList {
			for i := 0; i < len(word); i++ {
				pattern := fmt.Sprintf("%s.%s", word[:i], word[i+1:])
				adjacencyList[pattern] = append(adjacencyList[pattern], word)
			}
		}

		reverseDict := map[string][]string{beginWord: {}}

		q := []string{beginWord}

		for len(q) > 0  {
			n := len(q)
			visitedThisLevel := make(map[string][]string)
			for i := 0; i < n; i++ {
				word := q[0]
				q = q[1:]
				for i := 0; i < len(word); i++ {
					pattern := fmt.Sprintf("%s.%s", word[:i], word[i+1:])
					for _, nextWord := range adjacencyList[pattern] {
						if _, ok1 := reverseDict[nextWord]; !ok1 {
							if _, ok2 := visitedThisLevel[nextWord]; !ok2 {
								visitedThisLevel[nextWord] = []string{word}
								q = append(q, nextWord)
							} else {
								visitedThisLevel[nextWord] = append(visitedThisLevel[nextWord], word)
							}
						}
					}
				}

			}

			for k, v := range visitedThisLevel {
				reverseDict[k] = append(reverseDict[k], v...)
			}

		}
		return reverseDict
	}

	contains := func(seq []string, s string) bool {
		for _, v := range seq {
			if v == s {
				return true
			}
		}
		return false
	}

	if !contains(wordList, endWord) {
		return [][]string{}
	}

	reverseDict := buildReverseDict()

	buildWordLadders := func() [][]string {
		var dfs func(node string) [][]string
		dfs = func(node string) [][]string {
			if node == beginWord {
				return [][]string{{beginWord}}
			}
			if _, ok := reverseDict[node]; !ok {
				return [][]string{}
			}
			result := [][]string{}

			for _, parent := range reverseDict[node] {
				parentPathes := dfs(parent)
				for i := 0; i < len(parentPathes); i++ {
					result = append(result, parentPathes[i])
				}
				if node == endWord {
					fmt.Print(endWord)
				}
				for i := len(result) - 1; i > len(result)-len(parentPathes)-1; i-- {
					result[i] = append(result[i], node)
				}
			}

			return result
		}
		return dfs(endWord)
	}

	return buildWordLadders()
}