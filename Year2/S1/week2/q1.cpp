#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node{
public:
    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(T data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(T data, Node<T> *prev, Node<T> *next){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
    Node<T> *getprev(){
        return prev;
    }
    Node<T> *getnext(){
        return next;
    } 
    void setprev(Node<T> *input){
        this->prev = input;
        return;
    } 
    void setnext(Node<T> *input){
        this->next = input;
        return;
    }
    T getdata(){
        return data;
    }   
private:
    Node<T> *prev;
    Node<T> *next;
    T data;
};
template <class T>
class LinkedList{
public:
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    void addToTail(T data){
        Node<T> *node = new Node<T>(data);
        if (this->head == NULL){
            head = node;
          	tail = node;
            return;
        }
       	this->tail->setnext(node);
        node->setprev(this->tail);
        this->tail = node;
        return;
    }
    void addToHead(T data){
        Node<T> *node = new Node<T>(data);
        if (this->head == NULL){
            head = node;
          	tail = node;
            return;
        }
        this->head->setprev(node);
        node->setnext(this->head);
        this->head = node;
        return;
    }

    void deleteData(T data){
        Node<T> *current = this->head;
        while (current != NULL){
            if (current->getdata() == data){
              	if (current->getprev() == NULL && current->getnext() == NULL){
                    	this->head = NULL;
                      	this->tail = NULL;
                }
                else if (current->getprev() == NULL){
                    this->head = current->getnext();
                    current->getnext()->setprev(NULL);
                }
                else if (current->getnext() == NULL){
                    current->getprev()->setnext(NULL);
                    this->tail = current->getprev();
                }
              	else{
                	current->getprev()->setnext(current->getnext());
                	current->getnext()->setprev(current->getprev());
                }
                delete current;
                return;
            }
            current = current->getnext();
        }
        return;
    }

    void deleteData(T data, int n){
        for (int i=0;i<n;i++){
            this->deleteData(data);
        }
        return;
    }

    friend std::ostream &operator<<(std::ostream &out, LinkedList *n){
        Node<T> *current = n->head;
        out << "(";
        while (current->getnext() != NULL){
            out << current->getdata() << ", ";
            current = current->getnext();
        }
        out << current->getdata() << ")" << endl;
        return out;
    }
    
private:
    Node<T> *head;
    Node<T> *tail;
};