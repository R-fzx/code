//{$q+,s+,r+,i+}
program dark;
const
        maxn = 200005;
        infile = 'dark.in';
        oufile = 'dark.out';
        infi = 9999999999;
var
        x , y : array [ 1 .. maxn ] of double;
        n : longint;
        ans : double;
        inf , ouf : text;

function dist ( i , j : longint ): double;
begin
        dist := sqr( x[ i ] - x[ j ] ) + sqr ( y[ i ] - y[ j ] );
        dist := sqrt ( dist );
end;


procedure init;
var
        i : longint;
begin
        read ( inf , n );
        for i := 1 to n do read ( inf , x[ i ] , y[ i ] );
end;


procedure swap ( var a , b : double );
var
        c : double;
begin
        c := a;  a := b;  b := c;
end;


procedure qsort ( l , r : longint );
var
        i , j : longint;
        cmpx , cmpy : double;
begin
        if ( l >= r ) then exit;
        i := l;   j := r;
        cmpx := x[ ( l + r ) shr 1 ];   cmpy := y[ ( l + r ) shr 1 ];
        repeat
                while ( x[ i ] < cmpx )or( ( x[ i ] = cmpx )and( y[ i ] < cmpy ) ) do inc ( i );
                while ( x[ j ] > cmpx )or( ( x[ j ] = cmpx )and( y[ j ] > cmpy ) ) do dec ( j );
                if ( i <= j ) then begin
                        swap ( x[ i ] , x[ j ] );
                        swap ( y[ i ] , y[ j ] );
                        inc ( i );
                        dec ( j );
                end;
        until i > j;
        qsort ( l , j );
        qsort ( i , r );
end;


function calc ( l , r : longint ) : double;
var
        i , j , k , mid , i1 : longint;
        tmp , tmp1 : double;
begin
        if ( l = r ) then exit ( infi );
        if ( l + 1 = r ) then exit ( dist ( l , r ) );
        mid := ( l + r ) shr 1;
        tmp := calc ( l , mid );
        tmp1 := calc ( mid + 1 , r );
        if ( tmp1 < tmp ) then tmp := tmp1;
        j := mid - 5;
        if ( j < 1 ) then j := 1;
        k := mid + 5;
        if ( k > n ) then k := n;
        for i := j to k do
                for i1 := i + 1 to k do begin
                        tmp1 := dist ( i , i1 );
                        if ( tmp1 < tmp ) then tmp := tmp1;
                end;
        exit ( tmp );
end;

procedure main;
var
        i , j , k : longint;
begin
        qsort ( 1 , n );
        ans := calc ( 1 , n );
        writeln ( ouf , ans : 0 : 2 );
end;


begin
        assign ( inf , infile );  reset ( inf );
        assign ( ouf , oufile );  rewrite ( ouf );
        init;
        main;
        close ( inf );   close ( ouf );
end.
