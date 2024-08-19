#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    int size=0;

    void insertAtHead(int val){
        Node* temp= new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }

    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }

    void insertAtIdx(int idx, int val){
        if(idx<0 || idx>size) cout<<"Invalid Index";
        else if(idx==0) insertAtHead(val);
        else if(idx==(size-1)) insertAtTail(val);
        else{
            Node* t=new Node(val);
            Node* temp=head;
            for(int i=0;i<=idx-2;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }

    void remove(int idx){
        if(size==1) head=tail=NULL;
        else{
            Node* temp = head;
            for(int i=0;i<idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            temp->next->next=NULL;
        }
    }

    int get(int idx){
        if(size==0) cout<<"Invalid Index"<<endl;
        else{
            Node* temp = head;
            for(int i=0;i<=idx-1;i++){
                temp=temp->next;
            }
            return temp->val;
        }
    }
    
    void display(){
        Node* temp = head;
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList ll;
    cout<<"Adding Elements into the LL : "<<endl;
    ll.insertAtHead(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.insertAtTail(50);
    ll.display();
    cout<<"Adding Element at a Index : "<<endl;
    ll.insertAtIdx(3,60);
    ll.display();
    cout<<"Deleting Element at an Index : "<<endl;
    ll.remove(4);
    ll.display();
    cout<<"Display of the Elements :  "<<endl;
    ll.display();
}