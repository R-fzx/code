program wave;
const
        maxn = 25;
        infile = 'wave.in';
        oufile = 'wave.out';
var
        f : array [ 0 .. maxn , 0 .. maxn , 0 .. 1 ] of int64;
        used : array [ 1 .. maxn ] of boolean;
        n , m : longint;
        c : int64;
        ans : array [ 1 .. maxn] of longint;
        inf , ouf : text;


procedure pre;
var
        i , j , k : longint;
begin
        fillchar ( f , sizeof ( f ) , 0 );
        f[ 1 , 1 , 0 ] := 1;  f[ 1 , 1 , 1 ] := 1;
        for i := 2 to maxn - 5 do
                for j := 1 to i do begin
                        for k := 1 to j - 1 do
                                inc ( f[ i , j , 1 ] , f[ i - 1 , k , 0 ] );
                        for k := j to i do
                                inc ( f[ i , j , 0 ] , f[ i - 1 , k , 1 ] );
                end;
end;


function get ( x : longint ): longint;
var
        i : longint;
begin
        for i := 1 to n do begin
                if ( not used[ i ] ) then dec ( x );
                if ( x = 0 ) then exit ( i );
        end;
end;


procedure calc;
var
        i , j , k , x : longint;
begin
        k := -1;    x := -1;
        fillchar ( used , sizeof ( used ) , 0 );
        for i := n downto 1 do begin
                //if ( k = 1 ) then begin
                for j := 1 to i do begin
                        if ( k <> 1 ) then
                        if ( x < 0 )or( j >= x ) then begin
                                if ( f[ i , j , 1 ] < c ) then dec ( c , f[ i , j , 1 ] )
                                else begin
                                        x := get ( j );
                                        ans[ i ] := x;
                                        used[ x ] := true;
                                        x := j;
                                        k := 1;
                                        break;
                                end;
                        end;
                        if ( k <> 0 ) then
                        if ( x < 0 )or( j < x ) then begin
                                if ( f[ i , j , 0 ] < c ) then dec ( c , f[ i , j , 0 ] )
                                else begin
                                        x := get ( j );
                                        ans[ i ] := x;
                                        used[ x ] := true;
                                        x := j;
                                        k := 0;
                                        break;
                                end;
                        end;
                end;

        end;
        for i := n downto 1 do begin
                write ( ouf , ans[ i ] );
                if ( i > 1 ) then write ( ouf , ' ' ) else writeln ( ouf );
        end;
end;


procedure main;
var
        i : longint;
begin
        read ( inf , m );
        for i := 1 to m do begin
                read ( inf , n , c );
                calc;
        end;
end;


begin
        assign ( inf , infile );   reset ( inf );
        assign ( ouf , oufile );   rewrite ( ouf );
        pre;
        main;
        close ( inf );   close ( ouf );
end.
