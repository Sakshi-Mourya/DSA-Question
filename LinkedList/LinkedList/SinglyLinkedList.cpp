#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * add;
};
struct node *start=NULL, *temp=NULL, *New=NULL, *Prev=NULL, *Next=NULL;

int create();
int insert();
int Delete(); 
int display();

int main(){
    int ch;
    do{
        cout<<"....................Link List...................."<<endl;
        cout<<"Press 1 to CREATE link list"<<endl;
        cout<<"Press 2 to INSERT the element into link list"<<endl;
        cout<<"Press 3 to DELETE the element from link list"<<endl;
        cout<<"Press 4 to DISPLAY all he element from link list"<<endl;
        cout<<"Press 5 for EXIT"<<endl;
        cout<<"Enter the Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: Delete(); break;
            case 4: display(); break;
            case 5: break;
            default : cout<<"Invalid Choice...!!"<<endl;
        }
    }
    while(ch!=5);
    return 0;
}
int create()
{
    int n;
    char ch;
    cout<<"Enter a value : ";
    cin>>n;

    start=(struct node *)malloc(sizeof(struct node));

    start->data=n;
    start->add=NULL;
    temp=start;
    cout<<"To add more elements, Press 'y' or 'Y' : ";
    cin>>ch;

    while(ch=='y' || ch=='Y'){
        cout<<"Enter a value : ";
        cin>>n;

       New=(struct node *)malloc(sizeof(struct node)); 
       New->data=n;
       New->add=NULL;
       temp->add=New;
       temp=New;
       cout<<"To add more elements, Press 'y' or 'Y' : ";
       cin>>ch;
    }
    return 0;
}
int  insert()
{
    int n, position, count=0, i=1;
    if(start==NULL){
        cout<<"List not created, create a list first"<<endl;
    }
    else{
        cout<<"Enter a value : ";
        cin>>n;
        New = (struct node *)malloc(sizeof(struct node));
        New->data=n;
        New->add=NULL;
        cout<<"Enter a position for node insertion : ";
        cin>>position;

        if(position==1){
            New->add=start;
            start=New;
        }
        else{
            temp=start;
            while(temp!=NULL){
                count++;
                temp=temp->add;
            }
            if(position > count+1){
                cout<<"Invalid Position, it can't be more than "<<(count+1)<<endl;
            } 
            else if(position==count+1){
                temp=start;
                while(temp->add!=NULL)
                {
                    temp=temp->add;
                }
                temp->add=New;
            }
            else{
                Next=start;
                while( i < position){
                    Prev = Next;
                    Next = Next->add;
                    i++;
                }
                Prev->add = New;
                New->add=Next;
            }

        }
    }
    return 0;
}
int  Delete()
{
    int count=0, i=1, position;
    if(start==NULL)
    {
        cout<<"Nothing to delete in the list"<<endl;
    }
    else{
        cout<<"Enter a position for deletion : ";
        cin>>position;

        if(position==1){
            temp=start;
            start=start->add;
            cout<<"Deleted Element = "<<temp->data<<endl;
            free(temp);
        }
        else{
            temp=start;
            while(temp!=NULL)
            {
                count++;
                temp=temp->add;
            }
            if(position > count)
            {
                cout<<"Invalid position it can't be more than "<<count<<endl;
            }
            else if(position==count)
            {
                Next=start;
                while(Next->add!=NULL)
                {
                    Prev=Next;
                    Next=Next->add;
                }
                cout<<"Deleted Element = "<<Next->data<<endl;
                free(Next);
                Prev->add=NULL;
            }
            else
            {
                Next=start;
                while(i < position)
                {
                    Prev=Next;
                    Next=Next->add;
                    i++;
                }
                temp=Next;
                Next=Next->add;
                cout<<"Deleted element = "<<temp->data<<endl;
                free(temp);
                Prev->add=Next;
            }
        }
    }
    return 0;
}
int display()
{
    if(start==NULL)
    {
        cout<<"List not created, create a list first"<<endl;
    }
    else{
        temp=start;
        while(temp!=NULL){
            cout<<temp->data;
            cout<<" ";
            temp=temp->add;
        }
        cout<<endl;
    }
    return 0;
}