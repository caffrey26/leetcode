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
    ListNode* swapPairs(ListNode* head) {
        ListNode *a, *b, *prev;
        a = head;
        prev = NULL;
        while(a){
          b = a->next;
          if(b){
            //swap a, and b
            if(prev){
              prev->next = b;
            }else{
              head = b;
            }
            a->next = b->next;
            b->next = a;
            
            //next iter prep
            
          }
          prev = a; 
          a = a->next;
        }
        return head;
    }
};

int main(){
    Solution S;
    List L;
    // L.insertInList(5);
    // L.insertInList(4);
    // L.insertInList(3);
    // L.insertInList(2);
    L.insertInList(1);
    L.printList();
    L.head = S.swapPairs(L.head);
    L.printList();
    
}