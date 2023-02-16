//using BigDecimal
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
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
    void setdatat(T input){
        this->data = input;
        return;
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
        this->count = 0;
    }
    ~ LinkedList(){
        Node<T> *current = this->head;
        while(current){
            Node<T> *tmp = current;
            current = current->getnext();
            delete tmp;
        }
    }
    void addToTail(T data){
        Node<T> *node = new Node<T>(data);
        if (this->head == NULL){
            head = node;
          	tail = node;
            count++;
            return;
        }
       	this->tail->setnext(node);
        node->setprev(this->tail);
        this->tail = node;
        count++;
        return;
    }
    void addToHead(T data){
        Node<T> *node = new Node<T>(data);
        if (this->head == NULL){
            head = node;
          	tail = node;
            count++;
            return;
        }
        this->head->setprev(node);
        node->setnext(this->head);
        this->head = node;
        count++;
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
                count--;
                delete current;
                return;
            }
            current = current->getnext();
        }
        return;
    }
    void rdeleteData(T data){
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
                count--;
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
        while (current != NULL){
            out << current->getdata();    
            current = current->getnext();
        }
        return out;
    }
    int linksize(){
        int count = 0;
        Node<T> *current = this->head;
        while (current != NULL){
            count++;
            current = current->getnext();
        }
        return count;
    }
    T remove_head(){
        Node<T> *current = this->head;
        T result = this->head->getdata();
        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail = NULL;
            delete current;
            count--;
            return result;
        }
        head->getnext()->setprev(NULL);
        head = head->getnext();
        delete current;
        return result;
    }
    T remove_tail(){
        Node<T> *current = this->tail;
        T result = this->head->getdata();
        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail = NULL;
            delete current;
            count--;
            return result;
        }
        tail->getprev()->setnext(NULL);
        tail = tail->getprev();
        delete current;
        return result;
    }
long long int count;
private:
    Node<T> *head;
    Node<T> *tail;
};
class BigDecimal {
public:
    BigDecimal()
    {
        integer = new LinkedList<string>;
        decimal = new LinkedList<string>;
        is_positive = 1;
    }
    BigDecimal(string data)
    {
        integer = new LinkedList<string>;
        decimal = new LinkedList<string>;
        int len = (int)data.find(".") == -1 ? (data.size()) : (data.find("."));
        int i;
        for (i=0;i<len;i++){
            string tmp = "";
            tmp += data[i];
            this->integer->addToTail(tmp);
        }
        for (i+=1;i<(int)data.size();i++){
            string tmp = "";
            tmp += data[i];
            this->decimal->addToTail(tmp);
        }
        if (this->integer->gethead()->getdata() == "-"){
            this->integer->deleteData("-");
            this->is_positive = 0;
        }
        else this->is_positive = 1;
    }

    BigDecimal* operator+(BigDecimal *bigDecimal)
    {
        if (this->is_positive && bigDecimal->is_positive == 0) // +-
        {
            bigDecimal->is_positive = 1;
            return *this - bigDecimal;
        }
        if (this->is_positive == 0 && bigDecimal->is_positive) // -+
        {
            this->is_positive = 1;
            return *bigDecimal - this;
        }
        string result = "";
        this->Line_up_decimal(bigDecimal);
        this->Line_up_integer(bigDecimal);
        Node<string> *num1 = this->decimal->gettail(),*num2 = bigDecimal->decimal->gettail();
        int carry = 0;
        result += this->Add(num1,num2,&carry);
        result += ".";
        num1 = this->integer->gettail();num2 = bigDecimal->integer->gettail();
        result += this->Add(num1,num2,&carry);
        if (carry) result += "1";
        if (!this->is_positive) result += "-";
        reverse(result.begin(),result.end());
        BigDecimal *ans = new BigDecimal(result);
        ans->remove_zero();
        return ans; 
    }

