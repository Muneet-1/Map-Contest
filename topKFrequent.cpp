#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freqmap; 
        
        for (int num : nums) {
            freqmap[num]++;
        }

        priority_queue<pair<int, int>> maxheap;
        for (auto& entry : freqmap) {
            maxheap.push({entry.second, entry.first}); 
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return result;
    }
};