#include <bits/stdc++.h>
using namespace std;

void print(std::vector<int> const &a)
{
    std::cout << "The vector elements are : ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int x;
    cin >> x;
    cout << x + 100;
    // use Control + option + N for runnning at once
}