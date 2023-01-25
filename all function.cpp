#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;

};

///insert
void insertFront(node *header, int data);
void insertLast(node *header, int data);
void insertAt(node *header, int data, int index);
void insertBeforeValue(node *header, int data, int value);
void insertSortedOrder(node *header, int data);

///update
void updateFront(node *header, int data);
void updateLast(node *header, int data);
void updateAt(node *header, int data, int index);
void updateValue(node *header, int data, int value);

///delete
void deleteFront(node *header);
void deleteLast(node *header);
void deleteAt(node *header, int index);
void deleteValue(node *header, int value);

///search
int searchIndexOfValue(node *header, int data);
int valueOfIndex(node *header, int index);

///print
void printList(node *header);


void printList(node *header){
    node *ptr = header->link;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
    cout<<endl;
}

int searchIndexOfValue(node *header, int data)
{
    node *ptr = header->link;
    int index =0;

    while(ptr -> data != data && ptr != NULL)
    {
        index++;
        ptr = ptr->link;
    }
    if(ptr -> data == data)
        return index;
    else
        return -1;
}

int valueOfIndex(node *header, int index)
{
    node *ptr = header -> link;
    int i = 0;
    do
    {
        if(ptr==NULL)
        {
            cout<<"Array out of Bound OR Empty List"<<endl;
            return -9999;
        }
        else
        {
            ptr = ptr ->link;
            i++;
        }
    }
    while(i!=index);
    return ptr ->data;
}

void updateFront(node *header, int data)
{
    header ->link->data = data;
}

void updateLast(node *header, int data)
{
    node *ptr = header;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->data = data;
}


void updateAt(node *header, int data, int index)
{
    node *ptr = header;
    int indexCheck = -1;

    while(indexCheck<index-1 && ptr->link != NULL)
    {
        indexCheck++;
        ptr = ptr->link;
    }
    if(indexCheck+1 != index)
    {
        return;
    }
    ptr ->link->data = data;
}

void updateValue(node *header, int data, int value)
{
    int index = searchIndexOfValue(header, value);
    updateAt(header, data, index);
}

void deleteFront(node *header)
{
    if(header->link == NULL)
        return;

    node *ptr = header ->link;

    header -> link = ptr ->link;
    free(ptr);
}

void deleteLast(node *header)
{
    if(header ->link == NULL)
        return;

    node *ptr = header;
    while(ptr ->link ->link != NULL)
    {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr ->link = NULL;
}

void deleteAt(node *header, int index)
{
    if(header ->link == NULL)
        return;

    node *ptr = header;
    int indexCheck = -1;
    while(indexCheck<index-1 && ptr ->link != NULL)
    {
        indexCheck++;
        ptr = ptr->link;
    }
    if(indexCheck+1 != index)
    {
        return;
    }

    node *temp = ptr->link->link;
    free(ptr->link);
    ptr->link =temp;
}

void deleteValue(node *header, int value)
{
    int index = searchIndexOfValue(header, value);
    deleteAt(header, index);
}

void insertSortedOrder(node *header, int data)
{
    node *ptr = header->link;
    node *pred;
    node *newNode = (node*)malloc(sizeof(node));

    if(ptr == NULL || ptr->data >data)
    {
        newNode->data = data;
        newNode->link = ptr;
        header->link = newNode;
    }else
    {
        pred = header;
        while(ptr != NULL && ptr-> data<data)
        {
            pred = ptr;
            ptr = ptr->link;
        }

        newNode->data = data;
        newNode->link = pred->link;
        pred->link = newNode;
    }
}

void insertFront(node *header, int data)
{
    node *newNode = (node*) malloc(sizeof(node));
    if(newNode == NULL)
    {
        cout<<"Memory not available Function not Compiled"<<endl;

    }
    else
    {
        newNode->data = data;
        newNode->link = header->link;
        header->link = newNode;

    }
}


void insertLast(node *header, int data)
{
    node *ptr = header;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        cout<<"Memory not available Function not Completed"<<endl;
    }
    else
    {
        newNode->data = data;
        newNode->link = ptr->link;
        ptr->link = newNode;
    }

}
void insertAt(node *header, int data, int index)
{
    node *ptr = header;
    int indexCheck = -1;
    while(indexCheck<index -1 && ptr->link !=NULL)
    {
        indexCheck++;
        ptr = ptr->link;
    }
    if(indexCheck+1 != index)
    {
        cout<<"Out of Bound"<<endl;
    }
    else
    {
        node *newNode = (node*)malloc(sizeof(node));
        if(newNode == NULL)
        {
            cout<<"Memory not available Function not Completed"<<endl;
        }
        else
        {
            newNode->data = data;
            newNode->link = ptr->link;
            ptr->link = newNode;
        }
    }
}
void insertBeforeValue(node *header, int data, int value){
    int index = searchIndexOfValue(header, value);
    insertAt(header, data, index);
}
