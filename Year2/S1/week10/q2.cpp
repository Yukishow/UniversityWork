#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
template <class T>
class Node
{
public:
    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(T data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(T data, Node<T> *prev, Node<T> *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    Node<T> *getprev()
    {
        return prev;
    }

    Node<T> *getnext()
    {
        return next;
    }

    void setprev(Node<T> *input)
    {
        this->prev = input;
        return;
    }

    void setnext(Node<T> *input)
    {
        this->next = input;
        return;
    }
    
    T getdata()
    {
        return data;
    }

private:
    Node<T> *prev;
    Node<T> *next;
    T data;
};
template <class T>
class LinkedList
{
public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void addToTail(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->head == NULL)
        {
            head = node;
            tail = node;
            return;
        }
        this->tail->setnext(node);
        node->setprev(this->tail);
        this->tail = node;
        return;
    }
    void addToHead(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->head == NULL)
        {
            head = node;
            tail = node;
            return;
        }
        this->head->setprev(node);
        node->setnext(this->head);
        this->head = node;
        return;
    }

    void deleteData(T data)
    {
        Node<T> *current = this->head;
        while (current != NULL)
        {
            if (current->getdata() == data)
            {
                if (current->getprev() == NULL && current->getnext() == NULL)
                {
                    this->head = NULL;
                    this->tail = NULL;
                }
                else if (current->getprev() == NULL)
                {
                    this->head = current->getnext();
                    current->getnext()->setprev(NULL);
                }
                else if (current->getnext() == NULL)
                {
                    current->getprev()->setnext(NULL);
                    this->tail = current->getprev();
                }
                else
                {
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

void rdeleteData(T data)
    {
        Node<T> *current = this->tail;
        while (current != NULL)
        {
            if (current->getdata() == data)
            {
                if (current->getprev() == NULL && current->getnext() == NULL)
                {
                    this->head = NULL;
                    this->tail = NULL;
                }
                else if (current->getprev() == NULL)
                {
                    this->head = current->getnext();
                    current->getnext()->setprev(NULL);
                }
                else if (current->getnext() == NULL)
                {
                    current->getprev()->setnext(NULL);
                    this->tail = current->getprev();
                }
                else
                {
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
    void deleteData(T data, int n)
    {
        for (int i = 0; i < n; i++)
        {
            this->deleteData(data);
        }
        return;
    }

    Node<T> *gethead()
    {
        return head;
    }

    Node<T> *gettail()
    {
        return tail;
    }

    void sethead(Node<T> *input)
    {
        this->head = input;
        return;
    }

    void settail(Node<T> *input)
    {
        this->tail = input;
        return;
    }

    friend std::ostream &operator<<(std::ostream &out, LinkedList *n)
    {
        Node<T> *current = n->head;
        out << "(";
        while (current->getnext() != NULL)
        {
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
template<class T>
class Queue{
public:
  Queue(){
    this->list = new LinkedList<T>;
    this->count = 0;
  }
  void enqueue(T data){
    list->addToTail(data);
    this->count++;
    return;
  }

  T dequeue(){
        Node<T> *current = list->gethead();
        if (current == NULL) return NULL;
        T result = current->getdata();
        list->deleteData(result);
        this->count--;
        return result;
  }

  T front(){
    return list->gethead()->getdata();
  }

  bool isEmpty(){
    if (list->gethead() == NULL) return true;
    return false;
  }
  int size()
  {
    return this->count;
  }
  LinkedList<T> *getlist()
  {
    return list;
  }
  private: 
    LinkedList<T> *list;
    int count;
};
template <class T>
class Treenode{
public:
	T data;
	Treenode<T> *left, *right;
	int height;

	Treenode()
    {
        left = NULL;
        right = NULL;
        height = 1;
    }
	Treenode(T Data)
    {
        data = Data;
        left = NULL;
        right = NULL;
        height = 1;
        
    }
};
/*
有更好的邏輯程式碼
有時間再整理~~呵呵
*/
template <class T>
class AVL_Tree{
public:
	Treenode<T> *root;

	AVL_Tree()
    {
        root = NULL;
    }

    int getheight(Treenode<T> *node)
    {
        if (!node) return 0;
        return node->height;
    }

    int getBalanceFactor(Treenode<T> *node)
    {
        if (!node) return 0;
        return getheight(node->left) - getheight(node->right);
    }

    Treenode<T> *LeftRotate(Treenode<T> *y)
    {
        Treenode<T> *x = y->right;
        Treenode<T> *T2 = x->left;

        x->left = y;
        y->right = T2;

        y->height = max(getheight(y->right),getheight(y->left)) + 1;
        x->height = max(getheight(x->right),getheight(x->left)) + 1;

        return x;
    }

    Treenode<T> *RightRotate(Treenode<T> *x)
    {
        Treenode<T> *y = x->left;
        Treenode<T> *T2 = y->right;

        y->right = x;
        x->left = T2;

        x->height = max(getheight(x->right),getheight(x->left)) + 1;
        y->height = max(getheight(y->right),getheight(y->left)) + 1;
        

        return y;
    }

    Treenode<T> *insertnode(Treenode<T> *node,T data)
    {
        if (node == NULL) return (new Treenode<T>(data));

        if (judge(node->data,data))
            node->left = insertnode(node->left,data);
        else if (judge(data,node->data)) 
            node->right = insertnode(node->right,data);
        else return node;

        node->height = max(getheight(node->left),getheight(node->right)) + 1;
        int bf = getBalanceFactor(node);

        // Left Left case
        if (bf > 1 && judge(node->left->data,data))
        {
            return RightRotate(node);
        }
        // Right Right case
        if (bf < -1 && judge(data,node->right->data))
        {
            return LeftRotate(node);
        }
        // Left Right case
        if (bf > 1 && judge(data,node->left->data))
        {
            // cout << "LR" << endl;
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }
        // Right Left case
        if (bf < -1 && judge(node->right->data,data))
        {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node;
    }

    void insert(T data)
    {
        this->root = insertnode(this->root,data);
    }

    Treenode<T> *findmax(Treenode<T> *node)
    {
        if (!node || !node->right) return node;
        return findmax(node->right);
    }

    Treenode<T> *deletenode(Treenode<T> *node,T data)
    {
        if (!node) return NULL;
        if (judge(node->data,data)) node->left = deletenode(node->left,data);
        else if (judge(data,node->data)) node->right = deletenode(node->right,data);
        else
        {
            Treenode<T> *temp = NULL;
            //有左右子樹
            if (node->left && node->right)
            {
                temp = findmax(node->left);
                node->data = temp->data;
                node->left = deletenode(node->left,node->data);
            }
            else if (node->left)
            {
                temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                temp = node;
                node = node->right;
                delete temp;
            }
        }

        if (!node) return node;

        node->height = max(getheight(node->left),getheight(node->right)) + 1;
        int bf = getBalanceFactor(node);

        if (bf > 1)
        {
            if (getBalanceFactor(node->left) >= 0)
                return RightRotate(node);
            else
            {
                node->left = LeftRotate(node->left);
                return RightRotate(node);
            }
        }
        else if (bf < -1)
        {
            if (getBalanceFactor(node->right) <= 0)
                return LeftRotate(node);
            else
            {
                node->right = RightRotate(node->right);
                return LeftRotate(node);
            }
        }

        return node;
    }

    void delet(T data)
    {
        this->root = deletenode(this->root,data);
    }

    bool judge(string a,string b)
    {
        if (isdigit(a[0]))
        {
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        }
        int alen = a.size(),blen = b.size();
        int lenmax = alen > blen ? alen : blen;
        for (int i=alen;i<lenmax;i++) a += "+";
        for (int i=blen;i<lenmax;i++) b += "+";
        return a > b;
    }

    bool AllNULL(Node<Treenode<T>*> *head)
    {
        Node<Treenode<T>*> *current = head;
        while (current != NULL)
        {
            if (current->getdata() != NULL)
            return 1;
            current = current->getnext();
        }
        return 0;
    }

    string serialize()
    {
        string result = "";
        Treenode<T> *node = this->root;
        Queue<Treenode<T>*> queue;
        if (node == NULL) return "NULL";
        queue.enqueue(node);
        while (true)
        {
            node = queue.dequeue();
            if (node == NULL) result += "NULL,";
            else
            {
                result += node->data + ",";
                queue.enqueue(node->left);
                queue.enqueue(node->right);
            } 
            if (!AllNULL(queue.getlist()->gethead()))
            {
                node = queue.dequeue();
                if (node == NULL) result.erase(result.size()-1,1);
                else result += node->data;
                break;
            }
        }
        return result;
    }
    void in(Treenode<T> *node)
    {
        if (!node) return;
        in(node->left);
        cout << node->data << " ";
        in(node->right);
    }

    void pre(Treenode<T> *node)
    {
        if (!node) return;
        cout << node->data << " ";
        pre(node->left);
        pre(node->right);
    }

};

int main(){
    AVL_Tree<string> *Root = new AVL_Tree<string>();
    string input;
    while (cin >> input)
    {
        if (input == "insert")
        {
            cin >> input;
            Root->insert(input);
        }
        else
        {
            cin >> input;
            Root->delet(input);
        }
    }
    // Root->in(Root->root);
    // cout << endl;
    // Root->pre(Root->root);
    // cout << endl;
    cout << Root->serialize() << endl;

    return 0;
}