    BigDecimal* operator-(BigDecimal *bigDecimal) 
    {
        if (this->is_positive == 0 && bigDecimal->is_positive == 0) // --
        {
            this->is_positive = 1;
            bigDecimal->is_positive = 1;
            return *bigDecimal - this;
        }
        if (this->is_positive && bigDecimal->is_positive == 0) // +-
        {
            bigDecimal->is_positive = 1;
            return *this + bigDecimal;
        }
        if (this->is_positive == 0 && bigDecimal->is_positive) // -+
        {
            bigDecimal->is_positive = 0;
            return *bigDecimal + this;
        }
        this->Line_up_decimal(bigDecimal);
        this->Line_up_integer(bigDecimal);
        if (comp(bigDecimal)) // big num - small num
        {
            string result = "";
            Node<string> *num1 = bigDecimal->decimal->gettail(),*num2 = this->decimal->gettail();
            int carry = 0;
            result += this->subtract(num1,num2,&carry);
            result += ".";
            num1 = bigDecimal->integer->gettail();num2 = this->integer->gettail();
            result += this->subtract(num1,num2,&carry);
            result += "-";
            reverse(result.begin(),result.end());
            BigDecimal *ans = new BigDecimal(result);
            ans->remove_zero();
            return ans;
        }
        string result = "";
        Node<string> *num1 = this->decimal->gettail(),*num2 = bigDecimal->decimal->gettail();
        int carry = 0;
        result += this->subtract(num1,num2,&carry);
        result += ".";
        num1 = this->integer->gettail();num2 = bigDecimal->integer->gettail();
        result += this->subtract(num1,num2,&carry);
        reverse(result.begin(),result.end());
        BigDecimal *ans = new BigDecimal(result);
        ans->remove_zero();
        return ans; 
    }

    BigDecimal* operator*(BigDecimal *bigDecimal)
    {   
        bool sign = (this->is_positive == bigDecimal->is_positive);
        int dec_point = 0;
        dec_point += (this->decimal->linksize() + bigDecimal->decimal->linksize());
        string num1 = this->tostring(),num2 = bigDecimal->tostring();
        while (num1[0] == '0' && num1.size() > 2) num1.erase(0);
        while (num2[0] == '0' && num2.size() > 2) num2.erase(0);
        if (num1 == "0" || num2 == "0"){
            BigDecimal *ans = new BigDecimal("0.00");
            return ans;
        }
        int max = num1.size() + num2.size();
        int number[max]={0};
        for (int i=num1.size()-1;i>=0;i--){
            for (int j=num2.size()-1;j>=0;j--){
                int index = num1.size() - 1 - i + num2.size() - 1 - j;
                number[index] += ((num1[i] - '0') * (num2[j] - '0'));
            }
        }
        for (int i=0;i<max-2;i++){
            number[i+1] += number[i]/10;
            number[i] = number[i]%10;
        }
        int index = max - 1;
        while (number[index] == 0) index--;
        string result = "";
        while (index >= 0){
            result += to_string(number[index]);
            index--;
        }
        if (dec_point){
            int len = result.size();
            result.insert(len - dec_point,".");
        }
        if (result[0] == '.') result.insert(0,"0");
        if (!sign) result.insert(0,"-");
        while ((int)result.find(".") != -1 && result[result.size()-1] == '0') result.erase(result.size()-1);
        BigDecimal *ans = new BigDecimal(result);      
        return ans; 
    }
  
    BigDecimal* operator/(BigDecimal *bigDecimal) 
    {
        bool sign = (this->is_positive == bigDecimal->is_positive);
        int dec_point = 0;
        dec_point += (this->decimal->linksize() - bigDecimal->decimal->linksize());
        string num1 = this->tostring(),num2 = bigDecimal->tostring();
        while (num1[0] == '0' && num1.size() >= 2) num1.erase(0,1);
        while (num2[0] == '0' && num2.size() >= 2) num2.erase(0,1);
        if (num1 == "0"){
            BigDecimal *ans = new BigDecimal("0.00");
            return ans;
        }
        if (dec_point > 0) 
            while (dec_point > 0){
                num2 += "0";
                dec_point--;
            }
        else   
            while (dec_point < 0){
                num1 += "0";
                dec_point++;
            }     
        string result = "";
        int count = 0;
        while ((num1.size() > num2.size()) || ((num1.size() == num2.size()) && num1 > num2) || (num1 == num2)){
            count++;
            BigDecimal *numb1 = new BigDecimal(num1),*numb2 = new BigDecimal(num2);
            BigDecimal *tmp = *numb1 - numb2;
            delete numb1;
            delete numb2;
            num1 = tmp->tostring();
            num1.erase((int)num1.size()-1,1);
            num1.erase((int)num1.size()-1,1);
            if (num1 == "0") break;
        }
        result += to_string(count);
        if (num1 != "0")
        {
            result += ".";
            for (int i=0;i<7;i++){
                count = 0;
                num1 += "0";
                while ((num1.size() > num2.size()) || ((num1.size() == num2.size()) && num1 > num2) || (num1 == num2)){
                    count++;
                    BigDecimal *numb1 = new BigDecimal(num1),*numb2 = new BigDecimal(num2);
                    BigDecimal *tmp = *numb1 - numb2;
                    delete numb1;
                    delete numb2;
                    num1 = tmp->tostring();
                    num1.erase((int)num1.size()-1,1);
                    num1.erase((int)num1.size()-1,1);
                }
                result += to_string(count);
                if (num1 == "0") break;
            }
        }
        if (!sign) result.insert(0,"-");
        //cout << result << endl;
        BigDecimal *ans = new BigDecimal(result);
        //cout << ans->tostring() << endl;
        //cout << "--------------" << endl;
        ans->remove_zero();
        //cout << ans->tostring() << endl;
        return ans; 
    }

