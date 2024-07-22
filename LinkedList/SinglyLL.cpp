#include<iostream>
using namespace std;

class Node{

    public:

    int data; //node->data
    Node* next; //next pointer of Node type

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
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
        newNode->next = trav->next;
        trav->next = newNode;
    }
}

//Deleting
void deleteNode(Node* &head,int pos){

    //head
    if(pos == 1){
        Node* temp = head->next;
        head->next = NULL;
        head = temp;
    }
    else{
        Node* trav = head;
        Node* prev = NULL;
        int cnt=1;

        while(cnt<pos){
            prev = trav;
            trav = trav->next;
            cnt++;
        }

        prev->next = trav -> next;
        trav->next = NULL;
        delete trav;
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
}

int main(){

    Node* head = new Node(11);
    cout<<"data = "<<head->data<<endl;
    cout<<"next = "<<head->next<<endl;

    insertAthead(head,9);
    Print(head);
    cout<<endl;

    insertAtPos(head,2,10);
    Print(head);
    cout<<endl;

    insertAtPos(head,4,12);
    Print(head);
    cout<<endl;

    insertAtPos(head,5,15);
    Print(head);
    cout<<endl;

    insertAtPos(head,5,13);
    Print(head);
    cout<<endl;

    insertAtPos(head,6,14);
    Print(head);
    cout<<endl;

    cout<<"After deletion = : "<<endl;
    deleteNode(head,4);
    Print(head);
    cout<<endl;

    deleteNode(head,1);
    Print(head);
    cout<<endl;

    deleteNode(head,5);
    Print(head);
    cout<<endl;

}