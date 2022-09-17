#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    vector<int>::iterator it;
    int N,pos,value;
    cin>>N;
    while(N--)
    {
        int tem;
        cin>>tem;
        v.push_back(tem);
    }
    it=min_element(v.begin(),v.end());
    pos=it-v.begin();
    value=*it;
    cout<<"Menor valor: "<<value<<'\n';
    cout<<"Posicao: "<<pos<<'\n';
    return 0;
}

