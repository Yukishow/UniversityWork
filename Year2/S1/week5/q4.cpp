#include <iostream>
#include <string>
#include <sstream>
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
    void setdata(T input){
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
    LinkedList(LinkedList<T> *list)
    {
        head = NULL;
        tail = NULL;
        Node<T> *current = list->gethead();
        while (current){
            this->addToTail(current->getdata());
            current = current->getnext();
        }
        this->count = list->linksize();
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
        out<<"(";
        Node<T> *current = n->head;
        while(current != NULL){
            current == n->tail?out<< current->getdata()  : out<< current->getdata() <<", ";
            current=current->getnext();
        }
        out<<")\n";
        return out;
    }
    int linksize(){
        return count;
    }
    string listtostring()
    {
        Node<T> *current = this->head;
        string result;
        while (current){
            stringstream ss;
            ss << current->getdata();
            result += ss.str();
            current = current->getnext();
            //ss.clear();
        }
        return result;
    }
    void reverselist(){
        Node<string> *current = this->head;
        Node<string> *tmp;
        // 判斷是否是 1 或 0 位數
        if ((head == tail && tail) || !head) return;
        while (current){
            tmp = current->getnext();
            current->setnext(current->getprev());
            current->setprev(tmp);
            current = current->getprev();
        }
        tmp = head;
        head = tail;
        tail = tmp;
    }
    void remove_head(){
        if(head == NULL) return;
        Node<T> *current = head;
        if(head == tail){
            head = NULL;
            tail = NULL;
        }else{
            head->getnext()->setprev(NULL);
            head = head->getnext();
        }
        count--;
        delete current;
    }
    void remove_tail(){
        if(tail == NULL) return;
        Node<T> *current = tail;
        if(head == tail){
            head = NULL;
            tail = NULL;
        }else{
            tail->getprev()->setnext(NULL);
            tail = tail->getprev();
        }
        count--;
        delete current;
    }
private:
    Node<T> *head;
    Node<T> *tail;
    int count;
};
class BigDecimal {
public:
    BigDecimal()
    {
        integer = new LinkedList<string>();
        decimal = new LinkedList<string>();
        is_positive = 1;
    }
    BigDecimal(string data)
    {
        integer = new LinkedList<string>();
        decimal = new LinkedList<string>();
        is_positive = 1;
        this->stringTolist(data);
        remove_zero();
    }
    BigDecimal(BigDecimal *bigDecimal){
        integer = new LinkedList<string>(bigDecimal->integer);
        decimal = new LinkedList<string>(bigDecimal->decimal);
        this->is_positive = bigDecimal->is_positive;
    }
    ~ BigDecimal(){
        delete integer;
        delete decimal;
    }
    BigDecimal* operator+(BigDecimal *bigDecimal)
    {
        if (is_positive != bigDecimal->is_positive){
            bigDecimal->is_positive ^= 1;
            return *this - bigDecimal;
        }
        int len = decimal->linksize();
        if (len < bigDecimal->decimal->linksize()) len = bigDecimal->decimal->linksize();
        string num1 = this->listTostring();
        string num2 = bigDecimal->listTostring();
        //cout << num1 << " " << num2 << endl;
        if (num1[0] == '-') num1.erase(0,1);
        if (num2[0] == '-') num2.erase(0,1);
        // 對齊
        for(int i=0;i < len-decimal->linksize();i++) 
            num1 += "0";
        for(int i=0;i < len-bigDecimal->decimal->linksize();i++)
            num2 += "0";
        // 最後在處理小數點
        if((int)num1.find('.') != -1) num1.erase(num1.find('.'),1); 
        if((int)num2.find('.') != -1) num2.erase(num2.find('.'),1);
        string result = Add(num1,num2);
        while ((int)result.size() < len + 1) result.insert(0,"0");
        result.insert((int)result.size()-len,".");//把多乘的10除回去
        //取15位的小數(精度)
        while((int)result.find('.') != -1 && (int)result.size() - (int)result.find('.') - 1 > 15)
            result.erase((int)result.size()-1);
        if(is_positive) stringTolist(result);
        else stringTolist("-" + result);
        return this;
    }

