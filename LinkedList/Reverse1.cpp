#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Empty list or single element list
        if (head == NULL || head->next == NULL) {
            return head;
        } else {
            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* forward = NULL;

            while (curr != NULL) {
                forward = curr->next;  // Save next node
                curr->next = prev;     // Reverse the link
                prev = curr;           // Move prev to current
                curr = forward;        // Move curr to next node
            }
            return prev;  // New head of the reversed list
        }
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    // Free allocated memory
    while (reversedHead != NULL) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
