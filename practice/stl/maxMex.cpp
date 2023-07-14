#include <bits/stdc++.h>
using namespace std;
#define nline '\n'
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        set<int> st;
        for (int i = 0; i <= 100100; i++)
        {
            st.insert(i);
        }
        int q, x;
        cin >> q >> x;
        int y;
        while (q--)
        {
            cin >> y;
            bool flag = true;

            for (int i = y % x; i < y; i += x)
            {
                if (st.find(i) != st.end())
                {
                    st.erase(i);
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int i = y; i <= 100100; i += x)
                {
                    if (st.find(i) != st.end())
                    {
                        st.erase(i);
                        break;
                    }
                }
            }
            cout << *st.begin() << " ";
        }
        cout << nline;
    }
    return 0;
}