/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class myComparator
{
public:
    int operator() (ListNode* l1, ListNode* l2)
    {
        return l1->val > l2->val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myComparator > pq;
        for(int i = 0; i<lists.size();i++){
            //each of the first elements of the k lists will be pushed to a min heap
            if(lists[i])
                pq.push(lists[i]);
        }
        
        //now we create a dummy node
        ListNode* dummy = new ListNode(0); 
        ListNode* prev = NULL;
        prev = dummy;
        ListNode* cur =NULL;
        
        while(pq.empty() == false){
            //pop from pq
            cur = pq.top();
            pq.pop();
            prev->next = cur;
            prev = cur;
            
            cur = cur->next;
            
            //push cur in min heap
            if(cur)
                pq.push(cur);
            
        }
        return dummy->next;
        
    }
};