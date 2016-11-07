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

//use the most simple to solve.insert compare.

//int get

struct kNode{
    int val;
    int count;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int freq) {
        map<int,vector<int>> results;
        
        map<int,int> frequencyMap;
        
        for(auto &it:nums)
        {
            auto iter = frequencyMap.find(it);
            if(iter != frequencyMap.end())
            {
                //erase last one.
                
                int lastCount = frequencyMap.at(it);
                
                vector<int> *p = &results.at(lastCount);
                
                for(int i=0;i<p->size()-1;i++)
                {
                    if(p->at(i) == it)
                    {
                        p->erase(p->begin()+i);
                        break;
                    }
                }
                
                frequencyMap.at(it) = frequencyMap.at(it) + 1;
                
                int count = frequencyMap.at(it);
                
                auto itResult = results.find(count);
                
                if(itResult != results.end())
                {
                    results.at(count).push_back(it);
                }
                else
                {
                    vector<int> lists;
                    lists.push_back(it);
                    results.insert({count,lists});
                }
            }
            else
            {
//                frequencyMap.insert({it,1});
//                
//                auto itResult = results.find(1);
//                
//                if(itResult != results.end())
//                {
//                    frequencyMap.at(it) = frequencyMap.at(it) + 1;
//                    
//                    int count = frequencyMap.at(it);
//                    
//                    vector<int> curLists = results.at(count);
//                }
//                else
//                {
//                    vector<int> lists;
//                    lists.push_back(it);
//                    results.insert({1,lists});
//                }
            }
        }
        
        int count = 0;
        
        vector<int> vals;
        for(auto &k:results)
        {
            for(auto &it:k.second)
            {
                vals.push_back(it);
                count++;
                
                if(count == freq)
                    break;
            }
            if(count == freq)
                break;
        }
        
        return vals;
    }
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    
    vector<int> input = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    
    vector<int> once = mSolution->topKFrequent(input,10);
    
    for(int i=0;i<once.size();i++)
    {
        cout<<once.at(i)<<" "<<endl;
    }
    
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    
    return 0;
};
