#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <array>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//        list<int> sorted;
        //        for(auto &it:nums)
        //        {
        //            sorted.push_back(it);
        //        }
        
        vector<vector<int>> tripleLists;
        
        std::sort(nums.begin(), nums.end(),std::less<int>());
        
        
        
        
        return tripleLists;
    };
};

int main(int argsNum,const char **args)
{
    
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    mSolution->threeSum(nums);

    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
