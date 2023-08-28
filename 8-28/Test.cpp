#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        size_t count = 0;
//        size_t len = nums.size() - 1;
//        for (size_t i = 0; i < nums.size(); ++i)
//        {
//            if (nums[i] == val)
//            {
//                if (len <= i)
//                    break;
//                ++count;
//                if (nums[len] == val)
//                    --len;
//                swap(nums[i], nums[len--]);
//            }
//        }
//        return len + 1;
//    }
//};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0, end = nums.size()-1;
        while (begin < end)
        {
            if (nums[begin] == val)
            {
                nums[begin] = nums[end];
                --end;
            }
            else
                ++begin;
        }
        return begin+1;
    }
};

int main()
{
    vector<int> v;
    //v.resize(4, 0);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);

    Solution sol;
    int size = sol.removeElement(v, 3);

    for (int i = 0; i < size; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

//int main()
//{
//    vector<int> v(10, 0);
//    //v.size()--;
//    cout << v.size() << endl;
//    return 0;
//}