    BigDecimal* operator-(BigDecimal *bigDecimal) 
    {
        if (is_positive != bigDecimal->is_positive){
            bigDecimal->is_positive ^= 1;
            return *this + bigDecimal;
        }
        int len = decimal->linksize();
        if (len < bigDecimal->decimal->linksize()) len = bigDecimal->decimal->linksize();
        string num1 = this->listTostring();
        string num2 = bigDecimal->listTostring();
        if (num1[0] == '-') num1.erase(0,1);
        if (num2[0] == '-') num2.erase(0,1);
        // 對齊
        for(int i=0;i < len-decimal->linksize();i++) 
            num1 += "0";
        for(int i=0;i<len-bigDecimal->decimal->linksize();i++)
            num2 += "0";
        // 最後在處理小數點
        if((int)num1.find('.') != -1) num1.erase(num1.find('.'),1); 
        if((int)num2.find('.') != -1) num2.erase(num2.find('.'),1);
        if (!comp(num1,num2)){
            is_positive ^= 1;
            swap(num1,num2);
        }
        string result = subtract(num1,num2);
        while ((int)result.size() < len + 1) result.insert(0,"0");
        result.insert((int)result.size()-len,".");//把多乘的10除回去
        //取15位的小數(精度)
        while((int)result.find('.') != -1 && (int)result.size() - (int)result.find('.') - 1 > 15)
            result.erase((int)result.size()-1);
        if(is_positive) stringTolist(result);
        else stringTolist("-" + result);
        return this;
    }

    BigDecimal* operator*(BigDecimal *bigDecimal)
    {   
        long long dot = decimal->linksize() + bigDecimal->decimal->linksize();
        long long len = integer->linksize() + bigDecimal->integer->linksize() + dot;
        int resultarr[len] = {0};
        //for(int i=0;i<len;i++) resultarr[i]=0;
        string num1 = listTostring();
        string num2 = bigDecimal->listTostring();
        if (num1[0] == '-') num1.erase(0,1);
        if (num2[0] == '-') num2.erase(0,1);
        // 最後在處理小數點
        if((int)num1.find('.') != -1) num1.erase(num1.find('.'),1); 
        if((int)num2.find('.') != -1) num2.erase(num2.find('.'),1);
        string result = multip(num1,num2,resultarr);
        result.insert((int)result.size() - dot,".");
        while (result[0] == '0' && result.size()) result.erase(0,1);
        while((int)result.find('.') != -1 && (int)result.size() - (int)result.find('.') - 1 > 15)
            result.erase((int)result.size()-1);
        while((result[(int)result.size() - 1] == '0' && (int)result.find('.') != -1) || result[(int)result.size() - 1] == '.')
            result.erase((int)result.size() - 1);
        is_positive = !(is_positive ^ bigDecimal->is_positive);
        if(is_positive) stringTolist(result); 
        else stringTolist( "-" + result);
        return this;
    }
  
    BigDecimal* operator/(BigDecimal *bigDecimal) 
    {
        int len = decimal->linksize();
        if (len < bigDecimal->decimal->linksize()) len = bigDecimal->decimal->linksize();
        string num1 = this->listTostring();
        string num2 = bigDecimal->listTostring();
        if (num1[0] == '-') num1.erase(0,1);
        if (num2[0] == '-') num2.erase(0,1);
        // 對齊
        for(int i=0;i < len-decimal->linksize();i++) 
            num1 += "0";
        for(int i=0;i<len-bigDecimal->decimal->linksize();i++)
            num2 += "0";
        // 最後在處理小數點
        if((int)num1.find('.') != -1) num1.erase(num1.find('.'),1); 
        if((int)num2.find('.') != -1) num2.erase(num2.find('.'),1);
        // 清零
        while (num1[0] == '0' && num1.size()) num1.erase(0,1);
        while (num2[0] == '0' && num2.size()) num2.erase(0,1);
        // 提高精度 被除數補至15位
        for(int i=0;i<15;i++) num1 += "0";
        string result = division(num1,num2);
        // 提高精度 答案補至15位
        while((int)result.size() < 16) result.insert(0,"0");
        //補多乘的10除回去
        result.insert((int)result.size() - 15,".");
        //超過15位的小數刪掉
        while((int)result.find('.') != -1 && (int)result.size() - (int)result.find('.') - 1 > 15)
            result.erase(result.size()-1);
        is_positive = !(is_positive ^ bigDecimal->is_positive);
        if (is_positive) stringTolist(result);
        else stringTolist("-" + result);
        return this;        
    }

