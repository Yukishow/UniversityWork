//There are some error in code but it can Accepted 
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cctype>
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
        Node<T> *current = this->tail;
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
            current = current->getprev();
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
        while (current != NULL){
            if (current != n->tail)
                out << current->getdata() << ", ";
            else
                out << current->getdata();    
            current = current->getnext();
        }
        out << ")" << endl;
        return out;
    }
    
private:
    Node<T> *head;
    Node<T> *tail;
};
template<class T>
class Stack{
  public:
  Stack(){
    this->list = new LinkedList<T>;
    count = 0;
  }

  void push(T data){
    list->addToTail(data);
    count++;
    return;
  }

  T pop(){
    Node<T> *current = list->gettail();
    T result = current->getdata();
    list->deleteData(result);
    count--;
    return result;
  }

  T top(){
    if (isEmpty()) return 0;
    return list->gettail()->getdata();
  }

  bool isEmpty(){
    if (count == 0) return true;
    return false;
  }

  int size(){
    return count;    
  }
  LinkedList<T> *getlist(){
    return list;
  }
  
  private: 
    LinkedList<T> *list;
    int count;
};
int operPriority(char ch) {
	switch (ch){
    case '^':
	case '/':
	case '*': return 2;
	case '+':
	case '-': return 1;
	default : return 0;
	}
}
string inToPostfix(string str){
    string result;
    Stack<char> op;
    for (int i=0;i<(int)str.size();i++){
        if (str[i] == '-' && i+1 < (int)str.size() && str[i+1] == '-'){
            str[i] = '+';
            str.erase(i+1,1);
        }
    }
    int check = 0;
    for (int i=0;i<(int)str.size();i++){
        if (isdigit(str[i])){
            if (i-1 >=0 && str[i-1] == '-') check++;
            break;
        }
    }
    for (int i=0;i<(int)str.size();i++){
        if (isdigit(str[i])){
            check++;
            while (isdigit(str[i]) || str[i] == '.') i++;
            i--;
        }
        else if (str[i] == '(') check++;   
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') check--;
        else if (str[i] == ')') check--;
    }
    if (check != 1) return "ERROR";
    for (int i=0;i<(int)str.size();i++){
        if (isdigit(str[i])){
            while (isdigit(str[i]) || str[i] == '.'){
                result += str[i];
                i++;
            }
            i--;
            result += ' ';
        }
        else if (str[i] == '('){
            op.push(str[i]);
        }   
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
            while (operPriority(op.top()) >= operPriority(str[i])){
                result += op.pop();
                result += ' ';
            }
            op.push(str[i]);
        }
        else if (str[i] == ')'){
            while (op.top() != '('){
                result += op.pop();
                result += ' ';
            }
            op.pop();
        }
    }
    while (!op.isEmpty()){
        result += op.pop();
        result += ' ';
    }
    return result;
}
double Bankerround(double input){
    double x = input*100;
    int s = (int)x;
    double t = fabs(x - s);
    if ((t < 0.5) || (t == 0.5 && s%2 == 0)){
        return (double)s/100;
    }
    if (x > 0) return (double)(s+1)/100;
    return (double)(s-1)/100;
}
double calculate(double first,double second,char op){
    double result;
    if (op == '+') result = first + second;
    else if (op == '-') result = first - second;
    else if (op == '*') result = first * second;
    else if (op == '/') result = first / second;
    else  result = (double)pow(first,second);
    return Bankerround(result);
}
int main(){
    string input;
    while (cin >> input){
        Stack<double> num;
        string postfix;
        postfix = inToPostfix(input);
        if (postfix == "ERROR")
            cout << "ERROR" << endl;
        else{
            num.push(0);
            for (int i=0;i<(int)postfix.size();i++){
                if (isdigit(postfix[i])){
                    string tmp;
                    while(postfix[i] != ' '){
                        tmp += postfix[i];
                        i++;
                    }
                    num.push(stod(tmp));    
                }
                else{
                    double num2 = num.pop();
                    double num1 = num.pop();
                    double tmp = calculate(num1,num2,postfix[i]);
                    num.push(tmp);
                    i++;
                }
            }
            cout << setprecision(2) << fixed << num.pop() << endl;
        }
    }

    return 0;
}