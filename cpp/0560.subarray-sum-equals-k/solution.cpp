// Created by ZQ at 2025/03/07 17:14
// leetgo: 1.4.8
// https://leetcode.cn/problems/subarray-sum-equals-k/

/*
560. 和为 K 的子数组 (Medium)
给你一个整数数组 `nums` 和一个整数 `k` ，请你统计并返回 该数组中和为 `k` 的子数组的个数 。

子数组是数组中元素的连续非空序列。

**示例 1：**

```
输入：nums = [1,1,1], k = 2
输出：2
```

**示例 2：**

```
输入：nums = [1,2,3], k = 3
输出：2
```

**提示：**

- `1 <= nums.length <= 2 * 10⁴`
- `-1000 <= nums[i] <= 1000`
- `-10⁷ <= k <= 10⁷`

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	// target = presum[i] - presum[j] ==> presum[j] = currsum - target
    int subarraySum(vector<int>& nums, int k) {
		int currsum = 0;
		std::unordered_map<int , int> presums;
		presums[0] = 1;
		int res = 0;	

        for(auto num : nums) {
			currsum += num;
			if(presums.contains(currsum - k)) {
				res += presums[currsum - k];
			}
			presums[currsum] ++;
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
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->subarraySum(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
