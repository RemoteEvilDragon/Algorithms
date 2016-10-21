//5、一个合法的表达式由()包围，()可以嵌套和链接，如(())()也是合法表达式；现在有8对(),它们可以组成的合法表达式的个数为（ ）
//A.127 B. 132 C.429 D.255 E.1430


#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <map>
#include <chrono>
#include <thread>

using namespace std;

void  tryFetch(int leftValue,int rightValue,vector<char> already,int &all)
{
    for(int i=0;i<2;i++)
    {
        if(i==0)
        {
            int left = leftValue;
            int right = rightValue;
            
            
            vector<char> aa = already;
            
            aa.push_back('(');
            
            left--;
            
            if(left == 0)
            {
                while(right>0)
                {
                    right--;
                    
                    aa.push_back(')');
                }
                
                for(int i=0;i<aa.size();i++)
                    cout<<aa.at(i);
                
                all++;
                
                cout<<" index: "<<all<<endl;
                
            }
            else
            {
                tryFetch(left,right,aa,all);
            }
        }
        else
        {
            if(rightValue <= leftValue)
                return;
            
            int left = leftValue;
            int right = rightValue;
            
            vector<char> aa = already;
            
            aa.push_back(')');
            
            right--;
            
            if(right == 0)
            {
                while(left>0)
                {
                    left--;
                    aa.push_back('(');
                    
                }
                
                for(int i=0;i<aa.size();i++)
                    cout<<aa.at(i);
                
                all++;
                cout<<" index: "<<all<<endl;
            }
            else
            {
                tryFetch(left,right,aa,all);
            }
        }
    }
}

int main(int argsNum,const char **args)
{
    auto start =  std::chrono::high_resolution_clock::now();  
    
    vector<char> a;
    int count=0;
    tryFetch(8, 8,a,count);
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
