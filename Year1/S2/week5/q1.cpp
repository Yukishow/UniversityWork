// container(2)
#include <bits/stdc++.h>
using namespace std;
class container
{
private:
    int *box;
    int len;
    int index;
    static int count;
    bool reallocate(int size)
    {
        int *newarray = new int[size];
        for (int i = 0; i <= index; i++)
        {
            newarray[i] = box[i];
        }
        delete[] box;
        this->len = size;
        box = newarray;
        return true;
    }
    static void increase()
    {
        count++;
    }
    static void decrease()
    {
        count--;
    }

public:
    container(void) : box(NULL), len(0), index(-1)
    {
        increase();
    }
    int getLen()
    {
        return len;
    }
    int getIndex()
    {
        return index;
    }
    container(int len)
    {
        box = new int[len];
        index = -1;
        this->len = len;
        increase();
    }
    ~container()
    {
        delete[] box;
        decrease();
    }
    void traversal()
    {
        if (index == -1)
            cout << "empty" << endl;
        else
        {
            for (int i = 0; i <= index; i++)
            {
                cout << box[i] << " ";
            }
            cout << endl;
        }
    }
    bool push(int data)
    {
        if (len == 0)
            return 0;
        if (index == len - 1)
        {
            reallocate(len * 2);
        }
        index++;
        box[index] = data;
        return true;
    }
    int pop()
    {
        if (index == -1)
            return 0;
        else
        {
            int ret = box[0];
            for (int i = 0; i < index; i++)
            {
                box[i] = box[i + 1];
            }
            index--;
            return ret;
        }
    }
    static int getCount()
    {
        return count;
    }
};
int container::count = 0;