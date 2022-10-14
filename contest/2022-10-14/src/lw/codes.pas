//{$q+,s+,r+,i+}
program codes;
const
        maxn = 25;
        infile = 'codes.in';
        oufile = 'codes.out';
        maxs = 1060003;
var
        s : array [ 1 .. maxn ] of ansistring;
        ans : ansistring;
        n , tot , h , t , len : longint;
        head : array [ 0 .. maxs ] of longint;
        next , pnt : array [ 1 .. maxs ] of longint;
        q : array [ 1 .. maxs ] of ansistring;
        inf , ouf : text;

function hash ( ss : ansistring ): longint;
var
        tmp , i : longint;
begin
        tmp := 0;
        for i := 1 to length ( ss ) do begin
                tmp := tmp * 3 + ord ( ss[ i ] ) - 47;
                tmp := tmp mod maxs;
        end;
        hash := tmp;
end;


procedure init;
var
        i : longint;
begin
        readln ( inf , n );
        for i := 1 to n do readln ( inf , s[ i ] );
end;


function check ( ss : ansistring ) : boolean;
var
        i , j , k : longint;
begin
        k := hash ( ss );
        i := head[ k ];
        while ( i <> 0 ) do begin
                if ( q[ pnt[ i ] ] = ss ) then exit ( true );
                i := next[ i ];
        end;
        inc ( tot );
        next[ tot ] := head[ k ];
        head[ k ] := tot;
        pnt[ tot ] := t + 1;
        exit ( false );
end;


procedure enq ( ss : ansistring );
begin
        inc ( t );
        q[ t ] := ss;
end;



procedure swap ( var a , b : ansistring );
var
        c : ansistring;
begin
        c := a;  a := b;  b := c;
end;


procedure sort;
var
        i , j : longint;
begin
        for i := 1 to n do
                for j := i + 1 to n do
                        if ( s[ i ] + s[ j ] > s[ j ] + s[ i ] ) then swap ( s[ i ] , s[ j ] );
end;


procedure bfs;
var
        i , j , k : longint;
        ss : ansistring;
begin
         sort;
         h := 1;   t := 0;
         len := maxlongint;
         for i := 1 to n do begin
                check ( s[ i ] );
                enq ( s[ i ] );
         end;
         while ( h <= t ) do begin
                for i := 1 to n do begin
                        ss := q[ h ] + s[ i ];
                        k := length ( ss );
                        if ( k >= len ) then continue;
                        if ( check ( ss ) ) then begin
                                ans := ss;
                                len := k;
                        end
                        else enq ( ss );
                end;
                inc ( h );
         end;
         writeln ( ouf , len );
         writeln ( ouf , ans );
end;


begin
        assign ( inf , infile );  reset ( inf );
        assign ( ouf , oufile );  rewrite ( ouf );
        init;
        bfs;
        close ( inf );  close ( ouf );
end.
