// Created by ZQ at 2025/02/18 20:31
// leetgo: 1.4.8
// https://leetcode.cn/problems/trapping-rain-water/

/*
42. 接雨水 (Hard)
给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

**示例 1：**

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png)

```
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色
部分表示雨水）。
```

**示例 2：**

```
输入：height = [4,2,0,3,2,5]
输出：9
```

**提示：**

- `n == height.length`
- `1 <= n <= 2 * 10⁴`
- `0 <= height[i] <= 10⁵`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int trap(vector<int>& height) {
        // 维护 LMAX 和  RMAX ，双指针移动过程中算矮的那一侧
		int l = 0 , r = height.size() - 1;
		int LMAX{0} , RMAX{0};
		int res = 0;
			
		while(l < r) {
			LMAX = max(height[l] ,LMAX);
			RMAX = max(height[r] , RMAX);
			
			if(height[l] < height[r]) {
				res += min(LMAX , RMAX) - height[l];
				l ++;			
			} else {
				res += min(LMAX , RMAX) - height[r];
				r --;
			}
		}
		return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> height;
	LeetCodeIO::scan(cin, height);

	Solution *obj = new Solution();
	auto res = obj->trap(height);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
