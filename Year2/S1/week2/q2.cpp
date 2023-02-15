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
                if (current->getprev() == NULL){
                  	if (current->getnext() == NULL){
                    	this->head = NULL;
                      	this->tail = NULL;
                      	delete current;
                    	return;
                    }
                    this->head = current->getnext();
                    current->getnext()->setprev(NULL);
                    delete current;
                    return;
                }
                if (current->getnext() == NULL){
                  	if (current->getprev() == NULL){
                    	this->head = NULL;
                      	this->tail = NULL;
                      	delete current;
                    	return;
                    }
                    current->getprev()->setnext(NULL);
                    this->tail = current->getprev();
                    delete current;
                    return;
                }
                current->getprev()->setnext(current->getnext());
                current->getnext()->setprev(current->getprev());
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
	Node<T> *gethead(){
        return head;
    }
    Node<T> *gettail(){
        return tail;
    } 
    void sethead(Node<T> *input){
        this->head = input;
        return;
    } 
    void settail(Node<T> *input){
        this->tail = input;
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
//coding this work below
template<class T>
class Queue{
public:
  Queue(){
    this->list = new LinkedList<T>;
  }
  void enqueue(T data){
    list->addToTail(data);
    return;
  }

  T dequeue(){
        Node<T> *current = list->gethead();
        T result = current->getdata();
        list->deleteData(result);
        return result;
  }

  T front(){
    return list->gethead()->getdata();
  }

  bool isEmpty(){
    if (list->gethead() == NULL) return true;
    return false;
  }

  private: 
    LinkedList<T> *list;
};