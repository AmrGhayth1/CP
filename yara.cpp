// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void mergearrays(int q, int p, int x[], int y[], int merged[])
{
    int m = 0;
    for (int i = 0; i < p; i++)
    {
        merged[m++] = x[i++];
    }
    for (int j = 0; j < q; j++)
    {
        merged[m++] = y[j++];
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    // freopen("../../error.txt", "w", stderr);
    freopen("./output.txt", "w", stdout);
#endif
    int p, q;
    cin >> p >> q;
    int x[p], y[q], merged[q + p];
    for (int k = 0; k < p; k++)
    {
        cin >> x[k];
    }
    for (int l = 0; l < q; l++)
    {
        cin >> y[l];
    }
    mergearrays(q, p, x, y, merged);
    cout << merged[q + p];

    return 0;
}
