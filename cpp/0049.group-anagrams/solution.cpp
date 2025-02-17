// Created by ZQ at 2025/02/17 19:18
// leetgo: 1.4.8
// https://leetcode.cn/problems/group-anagrams/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

// @lc code=begin
using strArr = array<int, 26>;

class Solution {
public:
    static size_t hashArr(const strArr& arr)
    {
        size_t hashVal {};
        hash<int> fn;

        for (auto c : arr) {
            hashVal = (hashVal << 1) ^ fn(c);
        }

        return hashVal;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        unordered_map<strArr, vector<string>, decltype(&Solution::hashArr)> mp(1000, Solution::hashArr);

        for (auto& str : strs) {
            strArr t {};
            for (auto c : str) {
                t[c - 'a']++;
            }
            mp[t].push_back(std::move(str));
        }

        for (auto& entry : mp) {
            res.push_back(entry.second);
        }
        return res;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> strs;
    LeetCodeIO::scan(cin, strs);

    Solution* obj = new Solution();
    auto res = obj->groupAnagrams(strs);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
