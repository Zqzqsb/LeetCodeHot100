// Created by ZQ at 2025/07/04 14:42
// leetgo: 1.4.8
// https://leetcode.cn/problems/two-sum/

/*
1. 两数之和 (Easy)
给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值**`target`  的那 *
*两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

**示例 1：**

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```
输入：nums = [3,3], target = 6
输出：[0,1]
```

**提示：**

- `2 <= nums.length <= 10⁴`
- `-10⁹ <= nums[i] <= 10⁹`
- `-10⁹ <= target <= 10⁹`
- **只会存在一个有效答案**

**进阶：** 你可以想出一个时间复杂度小于 `O(n²)` 的算法吗？

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
			std::unordered_map<int , int> mp{};
			for(int i = 0 ; i < nums.size() ; i ++) {
				if(mp.contains(target - nums[i])) {
					return {i , mp[target -nums[i]]};
				} else {
					mp[nums[i]] = i;
				}
 			}
			return {};
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->twoSum(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
