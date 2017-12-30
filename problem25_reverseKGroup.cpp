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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev =NULL, *cur =head, *prevGtail = NULL, *curGtail = NULL;
        
        int iter;
        while(cur){
          iter = 0; 
          curGtail = cur;
          
          while(iter != k && cur!=NULL){
            if(cur != NULL){
              iter++;
              ListNode* nx = cur->next;
              cur->next = prev;
              
              prev = cur;
              cur = nx;
            }
          }
          
          if(cur == NULL && iter != k){
            ListNode *undoCur, *undoPrev, *undoNx; 
            undoCur = prev;
            undoPrev = NULL;
            
            while(undoCur != curGtail){
              undoNx = undoCur->next;
              undoCur->next = undoPrev;
              undoPrev = undoCur;
              undoCur = undoNx;
            }
            
            undoCur->next = undoPrev;
            if(prevGtail) 
              prevGtail->next = curGtail;
            else
              head = curGtail;
          }else{
            ListNode* curGhead = prev;
            if(prevGtail) 
              prevGtail->next = curGhead;
            else
              head = curGhead;
            prevGtail = curGtail;
          }
          
        }
        
        if(prevGtail && iter == k) prevGtail->next = NULL;
        return head;
       
    }
};

int main(){
    Solution S;
    List L;
    L.insertInList(6);
    L.insertInList(5);
    L.insertInList(4);
    L.insertInList(3);
    L.insertInList(2);
    L.insertInList(1);
    L.printList();
    L.head = S.reverseKGroup(L.head, 3);
    L.printList();
    
}