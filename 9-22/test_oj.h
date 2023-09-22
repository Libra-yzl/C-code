#pragma once

#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.begin() + k + 1);
        reverse(nums.begin() + k + 1, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

void test_oj1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    /*v.push_back(5);
    v.push_back(6);
    v.push_back(7);*/

    Solution sol;
    sol.rotate(v, 3);
    for (auto e : v) cout << e << " ";
    cout << endl;
}