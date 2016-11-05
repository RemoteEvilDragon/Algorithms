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
class Solution {
public:
    int myAtoi(string str) {
        
        while(str.size()>0)
        {
            if(str.at(0) == ' ')
                str.erase(str.begin());
            else
                break;
        }
        
        float num = 0;
        
        bool isMinus = false;
        
        
        int validEnd = (int)str.size()-1;
        for(int i=0;i<str.size();i++)
        {
            char ch = str.at(i);
            int digit = (int)ch;
            
            if(digit < 43 || digit == 44 || digit == 46 || digit==47 || digit>57 )
            {
                validEnd = i-1;
                break;
            }
        }
        
        if(validEnd < 0)
            return num;
        else
        {
            str = string(str,0,validEnd+1);
        }
        
        
        
        for(int i=0;i<str.size();i++)
        {
            char ch = str.at(i);
            int digit = (int)ch;
            
            if(digit < 43 || digit == 44 || digit == 46 || digit==47 || digit>57 )
                return num;
            
            if(digit == 43 || digit == 45)
            {
                if( i == 0 )
                {
                    if(digit == 45  )
                        isMinus = true;
                }
                else
                {
                    
                    return num;
                }
            }
            else
            {
                digit -= 48;
                
                num += digit*pow(10,str.size()-1-i);
                
                cout<<num<<endl;
                if(num - 2147483647.0f > .0f && !isMinus)
                    return 2147483647;
                
                if(num > 2147483648 && isMinus)
                    return -2147483648;
            }
        }
        
        if(isMinus)
            num = -num;
        
        return num;
    }
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
//    int a = (int)' ';
//    cout<<a<<endl;
    
    cout<< mSolution->myAtoi("2147483648")<<endl;
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    
    return 0;
};
