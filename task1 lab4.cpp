#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    node(int d){
        data=d;
        next=NULL;
    }
};

class list{
public:
    node*head;

    list(){
        head=NULL;
    }

    void insertatEnd(int data){
        node*newnode=new node(data);

        if(head==NULL){
            head=newnode;
            return;
        }

        node*temp=head;

        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newnode;
    }

    void arrangeEvenOdd(){
        if(head==NULL)
            return;

        node*evenHead=NULL;
        node*evenTail=NULL;
        node*oddHead=NULL;
        node*oddTail=NULL;

        node*temp=head;

        while(temp!=NULL){
            node*nextnode=temp->next;
            temp->next=NULL;

            if(temp->data%2==0){
                if(evenHead==NULL){
                    evenHead=temp;
                    evenTail=temp;
                }
                else{
                    evenTail->next=temp;
                    evenTail=temp;
                }
            }
            else{
                if(oddHead==NULL){
                    oddHead=temp;
                    oddTail=temp;
                }
                else{
                    oddTail->next=temp;
                    oddTail=temp;
                }
            }

            temp=nextnode;
        }

        if(evenHead==NULL){
            head=oddHead;
        }
        else{
            head=evenHead;
            evenTail->next=oddHead;
        }
    }

    void display(){
        node*temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }

        cout<<"NULL"<<endl;
    }
};

int main(){
    list l;

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter values:";

    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        l.insertatEnd(value);
    }

    cout<<"Original list:";
    l.display();

    l.arrangeEvenOdd();

    cout<<"Modified list:";
    l.display();

    return 0;
}