    BigDecimal* operator^(BigDecimal *bigDecimal) 
    {
        
        if (!is_positive) is_positive = !(stoi(bigDecimal->integer->gettail()->getdata())%2);
        bool sign = is_positive;
        bool signPower = bigDecimal->is_positive;
        bool is_int = 0;
        if (bigDecimal->decimal->listtostring() == "00") is_int = 1;
        else{   
            myln();
            *this * bigDecimal;
        }
        BigDecimal *result = new BigDecimal("1");
        if (listTostring() == "1.00" || listTostring() == "-1.00"){
            is_positive = sign;
            return this;
        }
        if (is_int){
            myPow(this,bigDecimal);
            delete bigDecimal;
            if (!signPower){
                *result / this;
                stringTolist(result->listTostring());
            }
            delete result;
            is_positive = sign;
            return this;
        }
        BigDecimal *tmp = (signPower) ? mytaylor() : (*result / mytaylor());
        tmp->is_positive = sign;
        stringTolist(tmp->listTostring());
        delete result;
        return this;
    }
    bool operator>(BigDecimal *bigDecimal)
    {
        if (integer->listtostring() == bigDecimal->integer->listtostring())
            return decimal->listtostring() > bigDecimal->decimal->listtostring();
        if (integer->linksize() == bigDecimal->integer->linksize())
            return integer->listtostring() > bigDecimal->integer->listtostring();
        return integer->linksize() > bigDecimal->integer->linksize();
    }
    void rounding(){
        remove_zero();
        BigDecimal *tmp = new BigDecimal("0.01");
        bool carry = 0;
        if(decimal->linksize() > 2){
            if(decimal->gethead()->getnext()->getnext()->getdata() == "5"){
                if(decimal->linksize() > 3)
                    carry = 1;
                else if(stoi(decimal->gethead()->getnext()->getdata()) % 2)
                    carry = 1;
            }else if(stoi(decimal->gethead()->getnext()->getnext()->getdata()) > 5)
                carry = 1;
        }
        while(decimal->linksize() > 2)
            decimal->remove_tail();
        if(carry){
            if(is_positive)
                *this + tmp;
            else
                *this - tmp;
        }else
            delete tmp;
    }
    friend std::ostream &operator<<(std::ostream &out, BigDecimal *bigDecimal)
    {
        bigDecimal->rounding();
        string result = bigDecimal->listTostring();
        if (result == "-0.00") result.erase(0,1);
        out << result << endl;
        return out;            
    }
    friend std::istream &operator>>(std::istream &in, BigDecimal *data)
    {
        string input;
        if (in >> input) data->stringTolist(input);
        return in;
    }

private:
    LinkedList<string> *integer;
    LinkedList<string> *decimal;
    bool is_positive;

