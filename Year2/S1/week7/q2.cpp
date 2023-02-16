#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Tree
{
public:
	Tree()
	{
		int j;
		for(j = 0;j < 2000;j ++)
			root[j] = -1;
	}
	int insert(int node)
	{
		int index = 0;
		while(index < 2000 && root[index] != -1)
		{
			if(root[index] < node)
				index = index * 2 + 2;
			else
				index = index * 2 + 1;
		}
        if (index >= 2000) return 0;
		root[index] = node;
        return 1;
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
        for (int i=0;i<2000;i++)
        {
            if (root[i] == -1) continue;
            printf("%d ",root[i]);
        }
	}
private:
    void in(int index)
    {
        if (root[index] == -1) return;
        in(index * 2 + 1);
        printf("%d ",root[index]);
        in(index * 2 + 2);
    }
    void pre(int index)
    {
        if (root[index] == -1) return;
        printf("%d ",root[index]);
        pre(index * 2 + 1);
        pre(index * 2 + 2); 
    }
    void post(int index)
    {
        if (root[index] == -1) return;
        post(index * 2 + 1);
        post(index * 2 + 2);
        printf("%d ",root[index]); 
    }
	int root[2000];
};
int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = rand();
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
