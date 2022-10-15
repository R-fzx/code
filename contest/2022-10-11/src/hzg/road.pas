program road;
type node=^cool;
cool=record
data,cost1,cost2:longint;
link:node;
end;
var i,p,m,n,mon1,mon2,x,y,ai,bi:longint;ans,anss:int64;
f,can:array[0..200] of boolean;
len1,len2:array[0..200,0..200] of longint;
a,b:array[0..200] of longint;
money:array[0..200] of int64;
son:array[0..200] of node;
dui:array[0..200000] of longint;

function maxs(x,y:int64):int64;
begin
if x>y then exit(x) else exit(y);
end;

function max(x,y,z:int64):int64;
begin
if (x>=y)and(x>=z) then exit(x)
else
if(y>=x)and(y>=z) then exit(y)
else exit(z);
end;

procedure search(x:longint);
var r,k:Longint;w:node;
begin
w:=son[x];
while w<>nil do
        begin
        k:=w^.data;
        if can[k]=false then
                begin
                can[k]:=true;search(k);
                end;
        w:=w^.link;
        end;
end;

function judge:boolean;
var r,k:Longint;
begin
fillchar(can,sizeof(can),false);
can[1]:=true;
search(1);
for r:=1 to n do
        begin
        if can[r]=false then exit(false);
        end;
exit(true);
end;

procedure build(x,y,ai,bi:longint);
var r,k:Longint;w:node;
begin
new(w);w^.data:=y;w^.cost1:=ai;w^.cost2:=bi;
w^.link:=son[x];son[x]:=w;
end;

procedure init;
var r,k,l,c1,c2,st,en:longint;w:node;boo:boolean;
begin
dui[1]:=1;st:=1;en:=2;
for r:=1 to n do
        begin
        money[r]:=maxlongint;a[r]:=0;b[r]:=0;
        end;
money[1]:=0;
fillchar(f,sizeof(f),false);f[1]:=true;
while st<>en do
        begin
        k:=dui[st];inc(st);f[k]:=false;
        w:=son[k];
        while w<>nil do
                begin
                l:=w^.data;c1:=w^.cost1;c2:=w^.cost2;
                boo:=false;anss:=money[k];
                if a[k]<c1 then inc(anss,(c1-a[k])*mon1);
                if b[k]<c2 then inc(anss,(c2-b[k])*mon2);
                if anss<money[l] then
                        begin
                        boo:=true;money[l]:=anss;
                        a[l]:=max(a[k],c1,a[l]);
                        b[l]:=max(b[k],c2,b[l]);
                        end;
                if (boo=true)and(f[l]=false)then
                        begin
                        dui[en]:=l;inc(en);f[l]:=true;
                        end;
                w:=w^.link;
                end;
        end;
end;

procedure shuchu;
var r:longint;
begin
ans:=0;
for r:=1 to n do
        begin
        if money[r]>ans then ans:=money[r];
        end;
writeln(ans);
end;

begin
assign(input,'road.in');reset(input);
assign(output,'road.out');rewrite(output);
readln(n,m);readln(mon1,mon2);
fillchar(len1,sizeof(len1),0);
fillchar(len2,sizeof(len2),0);
for i:=1 to n do son[i]:=nil;
for i:=1 to m do
        begin
        readln(x,y,ai,bi);
                begin
                if(len1[x,y]=0)or(len2[x,y]=0) then
                        begin
                        len1[x,y]:=maxs(len1[x,y],ai);
                        len2[x,y]:=maxs(len2[x,y],bi);
                        len1[y,x]:=len1[x,y];len2[y,x]:=len2[x,y];
                        build(x,y,ai,bi);
                        build(y,x,ai,bi);
                        end
                else
                if (ai<len1[x,y])or(bi<len2[x,y]) then
                        begin
                        len1[x,y]:=maxs(len1[x,y],ai);
                        len2[x,y]:=maxs(len2[x,y],bi);
                        len1[y,x]:=len1[x,y];len2[y,x]:=len2[x,y];
                        build(x,y,ai,bi);
                        build(y,x,ai,bi);
                        end;
                end;
        end;
if judge then
        begin
        init;
        shuchu;
        end
else writeln('-1');
close(input);close(Output);
end.
