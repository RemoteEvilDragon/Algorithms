#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <array>

using namespace std;


//Run time only beats 0.1% person,this is incrdiably low.
class Solution {
public:
    bool isValid(string s) {
     
        map<char,char> keyMaps = {
            {')','('},
            {']','['},
            {'}','{'},
        };
        
        string dynamic;
        
        for(int i=0;i<s.size();i++)
        {
            if(i > 0)
            {
                char character = s.at(i);
                
                
                if(keyMaps.find(character)!=keyMaps.end())
                {
                    if(dynamic.size() == 0)
                        return false;
                    
                    char last = dynamic.at(dynamic.size()-1);
                    if (last == keyMaps.at(character) )
                    {
                        dynamic.erase(dynamic.size()-1);
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    dynamic.push_back(character);
                }
            }
            else
            {
                dynamic.push_back(s.at(i));
            }
        }
        
        if(dynamic.size() > 0)
            return false;
        
        
        return true;
    }
};

int main(int argsNum,const char **args)
{
    
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    
    if (mSolution->isValid("()[]{}") )
        cout<<"Stream is valid!"<<endl;
    else
        cout<<"Stream is invalid!"<<endl;

    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
