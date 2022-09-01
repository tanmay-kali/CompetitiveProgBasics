
/*
Problem
Your class recently got a maths assignment with 55 questions. There are N (\le 20)N(≤20) students in the class and at most 22 people can collaborate. For each student, you know which problems they solved.
Find out if there exists a team of two students who can together solve all problems.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void solution()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++)
    {
        int probs;
        cin >> probs;
        for (int j = 0; j < probs; j++)
        {
            int p;
            cin >> p;
            A[i].push_back(p);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; ++j)
        {
            vector<int> solved(6, 0);
            for (int a : A[i])
            {
                solved[a] = 1;
            }
            for (int a : A[j])
            {
                solved[a] = 1;
            }
            int tot = accumulate(solved.begin(), solved.end(), 0);
            if (tot == 5)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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