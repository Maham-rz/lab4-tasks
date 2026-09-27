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

class circular{
public:
    node*head;
    node*tail;

    circular(){
        head=NULL;
        tail=NULL;
    }

    void insertatEnd(int data){
        node*newnode=new node(data);

        if(head==NULL){
            head=newnode;
            tail=newnode;
            tail->next=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }

    void insertatBeg(int data){
        node*newnode=new node(data);

        if(head==NULL){
            head=newnode;
            tail=newnode;
            tail->next=head;
        }
        else{
            newnode->next=head;
            head=newnode;
            tail->next=head;
        }
    }

    void insertatPos(int data,int pos){
        if(pos==0){
            insertatBeg(data);
            return;
        }

        if(head==NULL)
            return;

        node*temp=head;

        for(int i=0;i<pos-1;i++){
            temp=temp->next;

            if(temp==head)
                return;
        }

        node*newnode=new node(data);
        newnode->next=temp->next;
        temp->next=newnode;

        if(temp==tail)
            tail=newnode;
    }

    void deleteNode(int value){
        if(head==NULL)
            return;

        if(head==tail){
            if(head->data==value){
                delete head;
                head=NULL;
                tail=NULL;
            }
            return;
        }

        if(head->data==value){
            node*temp=head;
            head=head->next;
            tail->next=head;
            delete temp;
            return;
        }

        node*prev=head;
        node*temp=head->next;

        while(temp!=head){
            if(temp->data==value){
                prev->next=temp->next;

                if(temp==tail)
                    tail=prev;

                delete temp;
                return;
            }

            prev=temp;
            temp=temp->next;
        }
    }

    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        node*temp=head;

        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);

        cout<<endl;
    }
};

int main(){
    circular cll;

    cll.insertatEnd(10);
    cll.insertatEnd(20);
    cll.insertatEnd(30);

    cll.insertatBeg(5);

    cll.insertatPos(15,2);

    cout<<"List after insertion:";
    cll.display();

    cll.deleteNode(20);

    cout<<"List after deletion:";
    cll.display();

    return 0;
}
