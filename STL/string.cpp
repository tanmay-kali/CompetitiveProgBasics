
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
 
int main()
{
    string s0 ;
    string s1("Hello");
    string s2 = "Hello World";
    char a[] = {'a','b','c'};
    string s4(a);
    cout<<s4<<endl;

    //Check if empty 
    if(s0.empty()){
        cout <<"OKAY THIS IS EMPTY"<<endl;
    }
    //Apppend
    s0.append("I love c++  ");
    cout<<s0<<endl;

    //string concatenation
    s0+= " and python";
    cout<<s0<<endl;

    //Remove 
    s0.clear();
    cout<<s0<<endl;
    //length
    cout<<s0.length()<<endl;

    //compare two strings
    s0 = "Apple";
    s1 = "Mango";

    //0 if equal , >0  or < 0 if not equal
    //lexographic comparisan
    cout<<s0.compare(s1)<<endl;

    //Operator "<" or ">" over loaded for string 
    // s0< s1
    //s1< s0

    if (s1>s0){
        cout<<s1<<" is greater than "<<s0<<endl;
    }


    //indexing
    cout <<s1[0]<<endl;

    //finding substrings 
    string s = "I like Meta";
    int idx = s.find("Meta");
    cout<<s<<endl;
    cout<<idx<<endl;

    //Remove a word from a string 
    string word = "Meta";
    s.erase(idx,word.length());
    cout<<s<<endl;

    //iterating over all teh characters in the string 
    for(int i = 0; i <s1.length()+1;i++){
        cout<<s[i]<<":";
    }
    cout<<endl;

    //iterators
    for(auto it = s.begin(); it != s.end();it++){
        cout<<(*it)<<endl;
    }

    //for each loop
    for(auto c:s1){
        cout<<c<<".";
    }


    return 0;
}