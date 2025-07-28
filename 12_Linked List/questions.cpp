#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to add 1 to the number represented by the linked list
Node* addOne(Node* head) {
    head = reverse(head);  // Step 1: Reverse the list

    Node* temp = head;
    int carry = 1;  // Step 2: Start with carry = 1

    while (temp != NULL) {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if (carry == 0) break; // Stop early if no carry left

        if (temp->next == NULL && carry != 0) {
            // If at last node and carry still exists, add new node
            temp->next = new Node(carry);
            carry = 0;
        }
        temp = temp->next;
    }

    return reverse(head);  // Step 3: Reverse back to original order
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original List: ";
    printList(head);

    head = addOne(head);

    cout << "List after adding one: ";
    printList(head);

    return 0;
}