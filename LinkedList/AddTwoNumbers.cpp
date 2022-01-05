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

 int main() {
    ListNode *t = new ListNode(0);
    ListNode *p = t->next;
    p->val = 1;
    p->next->val = 2;

    ListNode *temp = t;
    while (temp->next != NULL) {
        cout << temp << " ";
        temp = temp->next;
    }
 }