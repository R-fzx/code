var i,n:longint;
	d:array[1..200]of qword;
begin
	assign(input,'t3.in');reset(input);
	assign(output,'t3.out');rewrite(output);
	readln(n);
	d[1]:=0;d[2]:=1;
	for i:=3 to n do
		d[i]:=(i-1)*(d[i-1]+d[i-2]);
	writeln(d[n]);
	close(input);close(output);
end.
