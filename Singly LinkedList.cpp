#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node *head = NULL;

void insertAtHead(int data){
    Node *newNode = new Node(data);

    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data){
    Node *newNode = new Node(data);

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
        
    }
    temp->next = newNode;
}

void insertAt(int position, int data){
    Node *newNode = new Node(data);
    Node *temp = head;

    if (position == 0){
        insertAtHead(data);
        return;
    }

    for(int i = 1; i < position; i++){
        if (temp->next != NULL){
            temp = temp->next;
        }
    }
    newNode->next = temp->next;

    temp->next = newNode;

}

void deleteFromHead(){
    head = head->next;
}
void deleteFromEnd(){

    Node *temp = head;

    if(temp->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next= NULL;
    
}

void deleteFromMiddle(int position){

    Node *temp = head;

    for(int i = 1; i< position; i++){
        if(temp->next != NULL){
            temp = temp->next;
        }
    }
    temp->next = temp->next->next;

}

void deleteWithValue(int value){
    

    if(head->data == value){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    while(temp->next && temp->next->data != value){
        temp = temp->next;
    }

    if (temp->next){
        Node *toDelete = temp;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void updateNode(int position, int value){
    Node *temp = head;

    if(position == 0){
        temp->data = value;
        return;
    }

    for (int i = 1; i<position; i++){
        if(temp->next != NULL){
            temp = temp->next;
        }
    }

    if(temp->next == NULL){
        return;
    }

    temp->next->data = value;
}

int main(){
    
    head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 =  new Node(30);

    

    head->next = temp1;
    temp1->next = temp2;

    //insert data in a Linked List (Begin, End, Middle)
    insertAtHead(5);
    insertAtEnd(3);
    insertAt(3,75);  //(position, data)

    //delete data in a Linked List (Begin, End, Middle)
    deleteFromHead();
    deleteFromEnd();
    deleteFromMiddle(3); //(position)
    deleteWithValue(10); //(data)


    insertAtHead(51);
    insertAtHead(45);
    //update node value with index(position, data)
    updateNode(5, 70);
    
    cout<<"Linked List :";
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
    

    /*
    #include <iostream>
    using namespace std;
    
    // Define Node structure
    struct Node {
       int data;
       struct Node* next;
    };
    
    // Initialize head pointer as NULL
    struct Node* head = NULL;
    
    // Insert a node at the beginning
    void insert(int new_data) {
       struct Node* new_node = new Node();  // Create a new node using dynamic memory
       new_node->data = new_data;           // Set data for the new node
       new_node->next = head;               // Set the new node's next pointer to current head
       head = new_node;                     // Update head to point to the new node
    }
    
    // Insert a node at a specific position
    void insertAtSpecificPosition(int new_data, int position) {
       struct Node* new_node = new Node();  // Create a new node
       struct Node* temp = head;            // Start from the head
       new_node->data = new_data;           // Set data for the new node
       new_node->next = NULL;               // Set next to NULL
    
       // If position is 0, insert at the beginning
       if (position == 0) {
          new_node->next = head;
          head = new_node;
          return;
       }
    
       // Traverse to the node before the desired position
       for (int i = 0; temp != NULL && i < position - 1; i++) {
          temp = temp->next;
       }
    
       // If position is out of bounds
       if (temp == NULL) {
          cout << "Position out of bounds." << endl;
          return;
       }
    
       // Insert the new node at the given position
       new_node->next = temp->next;
       temp->next = new_node;
    }
    
    // Insert a node at the end
    void insertAtEnd(int new_data) {
       struct Node* new_node = new Node();  // Create a new node
       struct Node* temp = head;            // Start from the head
       new_node->data = new_data;           // Set data for the new node
       new_node->next = NULL;               // Set next to NULL (end of list)
    
       // If the list is empty, make the new node the head
       if (head == NULL) {
          head = new_node;
          return;
       }
    
       // Traverse to the last node
       while (temp->next != NULL) {
          temp = temp->next;
       }
    
       // Insert the new node at the end
       temp->next = new_node;
    }
    
    // Display the linked list
    void display() {
       struct Node* ptr = head;  // Start from the head
       if (ptr == NULL) {
          cout << "The list is empty." << endl;
          return;
       }
       cout << "The linked list is: ";
       while (ptr != NULL) {  // Traverse until the end of the list
          cout << ptr->data << " ";
          ptr = ptr->next;
       }
       cout << endl;
    }
    
    int main() {
       // Insert nodes at the beginning
       insert(3);
       cout << "After inserting 3 at the beginning: ";
       display();
       
       insert(1);
       cout << "After inserting 1 at the beginning: ";
       display();
       
       insert(7);
       cout << "After inserting 7 at the beginning: ";
       display();
       
       insert(2);
       cout << "After inserting 2 at the beginning: ";
       display();
       
       insert(9);
       cout << "After inserting 9 at the beginning: ";
       display();
       
       // Insert a node at a specific position
       insertAtSpecificPosition(5, 2); // Insert 5 at position 2
       cout << "After inserting 5 at position 2: ";
       display();
       
       // Insert a node at the end
       insertAtEnd(10);
       cout << "After inserting 10 at the end: ";
       display();
       
       return 0;
    }

    */
