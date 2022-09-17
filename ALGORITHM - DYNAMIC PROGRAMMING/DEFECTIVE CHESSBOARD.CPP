#include<bits/stdc++.h>
#define ll long long
using namespace std ;

ll** allocate (ll n) { ///IT CREATES THE N X N CHESSBOARD

    ll **a = new ll*[ n ]  ;

    for(ll i = 0; i < n; i++) {

        *(a+i) = new ll[ n ] ;
    }

    return a ;
}

void print (ll **a, ll n) { ///IT PRINTS THE CHESSBOARD

    for(ll i = 0; i < n; i++) {

        for(ll j = 0; j < n; j++) {

            cout << setw(5) << a[i][j] ;
        }

        cout << '\n' ;
    }
}

ll tiles (ll n) { ///IT CALCULATES THE HIGHEST NUMBER OF TILES THAT CAN BE ADJUSTED IN CHESSBOARD

    ll number = ( n*n - 1 ) / 3 ;

    return number;
}

ll mark () { ///IT RETURNS THE TILE NUMBER FOR THE CURRENT CELL

    static ll idx = 0 ;

    return ++idx ;
}

void board (ll **a, ll n, ll rx, ll ry, ll cx, ll cy, ll r, ll c) { ///IT TRAVERSES THE WHOLE CHESSBOARD BLOCK BY BLOCK, CHECKS IF A BLOCK GOT ANY DEFECTIVE CELL, IF NOT THEN ASSIGN A TEMPORARY DEFECTIVE CELL INTO IT

    if(n == 1)///BASE CONDITION
        return ;

    n = n/2 ;

    ll defect = mark () ;///INDICATES TILE NUMBER THAT WILL BE ASSIGNED INTO THE CURRENT CELLS

    ll p = (rx + ry)/2 ;///WE USE p and q TO MAKE CO-ORDINATES FOR DIFFERENT BLOCKS, WHERE TEMPORARY DEFECTIVE CELLS WILL BE ADDED

    ll q = (cx + cy)/2 ;

    if( (rx <= r && r < rx+n) && (cx <= c && c < cx+n) ) { ///CEHECKING IF THE TOP-LEFT BLOCK GOT ANY DEFECTIVE CELL

        board (a, n, rx, rx+n, cx, cx+n, r, c) ;///CALLING THE TOP-LEFT BLOCK

    }else {

        a[ p-1 ][ q-1 ] = defect ;///IF THERE IS NO DEFECTIVE CELL IN THE TOP-LEFT BLOCK, ADD A TEMPORRAY ONE

        board (a, n, rx, rx+n, cx, cx+n, p-1, q-1) ;
    }

    if( (rx <= r && r < rx+n) && (cx+n <= c && c < cy) ) { ///CEHECKING IF THE TOP-RIGHT BLOCK GOT ANY DEFECTIVE CELL

        board (a, n, rx, rx+n, cx+n, cy, r, c) ;///CALLING THE TOP-RIGHT BLOCK

    }else {

        a[ p-1 ][ q ] = defect ;///IF THERE IS NO DEFECTIVE CELL IN THE TOP-RIGHT BLOCK, ADD A TEMPORRAY ONE

        board (a, n, rx, rx+n, cx+n, cy, p-1, q) ;
    }

    if( (rx+n <= r && r < ry) && (cx <= c && c < cx+n) ) { ///CEHECKING IF THE BOTTOM-LEFT BLOCK GOT ANY DEFECTIVE CELL

        board (a, n, rx+n, ry, cx, cx+n, r, c) ;///CALLING THE BOTTOM-LEFT BLOCK

    }else {

        a[ p ][ q-1 ] = defect ;///IF THERE IS NO DEFECTIVE CELL IN THE BOTTOM-LEFT BLOCK, ADD A TEMPORRAY ONE

        board (a, n, rx+n, ry, cx, cx+n, p, q-1) ;
    }

    if( (rx+n <= r && r < ry) && (cx+n <= c && c < cy) ) { ///CEHECKING IF THE BOTTOM-RIGHT BLOCK GOT ANY DEFECTIVE CELL

        board (a, n, rx+n, ry, cx+n, cy, r, c) ;///CALLING THE BOTTOM-RIGHT BLOCK

    }else {

        a[ p ][ q ] = defect ;///IF THERE IS NO DEFECTIVE CELL IN THE BOTTOM-RIGHT BLOCK, ADD A TEMPORRAY ONE

        board (a, n, rx+n, ry, cx+n, cy, p, q) ;
    }
}

int main()
{
    ll n, r, c ;

    cin >> n >> r >> c ;

    cout << "NUMBER OF TILES: " << tiles (n) << '\n' ;///HIGHEST NUMBER OF TILES THAT CAN BE ADJUSTED IN CHESSBOARD

    ll **a = allocate (n) ;///CREATING N X N CHESSBOARD

    for(ll i = 0; i < n; i++) {

        fill( a[i], a[i] + n, 0 ) ;///INITIALIZE EVERY CELL WITH ZERO
    }

    a[r][c] = -1 ;///ASSIGNING THE REAL DEFECTIVE CELL INTO THE CHESSBOARD

    ll rx = 0, ry = n, cx = 0, cy = n ;/// (RX-RY) IS THE RANGE OF ROW AND (CX-CY) IS THE RANGE OF COLUMN

    board (a, n, rx, ry, cx, cy, r, c) ;///ADJUSTING TILES IN THE CHESSBOARD

    cout << "CHESSBOARD:" << '\n' ;

    print (a, n) ;///PRINT THE CHESSBOARD AFTER ADJUSTING EVERY POSSIBLE TILE INTO IT

    return 0 ;
}
//TIME COMPLEXITY: O( N*N )
