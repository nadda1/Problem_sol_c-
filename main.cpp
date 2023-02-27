#include <iostream>
#include <vector>
#include <string>

using namespace std ;
//stack based on array class
template < class Type>

class ArrayStack
{
private:
    Type *stackList;

    int size ;

public :
    int first ;
    ArrayStack(){
        int virtualSize=100;
        stackList = new Type[virtualSize];
        first =0;
};
    ArrayStack( int actualSize){
        first =0;
        size=actualSize;
        stackList= new Type[size];

    }
    ~ArrayStack(){
        delete []stackList;
    }
    void Push(Type data)
    {
        stackList[first] = data;
        first++;
    }
    int actualcount()
    {
        return first;
    }
    bool Empty()
    {
        if(first==0)
        return true ;
        else return false ;
    }
    Type Pop()
    {
        if(first== 0)
            cout <<"Stack is empty!!"<<endl<<"there is no elements to delete!"<<endl;
        else
        {
            first--;
            return stackList[first];
        }
    }
    Type &top()
    {
        if(!Empty())

        return stackList[first - 1];

    }
    void TraversingStack(){
        vector<Type> DisplayContainer= vector<Type>();
        while (!Empty())
        {
            Type t = top();
            DisplayContainer.push_back(t);
            Pop();
        }

//        reverse(DisplayContainer.begin(),DisplayContainer.end());
        vector<int>::iterator it;
        for(const auto& it: DisplayContainer)
        {
            cout << it << " ";
        }
    }

   string simplify(string statment)
    {
        ArrayStack<string> stacklist;
        int n = statment.length();
        string ans;
        for(int i=0; i<n;++i)
        {
            //skip the / character at the beginning
            if(statment[i]=='/')
                continue;
            string tmp ;
            //append the rest of all characters in a string except /
            while(i<n&& statment[i]!='/')
            {
                tmp+=statment[i];
                ++i;
            }
            // skip the . and continue the rest file name
            if(tmp==".")
                continue;
            // it means we go to the level up means that we remove the part before .. in stack
            else if (tmp==".."){
                if(!stacklist.Empty())
                    stacklist.Pop();
            }
            else
                stacklist.Push(tmp);
        }
        // putting the stack elements into string
        while(!stacklist.Empty())
        {
            ans="/"+stacklist.top()+ans;
            stacklist.Pop();
        }
        if(ans.size()==0)
            return "/";
        return ans;
    }

};

int main() {


    ArrayStack<int>stackofNums;
    stackofNums.Push(22);
    stackofNums.Push(33);
    stackofNums.Push(69);
    stackofNums.Push(76);
    cout <<"count of numbers in stack: " <<endl;
    cout << stackofNums.actualcount();
    cout<<endl;
    int out =stackofNums.Pop();
    cout<<"the out element:"<<out<<endl;
    cout<<endl;
    cout<<"stack elements"<<endl ;
    stackofNums.TraversingStack();
    cout<<endl;
    string result=stackofNums.simplify("/home/../foo/");
    cout<<result<<endl;

    string simplified2=stackofNums.simplify("/home//");
    cout<<simplified2<<endl ;

    string simplified3 = stackofNums.simplify("/../");
    cout<< simplified3 << endl ;

    string simplified4 = stackofNums.simplify("/../hey/.//name/");
    cout<< simplified4 << endl ;


}
