#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
    node*prev;

    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
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
            newnode->next=head;
            newnode->prev=tail;
        }
        else{
            newnode->prev=tail;
            newnode->next=head;
            tail->next=newnode;
            head->prev=newnode;
            tail=newnode;
        }
    }

    void insertatBeg(int data){
        node*newnode=new node(data);

        if(head==NULL){
            head=newnode;
            tail=newnode;
            newnode->next=head;
            newnode->prev=tail;
        }
        else{
            newnode->next=head;
            newnode->prev=tail;
            head->prev=newnode;
            tail->next=newnode;
            head=newnode;
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
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next=newnode;

        if(temp==tail)
            tail=newnode;
    }

    void deleteNode(int value){
        if(head==NULL)
            return;

        node*temp=head;

        do{
            if(temp->data==value){

                if(head==tail){
                    delete temp;
                    head=NULL;
                    tail=NULL;
                    return;
                }

                if(temp==head){
                    head=head->next;
                    head->prev=tail;
                    tail->next=head;
                    delete temp;
                    return;
                }

                if(temp==tail){
                    tail=tail->prev;
                    tail->next=head;
                    head->prev=tail;
                    delete temp;
                    return;
                }

                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                return;
            }

            temp=temp->next;
        }while(temp!=head);
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
