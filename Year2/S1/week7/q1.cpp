#include<iostream>
#include<cstdlib>
#include<ctime>

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
class Tree
{
public:
	Tree()
    {
    	root = 0;
		int j, k;
		for(j = 0;j < 20;j ++)
			for(k = 0;k < 4;k ++)
				node[j][k] = -1;
	}
	int insert(int n)
	{
		int f = root, index = 0;
		while(node[index][0] != -1)
			index ++;
		if(index >= 20)
			return -1;
		if(node[root][0] == -1)
		{
			node[root][0] = 1;
			node[root][1] = n;
			return 1;
		}
		else
		{
			node[index][0] = 1;
			node[index][1] = n;
			while(1)
			{
				if(node[f][1] < n)
				{
					if(node[f][3] == -1)
					{
						node[f][3] = index;
						return 1;
					}
					else
					{
						f = node[f][3];
					}
				}
				else
				{
					if(node[f][2] == -1)
					{
						node[f][2] = index;
						return 1;
					}
					else
					{
						f = node[f][2];
					}
				}
			}
		}
	}
	void inorder()
	{
        in(0);
	}
	void preorder()
	{
        pre(0);
	}
	void postorder()
	{
        post(0);
	}
	void levelorder()
	{
        Queue<int> queue;
        queue.enqueue(0);
        while (queue.size() != 0)
        {
            int index = queue.dequeue();
            printf("%d ",node[index][1]);
            if (node[index][2] != -1) queue.enqueue(node[index][2]);
            if (node[index][3] != -1) queue.enqueue(node[index][3]);
        }
	}
private:
	int node[20][4];
	int root;
    void in(int index)
    {
        if (node[index][0] == -1) return;
        if (node[index][2] != -1) in(node[index][2]);
        printf("%d ",node[index][1]);
        if (node[index][3] != -1) in(node[index][3]);
    }
    void pre(int index)
    {
        if (node[index][0] == -1) return;
        printf("%d ",node[index][1]);
        if (node[index][2] != -1) pre(node[index][2]);
        if (node[index][3] != -1) pre(node[index][3]);
    }
    void post(int index)
    {
        if (node[index][0] == -1) return;
        if (node[index][2] != -1) post(node[index][2]);
        if (node[index][3] != -1) post(node[index][3]);
        printf("%d ",node[index][1]);
    }
};

int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = rand() % 10;
		tree->insert(node);
	}
	tree->inorder();
	printf("\n");
	tree->preorder();
	printf("\n");
	tree->postorder();
	printf("\n");
	tree->levelorder();
	printf("\n");
}