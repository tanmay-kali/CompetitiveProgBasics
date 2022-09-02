/*
How many people must be there in a room to make the probability 50% that at-least two people in the room have same birthday?
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float p;
    cin >> p;
    p = p / 100;
    // denotes the prob of 2ppl having same birthday
    float x = 1.0;
    int people = 0;
    float num = 365;
    float denom = 365;

    if (p == 1.0)
    {
        cout << "366" << endl;
        return 1;
    }

    while (x > 1 - p)
    {
        x = x * (num) / denom;
        num--;
        people++;
        float temp = 100 - (x * 100);
        cout << "People Count " << people << " probability is " << temp << endl;
    }

    return 0;
}