    void stringTolist(string str)
    {
        // 正負號處理
        if (str[0] == '-'){
            is_positive = 0;
            str.erase(0,1);
        }else is_positive = 1;
        // 如果沒有整數或小數 補回去
        if(!integer) integer = new LinkedList<string>();
        if(!decimal) decimal = new LinkedList<string>();
        int dot = ((int)str.find('.') == -1) ? str.size():str.find('.');
        // 數字整理位數不夠增加位數反之刪除
        // 整數
        Node<string> *current = integer->gethead();
        for (int i=0;i<dot;i++){
            string tmp(1,str[i]);
            if (current) current->setdata(tmp);
            else integer->addToTail(tmp);
            if (current) current = current->getnext();
        }
        // 小數
        current = decimal->gethead();
        for (int i=dot+1;i<(int)str.size();i++){
            string tmp(1,str[i]);
            if (current) current->setdata(tmp);
            else decimal->addToTail(tmp);
            if (current) current = current->getnext();
        }
        // 刪除多於位數
        while (integer->linksize() > dot) integer->remove_tail();
        int dec = str.size() - dot - 1;
        if (dec < 0) dec = 0;
        while (decimal->linksize() > dec) decimal->remove_tail();
        // 最後刪除頭尾的零
        remove_zero();
    }
    string listTostring()
    {
        string result = "";
        Node<string> *current = integer->gethead();
        while (current){
            result += current->getdata();
            current = current->getnext();
        }
        // 如果沒有整數 應該要是 0.
        if (result == "") result += "0";
        // err
        if (decimal->linksize() != 0){
            result += ".";
            current = decimal->gethead();
            while (current){
                result += current->getdata();
                current = current->getnext();
            }
        }
        if (!is_positive) result.insert(0,"-");
        return result;  
    }
    void remove_zero()
    {
        while (this->decimal->linksize() > 2 && this->decimal->gettail()->getdata() == "0")  
            this->decimal->remove_tail();
        while (decimal->linksize() < 2) decimal->addToTail("0");
        while (this->integer->linksize() > 1 && this->integer->gethead()->getdata() == "0") 
            this->integer->remove_head();
    }
    string Add(string num1,string num2)
    {
        num1 = reverse(num1);
        num2 = reverse(num2);
        // 如果 num2 位數較大 將它補到 num1 
        if (num2.size() > num1.size()){
            int n = num1.size();
            num1 += num2.substr(n);
            num2.erase(n);
        }
        int carry = 0;
        for (int i=0;i<(int)num1.size();i++){
            if (i >= (int)num2.size() && !carry) break;
            if (i < (int)num2.size())
                num1[i] = num1[i] + num2[i] - '0';
            num1[i] += carry;
            if (num1[i] > '9'){
                num1[i] -= 10;
                carry = 1;
            }else carry = 0;
        }
        if (carry) num1 += "1";
        num1 = reverse(num1);
        return num1;
    }
    string subtract(string num1,string num2)
    {
        int carry = 0;
        num1 = reverse(num1);
        num2 = reverse(num2);
        for (int i=0;i<(int)num1.size();i++){
            num1[i] -= carry;
            if (i < (int)num2.size()){
                num1[i] += '0';
                num1[i] -= num2[i];
            }
            carry = num1[i] < '0' ? 1 : 0;
            if (num1[i] < '0') num1[i] += 10;
        }
        num1 = reverse(num1);
        while (num1[0] == '0' && (int)num1.size()) num1.erase(0,1);
        return num1;
    }
    string reverse(string num)
    {
        for(int i=0;i<(int)num.size()/2;i++){
            char ch = num[i];
            num[i] = num[(int)num.size()-1-i];
            num[(int)num.size()-1-i]=ch;
        }
        return num;
    }
    bool comp(string num1,string num2)
    {
        if (num1.size() == num2.size()) return num1 > num2;
        return num1.size() > num2.size();
    }
    string multip(string num1,string num2,int *result)
    {
        int i=0,j=0;
        for (i = 0;i<(int)num1.size();i++)
            for (j = 0;j<(int)num2.size();j++)
                result[i+j] += (num1[i] - '0') * (num2[j] - '0');
        
        int back = i + j - 2;
        for (i = back;i>0;i--){
            if (result[i] >= 10){
                result[i - 1] += result[i] / 10;
                result[i] %= 10;
            }
        }
        num1 = "";
        for (i = back;i>=0;i--)
            num1.insert(0,to_string(result[i]));
        return num1;
    } 
    string division(string num1,string num2)
    {
        if (num1.size() < num2.size()) return "0.00";
        int base = num2.size();
        string result = "";
        while (num1.size() > num2.size()) num2 += "0";
        while ((int)num2.size() >= base){
            int tmp = 0;
            while (comp(num1,num2)){
                num1 = subtract(num1,num2);
                tmp++;
            }
            result += to_string(tmp);
            num2.erase((int)num2.size()-1);
        }
        // 清零
        while (result[0] == '0' && result.size()) result.erase(0,1);
        return result;
    }
    BigDecimal *myln()
    {
        BigDecimal *ln[17];
        ln[0]=new BigDecimal("6.907755278982136"); //ln1000
        ln[1]=new BigDecimal("4.605170185988091"); //ln100
        ln[2]=new BigDecimal("0.693147180559945"); //ln2
        ln[3]=new BigDecimal("0.048790164169432"); //ln1.05
        ln[4]=new BigDecimal("0.009950330853168"); //ln1.01
        ln[5]=new BigDecimal("0.001998002662673"); //ln1.002
        ln[6]=new BigDecimal("0.000199980002666"); //ln1.0002
        ln[7]=new BigDecimal("0.000019999800002"); //ln1.00002
        ln[8]=new BigDecimal("0.000001999998000"); //ln1.0000002
        ln[9]=new BigDecimal("0.000000199999979"); //ln1.000000002
        ln[10]=new BigDecimal("0.00000001999999"); //ln1.0000000002
        ln[11]=new BigDecimal("0.00000000199999"); //ln1.00000000002
        ln[12]=new BigDecimal("0.00000000020000"); //ln1.000000000002
        ln[13]=new BigDecimal("0.00000000002000"); //ln1.0000000000002
        ln[14]=new BigDecimal("0.00000000000199"); //ln1.00000000000002
        ln[15]=new BigDecimal("0.00000000000020"); //ln1.000000000000002
        ln[16]=new BigDecimal("0.00000000000001"); //ln1.0000000000000002

        BigDecimal *divisor[17];
        divisor[0]=new BigDecimal("1000"); //ln1000
        divisor[1]=new BigDecimal("100"); //ln100
        divisor[2]=new BigDecimal("2"); //ln2
        divisor[3]=new BigDecimal("1.05"); //ln1.05
        divisor[4]=new BigDecimal("1.01"); //ln1.01
        divisor[5]=new BigDecimal("1.002"); //ln1.002
        divisor[6]=new BigDecimal("1.0002"); //ln1.0002
        divisor[7]=new BigDecimal("1.00002"); //ln1.00002
        divisor[8]=new BigDecimal("1.000002"); //ln1.000002
        divisor[9]=new BigDecimal("1.0000002"); //ln1.0000002
        divisor[10]=new BigDecimal("1.00000002"); //ln1.00000002
        divisor[11]=new BigDecimal("1.000000002"); //ln1.000000002
        divisor[12]=new BigDecimal("1.0000000002"); //ln1.0000000002
        divisor[13]=new BigDecimal("1.00000000002"); //ln1.00000000002
        divisor[14]=new BigDecimal("1.000000000002"); //ln1.000000000002
        divisor[15]=new BigDecimal("1.0000000000002"); //ln1.0000000000002
        divisor[16]=new BigDecimal("1.00000000000002"); //ln1.00000000000002

        BigDecimal *limit = this;
        BigDecimal *result = new BigDecimal("0.00");
        for (int i =0;i<17;i++){
            while (*limit > divisor[i]){
                *limit / divisor[i];
                *result + ln[i];
            }
        }
        for(int i=0;i<17;i++){
            delete ln[i];
            delete divisor[i];
        }
        stringTolist(result->listTostring());
        //cout << listTostring() << endl;
        delete result;
        return this;
    }
    BigDecimal *mytaylor(){
        BigDecimal *e = new BigDecimal("2.718281828459045090795598298427648842334747314453125");
        BigDecimal *power = this;
        BigDecimal *result = new BigDecimal("1");
        // 次方項 是否為小數
        if ((integer->listtostring() + ".00") != listTostring()){
            BigDecimal *base = new BigDecimal("0." + power->decimal->listtostring());
            BigDecimal *dividend = new BigDecimal("1");
            for (int i=1;i<20;i++){
                BigDecimal *divisor = new BigDecimal(to_string(factorial(i)));
                *dividend * base;
                BigDecimal *tmp = new BigDecimal();
                tmp->stringTolist(dividend->listTostring());
                *tmp / divisor; //除以階乘
                *result + tmp; //加入result
                delete divisor;
                if(tmp->listTostring() == "0.00" || tmp->listTostring() == "-0.00"){
                    delete tmp;
                    break;
                }
                delete tmp;
            }
            delete base;
            delete dividend;
        }
        if (power->integer->listtostring() == "") power->integer->addToHead("0");
        if (power->integer->listtostring() != "0"){
            myPow(e,power);
            *result * e;
        }
        delete e;
        stringTolist(result->listTostring());
        delete result;
        return this;
    }
    string toBinary(int data){
        string n;
        while (data / 2){
            n += ((data % 2) + '0');
            data /= 2;
        }
        if (data) n += '1';
        return n;
    } 
    void myPow(BigDecimal *base,BigDecimal *power)
    {
        string binary = toBinary(stoi(power->integer->listtostring()));
        BigDecimal *e = new BigDecimal(base); //基數
        base->stringTolist("1");
        for(int i=0;i<(int)binary.size();i++){
            if(binary[i] == '1'){
                *base * e;
            }
            *e * e;
        }
        delete e;
    }
    long long factorial(int n){
        long long result = 1;
        for(int i=1;i<=n;i++)
            result *= i;
        return result;
    }
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
    list->remove_tail();
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
    case '^': return 3;
	case '/':
	case '*': return 2;
	case '+':
	case '-': return 1;
	default : return 0;
	}
}
bool isnegative(int p,string str){
        if(p == -1) return 1;
        if(str[p] == ')' || isdigit(str[p])) return 0;
        return 1;
    }
