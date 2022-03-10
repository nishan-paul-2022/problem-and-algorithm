#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll xp1,yp1,xp2,yp2,xp3,yp3,xp4,yp4;
    ll xa1,ya1,xa2,ya2,xa3,ya3,xa4,ya4;
    cin>>xp1>>yp1>>xp2>>yp2>>xp3>>yp3>>xp4>>yp4;
    cin>>xa1>>ya1>>xa2>>ya2>>xa3>>ya3>>xa4>>ya4;
    ll maxp,mayp,maxa,maya;
    ll mixp,miyp,mixa,miya;

    maxp = max( xp1, max( xp2, max(xp3,xp4) ) );
    mixp = min( xp1, min( xp2, min(xp3,xp4) ) );

    mayp = max( yp1, max( yp2, max(yp3,yp4) ) );
    miyp = min( yp1, min( yp2, min(yp3,yp4) ) );

    maxa = max( xa1, max( xa2, max(xa3,xa4) ) );
    mixa = min( xa1, min( xa2, min(xa3,xa4) ) );

    maya = max( ya1, max( ya2, max(ya3,ya4) ) );
    miya = min( ya1, min( ya2, min(ya3,ya4) ) );

    if( ( (mixa>=mixp && maxa<=maxp) && (miya>=miyp && maya<=mayp) ) || ( (mixp>=mixa && maxp<=maxa) && (miyp>=miya && mayp<=maya) ) )
        cout<<"YES";
    else{
        ll tst=0;
        ///P
        if( (xp1>=mixa && xp1<=maxa) && (yp1>=miya && yp1<=maya) ) tst++;
        if( (xp2>=mixa && xp2<=maxa) && (yp2>=miya && yp2<=maya) ) tst++;
        if( (xp3>=mixa && xp3<=maxa) && (yp3>=miya && yp3<=maya) ) tst++;
        if( (xp4>=mixa && xp4<=maxa) && (yp4>=miya && yp4<=maya) ) tst++;

        if( (xa1>=mixp && xa1<=maxp) && (ya1>=miyp && ya1<=mayp) ) tst++;
        if( (xa2>=mixp && xa2<=maxp) && (ya2>=miyp && ya2<=mayp) ) tst++;
        if( (xa3>=mixp && xa3<=maxp) && (ya3>=miyp && ya3<=mayp) ) tst++;
        if( (xa4>=mixp && xa4<=maxp) && (ya4>=miyp && ya4<=mayp) ) tst++;


        cout<<tst<<lne;
        if(tst==1)
            cout<<"YES";
        else if(tst==0 || tst>1)
            cout<<"NO";
    }
    return 0;
}
