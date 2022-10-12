var x1,y1,x2,y2:real;
procedure swap(var a,b:real);
var t:real;
begin
	t:=a;a:=b;b:=t;
end;
function max(a,b:real):real;
begin
	if a>b then exit(a) else exit(b);
end;
function min(a,b:real):real;
begin
	if a<b then exit(a) else exit(b);
end;
function calc(d,l,x1,y1,x2,y2:real):real;
var t,dt,res:real;
begin
	if d>500 then exit(0);
	if x1>x2 then swap(x1,x2);
	if y1>y2 then swap(y1,y2);
	dt:=l/3;
	if (y2+1e-8>l)and(y1<1e-8)and(x1-1e-8<-dt)and(x2+1e-8>dt) then exit(l+l*2/3*(500-d));
	if (y1+1e-8>l)or(y2<1e-8)or(x2<-dt+1e-8)or(dt-1e-8<x1) then exit(0);
	res:=0;
	if (x1-1e-8<0)and(x2+1e-8>0) then begin
		t:=min(y2,l-dt)-max(y1,0);
		res:=res+max(t,0);
	end;
	exit(calc(d+1,dt,x1,y1-l+dt,x2,y2-l+dt)+calc(d+1,dt,-y1+l-dt,x1,-y2+l-dt,x2)+calc(d+1,dt,y1-l+dt,-x1,y2-l+dt,-x2)+res);
end;
begin
	assign(input,'Metamorphosis.in');reset(input);
	readln(x1);readln(y1);readln(x2);readln(y2);
	close(input);
	assign(output,'Metamorphosis.out');rewrite(output);
	writeln(calc(1,81,x1,y1,x2,y2):0:1);
	close(output);
end.
{var l:real;
	x1,y1,x2,y2:longint;
begin
	assign(input,'Metamorphosis.in');reset(input);
	readln(x1);readln(y1);readln(x2);readln(y2);
	close(input);
	assign(output,'Metamorphosis.out');rewrite(output);
	if (x1<=0)and(x2>=0) then begin
		if y1<0 then y1:=0;
		if y2<0 then y2:=0;
		if y2<54 then l:=y2-y1 else l:=27027-y1;
	end else l:=0;
	writeln(l:0:1);
	close(output);
end.}