#include <iostream>
using namespace std;

struct Node{
    int key = 0;
    Node* next = nullptr;
};

void push_front(Node*& head_ref, int new_key){
    
    Node* temp = new Node;
    temp->key = new_key;
    temp->next = head_ref;
    head_ref = temp;
}

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

void insert_after(Node*& prev_ref, int new_key){
    if(prev_ref == nullptr){
        return;
    }
    Node* ins = new Node;
    ins->key = new_key;
    ins->next = prev_ref->next;
    prev_ref->next = ins;
}

void destroy_list(Node*& head_ref){
    if(head_ref == nullptr) return;

    while(head_ref->next != nullptr){
        Node* temp = head_ref->next->next;
        delete head_ref->next;
        head_ref->next = temp;
    }
    delete head_ref->next;
    head_ref = nullptr;
}

void print_list(Node* head_ref){
    if(head_ref == nullptr) {
        std::cout << std::endl;
        return;
    }
    while(head_ref->next != nullptr){
        std::cout << head_ref->key << " ";
        head_ref = head_ref->next;
    }
    std::cout << head_ref->key << std::endl;
}

Node* find(Node* head_ref, int key){
    if(head_ref == nullptr) return nullptr;
    Node* current = head_ref;
    while(current != nullptr){
        if(current->key == key){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


void remove_key(Node*& head_ref, int key) {
    if (head_ref == nullptr) return;
    if (head_ref->key == key) {
        Node* nw = head_ref->next;
        delete head_ref;
        head_ref = nw;
        return;
    }

    Node* current = head_ref;
    while (current->next != nullptr) {
        if (current->next->key == key) {
            break;
        }
        current = current->next;
    }

    if (current->next == nullptr) return;

    Node* temp = current->next->next;
    delete current->next;
    current->next = temp;
}

int main(){
   Node* HEAD = nullptr, *current = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  current = find(HEAD, 2);
  if (current->key == 2) {
    cout << "OK" << endl;
  }
  return 0;
}