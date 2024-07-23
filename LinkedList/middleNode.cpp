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
    ListNode* middleNode(ListNode* head) {
        // Empty list or only one node
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Only 2 nodes
        if (head->next->next == NULL) {
            return head->next;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }
            slow = slow->next;
        }

        return slow;
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

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    cout << "Middle node: " << middle->val << endl;

    // Free allocated memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
