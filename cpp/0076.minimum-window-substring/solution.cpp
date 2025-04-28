// Created by ZQ at 2025/04/28 17:07
// leetgo: 1.4.8
// https://leetcode.cn/problems/minimum-window-substring/

/*
76. 最小覆盖子串 (Hard)
给你一个字符串 `s` 、一个字符串 `t` 。返回 `s` 中涵盖 `t`
所有字符的最小子串。如果 `s` 中不存在涵盖 `t` 所有字符的子串，则返回空字符串
`""` 。

**注意：**

- 对于 `t` 中重复字符，我们寻找的子字符串中该字符数量必须不少于 `t`
中该字符数量。
- 如果 `s` 中存在这样的子串，我们保证它是唯一的答案。

**示例 1：**

```
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
```

**示例 2：**

```
输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
```

**示例 3:**

```
输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
```

**提示：**

- `ᵐ ⁼⁼ ˢ.ˡᵉⁿᵍᵗʰ`
- `ⁿ ⁼⁼ ᵗ.ˡᵉⁿᵍᵗʰ`
- `1 <= m, n <= 10⁵`
- `s` 和 `t` 由英文字母组成

**进阶：** 你能设计一个在 `o(m+n)` 时间内解决此问题的算法吗？

*/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool statisfy(int target[], int curr[]) {
        for (int i = 'a'; i <= 'z'; i++)
            if (curr[i] < target[i])
                return false;
        for (int i = 'A'; i <= 'Z'; i++)
            if (curr[i] < target[i])
                return false;
        return true;
    }
    string minWindow(string s, string t) {
        int target[200]{}, curr[200]{};

        for (auto c : t)
            target[c]++;

        int left = 0, right = 0;
        string res = "";
        bool already_covered = false;
        while (right < s.length()) {
            curr[s[right++]]++;

            // 如果从来没有覆盖过 当前也不能覆盖
            if (!already_covered && !statisfy(target, curr)) {
                continue;
            }
            already_covered = true;

            // 已经覆盖过 每次都在不破坏覆盖的情况下移动左端点 如果这个元素不要
            // 或者这个元素已经超标 可以弹出
            while (left < right &&
                   (target[s[left]] == 0 || curr[s[left]] > target[s[left]])) {
                curr[s[left++]]--;
            }
            if (res == "" || res.length() > right - left)
                res = s.substr(left, right - left);
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
    string t;
    LeetCodeIO::scan(cin, t);

    Solution *obj = new Solution();
    auto res = obj->minWindow(s, t);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
