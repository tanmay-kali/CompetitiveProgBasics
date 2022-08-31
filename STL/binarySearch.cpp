
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int arr[] = {2,3,5,5,5,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    bool present = binary_search(arr,arr+n,key);
    cout<<present;

    //get the index of the element(lower bound)

    auto it = lower_bound(arr,arr+n,5);
    cout << "Lower Bound is"<<it - arr<<endl;

    //upper bound
    auto it2 = upper_bound(arr,arr+n,5);
    cout << "Upper Bound is"<<it2 - arr<<endl;

    //log n time freq
    cout <<"Occurrence of 5 is "<<(it2-it)<<endl;


    return 0;



}
