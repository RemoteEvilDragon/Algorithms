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

//'-':45
//'+':43
//'0':48
//...
//'9':57
struct MaxSum{
    int begin;
    int end;
    int max;
    
    int begin2;
    int max2;
};

MaxSum iterRateRange2(vector<int> &inputNums,int endIndex)
{
    if(endIndex == 0)
    {
        MaxSum curMaxSum={0};
        curMaxSum.max = inputNums.at(0);
        curMaxSum.max2 = inputNums.at(0);
        
        return curMaxSum;
    }
    else//not a very good solution.optimize later.
    {
        MaxSum last = iterRateRange2(inputNums, endIndex-1);
        
        int curSum = 0;
        int newBegin2 = last.begin2;
        
        for(int i=endIndex;i>=last.begin2;i--)//This is slow.
        {
            curSum += inputNums.at(i);
            
            if(curSum > last.max2)
            {
                last.max2 = curSum;
                newBegin2 = i;
            }
        }
        
        last.begin = newBegin2;
        
        if(last.max2 > last.max)
        {
            last.end = endIndex;
            last.begin2 = newBegin2;
            last.max = last.max2;
            
            return last;
        }
        else
        {
            return last;
        }
        
    }
}

class Solution {
public:
    //26进制
    MaxSum getMax(vector<int> &inputNums){
        
        return iterRateRange2(inputNums,  (int)inputNums.size()-1);
        
    }
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
//    int a = (int)' ';
//    cout<<a<<endl;
//    3 11 75
    vector<int> input = {2,-1,343,1,1,1,-10,-10,-10,12,-10,-10,13,-3,-25,20,3,16,-2,18,20,-7,12,-5,-22,15,-4,7};
    
    
    MaxSum sum =  mSolution->getMax(input);
    
    cout<<sum.begin<<" "<<sum.end<<" "<<sum.max<<endl;
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    
    return 0;
};
