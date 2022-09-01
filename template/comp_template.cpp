#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
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

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> g1;
        unordered_map<int, int> umap;
        int cnt = 0;
        int ind, flag = 0;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            g1.push_back(temp);
        }
        for (int k = 0; k < n; k++)
            umap[g1[k]]++;
        for (auto x : umap)
        {
            if (x.second == 1)
            {
                cnt++;
            }
            if (x.second >= 2 && flag == 0)
            {
                flag = 1;
            }
        }
        if (cnt % 2 == 1 && flag == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
    // use Control + option + N for runnning at once
}