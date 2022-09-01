#include<iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> d{1, 2, 3, 4, 10};     // fill with custom values
    //add to the last of the vector
    //O(1)
    d.push_back(16);

    //remove last element O(1)
    d.pop_back();

    // insert in the middle 
    d.insert(d.begin()+3,100); // insert 100 after 3 positions

    d.insert(d.begin()+3,4,100); // insert 4 elements which are 100 after 3rd position

    //erase elemenst from middle
    d.erase(d.begin()+3); // remove the third element 

    //erase range of elements
    d.erase(d.begin()+2,d.begin()+5);

    //size 
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;

    // we avoid the shrinkl 
    d.resize(8);

    //remove all elements of the vector , but does not delete the memory occupied by the vector
    d.clear();

    //empty
    if(d.empty()){
        cout<<"This is is an emoty vector";
    }
    d.push_back(10);
    d.push_back(5);
    // front elem

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;


    //reserve 
    int n;
    // to avoid diubling we use reserve function
    vector<int> v;
    v.reserve(1000);
    //won't double until we cross 100 elememts

    
    return 0;
}