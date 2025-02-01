// Created by ZQ at 2025/02/02 00:06
// leetgo: 1.4.13
// https://leetcode.cn/problems/two-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int , int> mp;
		
		for(int i = 0 ; i < nums.size() ; i ++) {
			if(mp.find(target - nums[i]) != mp.end()) {
				return {i , mp[target - nums[i]]};
			}
			mp[nums[i]] = i;
		}
		return {-1 , -1};
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->twoSum(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
