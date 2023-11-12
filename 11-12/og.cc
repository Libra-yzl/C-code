#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2) const
        {
            return ((kv1.second  > kv2.second) || (kv1.second == kv2.second && kv1.first < kv2.first));
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mapCount;
        for (auto& ele : words) {
            mapCount[ele]++;
        }

        vector<pair<string, int>> sortV(mapCount.begin(), mapCount.end());
        // sort(sortV.begin(), sortV.end(), Compare());
        stable_sort(sortV.begin(), sortV.end(), Compare());

        vector<string> retV;
        vector<pair<string, int>>::iterator it = sortV.begin();
        while (k-- && it != sortV.end()) {
            retV.push_back(it->first);
            ++it;
        }
        return retV;
    }
};