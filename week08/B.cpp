#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node {
  int key;
  Node* next;
};

// Где-то тут определены
void print_list(Node* head_ref){
    if(head_ref == nullptr) {
        std::cout<< std::endl;
        return;
    }
    while(head_ref->next != nullptr){
        std::cout << head_ref->key << " ";
        head_ref = head_ref->next;
    }
    std::cout << head_ref->key << std::endl;
}

void destroy_list(Node*& head){
    if(head == nullptr) return;

    while(head->next != nullptr){
        Node* temp = head->next->next;
        delete head->next;
        head->next = temp;
    }
    delete head->next;
    head = nullptr;
}

// Место для реализации функций
void push_front(Node*& head_ref, int new_key){
    
    Node* temp = new Node;
    temp->key = new_key;
    temp->next = head_ref;
    head_ref = temp;
}

Node* read_list(Node* head){
    int el;
    cin >> el;
    while(el != 0){
        push_front(head, el);
        cin >> el;
    }
    return head;
}

int find_middle(const Node* head){
    int k = 1;
    int middle = 0;
    Node* current_next = head->next;
    while(current_next != nullptr){
        if(k%2 == 0) middle++;
        current_next = current_next->next;
        k++;
    }
    if(k%2 == 0) middle++;
    delete current_next;
    return middle;
}

int main() {
  Node* head = nullptr;
  head = read_list(head);
  int mid  = find_middle(head);
  cout << mid;
  destroy_list(head);
  return 0;
}