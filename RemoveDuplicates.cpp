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
    int removeDuplicates(vector<int>& nums) {
        
        int last = 0;
        int duplicateCount = 0;
        
        int index = 0;
        while(index<nums.size())
        {
            int cur = nums.at(index);
            if(index==0)
            {
                last = cur;
                index++;
            }
            else
            {
                if(last == cur)
                {
                    duplicateCount++;
                    nums.erase(nums.begin()+index);
                }
                else
                {
                    last = cur;
                    index++;
                }
            }
        }
        
        return (int)nums.size();
    }
};

int main(int argsNum,const char **args)
{
    
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    
    vector<int> nums = {1,1,1,2};
//    vector<int> nums = {};
    cout<<mSolution->removeDuplicates(nums)<<endl;
    
    
//    if (mSolution->isValid("()[]{}") )
//        cout<<"Stream is valid!"<<endl;
//    else
//        cout<<"Stream is invalid!"<<endl;

    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
