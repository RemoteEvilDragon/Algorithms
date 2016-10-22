#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <map>
#include <chrono>
#include <thread>

using namespace std;

enum WildType{
    NORMAL = 0,
    EVERY,
    REPEAT,
    SINGLE,
};

struct indexType{
    char character;
    bool assigned;
    WildType type;
    int len;
};

struct alphaNode{
    char character;
    int len;
    WildType type;
};

class Solution {
public:
        void prettyPrintString(vector<alphaNode> &aBetas)
        {
            //输出字符串简化
            for(int i=0;i<aBetas.size();i++)
            {
                alphaNode alphaBeta = aBetas.at(i);
                cout<<alphaBeta.character;
                
                if(alphaBeta.len > 0)
                    cout<<alphaBeta.len;
                
                if(i<aBetas.size()-1)
                    cout<<"   ";
            }
            
            cout<<endl<<endl;
        }

        void prettyPrintRe(vector<indexType> &alphas)
        {
            //输出表达式简化结果
            for(int i=0;i<alphas.size();i++)
            {
                indexType cur = alphas.at(i);
                
                if(cur.type == WildType::NORMAL)
                {
                    cout<<cur.character<<" ";
                }
                else if(cur.type == WildType::SINGLE)
                {
                    cout<<". ";
                }
                else if(cur.type == WildType::REPEAT)
                {
                    cout<<cur.character<<"*";
                }
                else if(cur.type == WildType::EVERY)
                {
                    cout<<".*";
                }
                
                if(cur.len > 0)
                    cout<<cur.len;
                
                if(i<alphas.size()-1)
                    cout<<"   ";
            }
            cout<<endl<<endl;
        }
    
    
//        bool filterBy(vector<indexType> &alphas,indexType *current,int condition,int index)
//        {
//            bool match = false;
//            
//            int ii = 0;
//            
//            if(condition%2 == 0)//2,4
//                ii = index-1;
//            else
//                ii = index+1;
//            
//            indexType adhere = alphas.at(ii);
//            
//            if( adhere.type == WildType::REPEAT || adhere.type == WildType::EVERY)
//            {
//                match = true;
//            }
//            else if( adhere.type == WildType::SINGLE )
//            {
//                match = true;
//                current->len++;
//            }
//            
//            if(match)
//                alphas.erase(alphas.begin()+ii);
//            else
//                return true;
//            
//            return false;
//        }
    
        void simplifyRe(vector<indexType> &alphas)
        {
            int index = (int)alphas.size()-1;
            while(index>=0)
            {
                indexType *current = &alphas.at(index);
                
                if(current->type == WildType::EVERY)
                {
                    while( index+1 < alphas.size())
                    {
                        bool match = false;
                        
                        indexType adhere = alphas.at(index+1);
                        
                        if( adhere.type == WildType::REPEAT || adhere.type == WildType::EVERY)
                        {
                            match = true;
                        }
                        else if( adhere.type == WildType::SINGLE )
                        {
                            match = true;
                            current->len++;
                        }
                        
                        if(match)
                            alphas.erase(alphas.begin()+index+1);
                        else
                            break;
                    }
                    while( (index-1>=0) && (alphas.at(index-1).type == WildType::REPEAT || alphas.at(index-1).type == WildType::EVERY))
                    {
                        bool match = false;
                        
                        indexType adhere = alphas.at(index-1);
                        
                        if( adhere.type == WildType::REPEAT || adhere.type == WildType::EVERY)
                        {
                            match = true;
                        }
                        else if( adhere.type == WildType::SINGLE )
                        {
                            match = true;
                            current->len++;
                        }
                        
                        if(match)
                        {
                            alphas.erase(alphas.begin()+index-1);
                            index--;
                            current--;
                        }
                        else
                            break;
                    }
                }
                
                index--;
            }
            index = (int)alphas.size()-1;
            while(index>=0)
            {
                indexType *current = &alphas.at(index);
                
                if(current->type == WildType::REPEAT)
                {
                    while((index+1 < alphas.size()))
                    {
                        bool match = false;
                        
                        indexType adhere = alphas.at(index+1);
                        
                        if( adhere.type == WildType::REPEAT && current->character == adhere.character )
                        {
                            match = true;
                        }
                        else if(adhere.type == WildType::NORMAL && current->character == adhere.character)
                        {
                            current->len++;
                            match = true;
                        }
                        
                        if(match)
                            alphas.erase(alphas.begin()+index+1);
                        else
                            break;
                        
                    }
                    while(index-1 >= 0 )
                    {
                        bool match = false;
                        
                        indexType adhere = alphas.at(index-1);
                        
                        if( adhere.type == WildType::REPEAT && current->character == adhere.character )
                        {
                            match = true;
                        }
                        else if(adhere.type == WildType::NORMAL && current->character == adhere.character)
                        {
                            current->len++;
                            match = true;
                        }
                        
                        if(match)
                        {
                            alphas.erase(alphas.begin()+index-1);
                            index--;
                            current--;
                        }
                        else
                            break;
                    }
                }
                index--;
            }
            
//             prettyPrintRe(alphas);
            
            //3.去掉形如a两边相同的字符aa
//            index = (int)alphas.size()-1;
//            while(index>=0)
//            {
//                indexType *current = &alphas.at(index);
//                
//                if(current->type == WildType::NORMAL)
//                {
//                    while((index-1 >= 0) &&
//                          (alphas.at(index-1).type == WildType::NORMAL && current->character == alphas.at(index-1).character ))
//                    {
//                        current->len++;
//                        alphas.erase(alphas.begin()+index-1);
//                        index--;
//                        current--;
//                    }
//                }
//                
//                index--;
//            }
            
            //4.去掉形如.两边相同的字符.
//            index = (int)alphas.size()-1;
//            while(index>=0)
//            {
//                indexType *current = &alphas.at(index);
//                
//                if(current->type == WildType::SINGLE)
//                {
//                    while((index-1 >= 0) &&
//                          (alphas.at(index-1).type == WildType::SINGLE  ))
//                    {
//                        current->len++;
//                        alphas.erase(alphas.begin()+index-1);
//                        index--;
//                        current--;
//                    }
//                }
//                
//                index--;
//            }
            
//            prettyPrintRe(alphas);
        }

