#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        int k = 0;
        for (int i = 0; i < array.size(); ++i)
        {   
            if (array[i] % 2 == 1)
            {
                int j = i;
                int tmp = array[i];
                while (j > 0)
                {
                    if (j <= k) break;
                    swap(array[j], array[j-1]);
                    --j;
                }
                k++;
            }
        }
        return array;
    }
};