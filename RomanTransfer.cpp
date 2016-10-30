#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <array>

using namespace std;

struct Roman{
    int val;
    int lel;
};

struct charRoman{
    int val;
    string roman;
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        
        vector<charRoman> keyMaps = {
            {1000,"M"},
            {900,"CM"},
            {500,"D"},
            {400,"CD"},
            {100,"C"},
            {90,"XC"},
            {50,"L"},
            {40,"XL"},
            {10,"X"},
            {9,"IX"},
            {5,"V"},
            {4,"IV"},
            {1,"I"}
        };
        
        for(auto &it:keyMaps)
        {
            if(num/it.val > 0)
            {
                for(int i=0;i<num/it.val;i++)
                {
                    roman.append(it.roman);
                }
            }
            
            num = num%it.val;
        }
        
        return roman;
    }
 
    int romanToInt(string s) {//foolish brute force.
        int interger= 0 ;
        
        map<char,Roman> keyMaps = {
            {'I',{1,0}},
            {'V',{5,1}},
            {'X',{10,2}},
            {'L',{50,3}},
            {'C',{100,4}},
            {'D',{500,5}},
            {'M',{1000,6}},
        };
        
        vector<int> eraseLists;
        
        char last = '\0';
        for(int i=0;i<s.size();i++)
        {
            char character = s.at(i);
            
            if(last != '\0')
            {
                Roman lastRoman = keyMaps.at(last);
                Roman nowRoman = keyMaps.at(character);
                
                if(lastRoman.lel < nowRoman.lel)//last is less than cur.
                {
                    eraseLists.insert(eraseLists.begin(),i-1);
                    eraseLists.insert(eraseLists.begin(),i);
                    
                    interger += (nowRoman.val-lastRoman.val);
                }
            }
            last = character;
        }
        
        
        for(auto &it:eraseLists)
        {
            s.erase(s.begin()+it);
        }
        
        
        for(int i=0;i<s.size();i++)
        {
            Roman nowRoman = keyMaps.at(s.at(i));
            interger += nowRoman.val;
        }
        
        return interger;
    }
};

int main(int argsNum,const char **args)
{
    
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    cout<<mSolution->romanToInt("DCCCXC")<<endl;
    
    
    cout<<mSolution->intToRoman(999)<<endl;
    

    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
