#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};

void printList(ListNode* n)
{
    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;
    }
}

int main(){
    Solution s;

    ListNode* Head = new ListNode();
    ListNode* sec = new ListNode();
    ListNode* third = new ListNode();
    ListNode* forth = new ListNode();
    ListNode* fifth = new ListNode();
    ListNode* six = new ListNode();
    ListNode* sev = new ListNode();
    ListNode* eight = new ListNode();

    Head->val = 1; // assign val in first node
    Head->next = sec; // Link first node with second

    sec->val = 2; // assign val to sec node
    sec->next = third;

    third->val = 3; // assign val to third node
    third->next = NULL;
    ListNode* x = s.addTwoNumbers(Head,sec);

    while(x != NULL){
    cout << x->val;
    x = x->next;
    }
    //printList(x);
}