    BigDecimal* operator^(BigDecimal *bigDecimal) 
    {
        double num = stod(this->Tostring());
        double exp = stod(bigDecimal->Tostring());
        double result = pow(num,exp);
        BigDecimal *ans = new BigDecimal(to_string(result));
        return ans->rounding();
    }

    BigDecimal *operator=(BigDecimal *bigDecimal)
    {
        this->integer = bigDecimal->integer;
        this->decimal = bigDecimal->decimal;
        return this;
    }
    friend std::ostream &operator<<(std::ostream &out, BigDecimal *bigDecimal)
    {
        bigDecimal= bigDecimal->rounding();
        if (!bigDecimal->is_positive) out << "-";
        out << bigDecimal->integer << "." << bigDecimal->decimal << endl;
        return out;            
    }
    friend std::istream &operator>>(std::istream &in, BigDecimal *data)
    {
        string input;
        if (in >> input) (*data) = BigDecimal(input);
        return in;
    }
    BigDecimal* rounding()
    {
        while (this->decimal->linksize() <= 1) this->decimal->addToTail("0");
        if (this->decimal->linksize() == 2) return this;
        if ((this->decimal->gethead()->getnext()->getnext()->getdata() > "5") ||
        (this->decimal->gethead()->getnext()->getnext()->getdata() == "5" && this->decimal->gethead()->getnext()->getnext()->getnext() != NULL) 
        || (this->decimal->gethead()->getnext()->getnext()->getdata() == "5" && (stoi(this->decimal->gethead()->getnext()->getdata()) & 1)))
        {
            while (this->decimal->linksize() > 2) this->decimal->remove_tail();
            BigDecimal *exp = new BigDecimal("0.01"); 
            if (this->is_positive) return *this + exp;
            return *this - exp;
        }
        while (this->decimal->linksize() > 2) this->decimal->remove_tail();
        return this;
    }
private:
    LinkedList<string> *integer;
    LinkedList<string> *decimal;
    bool is_positive;

