#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    int snt[1000010]={};
    for (int i = 2; i < 1000010; i++)
    {
        if (n % i == 0)
        {
            n /= i;
            i--;
            snt[i]++;
        }
    }
    int res = 1000000000;
    vector<int> list;
    for (int i = 0; i < 1000010; i++)
    {
        if (snt[i] != 0)
            list.push_back(snt[i]);
    }
    if (n != 1)
        list.push_back(1);
    for (int i = 2; i < 10000; i++)
    {
        int sum = 0;
        for (int x : list)
        {
            sum += min(x % i, i - x % i);
        }
        res = min(sum, res);
    }

    cout<<(res);
}