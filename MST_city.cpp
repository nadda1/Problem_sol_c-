#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
long long removeloop(long long b[], long long x){

    while(b[x] != x)
    {
        b[x] = b[b[x]];
        x =b[x];
    }
    return x;
}
void makePAirs(int ui, int vi,long long m[])
{
    long long index1 = removeloop(m,vi);
    long long  index2 = removeloop(m,ui);
    m[index1] = m[index2];
}

long long Find_MST_city(pair<long long, pair<int, int> > g[],long long  m,long long  vertices[]){
    long long sum=0;
    long long min=0;
    int e1, e2;

    for(int k = 0;k < m;++k)
    {
        e1 = g[k].second.first;
        e2 = g[k].second.second;
        min = g[k].first;
        if(removeloop(vertices,e1) != removeloop(vertices,e2))
        {
            sum += min;
            makePAirs(e1,e2,vertices);
        }
    }
    return sum;


}

int main() {
    long long M, N;
    cin>>N>>M;
    pair <long long, pair<int, int> > city[M];

    long long  v[N];
    for(long long i=1;i<=N;++i){
        v[i]=i;
    }

    int ui,vi;
    long long ci;
    for(long long j=0;j<M;++j){
        cin>>ui>>vi>>ci;
        city[j]= make_pair(ci, make_pair(vi,ui));
    }
    sort(city,city+M);
    long long mst= Find_MST_city(city,M,v);
    cout<<mst;


    return 0;
}
