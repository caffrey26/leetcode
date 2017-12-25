#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

struct List{
  ListNode* head;
  List(): head(NULL) {}
  void insertInList(int n){
      ListNode* node = new ListNode(n);
      if(head == NULL){
          head = node;
      }else{
          node->next = head;
          head = node;
      }
  }
  void printList(){
      ListNode* temp = head;
      while(temp){
          cout<<temp->val;
          
          if(temp->next) 
            cout<<"-->";
          else
            cout<<endl;
          
          temp = temp->next;
      }
  }
  
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prev = NULL, *small = NULL, *large =NULL;
        //whichever is less goes first
        ListNode* dummy = new ListNode(0);
        //if one of them is NULL, then the NOT-NULL one. If both are NOT-NULL then the smaller one
        if(l1 && !l2){
             dummy->next = l1;  
        }else if(l2 && !l1){
            dummy->next = l2;
        } else if (l1 && l2){
            if(l1->val <= l2->val){
                dummy->next = l1;
                prev = dummy;
                small = l1;
                large = l2;
            }else{
                dummy->next = l2;
                prev = dummy;
                small = l2;
                large = l1;
            }
        }
        
        while(small && large){
            
            if(small->val <= large->val){
                prev = small;
                small = small->next;
            }else{
                prev->next = large;
                prev = large;
                ListNode* temp = small;
                small =large;
                large = temp;
                small = small->next;
            }
        }
        
        if(small)
            prev->next = small;
        if(large)
            prev->next = large;
            
        return dummy->next;
    }
    
};

int main(){
    Solution S;
    List L;
    L.insertInList(4);
    L.insertInList(2);
    L.insertInList(1);
    // L.insertInList(2);
    // L.insertInList(1);
    L.printList();
    List L2;
    L2.insertInList(4);
    L2.insertInList(3);
    L2.insertInList(1);
    // L2.insertInList(2);
    // L2.insertInList(1);
    L2.printList();
    ListNode* R = S.mergeTwoLists(L.head,L2.head);
    List L3; 
    L3.head = R;
    L3.printList();
    
}