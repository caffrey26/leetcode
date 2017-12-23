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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      //we will traverse the node using two pointers
      
      if(head == NULL) return head;
      ListNode* slowPtr = head;
      //there is a trivial case when there is just one node in the list
      if(head->next == NULL)
        return NULL; //we assume n is always valid
      ListNode* fastPtr = head->next;
      
      //fastPtr will hit the last node (list has even number of nodes), or second to last node (list has odd number of nodes)
      int len = 2; //initialize from 2 already
      while(fastPtr->next && fastPtr->next->next){
          fastPtr = fastPtr->next->next;
          slowPtr = slowPtr->next;
          len += 2;
      }
      int slowPtrPos = len/2; //len is an even number right now
      //either fastPtr->next is NULL, or next->next is NULL
      if(fastPtr->next != NULL){
          len++; //length is odd
      }
       ListNode* prev = NULL;
      int nodeFromFront = len - n + 1;
      if(nodeFromFront > slowPtrPos){
          //the node to be deleted lies forward
          prev = slowPtr;
          slowPtr = slowPtr->next;
          nodeFromFront = nodeFromFront - slowPtrPos;
      }else{
          slowPtr = head;
      }
      
      //now we have to delete nodeFromFront-th node, while we are at node being pointed by slowPtr
      
     
        
      int l = 1;
      
      while(l != nodeFromFront){
          l++;
          prev = slowPtr;
          slowPtr = slowPtr->next;
      }
        if(prev == NULL){
            head = head->next;
        }
        else 
            prev->next = prev->next->next;
      return head;
    }
};

int main(){
    Solution S;
    List L;
    L.insertInList(5);
    L.insertInList(4);
    L.insertInList(3);
    L.insertInList(2);
    L.insertInList(1);
    L.printList();
    S.removeNthFromEnd(L.head, 2);
    L.printList();
    
}