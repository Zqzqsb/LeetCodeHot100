// Created by ZQ at 2025/02/18 20:12
// leetgo: 1.4.8
// https://leetcode.cn/problems/3sum/

/*
15. 三数之和 (Medium)
给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、 `i != k` 
且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请你返回所有和为 `0` 且不重复的三元组
。

**注意：** 答案中不可以包含重复的三元组。

**示例 1：**

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

**示例 2：**

```
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
```

**示例 3：**

```
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
```

**提示：**

- `3 <= nums.length <= 3000`
- `-10⁵ <= nums[i] <= 10⁵`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
		vector<vector<int>>	 res;
		// 枚举所有三元组的左端点
		for(int i = 0 ; i < nums.size() ; i ++) {
			// 不重复枚举左端点
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			// 如果左端点已经大于 零， 不会再有合法的答案了
			if(nums[i] > 0) break;
			// 用双指针枚举另外两个点
			int l = i + 1 , r = nums.size() - 1;
			int target = -nums[i];
			while(l < r) {
				if(nums[l] + nums[r] == target) {
					res.push_back({nums[i] , nums[l] , nums[r]});
					// 不重复枚举点
					while(l < r && nums[l] == nums[l + 1]) l ++;
					while(l < r && nums[r] == nums[r - 1]) r --;
					l ++;
					r --;
				} else if(nums[l] + nums[r] < target) {
					l ++;
				} else {
					r --;
				}
			}
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
	auto res = obj->threeSum(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
