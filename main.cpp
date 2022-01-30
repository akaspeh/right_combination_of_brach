#include <iostream>
#include <string>

using namespace std;

#define sizearr 255

struct Stack{
    char arrStack[sizearr];
    int sTop = -1;
    int count=0;
    bool empty(){
        if(sTop==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    //--------------------------------------
    bool full(){
        if(sTop==sizearr-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    //--------------------------------------
    char pop(){
        if (empty()){
            cout << "underflow_error\n";
            return 0;
        }
        else{
            char element = arrStack[sTop];
            sTop--;
            count++;
            return element;
        }

    }

    //---------------------------------------

    void push(char *element){
        if(full()){
            cout << "overflow_error\n";
        }
        else{
            sTop++;
            arrStack[sTop]= *element;
            count++;
        }
    }

    //---------------------------------------

    int size(){
        return count;
    }

    //---------------------------------------

    void clear(){
        count = 0;
        sTop = -1;
    }

    //---------------------------------------

    char top(){
        if(empty()){
            cout << "Stack is empty\n";
            return 0;
        }
        else{
            cout << "Top: " << arrStack[sTop] << endl;
            cout << "\n";
            return arrStack[sTop];
        }
    }
};

bool closeBrace(char a){
    switch (a) {
        case '}':
            return 1;
        case ')':
            return 1;
        case ']':
            return 1;
        default:
            return 0;
    }
}

char inverseBrace(char a){
    switch (a) {
        case '{':
            return '}';
        case '(':
            return ')';
        case '[':
            return ']';
        default:
            return 0;
    }
}

void result(Stack *mySubsequence,int size,string row){
    if(size%2!=0){
        cout << "no" << endl;
        return;
    }
    for(int i = 0;i<size;i++){
        char A=row[i];
        if(closeBrace(row[i])){
            if(mySubsequence->empty()){
                cout << "no" << endl;
                return;
            }
            char b = mySubsequence->pop();
            if(inverseBrace(b)!=A){
                cout << "no" << endl;
                return;
            }
        }
        else{
            mySubsequence->push(&A);
        }
    }
    string a = (mySubsequence->empty()) ? "yes" : "no";
}

int main() {
    Stack mySubsequence;
    string row;
    cin >> row;
    result(&mySubsequence, row.length(), row);
    return 0;
}
