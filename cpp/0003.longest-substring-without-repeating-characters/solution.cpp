// Created by ZQ at 2025/02/21 17:56
// leetgo: 1.4.8
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

/*
3. 无重复字符的最长子串 (Medium)
给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长 子串** 的长度。

**示例 1:**

```
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

**提示：**

- `0 <= s.length <= 5 * 10⁴`
- `s` 由英文字母、数字、符号和空格组成

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s == "") return 0;
       	array<int , 200> counts{};
		int start = 0 , end = 0;
		int res = 1;
		
		while(end < s.length()) {
			while(counts[s[end]]) {
				counts[s[start ++ ]] --;
			}
			counts[s[end++]] ++;
			res = max(res , end - start);
		}
		return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->lengthOfLongestSubstring(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
