#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next,*prev;
}Node;

void initLinkList(struct Node **head){
    (*head) = NULL;
}

void addToHead(struct Node **head, int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if (*head == NULL){
        (*head) = node;
        return;
    }
    node->next = *head;
    (*head)->prev = node;
    (*head) = node;
    return;
}

void addToTail(struct Node **head, int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if (*head == NULL){
        (*head) = node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = node;
    node->prev = current;
    return;
}

void display(struct Node *head){
    Node *current = head;
    printf("(");
    while (current->next != NULL){
        printf("%d, ",current->data);
        current = current->next;
    }
    printf("%d)\n",current->data);
    return;
}

void deleteData(struct Node **head, int data){
    Node *current = *head;
        while (current != NULL){
            if (current->data == data){
                if (current->prev == NULL && current->next == NULL){
                    *head = NULL;
                }
                else if (current->prev == NULL){
                    (*head) = current->next;
                    (*head)->prev = NULL;
                }
                else if (current->next == NULL){
                    current->prev->next = NULL;
                }
                else{
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                free(current);
                return;
            }
            current = current->next;
        }
        return;
}

void deleteDatas(struct Node **head, int data, int n){
    for (int i=0;i<n;i++){
        deleteData(head,data);
    }
    return;
}

void enqueue(struct Node **queue, int data){
    addToTail(queue,data);
    return;
}

int front(struct Node *queue){
    return queue->data;
}

int dequeue(struct Node **queue){
    int result = front(*queue);
    deleteData(queue,result);
    return result;
}

int isEmpty(struct Node *queue){
    if (queue == NULL) return 1;
    return 0;
}