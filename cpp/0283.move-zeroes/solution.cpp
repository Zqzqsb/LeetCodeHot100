// Created by ZQ at 2025/02/18 19:57
// leetgo: 1.4.8
// https://leetcode.cn/problems/move-zeroes/

/*
283. 移动零 (Easy)
给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

**示例 1:**

```
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
```

**示例 2:**

```
输入: nums = [0]
输出: [0]
```

**提示**:

- `1 <= nums.length <= 10⁴`
- `-2³¹ <= nums[i] <= 2³¹ - 1`

**进阶：** 你能尽量减少完成的操作次数吗？

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int i = 0 , j = 0;
		while(j < nums.size()) {
			if(nums[j] != 0 ) {
				swap(nums[i++] , nums[j]);
			}
			j ++;
		}
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res =obj->moveZeroes(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
