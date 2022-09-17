#include<iostream>
using namespace std ;
int main()
{
    int n,i,k=0,swt=0,four,seven,tem1  ;
    cin>>n ;
    four = n/4 ;
    seven = n/7 ;
    if(n<8)
        if(n==4 || n==7)
            cout<<n ;
        else
            cout<<-1 ;
    else if(n%4!=0 && n%7!=0)
    {
        for(i=1; i<=four; i++)
        {

            k=k+4 ;
            tem1 = n-k ;
            if(tem1%7==0)
            {
                seven = tem1/7 ;
                break ;
            }
        }
        if(tem1<4)
            cout<<-1 ;
        else
        {
            for(k=1; k<=i; k++)
                cout<<4 ;
            for(k=1; k<=seven; k++)
                cout<<7 ;
        }
    }
    else if(n%4==0 && n%7==0)
        if(four<=seven)
            for(k=1; k<=four; k++)
                cout<<4 ;
        else
            for(k=1; k<=seven; k++)
                cout<<7 ;
    else if(n%4==0 && n%7!=0)
    {
        for(i=1; i<=four; i++)
        {

            k=k+4 ;
            tem1 = n-k ;
            if(tem1%7==0)
            {
                seven = tem1/7 ;
                break ;
            }
        }
        if(i+seven<four)
        {
            for(k=1; k<=i; k++)
                cout<<4 ;
            for(k=1; k<=seven; k++)
                cout<<7 ;
        }
        else
            for(k=1; k<=four; k++)
                cout<<4 ;
    }
    else if(n%7==0 && n%4!=0)
    {
        for(k=1; k<=seven; k++)
            cout<<7 ;
    }
    return 0 ;
}

