#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    int l;
    cin >> l;
    //int price[10][2]{(1, 0), (5, 0), (8, 0), (9, 0), (10, 0), (17, 0), (17, 0), (20, 0), (24, 0), (30, 0)};
    int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int pr[10];
    for(int i = 0; i < 10; i++){
        pr[i] = 0;
    }
    pr[0] = 0;
    vector <vector <int> > path(10);
    int path[10];
    for(int i = 1; i <= l; i++){
        int j = 1;
        pr[i % 10] = 0;
        while(i - j != -1 && j < 10){
            if(pr[i % 10] < (pr[(i - j) % 10] + price[j - 1])){
                pr[i % 10] = pr[(i - j) % 10] + price[j - 1];
                path[i % 10] = path[(i - j) % 10];
                path[i % 10].push_back(j);
                
                cout<<i<<" "<<j<<":"<<pr[(i - j) % 10]<<"+"<<price[j - 1];
                cout<<endl;
                for(int k = 0; k < path[i % 10].size(); k++){
                    cout << path[i % 10][k]<<" ";
                }
                cout<<endl;
                
            }
            j++;
        }
        cout<<endl;
    }
    sort(path[l % 10].begin(), path[l % 10].end());
    for(int i = 0; i < path[l % 10].size(); i++){
        cout << path[l % 10][i]<<" ";
    }
    return 0;
}