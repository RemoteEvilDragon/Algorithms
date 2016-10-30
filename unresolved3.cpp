#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <array>

using namespace std;

void tripleSearch(vector<int>& nums,int left,int right)
{
    int allLenth = right-left;
    
    if(left == right)
    {
        
    }
    int firsStart = left;
    int firstEnd = allLenth/3;
    
    int secondStart = firstEnd+1;
    int secondEnd = allLenth*2/3;
    
    int thirdStart = secondEnd+1;
    int thirdEnd = right;
    
    int firstAll=0;
    for(int i=firsStart;i<=firstEnd;i++)
    {
        firstAll += nums.at(i);
    }
    
    int secondAll=0;
    for(int i=secondStart;i<=secondEnd;i++)
    {
        secondAll += nums.at(i);
    }
    
    
    if(firstAll == secondAll)
    {
        tripleSearch(nums,thirdStart,thirdEnd);
    }
    else
    {
        int thirdAll = 0;
        for(int i=thirdStart;i<thirdEnd;i++)
        {
            thirdAll+= nums.at(i);
        }
        
        if(firstAll == thirdAll)
            tripleSearch(nums,secondStart,secondEnd);
        else
            tripleSearch(nums,firsStart,firstEnd);
    }
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        
        
        
        
    };
};

int main(int argsNum,const char **args)
{
    
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    vector<int> nums = {1,2,1,2,3};
    
    cout<<mSolution->singleNumber(nums)<<endl;
    
    
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
