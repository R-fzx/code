var a,b,i:longint;
	sum:qword;
	sx:array[2..50000000] of longint;
procedure init;
var i,k:longint;
	j:qword;
begin
	for i:=2 to 7071 do if sx[i]=1 then begin
			j:=i;k:=1;
			while j*i<=50000000 do begin
				inc(k);
				j:=j*i;
				sx[j]:=k;
			end;
		end;
end;
begin
	for i:=2 to 50000000 do sx[i]:=1;
	init;
	assign(input,'t2.in');reset(input);
	assign(output,'t2.out');rewrite(output);
	readln(a,b);
	while (a<>0)and(b<>0) do begin
		sum:=0;
		for i:=a to b do sum:=sum+sx[i];
		writeln(sum);
		readln(a,b);
	end;
        close(input);close(output);
end.