string inToPostfix(string str){
    string result = "";
    Stack<char> oper;
    for (int i=0;i<(int)str.size();i++){
        if (isdigit(str[i]) || str[i] == '.')
        {
            while (isdigit(str[i]) || str[i] == '.'){
                result += str[i];
                i++;
            }
            result += " ";
            i--;
        }
        else
        {
            if (str[i] == '-' && isnegative(i-1,str)) result += "-";
            else if (str[i] == ')')
            {
                if (oper.isEmpty()) return "ERROR";
                while (oper.top() != '('){
                    result += oper.pop();
                    result += " ";
                    if (oper.isEmpty()) return "ERROR";
                }
                oper.pop();
            }
            else if (!oper.isEmpty() && operPriority(oper.top()) >= operPriority(str[i]) && str[i] != '(' ){
                while(operPriority(str[i]) <= operPriority(oper.top()) && oper.top() != '(')
                {
                    result += oper.pop();
                    result += " ";
                    if (oper.isEmpty()) break;
                }
                oper.push(str[i]);
            }
            else{
                oper.push(str[i]);
            }
        }
    }
    while(!oper.isEmpty()){
        result += oper.pop();
        result += " ";
    }
    return result;
}

int main(){
    string input;
    while(cin >> input){
        Stack<BigDecimal*> nums;
        string postfix = inToPostfix(input);
        bool err = 0;
        //cout << postfix << endl;
        if (postfix == "ERROR") cout << "ERROR" << endl;
        else{
            for (int i=0;i<(int)postfix.size();i++){
                if (isdigit(postfix[i]) || isdigit(postfix[i+1])){
                    string tmp;
                    while(postfix[i] != ' '){
                        tmp += postfix[i];
                        i++;
                    }
                    BigDecimal *num = new BigDecimal(tmp);
                    nums.push(num);
                }
                else{
                    if (nums.size() < 2)
                    {
                        err =1;
                        cout << "ERROR" << endl;
                        break;
                    }
                    else
                    {
                        BigDecimal *num2 = nums.pop();
                        BigDecimal *num1 = nums.pop();
                        if (postfix[i] == '+') *num1 + num2;
                        else if (postfix[i] == '-') *num1 - num2;
                        else if (postfix[i] == '*') *num1 * num2;
                        else if (postfix[i] == '/') *num1 / num2;
                        else *num1 ^ num2;
                        num1->rounding();
                        nums.push(num1);
                        i++;
                    } 
                }
            }
            if (err) continue;
            if (nums.size() > 1) cout << "ERROR" << endl;
            else cout << nums.pop();
        }
    }
    return 0;
}