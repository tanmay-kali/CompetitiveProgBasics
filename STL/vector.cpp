#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // construct vector object
    // define what type of data is going to hold like int
    vector<int> a;
    vector<int> b(5, 10);              // five int with value 10 , init the value with zeroes
    vector<int> c(b.begin(), b.end()); // fill with values of b
    vector<int> d{1, 2, 3, 4, 10};     // fill with custom values

    // Iterate over vector

    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << ",";
    }
    cout << endl;

    for (auto it = b.begin(); it != b.end(); it++)
    {
        cout << (*it) << ",";
    }
    cout << endl;

    // for each loop

    for (int x : d)
    {
        cout << x << ",";
    }
    cout << endl;

    // user input
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
    }

    for (int x : v)
    {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}