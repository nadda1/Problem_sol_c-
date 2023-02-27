#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
const int INF=1e9+7;
#define ll long long;
using namespace std;
long long openLock(int lii[], int  count,long long value)
{
    //fill first row and first column
    long long   Tabulation[count + 1][value + 1];
    Tabulation[0][0] = 1;
    for (long long i = 1; i <= count; i++)
        Tabulation[0][i] = 0;


    for (int l = 1; l <= count; l++)
    {
        for (long long  kk = 0;kk <= value; kk++)
        {
            if (lii[l-1] > kk)

                Tabulation[l][kk] = Tabulation[l - 1][kk];
            else
            {
                Tabulation[l][kk] = Tabulation[l - 1][kk] + Tabulation[l- 1][kk- lii[l - 1]];
            }
        }
    }
    long long MOdv=Tabulation[count][value]%INF;
    return MOdv;

}
int main() {
    int   n ;
    long long x;
    long long j;
    cin>>n>>x;
    int  group[n];
    for(int  i=0; i<n;i++){
        cin>>j;
        group[i]=j;
    }
    cout<<openLock(group,n,x);

}
