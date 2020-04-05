#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int n, k, t;
int s[60][60];

bool rs[60][60], cs[60][60], flag;
//function here
void flagr(int row, int col, int m) {
    if (row == n && col == n + 1 && m == k && !flag) {
        flag = true;
        cout << "Case #" << t << ": " << "POSSIBLE\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << s[i][j] << " ";
            }
            cout << "\n";
        }
        return;
        
    } 
	else if (row > n) {
        return;
    } else if (col > n) {
        flagr(row + 1, 1, m);
    }
    for (int i = 1; i <= n && !flag; ++i) {
        if (!rs[row][i] && !cs[col][i]) {
            rs[row][i] = cs[col][i] = true;
            if (row == col) 
			{
                m += i;
            }
            s[row][col] = i;

            flagr(row, col + 1, m);

            rs[row][i] = cs[col][i] = false;
            if (row == col)
			{
                m -= i;
            }
            s[row][col] = 0;
        }
    }
}

int main() {
    int tc;
    
    //input the number of test case
    cin>>tc;
    
    
    for (t = 1; t <= tc; ++t)
		{
           scanf(" %d %d", &n, &k);
           flagr(1, 1, 0);
           if (!flag)
		   {
                cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
        }
        flag = false;
    }
    return 0;
}