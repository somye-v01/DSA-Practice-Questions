func twoSum(nums []int, target int) []int {
	mp := make(map[int]int)

	for idx, val := range nums {
		ntf := target - val

		if val, ok := mp[ntf]; ok {
			return []int{idx, val}
		}

		mp[val] = idx
	}

	return []int{-1, -1}
}