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
    int strStr(string haystack, string needle) {
        
        int sameCount=0;
        
        //use strConverter to something else.
        for(int i=0;i<haystack.size();i++)
        {
            char hay = haystack.at(i);
            
            for(int j=0;j<needle.size();j++)
            {
                
            }
        }
        return -1;
    }
};

int main(int argsNum,const char **args)
{
    
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    
    vector<int> nums = {1,1,1,2};
//    vector<int> nums = {};
    cout<<mSolution->strStr("this is simple question","simple")<<endl;
    
    
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
