#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <map>
#include <chrono>
#include <thread>

void getAllNumOrder(vector<int> remains,vector<int> accumulate,int &unique)
{
    for(int i=0;i<remains.size();i++)
    {
        vector<int> next = remains;
        
        vector<int> storage = accumulate;
        
        storage.push_back(next.at(i));
        
        next.erase(next.begin()+i);
        
        if(next.size() == 0)
        {
            cout<<"}";
            
            for(int i =0;i<storage.size();i++)
            {
                cout<<storage.at(i);
                if(i!=storage.size() -1)
                    cout<<",";
            }
            
            
            cout<<"}";
            
            bool ishitunlike = true;
            
            for(int i=1;i<=5;i++)
            {
                if(storage.at(i-1) == i)
                {
                    ishitunlike = false;
                    break;
                }
            }
            
            if(ishitunlike)
            {
                unique++;
               cout<<"   this combine is unique with now index: "<<unique;
            }
                    
            cout<<endl;
       
        }
        else
            getAllNumOrder(next,storage,unique);
    }
}

int main(int argsNum,const char **args)
{
    auto start =  std::chrono::high_resolution_clock::now();
    
    vector<int> starts;
    for(int i=1;i<=5;i++)
    {
        starts.push_back(i);
    }
    vector<int> accu;
    
    int unique=0;
    getAllNumOrder(starts,accu,unique);
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};