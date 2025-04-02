// Created by ZQ at 2025/04/02 23:51
// leetgo: 1.4.8
// https://leetcode.cn/problems/maximum-subarray/

/*
53. 最大子数组和 (Medium)
给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
。

**子数组** 是数组中的一个连续部分。

**示例 1：**

```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

**示例 2：**

```
输入：nums = [1]
输出：1
```

**示例 3：**

```
输入：nums = [5,4,-1,7,8]
输出：23
```

**提示：**

- `1 <= nums.length <= 10⁵`
- `-10⁴ <= nums[i] <= 10⁴`

**进阶：** 如果你已经实现复杂度为 `O(n)` 的解法，尝试使用更为精妙的 **分治法** 求解。

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	static const int N = 1e5;
	int dp[N];
    int maxSubArray(vector<int>& nums) {
		memset(dp , 0 , sizeof(dp));

		int res = nums[0];
		for(int i = 1 ; i < nums.size() ; i ++) {
			if (dp[i - 1] <= 0) dp[i] = nums[i];
			else dp[i] = dp[i - 1] + nums[i];
			
			res = max(res , dp[i]);
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
	auto res = obj->maxSubArray(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
