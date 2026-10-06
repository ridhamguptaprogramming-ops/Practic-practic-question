#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {

    if (head == nullptr || head->next == nullptr) {
        return;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr &&
           fast->next->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = slow->next;
    slow->next = nullptr;

    ListNode* prev = nullptr;

    while (second != nullptr) {
        ListNode* temp = second->next;

        second->next = prev;
        prev = second;

        second = temp;
    }
    ListNode* first = head;
    second = prev;

    while (second != nullptr) {

        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

int main() {

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    reorderList(head);

    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

    return 0;
};