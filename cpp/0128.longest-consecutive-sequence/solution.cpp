// Created by ZQ at 2025/02/18 19:38
// leetgo: 1.4.8
// https://leetcode.cn/problems/longest-consecutive-sequence/

/*
128. 最长连续序列 (Medium)
给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

**示例 1：**

```
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

**示例 2：**

```
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
```

**示例 3：**

```
输入：nums = [1,0,1,2]
输出：3
```

**提示：**

- `0 <= nums.length <= 10⁵`
- `-10⁹ <= nums[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) return 0;
		unordered_set<int> set;
		for(auto i : nums) set.insert(i);

		int res = 1;	
		for(auto i : set) {
			if(res > set.size() / 2) return res;
			if(set.contains(i - 1)) continue;
			
			int t = i;
			while(set.contains(t + 1)) t ++;
			res = max(res , t - i + 1);
		}
		return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->longestConsecutive(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
