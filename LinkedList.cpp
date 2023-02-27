#include <iostream>
#include<string>
using namespace std ;
class afterlast{};
class beforefirst{};
template <class T>

struct node{
    T data ;
    node<T> *link ;
    node<T> *previous ;
    node(){
        link= nullptr;
    }
    node(T info):data(info){}
    node(T d ,node<T> * l= nullptr): data(d), link(l) {}


};

template<class T>
class myList {
protected:
    node<T> *first ,*last , *current ;//current to traverse the linked list
    int count=0 ;
public:
    node<T> getFirst() {
        return first;
    }
    myList(){
        first= NULL;
        last=NULL ;
        current=first->link;


    }
    myList(T value, int initial_size){
        node<T> *tmp=new node<T>;//first we assign the first node
        tmp->data=value;
        tmp->link=NULL;
        first=tmp;
        last=tmp;
        tmp=NULL;
        for(int i=1;i<initial_size;i++){
            //for every iteration in the loop assign a new new
            node<T> *newnode=new node<T>;
            newnode->data=value;
            newnode->link=NULL;
            //link the first node with the next node and so on
            last->link=newnode;
            last=newnode;
        }

    }
    myList<T>& operator = (const myList<T> &another_list){
        node<T> newcurrent=new node<T>;
        if(this==another_list)
            return *this;
        else {
            if(first!=NULL)
                this->~myList();
            if(another_list.first!=NULL)
                another_list-> ~myList();
            else{
                if(first!=NULL)
                    this->~myList();
                if(another_list.first!=NULL)
                    another_list-> ~myList();
                else {

                    node<T> trail=new node<T>;
                    trail->data=first->data;
                    current=first->link;

                    while (current!=NULL)
                    {
                        newcurrent=new node<T>; // make new current to traverse the new list
                        newcurrent->data =current->data ;
                        newcurrent->link = NULL ;
                        last->link =newcurrent;
                        last=newcurrent;
                        current=current->link ; // move to the next node
                    }
                }




            }
            return *this;

        }
    }
    ~myList(){
        node<T>*temp;
        while (first != NULL) //loop to the end of the list
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = NULL;
    }
    int size(){
        current=first;
        while (current!=NULL)
        {
         count++;
         current=current->link ;
        }
        return count;
    }
    void display()
    {

        current=first;
        while(current!=NULL)
        {
            cout<<current->data<<" << " ;
            current=current->link;
        }
        cout<<endl;
    }

    class iterator{
    private:

    public:
        node<T> *headNode ;


        iterator(){
            headNode=NULL;

        }
        iterator(node<T> *hd){
            headNode=hd;
        }

        void operator++() {
            if (this->headNode->link == NULL )// throw exception
                throw afterlast();
             this->headNode= this->headNode->link;
        }
        iterator operator++(int)
        {
            if (this == nullptr)
                throw out_of_range("Segmentation fault!");
            myList<T> ::iterator tmp = *this;
            ++*this;
            return tmp;

        }

        void  operator--() {
            if (this->headNode->previous == NULL )// throw exception
                throw beforefirst();
           this->headNode= this->headNode->previous;
        }

        T& operator*()  {
            return headNode->data;
        }
        bool operator==(const iterator& r)  {
            if( r.headNode==headNode)
                return true ;

            return false;
        }


};
    void push_back(T v)
    {
        node<T> *temp=new node<T>;
        temp->data=v;
        temp->link=NULL;
        if(first==NULL)//if this is the first element in the list
        {
            first=last=temp;
        }
        else
        {
            //link the new node in the end of the list
            last->link=temp;
            temp->previous=last ;
            //move the last node to point to the last element added in the list
            last=temp;
        }
    }


    iterator erase(iterator index) {
        node<T> *curr =index.headNode->link;
        if (curr == last) throw afterlast();
        index.headNode->link = index.headNode->link->link;

        delete curr;
        count--;
        return index;
    }

    iterator begin(){
        return iterator(first) ;

    }
    iterator end()
    {
        return iterator(last) ;

    }
    void push_front( T new_data)
    {
        node<T>* new_node2 = new node<T>;
        new_node2->data = new_data;
        first->previous = new_node2;
        new_node2->link = first;
        first = new_node2;

    }
    void insert(iterator position,const T& val) {
        node<T>* newNode = new node<T>;
        if (position.headNode == first) {
            push_front(val);
            count++ ;
            }
        else if (position.headNode == last)
        {
            push_back(val);
            count ++ ;
        }
        else {
            node<T> *pre, *curr = first;
            while(curr != position.headNode)
            {
                pre = curr;
                curr = curr->link;
            }
            node<T> * insertedN = new node<T>(val,pre->link);//make it point to the given position

//            insertedN->data= val ;
//            insertedN->link=pre->link;
//            insertedN->previous = pre;
            // make the previous point to the inserted node
            pre->link =insertedN ;

        }


    }
    iterator getPreviousIterator(iterator index){
        node<T> *pre, *curr = first;
        while(curr != index.headNode)
        {
            pre = curr;
            curr = curr->link;
        }
        return index ;



    }


};

int main() {
    try {

        myList<int> li(13,1);
    myList<int> l2(3,5);
    myList<int>::iterator iter = li.begin();
    myList<int>::iterator it2= li.begin() ;
    cout<<"display list 2 \n";
    l2.display();



    li.push_back(2);
    li.push_back(4);
    li.push_back(5);
    li.display();



    ++iter;
    cout<<"iterator point to "<<*iter<<endl;
    myList<int>::iterator it=iter;
    li.insert(iter , 20);
    li.display();
    ++iter ;
    cout<<"iterator point to "<<*iter<<endl;
    ++iter;
    --iter;
    cout<<"iterator point to "<<*iter<<endl;
    --iter;

    li.erase(iter);
    cout<< "after deleting element \n";
    li.display();



        ++iter;
        ++iter;
        ++iter;

    }

    catch (afterlast()){
        cout<<"this point to the last node n the list ";
    }
}
