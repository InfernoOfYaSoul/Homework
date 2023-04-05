#include <iostream>
using namespace std;

struct Node{
    int key = 0;
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

List* push_front(List* list_ptr, int new_key){
    if(list_ptr == nullptr) return nullptr;
    
    if(list_ptr->HEAD == list_ptr->NIL && list_ptr->size == 0){
        //cerr<<list_ptr->TAIL->key;
        //cerr<<list_ptr->HEAD->key<<endl;
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size += 1;
        //cerr<<list_ptr->TAIL->key;
        //cerr<<list_ptr->HEAD->key<<endl<<endl;
        return list_ptr;
    }
    
    if(list_ptr->HEAD->next == nullptr){
        
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        
        list_ptr->HEAD->next = list_ptr->TAIL;
        
        list_ptr->TAIL->prev = list_ptr->HEAD;
        list_ptr->size++;
        
        return list_ptr;
    }
    Node* old = list_ptr->HEAD;
    list_ptr->HEAD = new Node;
    list_ptr->HEAD->key = new_key;
    list_ptr->HEAD->next = old;
    old->prev = list_ptr->HEAD;
    list_ptr->size++;
    return list_ptr;
}

List* push_back(List* list_ptr, int new_key){
    if(list_ptr == nullptr) return nullptr;
    
    if(list_ptr->HEAD == list_ptr->NIL && list_ptr->size == 0){
        //cerr<<list_ptr->TAIL->key;
        //cerr<<list_ptr->HEAD->key<<endl;
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size += 1;
        //cerr<<list_ptr->TAIL->key;
        //cerr<<list_ptr->HEAD->key<<endl<<endl;
        return list_ptr;
    }
    if(list_ptr->HEAD->next == nullptr){
        
        list_ptr->TAIL = new Node;
        list_ptr->TAIL->key = new_key;
        
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->TAIL->prev = list_ptr->HEAD;

        list_ptr->size++;
        
        return list_ptr;
    }
    Node* old = list_ptr->TAIL;
    list_ptr->TAIL = new Node;
    list_ptr->TAIL->key = new_key;
    list_ptr->TAIL->prev = old;
    old->next = list_ptr->TAIL;

    list_ptr->size++;
    return list_ptr;
}

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key){
    if(list_ptr == nullptr || prev_ptr == nullptr) return nullptr;

    if (prev_ptr == list_ptr->NIL)  return list_ptr;

    Node *cur = new Node;
    cur->key = new_key;
    cur->next = prev_ptr->next;
    prev_ptr->next = cur;
    if (prev_ptr == list_ptr->TAIL) {
        list_ptr->TAIL = cur;
    }else{
        cur->next->prev = cur;
    }
    list_ptr->size++;
    return list_ptr;
}

void print(const List* list_ptr){
    if(list_ptr == nullptr || list_ptr->HEAD == list_ptr->NIL){
        std::cout<< std::endl;
        return;
    }
    Node* current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        std::cout << current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
    return;
}

void clear_list(List* list_ptr){}

int main(){
    List* list = create_empty_list();
  list = push_back(list, 0);
  list = insert_after(list, list->HEAD, 1);
  if ((list->HEAD->key == 0) and (list->TAIL->key == 1)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list->TAIL;
  delete list->NIL;
  delete list;
  return 0;



    //List* list = nullptr;
  //list = push_front(list, 1);
  //cout<< list->TAIL->key;
  //cout<< list->HEAD->key<<"!"<<endl;
  //list = push_front(list, 7);
  //cout<< list->TAIL->key;
  //cout<< list->HEAD->key<<"!"<<endl;
  //list = push_front(list, 8);
  //cout<< list->TAIL->key;
  //cout<< list->HEAD->key<<"!";
  //list = push_front(list, 0);
  /*if ((list->HEAD->key == 0) and (list->TAIL->key == 1)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  //delete list->NIL;
  delete list;
  return 0;*/
}