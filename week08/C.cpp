#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

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

Node* cmp(Node* f, Node* s){
    if(f == nullptr) return s;
    if(s == nullptr) return f;
    if(f->key <= s->key) return f;
    return s;
}

void step(Node* prev, Node*& f, Node*& s){
    if (prev->key == f->key)
        f = f->next;
    else
        s = s->next;
}

Node* mergeTwoLists(Node* list1, Node* list2){
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    Node* current1 = list1;
    Node* current2 = list2;
    Node* prev = cmp(current1, current2);
    Node* HEAD = prev;
    step(prev, current1, current2);
    
    while(current1 != nullptr || current2 != nullptr){
        prev->next = cmp(current1, current2);
        step(prev->next, current1, current2);
        prev = prev->next;
    }

    return HEAD;
}


int main() {
  Node* head1 = nullptr;
  Node* head2 = nullptr;
  head1 = read_list(head1);
  head2 = read_list(head2);
  //print_list(head1);
  //print_list(head2);
  head1 = mergeTwoLists(head1, head2);
  print_list(head1);
  destroy_list(head1);
  destroy_list(head2);
  return 0;
}