#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void userInput()
{
    int size;
    cin >> size;
    int arr[size];
    cout << "Enter array elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Array elements are:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int x;
    // cin >> x;
    // cout << x + 100 << endl;
    // use Control + option + N for runnning at once
    userInput();
    // get a full line
    //  while (getline(cin, s))
    //  {
    //      cout << s << endl;
    //  }
    return 0;
}