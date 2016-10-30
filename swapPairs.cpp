#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <array>

using namespace std;
//There is a very good method would beats 90% other people in the world,with time,try this out.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *swaped = nullptr;
        
        ListNode *exchange = nullptr;
        ListNode *tail = nullptr;
        
        if(head->next == nullptr)
            return head;
        
        
        int i = 1;
        
        while(1)
        {
            if(i%2 == 0)//even
            {
                if(swaped == nullptr)//first time.
                {
                    swaped = head;
                    
                    exchange->next = head->next;
                    
                    swaped->next = exchange;
                    
                    tail = exchange;
                }
                else
                {
                    tail->next = head;
                    
                    exchange->next = head->next;
                    
                    tail = tail->next;
                    
                    tail->next = exchange;
                    
                    tail = exchange;
                }
                
                head = tail->next;
            }
            else//ord
            {
                exchange = head;
                
                head = head->next;
            }
            
            
            i++;
            
            if(head == nullptr)
                break;
        }
        
        return swaped;
    };
};

int main(int argsNum,const char **args)
{
    
    Solution* mSolution = new Solution();
    
    auto start =  std::chrono::high_resolution_clock::now();
    
    ListNode item1(1);
//    ListNode item2(2);
//    ListNode item3(3);
//    ListNode item4(4);
    
//    item1.next = &item2;
//    item2.next = &item3;
//    item3.next = &item4;
    
    ListNode *swaped = mSolution->swapPairs(&item1);
    
    
//    if (mSolution->isValid("()[]{}") )
//        cout<<"Stream is valid!"<<endl;
//    else
//        cout<<"Stream is invalid!"<<endl;

    auto end =  std::chrono::high_resolution_clock::now();
    
    std::cout << "Algorithm takes "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
    << " milliseconds.\n";
    
    return 0;
};
