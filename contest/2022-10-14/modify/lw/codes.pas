//{$M 2560000}
program codes;
const
        maxn = 25;
        infile = 'codes.in';
        oufile = 'codes.out';
var
        s : array [ 1 .. maxn ] of string;
        l : array [ 1 .. maxn ] of longint;
        n , got : longint;
        ans , min : string;
        inf , ouf : text;


procedure init;
var
        i : longint;
begin
        readln ( inf , n );
        for i := 1 to n do readln ( inf , s[ i ] );
        for i := 1 to n do l[ i ] := length( s[ i ] );
end;


function prefix ( s1 , s2 : string ) : boolean;
var
        i , l1 , l2 : longint;
begin
        l1 := length ( s1 );  l2 := length ( s2 );
        if ( l1 > l2 ) then exit ( false );
        for i := 1 to l1 do
                if ( s1[ i ] <> s2[ i ] ) then exit ( false );
        exit ( true );
end;



procedure dfs ( le , tmp : string; c , len , left , dif : longint );
var
        i , j , k : longint;
        s1 : string;
begin
        if ( len > got ) then exit;
        if ( le = '' ) then begin
                if ( dif = 1 ) then begin
                if ( ans = '' ) then ans := tmp
                else
                if ( length ( tmp ) < length ( ans ) ) then ans := tmp
                else
                if ( length( tmp ) = length ( ans ) )and( tmp < ans ) then
                        ans := tmp;
                got := length ( ans );
                end;
                exit;
        end;
        if ( c = 1 ) then begin
                tmp := tmp + le;
                len := len + left;
        end;
        for i := 1 to n do
                if ( prefix ( s[ i ] , le ) ) then begin
                        s1 := copy ( le , l[ i ] + 1 , left - l[ i ] );
                        if ( dif = 1 )or( s1 <> '' ) then k := 1
                        else k := 0;
                        dfs ( s1 , tmp , 0 , len , length ( s1 ) , k );
                end
                else
                if ( prefix ( le , s[ i ] ) ) then begin
                        s1 := copy ( s[ i ] , left + 1 , l[ i ] - left );
                        if ( dif = 1 )or( s1 <> '' ) then k := 1
                        else k := 0;
                        dfs ( s1 , tmp , 1 , len , l[ i ] - left , k );
                end;
end;


procedure main;
var
        i : longint;
begin
        ans := '';
        got := 0;
        for i := 1 to n do got := got + l[ i ];
        for i := 1 to n do
                dfs ( s[ i ] , '' , 1 , 0 , l[ i ] , 0 );
        writeln ( ouf , length ( ans ) );
        writeln ( ouf , ans );
end;


begin
        assign ( inf , infile );  reset ( inf );
        assign ( ouf , oufile );  rewrite ( ouf );
        init;
        main;
        close ( inf );   close ( ouf );
end.
