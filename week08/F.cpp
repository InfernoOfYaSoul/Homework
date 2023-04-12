#include <iostream>
using namespace std;


struct Node{
    string key = " ";
    Node* prev = nullptr;
    Node* next = nullptr;
};

struct List{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};

List* create_empty_list(){
    List* list = new List;
    list->NIL = new Node; 
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}



List* push_back(List* list_ptr, string new_key){
    if (list_ptr == nullptr) {
        return nullptr;
    }
    if (list_ptr->TAIL == list_ptr->NIL) {
        list_ptr->TAIL = new Node;
        list_ptr->TAIL->key = new_key;
        list_ptr->TAIL->prev = list_ptr->TAIL;
        list_ptr->TAIL->next = list_ptr->TAIL;
        list_ptr->HEAD = list_ptr->TAIL;
        list_ptr->size++;
        return list_ptr;
    }
    if (list_ptr->TAIL->prev == list_ptr->TAIL) {
        list_ptr->TAIL = new Node;
        list_ptr->TAIL->next = list_ptr->HEAD;
        list_ptr->TAIL->prev = list_ptr->HEAD;
        list_ptr->TAIL->key = new_key;
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->HEAD->prev = list_ptr->TAIL;
        return list_ptr;
    }
    Node *current = list_ptr->TAIL;
    list_ptr->TAIL = new Node;
    list_ptr->TAIL->key = new_key;
    list_ptr->TAIL->next = list_ptr->HEAD;
    list_ptr->TAIL->prev = current;
    list_ptr->HEAD->prev = list_ptr->TAIL;
    current->next = list_ptr->TAIL;
    list_ptr->size++;
    return list_ptr;
}

void print(const List* list_ptr){
    if(list_ptr == nullptr || list_ptr->HEAD == list_ptr->NIL){
        std::cout<< std::endl;
        return;
    }
    //cerr<<1;
    Node* current = list_ptr->HEAD;
    //cerr<<2;
    while (current->next != list_ptr->HEAD && current->next != current) {
        //cerr<<current->prev->key<<" "<<current->next->key<<" ";
        std::cout << current->key << "  ";
        current = current->next;
    }
    //cerr<<current->prev->key<<" "<<current->next->key<<" ";
    std::cout << current->key << std::endl;
    return;
}

void destroy_list(List* list_ptr){
    if (list_ptr == nullptr) return;
    Node *current = list_ptr->HEAD;
    for (size_t i = 0; i < list_ptr->size; ++i) {
        Node *oldNode;
        if (current->next != list_ptr->NIL) {
            oldNode = current;
            current = current->next;
            delete oldNode;
        } else {
            delete current;
        }
    }
    delete list_ptr->NIL;
    delete list_ptr;
    return;
}



void lets_play(List* list, Node*& current, int leap, string targ, int cntr){
    //print(list);
    cntr++;
    for(int i = 0; i < leap; i++){
        current = current->next;
    }
    if(current->key == targ){
        cout << cntr;
        destroy_list(list);
        return;
    }
    current = current->next;
    Node* prev_current = current->prev;
    //delete delete delete
    if(current->prev != list->TAIL && current->prev != list->HEAD){
        prev_current->prev->next = current;
        current->prev = prev_current->prev;
    }else{
        if(prev_current == list->HEAD){
            prev_current->prev->next = prev_current->next;
            prev_current->next->prev = prev_current->prev;
            list->HEAD = prev_current->next; 
        }else{
            prev_current->prev->next = prev_current->next;
            prev_current->next->prev = prev_current->prev;
            list->TAIL = prev_current->prev; 
        }
    }
    list->size--;
    delete prev_current;
    //delete delete delete

    lets_play(list, current, leap, targ, cntr);

}


int main(){
    int n, leap;
    cin >> n;
    List* list = create_empty_list();
    for(int i; i<n; i++){
        string c;
        cin >> c;
        push_back(list, c);
    }
    cin >> leap;
    string look;
    cin >> look;
    //Node* targ = find_key(list, look);
    lets_play(list, list->TAIL, leap, look, 0);
}