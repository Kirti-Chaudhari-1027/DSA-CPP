#include<iostream>
using namespace std;

class Node{

    public:

    int data; //node->data
    Node* next; //next pointer of Node type
    Node* prev; //previous pointer of Node type

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }

        cout<<"Value deleted = "<<val<<endl;
    }
};

//Insert At Head
void insertAthead(Node* &head, int data){

    //empty
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

}

//Inserting at given Position
void insertAtPos(Node* &head,int pos, int data){

    //empty
    if(head == NULL || pos == 1){
        insertAthead(head,data);
    }
    else{
        Node* trav = head;
        int cnt = 1;

        while(cnt<pos-1){
            trav = trav->next;
            cnt++;
        }

        Node* newNode = new Node(data);
        if(trav->next == NULL){
            trav->next = newNode;
            newNode->prev = trav;
        }
        else{
            newNode->next = trav->next;
            trav->next->prev = newNode;
            trav->next = newNode;
            trav->next->prev = trav;
        }
    }
}

//Deleting
void deleteNode(Node* &head,int pos){

    //head
    if(pos == 1){
        Node* temp = head->next;
        temp->prev = NULL;
        head->next = NULL;
        delete head;
        head = temp;
    }
    else{
        Node* trav = head;
        Node* prev_node = NULL;
        int cnt=1;

        while(cnt<pos){
            prev_node = trav;
            trav = trav->next;
            cnt++;
        }

        if(trav->next == NULL){
            prev_node->next = NULL;
            trav->prev = NULL;
            delete trav;
        }
        else{
            prev_node->next = trav -> next;
            trav->next->prev = prev_node;
            trav->next = NULL;
            trav->prev = NULL;
            delete trav;
        }
    }
}

//Printing
void Print(Node* &head){

    if(head == NULL){
        cout<<"Empty LL"<<endl;
    }
    else{
        Node* temp = head;
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }

    }
    cout<<endl;
}

int main(){

    Node* head = new Node(15);
    Print(head);

    insertAthead(head,13);
    Print(head);

    insertAtPos(head,2,14);
    Print(head);

    insertAtPos(head,3,16);
    Print(head);

    insertAtPos(head,5,17);
    Print(head);

    cout<<"After deletion = :"<<endl;
    deleteNode(head,2);
    Print(head);

    cout<<"After deletion = :"<<endl;
    deleteNode(head,1);
    Print(head);   

    cout<<"After deletion = :"<<endl;
    deleteNode(head,3);
    Print(head); 
}