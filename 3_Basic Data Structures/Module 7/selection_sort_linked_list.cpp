#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode; // or tail = tail->next
}

void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << endl;
        tmp = tmp->next;
    }
}

void sort_linked_list(Node* head){
    for(Node* i=head; i->next != NULL; i=i->next){
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->val > j-> val){
                swap(i->val, j->val);
            }
        }
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Main function: Entry point of the program.
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    print_linked_list(head);

    // delete_at_any_position(head, 2);

    sort_linked_list(head);

    print_linked_list(head);

    return 0;
}