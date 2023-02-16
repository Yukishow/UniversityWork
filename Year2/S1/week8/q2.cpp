//this code may have error
#include <iostream>
#include <string>
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
		this->prev = NULL;
		this->next = NULL;
		this->data = data;
	}
	Node(T data, Node<T> *prev, Node<T> *next)
	{
		this->prev = prev;
		this->next = next;
		this->data = data;
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
	}
	void setnext(Node<T> *input)
	{
		this->next = input;
	}
	T getdata()
	{
		return data;
	}
	void setdatat(T input)
	{
		this->data = input;
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
		count = 0;
	}
	void addToTail(T data)
	{
		Node<T> *node = new Node<T>(data);
		if (this->head == NULL)
		{
			head = node;
			tail = node;
			count++;
			return;
		}
		count++;
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
			count++;
			return;
		}
		count++;
		this->head->setprev(node);
		node->setnext(this->head);
		this->head = node;
		return;
	}
	void deleteData(T data)
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
				count--;
				delete current;
				return;
			}
			current = current->getprev();
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
				count--;
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
			this->deleteData(data);
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
	}
	void settail(Node<T> *input)
	{
		this->tail = input;
	}
	int size()
	{
		return count;
	}
	Node<T> *insert(T data)
    {
        Node<T> *current = this->head;
        if (current == NULL)
        {
            this->head = new Node<T>(data);
            this->tail = this->head;
            return this->head;
        }
        if (current->getdata()->getdata() > data->getdata())
        {
            this->head->setprev(new Node<T>(data));
            this->head->getprev()->setnext(this->head);
            this->head = this->head->getprev();
            return this->head;
        }
        while (current)
        {
            if (current->getdata()->getdata() == data->getdata())
                return current;
            if (current->getdata()->getdata() > data->getdata())
            {
                current->getprev()->setnext(new Node<T>(data));
                current->getprev()->getnext()->setnext(current);
                current->getprev()->getnext()->setprev(current->getprev());
                current->setprev(current->getprev()->getnext());
                return current->getprev();
            }
            else if (current->getnext() == NULL)
            {
                current->setnext(new Node<T>(data));
                current->getnext()->setprev(current);
                return current->getnext();
            }
            else
                current = current->getnext();
        }
    }
	Node<T> *search(T data)
    {
        Node<T> *current = this->head;
        while (current)
        {
            if (current->getdata()->getdata() == data->getdata())
                return current;
            current = current->getnext();
        }
        return NULL;
    }
	friend std::ostream &operator<<(std::ostream &out, LinkedList *n)
	{
		Node<T> *current = n->head;
		out << "(";
		while (current != NULL)
		{
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
	int count;
};
class GeneralTreeNode
{
public:
	GeneralTreeNode()
	{
		this->is_end = 0;
		this->children =new LinkedList<GeneralTreeNode*>;
	}
	GeneralTreeNode(string data)
	{
		this->data = data;
		this->is_end = 0;
		this->children =new LinkedList<GeneralTreeNode*>;
	}
	string getdata()
	{
		return this->data;
	}
	void setdata(string data)
	{
		this->data = data;
	}
	void setend(bool data)
	{
		this->is_end = data;
	}
	bool getend()
	{
		return this->is_end;
	}
	LinkedList<GeneralTreeNode*> *getChildren()
	{
		return this->children;
	}
	void setChildren(LinkedList<GeneralTreeNode*> *children)
	{
		this->children = children;
	}
private:
    LinkedList<GeneralTreeNode*> *children;
    bool is_end;
    string data;
};
/**
 * Rules of Serialize and Deserialize for General Tree:
 * 1. The serialized string should be in the following format which is standard JSON format but without any spaces:
 * {"root":{"children":[{"children":[{"children":[],"data":"d"},{"children":[],"data":"p"}],"data":"a"},{"children":[],"data":"b"}],"data":""}}
 * In each node, there are two data structures.
 *  a. children.
 *  b. data.
 * "children" is an array that always comes first.
 * "data" is a data structure stored in the node, that comes after children, sorted in alphabetical order.
 *
 * 2. All nodes in the same layer should be sorted in alphabetical order if is a character type, and sorted by numerical order if is a number type.
 * 3. LinkedList is treated as Array in serialization and deserialization.
 */
class GeneralTree
{
public:
	GeneralTree()
	{
		this->root = new GeneralTreeNode;
	}
	bool insert(string data)
	{
		string str = data;
		GeneralTreeNode *current = this->root;
		GeneralTreeNode *tmp = new GeneralTreeNode();
		for (int i=1;i<=(int)str.size();i++)
		{
			tmp->setdata(data.substr(0,i));
			if (current->getChildren()->search(tmp))
			{
				current = current->getChildren()->search(tmp)->getdata();
				if (i == (int)str.size())
				{
					current->setend(1);
					delete tmp;
					return 0;
				}
				else
					continue;
			}
			GeneralTreeNode *newnode = new GeneralTreeNode(data.substr(0,i));
			current = current->getChildren()->insert(newnode)->getdata();
			if (i == (int)str.size()) newnode->setend(1);
		}
		delete tmp;
		return 1;
	}
	bool find(string data)
	{
		string str = data;
		GeneralTreeNode *current = this->root;
		GeneralTreeNode *tmp = new GeneralTreeNode();
		for (int i=1;i<=(int)str.size();i++)
		{
			tmp->setdata(data.substr(0,i));
			if (current->getChildren() == NULL)
			{
				delete tmp;
				return 0;
			}
			Node<GeneralTreeNode*> *temp = current->getChildren()->search(tmp);
			if (temp)
			{
				if (i == (int)str.size())
				{
					delete tmp;
					if (temp->getdata()->getend()) return 1;
					return 0;
				}
				current = temp->getdata();
			}
			else
			{
				delete tmp;
				return 0;
			}
		}
		delete tmp;
		return 0;
	}
	void setRoot(GeneralTreeNode *root)
	{
        if (this->root == NULL)
		{
			this->root = root;
			return;
		}
		this->root->setdata(root->getdata());
	}
	string treetostring(GeneralTreeNode *node,int judge)
	{
		if (!node) return "";
        string ans = "";
        if (judge != 0) ans += ",";
        ans += "{\"children\":[";
        if (node->getChildren() != NULL)
        {
            Node<GeneralTreeNode*> *current = node->getChildren()->gethead();
            judge = 0;
            while (current)
            {
                ans += this->treetostring(current->getdata(),judge);
                current = current->getnext();
                judge++;
            }
        }
        ans += "],\"data\":\"";
        if (node)
        {
            if (node->getdata() != "")
                ans += (node->getdata())[(node->getdata()).length() - 1];
        }
        ans += "\"";
        if (node->getend())
        {
            ans += ",\"end\":\"true\"";
        }
        ans += "}";
        return ans;
	}
    string serialize()
	{
		string result = "{\"root\":";
		result += this->treetostring(this->root,0);
		result += "}";
		return result;
	}
private:
    GeneralTreeNode *root;
};

int main()
{
	GeneralTree *Root = new GeneralTree;
	int m,n;
	string input;
	cin >> m >> n;
	while (m--)
	{
		cin >> input;
		Root->insert(input);
	}
	while (n--)
	{
		cin >> input;
		cout << Root->find(input) << endl;
	}
    cout << Root->serialize() << endl;
	return 0;
}