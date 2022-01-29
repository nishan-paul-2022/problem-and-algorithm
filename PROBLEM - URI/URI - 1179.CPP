#include<bits/stdc++.h>
using namespace std;
int main()
{
    int par[15],impar[15],j=0,k=0;
    for(int i=0; i<15; i++)
    {
        int tem;
        cin>>tem;
        if(tem%2==0)
        {
            par[j]=tem;
            if(j==4)
            {
                for(int l=0; l<5; l++)
                    printf("par[%d] = %d\n",l,par[l]);
                j=-1;
            }
            j++;
        }
        else
        {
            impar[k]=tem;
            if(k==4)
            {
                for(int l=0; l<5; l++)
                    printf("impar[%d] = %d\n",l,impar[l]);
                k=-1;
            }
            k++;
        }
    }
    for(int l=0; l<k; l++)
            printf("impar[%d] = %d\n",l,impar[l]);
    for(int l=0; l<j; l++)
            printf("par[%d] = %d\n",l,par[l]);
    return 0;
}
