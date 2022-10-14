var
	fin,fout:text;
	i,j,k,t,n:longint;
	c:int64;
	w,m:array[0..43,0..43] of int64;
	b:array[0..43] of boolean;
	up,first:boolean;

procedure print(x,y:longint);
var
	i:longint;
begin
	i:=0;
	while i<y do
	begin
		inc(i);
		if (b[i])and(x>=i) then
			begin
				inc(x);inc(y)
			end;
	end;
	b[x]:=true;
	write(fout,x,' ');
end;

begin
	assign(fin,'wave.in');reset(fin);
	readln(fin,t);
	w[1,1]:=1;w[2,2]:=1;w[1,2]:=0;
	m[1,1]:=1;m[2,2]:=0;m[1,2]:=1;

	for i:=3 to 20 do
		for j:=1 to 20 do
		begin
			for k:=1 to j-1 do
				w[j,i]:=w[j,i]+m[k,i-1];
			for k:=j to i-1 do
				m[j,i]:=m[j,i]+w[k,i-1]
		end;

	assign(fout,'wave.out');rewrite(fout);
	while t>0 do
	begin
		dec(t);
		readln(fin,n,c);
		fillchar(b,sizeof(b),0);
		up:=true;first:=true;
		i:=1;
		while n>0 do
		begin
			if up then
				if c>m[i,n] then
					begin
						c:=c-m[i,n];
						inc(i);
						if first then up:=false;
					end
				else
					begin
						print(i,n);
						dec(n);
						first:=false;
						up:=false
					end
			else
				if c>w[i,n] then
					begin
						c:=c-w[i,n];
						if first then up:=true
							else inc(i);
					end
				else
					begin
						print(i,n);
						dec(n);
						first:=false;
						up:=true;
                                                i:=1;
					end;
		end;
		writeln(fout);
	end;
	close(fin);
	close(fout)

end.
