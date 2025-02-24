// Created by ZQ at 2025/02/21 18:06
// leetgo: 1.4.8
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/

/*
438. 找到字符串中所有字母异位词 (Medium)
给定两个字符串 `s` 和 `p`，找到 `s` 中所有 `p` 的 **异位词** 的子串，返回这些子串的起始索引。不考虑
答案输出的顺序。

**示例 1:**

```
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
```

**示例 2:**

```
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
```

**提示:**

- `1 <= s.length, p.length <= 3 * 10⁴`
- `s` 和 `p` 仅包含小写字母

*/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        if(s.length() < p.length()) return {};
        array<int , 200> pattern{} , window{};
        
        for(int i = 0 ; i < p.length() ; i ++) {
            pattern[p[i]] ++;
            window[s[i]] ++; 
        }
        
        vector<int> res{};
        int start{0} , end = p.length() - 1;
        while(end < s.length()) {
            if(pattern == window) {
               res.push_back(start ); 
            }
            if(end == s.length() - 1) break;
            window[s[start ++]] --;
            window[s[++ end]] ++;
        } 
        return res;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    string p;
    LeetCodeIO::scan(cin, p);

    Solution* obj = new Solution();
    auto res = obj->findAnagrams(s, p);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
