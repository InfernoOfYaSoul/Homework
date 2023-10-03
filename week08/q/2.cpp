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
        lst->next = nullptr;
        head_ref = lst;
        return;
    }
    Node* ptr = head_ref;
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }
    lst->key = new_key;
    ptr->next = lst;
    lst->next = nullptr;
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

Node* copy(Node*& head_ref, Node*& nw){
    destroy_list(nw);
    Node* pntr = head_ref;
    Node* HEAD = nullptr;
    while(pntr != nullptr){
        push_back(HEAD, pntr->key);
        pntr = pntr->next;
    }
    delete pntr;
    return HEAD;
}



int main(){
    int l;
    cin >> l;
    int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int pr[11];
    for(int i = 0; i < 11; i++){
        pr[i] = 0;
    }
    pr[0] = 0;
    Node* path[11];
    Node* p = new Node;
    for(int i = 0; i < 11; i++){
        path[i] = nullptr;
    }
    for(int i = 1; i <= l; i++){
        int j = 1;
        int jmax = j;
        pr[i % 11] = 0;
        while(i - j != -1 && j <= 10){
            if(pr[i % 11] < (pr[(i - j) % 11] + price[j - 1])){
                jmax = j;
                pr[i % 11] = pr[(i - j) % 11] + price[j - 1];
            }
            j++;
        }
        j = jmax;
        path[i % 11] = copy(path[(i - j) % 11], path[i % 11]);
        push_back(path[i % 11], j);  
        p = path[(i - j) % 11];     
        /*
        cout<<i<<" "<<j<<":"<<pr[(i - j) % 11]<<"+"<<price[j - 1];
        cout<<endl;

        p = path[i % 11];
        while(p != nullptr){
            cout << p->key<<" ";
            p = p->next;
        }
        cout<<endl;*/
        //cout<<endl;
    }

    
    p = path[l % 11];
    int out[10];
    for(int i = 0; i < 10; i++){
        out[i] = 0;
    }

    while(p != nullptr){
        out[p->key-1]++;
        p = p->next;
    }
    
    for(int i = 0; i < 11; i++){
        delete path[i];
    }
    delete p;

    for(int i = 0; i < 10; i++){
        if(out[i] != 0){
            for(int j = 0; j < out[i]; j++){
                cout<<i+1<<" ";
            }
        }
    }
    cout<<endl;
}