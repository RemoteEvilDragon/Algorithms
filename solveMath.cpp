// 6、一面墙，单独工作时，A花18小时砌好，B花24小时，C花30小时，现A,B,C的顺序轮流砌，每人工作1小时换班，完工时，B总共干了多少小时？（ ）
// A:8小时 B:7小时44分 C:7小时 D:6小时48分

#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <map>
#include <chrono>
#include <thread>

using namespace std;


int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    if( mSolution->isMatch("ab",".*c") )
        cout<<"Matched."<<endl;
    else
        cout<<"Not Matched."<<endl;
    
    float a = 1/18.0f;
    float b = 1/24.0f;
    float c = 1/30.0f;
    
    float work = 0;
    
    int order = 0;
    
    float btime = 0;
    while(work <= 1.0f)
    {
        if(order == 0)
        {
            if(work + a<1)
                work += a;
            else
            {
               cout<<"b has done work with "<<btime<<endl;
               break;
            }
        }
        else if(order == 1)
        {
            if(work + b <1)
            {
                work += b;
                btime += 1;
            }
            else
            {
                btime += 1-work;
                cout<<"b has done work with "<<btime<<endl;
            }
        }
        else if(order == 2)
        {
            if(work + c<1)
                work += c;
            else
            {
                cout<<"b has done work with "<<btime<<endl;
                break;
            }
        }
        
        order++;
        if(order >2)
            order = 0;
    }
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
