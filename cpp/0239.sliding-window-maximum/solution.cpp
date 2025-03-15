// Created by ZQ at 2025/03/15 11:21
// leetgo: 1.4.8
// https://leetcode.cn/problems/sliding-window-maximum/

/*
239. 滑动窗口最大值 (Hard)
给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在
滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

**示例 1：**

```
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**示例 2：**

```
输入：nums = [1], k = 1
输出：[1]
```

**提示：**

- `1 <= nums.length <= 10⁵`
- `-10⁴ <= nums[i] <= 10⁴`
- `1 <= k <= nums.length`

*/

#include <bits/stdc++.h>
#include <deque>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// 使用一个 单调递增的双端队列 更远更小的值是不好的
		deque<int> q;
		vector<int> res;	
		for(int i = 0 ; i < nums.size() ; i ++) {
			// 弹出队尾 直到队列为空或者队尾元素比当前元素大
			while(q.size() && nums[q.back()] <= nums[i]) q.pop_back();
			
			// 检查队头是否出窗口
			if(q.size() && q.front() < i - k + 1) q.pop_front();
			q.push_back(i);
			if(i >= k - 1) res.push_back(nums[q.front()]);
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
	auto res = obj->maxSlidingWindow(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
