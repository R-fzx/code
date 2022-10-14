var
	dis,ans,x1,x2,y1,y2:double;
	x,y:array[0..200043] of longint;
	n:longint;
        fin,fout:text;

procedure sort(l,r:longint);
var
	i,j,m1,m2,tp:longint;
begin
	i:=l;j:=r;m1:=x[(l+r) shr 1];m2:=y[(l+r) shr 1];
	repeat
		while (x[i]<m1)or(x[i]=m1)and(y[i]<m2) do inc(i);
		while (x[j]>m1)or(x[j]=m1)and(y[j]>m2) do dec(j);
		if i<=j then
			begin
				tp:=x[i];x[i]:=x[j];x[j]:=tp;
				tp:=y[i];y[i]:=y[j];y[j]:=tp;
				inc(i);dec(j)
			end;
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
end;

procedure init;
var
	i:longint;
begin
	assign(fin,'dark.in');reset(fin);
	readln(fin,n);
	for i:=1 to n do readln(fin,x[i],y[i]);
	close(fin);
	sort(1,n);
end;

procedure main;
var
	i,j,fuck:longint;
begin
	ans:=1e100;
	for i:=1 to n-1 do
		if (x[i]=x[i+1])and(y[i]=y[i+1]) then
			begin
				ans:=0;
				exit;
			end;
	if n<=5000 then
		begin
			for i:=1 to n do
				for j:=i+1 to n do
				begin
					x1:=x[i];y1:=y[i];x2:=x[j];y2:=y[j];
					dis:=sqrt(sqr(x1-x2)+sqr(y1-y2));
					if dis<ans then ans:=dis;
				end;
		end
	else
		begin
			fuck:=0;
                        randomize;
			repeat
				inc(fuck);
				i:=random(n)+1;j:=random(n)+1;
				if i<>j then
					begin
						x1:=x[i];y1:=y[i];x2:=x[j];y2:=y[j];
						dis:=sqrt(sqr(x1-x2)+sqr(y1-y2));
						if dis<ans then ans:=dis;
					end;
			until fuck>2000000;
		end;
end;

procedure print;
begin
	assign(fout,'dark.out');rewrite(fout);
	writeln(fout,ans:0:2);
	close(fout);
end;

begin
	init;
	main;
	print
end.
