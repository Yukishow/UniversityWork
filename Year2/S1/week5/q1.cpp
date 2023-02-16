#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

class Queue
{
public:
    // front and rear initial -1 will make bug
    Queue()
    {
        front = 0;
        rear = 0;
    }
    int enqueue(int d)
    {
        // Full return -1
        if ((rear + 1) % SIZE == front) return -1;
        rear = (rear + 1) % SIZE;
        data[rear] = d;
        return 1;
    }
    int *dequeue()
    {
        // IsEmpty return nullptr;
        if (front == rear) return nullptr;
        front = (front + 1) % SIZE;
        return &(data[front]);
    }

private:
    int data[SIZE];
    int front,rear;
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while (1)
    {
        cin >> command;
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "enqueue") == 0)
        {
            cout << "Please input a integer data:";
            cin >> data;
            if (queue->enqueue(data) == 1)
            {
                cout << "Successfully enqueue data " << data << " into queue." << endl;
            }
            else
            {
                cout << "Failed to enqueue data into queue." << endl;
            }
        }
        else if (strcmp(command, "dequeue") == 0)
        {
            temp = queue->dequeue();
            if (temp == NULL)
            {
                cout << "Failed to dequeue a data from queue.\n";
            }
            else
            {
                cout << "Dequeue data " << *temp << " from queue." << endl;
            }
        }
    }
}
