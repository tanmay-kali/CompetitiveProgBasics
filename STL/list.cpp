#include<iostream>
#include <list>
#include <string>
using namespace std;


int main()
{
    //Doubly Linked List
    //useful data insertion and deletion in the middle O(1)
    
    //push_back,push_front,pop_back,pop_front,insert,erase(idx),remove(num)
    list<int> l;
    list<int> l1{1,3,12,15,4,5,6};
    list<string> l2{"mango"};
    l2.push_back("pineapple");
    //iterate
    for(auto s:l1){
        cout<<s<<"-->";
    }
    cout<<endl;

    //sort the list
    l1.sort();
    for(auto s:l1){
        cout<<s<<"-->";
    }
    cout<<endl;

    //reverse the list
    l1.reverse();
    for(auto s:l1){
        cout<<s<<"-->";
    }
    cout<<endl;

    //remove front
    l1.pop_front();

    //remove the last element 
    l1.pop_back();

    //ass to the front
    l1.push_back(23);

    



    
    return 0;
}