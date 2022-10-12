program DerProze;
var i,year,month,day:longint;

function nian(x:longint):longint;
begin
if x mod 100<>0 then
        begin
        if x mod 4<>0 then exit(365) else exit(366);
        end
else
        begin
        if x mod 400<>0 then exit(365) else exit(366);
        end;
end;

function yue(x,y:longint):longint;
var r:longint;
begin
if(x=1)or(x=3)or(x=5)or(x=7)or(x=8)or(x=10)or(x=12)then exit(31)
else
if (x=4)or(x=6)or(x=9)or(x=11) then exit(30)
else
if nian(y)=365 then exit(28)
else exit(29);
end;

function find(x,y:longint):longint;
var r,k,l:longint;
begin
if y=2 then
        begin
        k:=x mod 7;
        l:=5;
        for r:=1 to k do l:=(l+1) mod 7;
        exit(l);
        end
else
        begin
        k:=x mod 7;
        l:=5;
        for r:=1 to k do
                begin
                if l=0 then l:=6 else dec(l);
                end;
        exit(l);
        end;
end;

function cal(x,y,z:longint):longint;
var r,k,boo,ans,std:longint;
begin
if x<2011 then
        begin
        ans:=0;
        for r:=y+1 to 12 do inc(ans,yue(r,x));
        inc(ans,yue(y,x)-z);
        for r:=x+1 to 2010 do inc(ans,nian(r));
        for r:=1 to 9 do inc(ans,yue(r,2011));
        k:=find(ans,1);
        exit(k);
        end
else
if x>2011 then
        begin
        ans:=0;
        for r:=10 to 12 do inc(ans,yue(r,2011));
        for r:=2012 to x-1 do inc(ans,nian(r));
        for r:=1 to y-1 do inc(ans,yue(r,x));
        inc(ans,z);
        k:=find(ans,2);
        exit(k);
        end
else
        begin
        std:=0;ans:=0;
        for r:=1 to 9 do inc(std,yue(r,x));
        for r:=1 to y-1 do inc(ans,yue(r,x));
        inc(ans,z);
        boo:=1;
        if ans>std then boo:=2;
        ans:=abs(ans-std);
        k:=find(ans,boo);
        exit(k);
        end;
end;

procedure shuchu(x:longint);
begin
if x=1 then writeln('monday');
if x=2 then writeln('tuesday');
if x=3 then writeln('wednesday');
if x=4 then writeln('thursday');
if x=5 then writeln('friday');
if x=6 then writeln('saturday');
if x=0 then writeln('sunday');
end;

begin
assign(input,'DerProze.in');reset(input);
assign(output,'DerProze.out');rewrite(output);
readln(year,month,day);
i:=cal(year,month,day);
shuchu(i);
close(input);close(Output);
end.
