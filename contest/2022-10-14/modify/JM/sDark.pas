type
	point=record
		x,y:double;
	end;

var
	ans,x1,x2,y1,y2:double;
	p,b,q:array[0..200043] of point;
	n:longint;
        fin,fout:text;

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
	assign(fin,'dark.in');reset(fin);
	readln(fin,n);
	for i:=1 to n do readln(fin,p[i].x,p[i].y);
	close(fin);
	sort(1,n);
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
{
procedure merge(x,y,z:longint);
var
	i,j,t:longint;
begin
	i:=x;j:=y+1;
	
	t:=x-1;
	while (i<=y)or(j<=z) do
	begin
		if ((p[i].y<p[j].y)or(j>z))and(i<=y)then begin inc(t);b[t]:=p[i];inc(i); end
			else if (j<=z) then begin inc(t);b[t]:=p[j];inc(j); end;
	end;

	for i:=x to z do p[i]:=b[i];
end;
}


procedure merge(x,y,z:longint);
var
	i,j,t,k:longint;
begin
	i:=x;j:=y+1;

	t:=x-1;
	while (i<=y)and(j<=z) do
	begin
        inc(t);
                if (p[i].y<p[j].y) then begin b[t]:=p[i];inc(i); end
			else begin b[t]:=p[j];inc(j); end;
	end;

        if i<=y then
          for k:=t+1 to z do
          begin
          b[k]:=p[i];inc(i);
          end;
        if j<=z then
          for k:=t+1 to z do
          begin
            b[k]:=p[j];
            inc(j);
          end;
	for i:=x to z do p[i]:=b[i];
end;

function suan(l,r:longint):double;
var
	i,j,k,mid:longint;
	xp:double;
	tp:point;
begin
	if r-l<4 then
		begin
			xp:=1e100;
			for i:=l to r-1 do
				for j:=i+1 to r do
					xp:=min(xp,dis(p[i],p[j]));
			for i:=l to r-1 do
				for j:=i+1 to r do
					if p[i].y>p[j].y then
						begin
							tp:=p[i];p[i]:=p[j];p[j]:=tp;												end;	
			exit(xp)
		end;
	mid:=(l+r) shr 1;
	xp:=min(suan(l,mid),suan(mid+1,r));

	merge(l,mid,r);

	k:=0;
	for i:=l to r do
		if abs(p[i].x-p[mid].x)<xp then
			begin
				inc(k);q[k]:=p[i]
			end;
	for i:=1 to k-1 do
		for j:=i+1 to k do
		begin
			if q[j].y-q[i].y>xp then break;
			xp:=min(xp,dis(q[i],q[j]));
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
	assign(fout,'dark.out');rewrite(fout);
	writeln(fout,ans/2:0:2);
	close(fout);
end;

begin
	init;
	main;
	print
end.