        vector<alphaNode> simplifyString(string &s)
        {
            //最简化string expression.
            int index = 0;
            
            vector<alphaNode> aBetas;
            
            alphaNode last={0};
            while(index < s.size())
            {
                if(index == 0)
                {
                    last.character = s.at(index);
                    last.len = 1;
                }
                else
                {
                    char cur = s.at(index);
                    
                    if(cur == last.character)
                    {
                        last.len++;
                    }
                    else
                    {
                        aBetas.push_back(last);
                        last={0};
                        last.len = 1;
                        last.character = cur;
                    }
                }
                
                if(index == s.size() -1)
                {
                    aBetas.push_back(last);
                }
                index++;
            }

            return aBetas;
        }
    
        bool tryFind(string &s,vector<indexType> &regs,int i,int j)
        {
            if( i == s.size() )
            {
                if(j == regs.size())
                {
                    return true;
                }
                else//字符串用完了，表达式没用完
                {
                    for(int m = j;m<regs.size();m++)
                    {
                        indexType reg = regs.at(m);
                        if(reg.len >=1 )
                            return false;
                    }
                    return true;
                }
            }
            else
            {
                if(j == regs.size())//表达式用完了，字符串没用完
                {
                    return false;
                }
            }
            
            
            char al = s.at(i);
            
            indexType reg = regs.at(j);
            
            if(reg.type == WildType::EVERY)
            {
                for(int k = reg.len + i;k<=s.size();k++ )
                {
                    if(tryFind(s,regs,k,j+1))
                        return true;
                }
            }
            else if(reg.type == WildType::NORMAL)
            {
                if(al != reg.character)//next;
                    return false;
                else
                    return tryFind(s,regs,i+1,j+1);
            }
            else if(reg.type == WildType::SINGLE)
            {
                return tryFind(s,regs,i+1,j+1);
            }
            else if(reg.type == WildType::REPEAT)
            {
                for(int k = 0;k<reg.len;k++ )
                {
                    if(i+k >= s.size() )
                        return false;
                    
                    char character = s.at(i+k);
                    
                    if(reg.character != character)
                        return false;
                }
                
                bool isMatched = false;
                for(int k = reg.len + i; k<=s.size(); k++)
                {
                    if( k > reg.len + i)
                    {
                        char character = s.at(k-1);
                        if(reg.character != character)
                        {
                            isMatched = false;
                            break;
                        }
                    }
                    
                    if(tryFind(s,regs,k,j+1))
                    {
                        isMatched = true;
                        break;
                    }
                }
                
                if(isMatched)
                    return true;
            }
            
            return false;
        }
    
        bool isMatch(string s, string p) {
            
            vector<indexType> alphas;
            
            indexType cur = {0};
            
            for(auto &it:p)
            {
                if(it == '*')
                {
                    if(alphas.size() > 0)
                    {
                        indexType *last = &alphas.at(alphas.size()-1);
                        
                        if(last->assigned)
                        {
                            if(last->character == '.')
                            {
                                last->type = WildType::EVERY;
                                last->len = 0;
                            }
                            else
                            {
                                last->type = WildType::REPEAT;
                                last->len = 0;
                            }
                        }
                    }
                }
                else
                {
                    cur.len = 1;
                    
                    if(it == '.')
                    {
                       cur.type = WildType::SINGLE;
                    }
                    else
                    {
                        cur.type = WildType::NORMAL;
                    }
                    
                    cur.character = it;
                    cur.assigned = true;
                    alphas.push_back(cur);
                    cur = {0};
                }
            }
            
            simplifyRe(alphas);
            
            vector<alphaNode> aBetas = simplifyString(s);
            
            prettyPrintRe(alphas);
            
            prettyPrintString(aBetas);
            
            return tryFind(s, alphas, 0, 0);
        }
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    if( mSolution->isMatch("ab",".*..") )
        cout<<"Matched."<<endl;
    else
        cout<<"Not Matched."<<endl;
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
