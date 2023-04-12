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
void push_back(Node*& head_ref, int new_key){
    Node* lst = new Node;
    if(head_ref == nullptr){
        lst->key = new_key;
        head_ref = lst;
        return;
    }
    Node* ptr = head_ref;
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }
    lst->key = new_key;
    ptr->next = lst;
}

Node* read_list(Node* head){
    int el;
    cin >> el;
    while(el != 0){
        push_back(head, el);
        cin >> el;
    }
    push_back(head, el);
    return head;
}

Node* reverse(Node* head){
    if (head == nullptr) return nullptr;

    Node* current = head;
    Node* current_next = head->next;
    head->next = nullptr;
    while (current_next != nullptr){
        Node* new_current_next = current_next->next;
        current_next->next = current;
        current = current_next;
        current_next = new_current_next;
    }
    return current;   
}

// Принципиальный вид main
int main() {
  Node* head = nullptr;
  head = read_list(head);
  head = reverse(head);
  print_list(head);
  destroy_list(head);
  return 0;
}
