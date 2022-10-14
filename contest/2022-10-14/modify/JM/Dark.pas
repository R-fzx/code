type
	point=record
		x,y:double;
	end;

var
	ans,x1,x2,y1,y2:double;
	p,b,q:array[0..200043] of point;
	n:longint;

procedure sort(l,r:longint);
var
	i,j:longint;
	m1:double;
	tp:point;
begin
	i:=l;j:=r;m1:=p[(l+r) shr 1].x;
	repeat
		while p[i].x<m1 do inc(i);
		while p[j].x>m1 do dec(j);
		if i<=j then
			begin
				tp:=p[i];p[i]:=p[j];p[j]:=tp;
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
	assign(input,'dark.in');reset(input);
	readln(n);
	for i:=1 to n do readln(p[i].x,p[i].y);
	sort(1,n);
	close(input)
end;

function min(a,b:double):double;
begin
	if a<b then min:=a
		else min:=b
end;

function dis(p1,p2:point):double;
begin
	dis:=sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y))
end;

procedure sortq(l,r:longint);
var
	i,j:longint;
	m1:double;
	tp:point;
begin
	i:=l;j:=r;m1:=q[(l+r) shr 1].y;
	repeat
		while q[i].y<m1 do inc(i);
		while q[j].y>m1 do dec(j);
		if i<=j then
			begin
				tp:=q[i];q[i]:=q[j];q[j]:=tp;
				inc(i);dec(j)
			end;
	until i>j;
	if l<j then sortq(l,j);
	if i<r then sortq(i,r);
end;

function suan(l,r:longint):double;
var
	i,j,k,mid:longint;
	xp:double;
	tp:point;
begin
	if r-l<3 then
		begin
			xp:=1e100;
			for i:=l to r-1 do
				for j:=i+1 to r do
					xp:=min(xp,dis(p[i],p[j]));
			exit(xp)
		end;
	mid:=(l+r) shr 1;
	xp:=min(suan(l,mid),suan(mid+1,r));

	k:=0;
	for i:=mid-1 downto l do
		if p[mid+1].x-p[i].x<xp then
			begin
				inc(k);q[k]:=p[i]
			end
		else
			break;
	for i:=mid+1 to r do
		if p[i].x-p[mid].x<xp then
			begin
				inc(k);q[k]:=p[i]
			end
		else
			break;

	sortq(1,k);
	for i:=1 to k-1 do
		for j:=i+1 to k do
		begin
			if q[j].y-q[i].y<xp then
				xp:=min(xp,dis(q[i],q[j]))
			else break;
		end;
        suan:=xp
end;

procedure main;
var
	i,j,fuck:longint;
begin
	ans:=suan(1,n);
end;

procedure print;
begin
	assign(output,'dark.out');rewrite(output);
	writeln(ans/2:0:2);
	close(output)
end;

begin
	init;
	main;
	print;
end.
