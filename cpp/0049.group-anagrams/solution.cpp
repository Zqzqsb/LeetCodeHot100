// Created by ZQ at 2025/05/06 17:10
// leetgo: 1.4.8
// https://leetcode.cn/problems/group-anagrams/

/*
49. 字母异位词分组 (Medium)
给你一个字符串数组，请你将 **字母异位词**
组合在一起。可以按任意顺序返回结果列表。

**字母异位词** 是由重新排列源单词的所有字母得到的一个新单词。

**示例 1:**

```
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**示例 2:**

```
输入: strs = [""]
输出: [[""]]
```

**示例 3:**

```
输入: strs = ["a"]
输出: [["a"]]
```

**提示：**

- `1 <= strs.length <= 10⁴`
- `0 <= strs[i].length <= 100`
- `strs[i]` 仅包含小写字母

*/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  public:
    static size_t hashArray(const array<int, 26> &arr) {
        size_t res{};
        hash<int> fn;

        for (auto c : arr)
            res = (res << 1) ^ fn(c);

        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<array<int, 26>, vector<string>,
                      decltype(&Solution::hashArray)>
            dict(1000, Solution::hashArray);
        
        for(auto &str : strs) {
            array<int , 26> arr{};
            for(auto c : str) {
                arr[c - 'a'] ++;
            }
            dict[arr].push_back(std::move(str));
        }
        
        for(auto& entry : dict) {
            res.emplace_back(entry.second);
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> strs;
    LeetCodeIO::scan(cin, strs);

    Solution *obj = new Solution();
    auto res = obj->groupAnagrams(strs);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
