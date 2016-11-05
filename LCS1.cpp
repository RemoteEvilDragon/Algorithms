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
};

MaxSum iterRateRange(vector<int> &inputNums,int left,int right)
{
    MaxSum curMaxSum={0};
    
    int middle = (left+right)/2;
    
    if (left == middle || right == middle)
    {
        curMaxSum.begin = left;
        curMaxSum.end = left;
        curMaxSum.max = left;
        return curMaxSum;
    }
    
    MaxSum leftMax = iterRateRange(inputNums,left,middle-1);
    
    MaxSum rightMax = iterRateRange(inputNums, middle+1, right);
    
    curMaxSum.max = inputNums.at(middle);
    
    int curSum = curMaxSum.max;
    
    curMaxSum.begin = middle;
    for(int i=middle-1;i>=0;i--)
    {
        curSum += inputNums.at(i);
        
        if( curSum > curMaxSum.max  )
        {
            curMaxSum.max = curSum;
            curMaxSum.begin = i;
        }
    }
    
    curMaxSum.end = middle;
    for(int i=middle+1;i<inputNums.size();i++)
    {
        curSum += inputNums.at(i);
        
        if( curSum > curMaxSum.max  )
        {
            curMaxSum.max = curSum;
            curMaxSum.end = i;
        }
    }

    
    if(leftMax.max > rightMax.max)
    {
        if(leftMax.max > curMaxSum.max)
        {
            return leftMax;
        }
        else
        {
            return curMaxSum;
        }
        
    }
    else
    {
        if(rightMax.max > curMaxSum.max)
            return rightMax;
        else
            return curMaxSum;
    }
}

class Solution {
public:
    //26进制
    MaxSum getMax(vector<int> &inputNums){
        
        return iterRateRange(inputNums, 0, (int)inputNums.size()-1);
        
    }
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
//    int a = (int)' ';
//    cout<<a<<endl;
    vector<int> input = {13,-3,-25,20,3,16,-2,18,20,-7,12,-5,-22,15,-4,7};
    
    
    MaxSum sum =  mSolution->getMax(input);
    
    cout<<sum.begin<<" "<<sum.end<<" "<<sum.max<<endl;
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    
    return 0;
};
