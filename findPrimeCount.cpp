#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <math.h>

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TreeNode root={1};
//
//TreeNode item1(2);
//TreeNode item2(2);
//TreeNode item3(3);
//TreeNode item4(4);
//TreeNode item5(5);
//TreeNode item6(6);
//TreeNode item7(7);
//TreeNode item8(8);
//
//root.left = &item1;
//root.right= &item2;
//
//item1.left = &item3;
//item1.right = &item4;
//
//item2.left = &item5;
//item2.right = &item6;
//
//item6.left = &item7;
//item7.left = &item8;

class Solution {
public:
    int countPrimes(int n) {//Memory limit excedeed.
        
        int primeCount = 0;
        
        vector<int> numbers;
        for(int i=2;i<=n-1;i++)
        {
            numbers.push_back(i);
        }
        
        int index = 0;
        while(index < numbers.size())
        {
            int cur = numbers.at(index);
            int utmostIndex = 0;
            int everyIndex = 2;
            
            primeCount++;
            
            while(utmostIndex < numbers.size())
            {
                utmostIndex = everyIndex*cur-2;
                
                if(utmostIndex >= numbers.size())
                    break;
                
                numbers.at(utmostIndex) = 0;
                
                everyIndex++;
            }
            
            while(index < numbers.size())
            {
                index++;
                
                if(index == numbers.size())
                    break;
                
                if(numbers.at(index) != 0)
                    break;
            }
        }
        
        return primeCount;
    }
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    cout<< mSolution->countPrimes(1500000)<<endl;
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    
    return 0;
};
