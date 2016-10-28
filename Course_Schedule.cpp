struct searchNode{
    int val;
    int level;
};
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int,vector<int>> keyMaps;
        vector<int> remainSearch;
        
        vector<int> tempContainer;
        
        tempContainer.resize(numCourses);
        
        //1.初始化寻找的keymap
        for(auto &it:prerequisites)//nlogn
        {
            auto iter = keyMaps.find(it.first);//平衡二叉树
            if(iter != keyMaps.end())
            {
                vector<int> *item = &keyMaps.at(it.first);
                item->push_back(it.second);
            }
            else
            {
                vector<int> items;
                items.push_back(it.second);
                keyMaps.insert(std::pair<int,vector<int>>(it.first,items));
                remainSearch.push_back(it.first);
            }
            
            tempContainer.at(it.first) = 1;
        }
        
        //2.寻找初始叶子节点
        map<int,int> leefNodes;
        for(int i=0;i<numCourses;i++)//nlogn
        {
            if(tempContainer.at(i) == 0)
                leefNodes.insert(std::pair<int,int>(i,0));
        }
        
        //3.逐个遍历，尝试添加叶子节点
        int searchIndex;
        vector<searchNode> keyNeeds;
        while(keyMaps.size() > 0)
        {
            keyNeeds.clear();//Clear vector for the next loop.
            keyNeeds.push_back({remainSearch.at(0),0});//First one.
            searchIndex = 0;
            
            while(1)
            {
                searchNode parent = keyNeeds.at(searchIndex);
                
                vector<int> needs = keyMaps.at(parent.val);//key,value type.
                
                int addCount = 1;
                for(int i=0;i < needs.size();i++)//
                {
                    int need = needs.at(i);
                    
                    if(leefNodes.find(need) == leefNodes.end())//非叶子节点
                    {
                        for(int j =0;j<searchIndex;j++)//保护判断
                        {
                            if(keyNeeds.at(j).val == need)//构成回环 则无解.
                            {
                                return false;
                            }
                        }
                        keyNeeds.insert(keyNeeds.begin()+searchIndex+addCount,{need,parent.level+1});
                        addCount++;
                    }
                }
                
                if(addCount == 1)
                {
                    
                    leefNodes.insert(std::pair<int,int>(parent.val,0));
                    //delete parent value in this iterate list.
                    
                    keyNeeds.erase(keyNeeds.begin()+searchIndex);
                    
                    searchIndex--;
                    
                    //check if parent's parent is leefnode then.
                    //删除可能是叶子节点的各个父节点
                    if(searchIndex+1 < keyNeeds.size())
                    {
                        searchNode right = keyNeeds.at(searchIndex+1);
                        searchNode left;
                        while(searchIndex >= 0 )
                        {
                            left = keyNeeds.at(searchIndex);
                            
                            if(left.level>= right.level)
                            {
                                leefNodes.insert(std::pair<int,int>(left.val,0));
                                
                                keyNeeds.erase(keyNeeds.begin()+searchIndex);
                                
                                searchIndex--;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                
                searchIndex++;//In needs list search index.
                
                if(searchIndex == keyNeeds.size())
                {
                    for(auto &it:keyNeeds)//添加更新叶子节点队列
                    {
                        leefNodes.insert(std::pair<int,int>(it.val,0));
                    }

                    keyMaps.erase(remainSearch.at(0));//删除当前已全部推导可完成的课程
                    
                    remainSearch.erase(remainSearch.begin());
                    
                    break;
                }
            }
        };
        
        return true;
    }
};