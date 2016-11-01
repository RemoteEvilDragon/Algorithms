#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <array>

using namespace std;

struct Edge{
    int m;
    int n;
};

//very very low lcs method here.
string searchLCS(string &s1,string &s2,int m,int n)
{
    if(n<0 || m<0)
        return "";
    
    if(s1.at(m) == s2.at(n))
    {
        if(m == 0 && n== 0)
        {
            string str;
            str.push_back(s1.at(m));
            return str;
        }
        else
        {
            string str = searchLCS(s1, s2, m-1, n-1);
            str.push_back(s1.at(m));
            return str;
        }
    }
    else
    {
        if(m == 0 && n== 0)
            return "";
        else
        {
            
            string l1 = searchLCS(s1, s2, m, n-1);
            string l2 = searchLCS(s1, s2, m-1, n);
            
            if( l1 >= l2 )
            {
                
                return l1;
            }
            else
            {
                return l2;
            }
        }
    }
}

class Solution {
public:
    string longestCommonString(string s1,string s2) {
        
        string common =  searchLCS(s1,s2,s1.size()-1,s2.size()-1);
        
        return common;
    };
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();

    cout<< mSolution->longestCommonString("dssdfhoew","hvieowuqh").c_str()<<endl;
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    
    return 0;
};
