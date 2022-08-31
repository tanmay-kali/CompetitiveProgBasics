
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int arr[] = { 6, 3, 5, 2, 8 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int elem = 2;
 
    auto itr = find(arr, arr + n, elem);
 
    if (itr != end(arr))
    {
        cout << "Element " << elem << " is present at index "
             << distance(arr, itr) << " in the given array";
    }
    else {
        cout << "Element is not present in the given array";
    }
 
    return 0;
}
