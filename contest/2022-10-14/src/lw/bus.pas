program bus;
const
        maxn = 100050;
        infile = 'bus.in';
        oufile = 'bus.out';
var
        a : array [ 1 .. maxn ] of int64;
        ans : int64;
        n : longint;
        inf , ouf : text;



procedure init;
var
        i : longint;
begin
        read ( inf , n );
        for i := 1 to n do read ( inf , a[ i ] );
end;


procedure main;
var
        i : longint;
begin
        ans := 0;
        for i := 1 to n do inc ( ans , a[ i ] );
        writeln ( ouf , ans );
end;


begin
        assign ( inf , infile );   reset ( inf );
        assign ( ouf , oufile );   rewrite ( ouf );
        init;
        main;
        close ( inf );  close ( ouf );
end.