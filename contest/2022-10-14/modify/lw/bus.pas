program bus;
const
        maxn = 100050;
        infile = 'bus.in';
        oufile = 'bus.out';
var
        a : array [ 1 .. maxn ] of int64;
        ans , min : int64;
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
        ans := 0;   min := maxlongint;
        for i := 1 to n do begin
		if ( a[ i ] < min ) then min := a[ i ];
		inc ( ans , min );
	end;
        writeln ( ouf , ans );
end;


begin
        assign ( inf , infile );   reset ( inf );
        assign ( ouf , oufile );   rewrite ( ouf );
        init;
        main;
        close ( inf );  close ( ouf );
end.