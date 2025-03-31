#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; 
        
        map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }

        int count = 1;       
        int maxCount = 1;    

        auto i = m.begin();
        auto next = std::next(i);

        while (next != m.end()) {
            if (next->first - i->first == 1) { 
                count++;
            } else {
                maxCount = max(maxCount, count); 
                count = 1; 
            }
            i = next; 
            next = std::next(i);
        }

        
        maxCount = max(maxCount, count);

        return maxCount;
    }
};