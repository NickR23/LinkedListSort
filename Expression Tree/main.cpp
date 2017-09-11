

#include <iostream>
#include <stdlib.h>
using namespace std;

static string input;

class Enode{
private:
    char chara;
    int value;
    Enode *left;
    Enode *right;
public:
    Enode(char c, int v, Enode *l, Enode *r){chara=c,value=v,left=l,right=r;}
    char getChara(){return(chara);}
    int getValue(){return(value);}
    Enode *getLeft(){return(left);}
    Enode *getRight(){return(right);}
    void setLeft(Enode *l){left=l;}
    void setRight(Enode *r){right=r;}
    void setValue(int v){value=v;}
};

class List{
private:
    Enode *first;
public:
    List(){first=NULL;}
    void print(Enode *f);
    void insert(Enode *c);
};

void List::insert(Enode *current){
    //cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    //cout<<"INPUT: "<<input<<endl;
    char chara = input[0];
    //cout<<"Character: "<<chara<<endl;
    int value;
    value = atoi (&chara);
        //+*35-94


    
    Enode *newbie=new Enode(chara,value,NULL,NULL);
    if( first == NULL ){
        first=newbie;
        current=first;
        //cout<<"FIRST: "<<first->getChara()<<"**"<<endl;
        input.erase(0,1);
        insert(first);
        input.erase(0,1);
        insert(first);
        //cout<<"First: "<<first->getChara()<<" Left of first: "<<first->getLeft()->getChara()<<" Right of first: "<<first->getRight()->getChara()<<endl;
        print(first);
        cout<<"Solution is ... "<<first->getValue()<<" !"<<endl<<endl;
    }
    
    else {
       // cout<<"CURRENT: "<<current->getChara()<<endl;
        if( (newbie->getChara() == '+' || newbie->getChara() == '-' || newbie->getChara() == '*' )  ){
            if(current->getLeft() == NULL){
                current->setLeft(newbie);
                //cout<<"! "<<current->getLeft()->getChara()<<" Set to LEFT of current ("<<current->getChara()<<")"<<endl;
            }
            else{
                current->setRight(newbie);
                //cout<<"! "<<current->getRight()->getChara()<<" Set to RIGHT of current ("<<current->getChara()<<")"<<endl;
            }
            input.erase(0,1);
            insert(newbie);
            input.erase(0,1);
            insert(newbie);
        }
        else{
            if(current->getLeft() == NULL){
                current->setLeft(newbie);
                //cout<<"! "<<current->getLeft()->getChara()<<" Set to LEFT of current ("<<current->getChara()<<")"<<endl;
            }
            else {
                current->setRight(newbie);
                //cout<<"! "<<current->getRight()->getChara()<<" Set to RIGHT of current ("<<current->getChara()<<")"<<endl;
            }
        }

    }

}

void List::print(Enode *current){
    if( (current->getLeft()->getChara() == '+' || current->getLeft()->getChara() == '-' || current->getLeft()->getChara() == '*' )){
        print(current->getLeft());
    }
    if((current->getRight()->getChara() == '+' || current->getRight()->getChara() == '-' || current->getRight()->getChara() == '*' )){
        print(current->getRight());
    }
    
    
        if( current->getChara() == '+' ){
            current->setValue( (current->getLeft()->getValue()) + (current->getRight()->getValue()) );
            cout<<current->getLeft()->getValue()<<" + "<<current->getRight()->getValue()<<" == "<<current->getValue()<<endl;
        }
        else if (current->getChara() == '-'){
            current->setValue( (current->getLeft()->getValue()) - (current->getRight()->getValue()) );
            cout<<current->getLeft()->getValue()<<" - "<<current->getRight()->getValue()<<" == "<<current->getValue()<<endl;
        }
        else if(current->getChara() == '*'){
            current->setValue( (current->getLeft()->getValue()) * (current->getRight()->getValue()) );
            cout<<current->getLeft()->getValue()<<" * "<<current->getRight()->getValue()<<" == "<<current->getValue()<<endl;
        }
    cout<<"CURRENT: "<<current->getValue()<<endl;
}









int main() {
    List l;
    Enode *current;
    cout << "Input string: \n";
    cin >> input;
    l.insert(current);

    return 0;
}

