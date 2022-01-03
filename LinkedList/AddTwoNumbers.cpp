// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display() {
   struct ListNode* ptr;
   while (ptr != NULL) {
      cout<< ptr->val <<" ";
      ptr = ptr->next;
   }
}

int main() {
    ListNode *l = new ListNode(0);
    l->next->val = 1;
    l = l->next;
    l->next->val = 2;

    display();
}