    void Line_up_decimal(BigDecimal *bigDecimal)
    {
        if (this->decimal->gethead() == NULL )
        {
            this->decimal->addToTail("0");
            this->decimal->addToTail("0");
        }
        if (bigDecimal->decimal->gethead() == NULL)
        {
            bigDecimal->decimal->addToTail("0");
            bigDecimal->decimal->addToTail("0");
        }
        int maxlen = this->decimal->linksize()>bigDecimal->decimal->linksize() ? this->decimal->linksize():bigDecimal->decimal->linksize();
        while (this->decimal->linksize() < maxlen) this->decimal->addToTail("0");
        while (bigDecimal->decimal->linksize() < maxlen) bigDecimal->decimal->addToTail("0");
    }
    void Line_up_integer(BigDecimal *bigDecimal)
    {
        int maxlen = this->integer->linksize()>bigDecimal->integer->linksize() ? this->integer->linksize():bigDecimal->integer->linksize();
        while (this->integer->linksize() < maxlen) this->integer->addToHead("0");
        while (bigDecimal->integer->linksize() < maxlen) bigDecimal->integer->addToHead("0");
    }
    string Add(Node<string> *num1,Node<string> *num2,int *carry)
    {
        string result = "";
        while (num1 != NULL && num2 != NULL){
            if (stoi(num1->getdata()) + stoi(num2->getdata()) + *carry > 9){
                result += to_string(stoi(num1->getdata()) + stoi(num2->getdata()) + *carry - 10);
                *carry = 1;
            }
            else{
                result += to_string(stoi(num1->getdata()) + stoi(num2->getdata()) + *carry);
                *carry = 0;
            }
            num1 = num1->getprev();
            num2 = num2->getprev();
        }
        return result;
    }
    string subtract(Node<string> *num1,Node<string> *num2,int *carry)
    {
        string result = "";
        while (num1 != NULL && num2 != NULL){
            if (stoi(num1->getdata()) - stoi(num2->getdata()) - *carry < 0){
                result += to_string(stoi(num1->getdata()) - stoi(num2->getdata()) - *carry + 10);
                *carry = 1;
            }
            else{
                result += to_string(stoi(num1->getdata()) - stoi(num2->getdata()) - *carry);
                *carry = 0;
            }
            num1 = num1->getprev();
            num2 = num2->getprev();
        }
        return result;
    }
    bool comp(BigDecimal *input)
    {
        string first = "",second = "";
        Node<string> *current = this->integer->gethead(); 
        while ( current != NULL){
            first += current->getdata();
            current = current->getnext();
        }
        current = this->decimal->gethead();
        while ( current != NULL){
            first += current->getdata();
            current = current->getnext();
        }
        current = input->integer->gethead();
        while ( current != NULL){
            second += current->getdata();
            current = current->getnext();
        }
        current = input->decimal->gethead();
        while ( current != NULL){
            second += current->getdata();
            current = current->getnext();
        }
        if (first == second) return 0;
        return first < second;
    }
    void remove_zero()
    {
        while (this->integer->gethead()->getdata() == "0" && this->integer->linksize() >= 2) this->integer->remove_head();
        if (this->decimal->gethead() != NULL)
            while (this->decimal->gettail()->getdata() == "0" && this->decimal->linksize() >= 3) this->decimal->remove_tail();
    }
    string tostring()
    {
        string result = "";
        Node<string> *current = this->integer->gethead();
        while (current != NULL){
            result += current->getdata();
            current = current->getnext();
        }
        current = this->decimal->gethead();
        while (current != NULL){
            result += current->getdata();
            current = current->getnext();
        }
        return result;
    }
    string Tostring()
    {
        string result = "";
        Node<string> *current = this->integer->gethead();
        while (current != NULL){
            result += current->getdata();
            current = current->getnext();
        }
        current = this->decimal->gethead();
        if (current != NULL) result += ".";
        while (current != NULL){
            result += current->getdata();
            current = current->getnext();
        }
        if(!is_positive) result.insert(0,"-");
        return result;
    }
};
int operPriority(char ch) {
	switch (ch){
    case '^': return 3;
	case '/':
	case '*': return 2;
	case '+':
	case '-': return 1;
	default : return 0;
	}
}
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
    list->rdeleteData(result);
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
    //cout << result << endl;
    return result;
}
int main(){
    string input;
    while (cin >> input){
        Stack<BigDecimal*> num;
        string postfix;
        postfix = inToPostfix(input);
        if (postfix == "ERROR")
            cout << "ERROR" << endl;
        else{
            BigDecimal *f = new BigDecimal("0");
            num.push(f);
            for (int i=0;i<(int)postfix.size();i++){
                if (isdigit(postfix[i])){
                    string tmp;
                    while(postfix[i] != ' '){
                        tmp += postfix[i];
                        i++;
                    }
                    BigDecimal *f = new BigDecimal(tmp);
                    num.push(f);    
                }
                else{
                    BigDecimal *num2 = num.pop();
                    BigDecimal *num1 = num.pop(); 
                    BigDecimal *tmp;
                    switch (postfix[i])
                    {
                        case '+': tmp = *num1 + num2;
                        break;
                        case '-': tmp = *num1 - num2;
                        break;
                        case '*': tmp = *num1 * num2;
                        break;
                        case '/': tmp = *num1 / num2;
                        break;
                        case '^': tmp = *num1 ^ num2;
                        break;
                        default: break;
                    }
                    tmp = tmp->rounding();
                    num.push(tmp);
                    i++;
                }
            }
            cout << num.pop();
        }
    }

    return 0;
}