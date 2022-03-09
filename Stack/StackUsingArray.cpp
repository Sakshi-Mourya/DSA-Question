#include<iostream>
using namespace std;
# define maxsize 10

int stack[maxsize], top=-1;

int push();
int pop();
int display();

int main(){
    int ch;
    do{
        cout<<".........Stack Implementation using Array........."<<endl;
        cout<<"Press 1 for PUSH the element into the stack"<<endl;
        cout<<"Press 2 for POP the element from the stack"<<endl;
        cout<<"Press 3 for DISPLAY the element into the stack"<<endl;
        cout<<"Press 4 for EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : display(); break;
            case 4: break;
            default: cout<<"Invalid Choice, re-enter the choice again: "<<endl;
        }
    }
    while(ch!=4);
    return 0;
}
int push()
{
    int n;
    if(top==(maxsize-1)){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        cout<<"Enter a value : "<<endl;
        cin>>n;
        top++;
        stack[top]=n;
    }
    return 0;
}

int pop()
{
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        cout<<"Deleted data = "<<stack[top]<<endl;
        top--;
    }
    return 0;
}
int display()
{
    int i;
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        for(i=0; i<=top; i++)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}