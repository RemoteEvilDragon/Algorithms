struct indexType{
    char character;
    int interger;
    bool hasAestrial;
};
class Solution {
public:
    
        //violence method.
        bool tryFind(string &s,vector<indexType> &alphas,int sindex,int alphaIndex,int &sMargin)
        {
            if(alphaIndex == alphas.size() )
                return true;
            
            if(sindex == s.size()+1 )
                return false;
            
            indexType item = alphas.at(alphaIndex);
            
            bool isCharacterEqual = false;
            
            if ( alphaIndex == alphas.size() - 1)//last one compare.
            {
                if ( sindex == s.size() )
                    isCharacterEqual = true;
                else
                {
                    sMargin++;
                    
                    return tryFind(s,alphas,sindex+1,alphaIndex,sMargin);
                }
            }
            else//common compare.
            {
                if(sindex == s.size())
                    return false;
                
                char character = s.at(sindex);
                isCharacterEqual = (item.character == character);
            }
            
            if( isCharacterEqual &&
               ( (item.hasAestrial && sMargin >= item.interger) || (!item.hasAestrial && sMargin == item.interger) ) )//character is equal then.
            {
                sMargin = 1;
                
                return tryFind(s,alphas,sindex+1,alphaIndex+1,sMargin);
            }
            else
            {
                sMargin++;
                
                return tryFind(s,alphas,sindex+1,alphaIndex,sMargin);
            }
            
            return false;
        }
    
        bool isMatch(string s, string p) {
            
            vector<indexType> alphaBetaVector;
            
            indexType cur = {0};
            
            for(auto &it:p)
            {
                if(it == '*')
                {
                    cur.hasAestrial = true;
                }
                else if(it == '.')
                {
                    cur.interger++;
                }
                else
                {
                    cur.character = it;
                    alphaBetaVector.push_back(cur);
                    cur = {0};
                    cur.interger = 1;
                }
            }
            alphaBetaVector.push_back(cur);//add end symbol.
            
            int initial = 0;
            
            return tryFind(s,alphaBetaVector,0,0,initial);
        }
};

int main(int argsNum,const char **args)
{
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    if( mSolution->isMatch("aab","*b") )
        cout<<"Matched."<<endl;
    else
        cout<<"Not Matched."<<endl;
    
    
    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};