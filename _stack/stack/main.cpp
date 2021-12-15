#include <iostream>
using namespace std;

int push(char* a,int top,char elem){
    a[++top]=elem;
    return top;
}
//数据元素出栈

int pop(char * a,int top){
    if (top==-1) {
        printf("null");
        return -1;
    }
    printf("pop %c\t",a[top]);
    top--;
    return top;
}


void judge(string str){

    char a[100];
    int top = 0;
    for(int i = 0; i < str.length(); i++) {
       if( str[i] == '('||str[i] == '['||str[i] == '{') {
           top = push(a,top,str[i]);
       }
       if( str[i] == ')'||str[i] == ']'||str[i] == '}') {
           if(top == -1){
               cout<< "wrong!"<<endl;
               i = str.length() +2 ;
           }
           if(str[i] - a[top] == 1 || str[i] - a[top] == 2  ){
               top = pop(a,top);
           }
        }
    }

    if(top == 0 ) {
        cout<< "right" <<endl;
    } else{
        cout<< "wrong!"<<endl;
    }

}

int main() {
    string str1 = "(5+e)-{2+[5*{f8}]-4}*(k)";
    string str2 = "(5+e{-{2}+[5*{f8}]-4}*(k)";
    string str3 = "(5+e)-{2+[5*{f8})-4}*(k)";
    string str4 = "(5+e)-(2+[5*{f8}]-4)*(k)";

    judge(str1);
    judge(str2);
    judge(str3);
    judge(str4);
    return 0;
}
