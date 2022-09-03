/*
Question
Madoka is a very strange girl, and therefore she suddenly wondered how many pairs of integers (𝑎,𝑏) exist, where 1≤𝑎,𝑏≤𝑛, for which lcm(𝑎,𝑏)gcd(𝑎,𝑏)≤3.

In this problem, gcd(𝑎,𝑏) denotes the greatest common divisor of the numbers 𝑎 and 𝑏, and lcm(𝑎,𝑏) denotes the smallest common multiple of the numbers 𝑎 and 𝑏.
*/

/*
The number of the pairs of the first kind is 𝑛, of the second kind is 2⋅⌊𝑛2⌋, and of the third kind is 2⋅⌊𝑛3⌋ (the factor 2 in the latter two formulae arises from the fact that pairs are ordered).
Therefore, the answer to the problem is 𝑛+2⋅(⌊𝑛2⌋+⌊𝑛3⌋).
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solution()
{
    int n;
    cin >> n;
    cout << (n + n / 2 * 2 + n / 3 * 2) << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }

    return 0;
}