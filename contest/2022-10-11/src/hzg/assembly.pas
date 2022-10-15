program assembly;
var i,p,n,m,total:longint;ans,anss:double;
b,l:array[0..100] of longint;
sup,opp,pri:array[0..100] of longint;
f:array[0..100]of boolean;

procedure addwin(x:longint);
var r,k:longint;zan:double;
begin
anss:=1;
for r:=1 to x do
        begin
        k:=sup[r];
        zan:=(l[k]+pri[k])/100;
        if zan>1 then zan:=1;
        anss:=anss*zan;
        end;
ans:=ans+anss;
end;

procedure addopp(x:longint);
var r,k,num:Longint;zan:double;
begin
anss:=1;num:=m;
for r:=1 to x do
        begin
        k:=opp[r];
        zan:=(l[k]+pri[k])/100;
        if zan>1 then zan:=1;
        zan:=1-zan;
        anss:=anss*zan;
        num:=num+b[k];
        end;
anss:=anss*m/num;
ans:=ans+anss;
end;

procedure win(x,y,z:longint);
var r:longint;
begin
sup[y]:=x;
f[x]:=true;
if y<z then
        begin
        for r:=1 to n do
                begin
                if f[r]=false then win(r,y+1,z);
                end;
        f[x]:=false;
        end
else addwin(z);
end;

procedure beat(x,y,z:longint);
var r,k:Longint;
begin
opp[y]:=x;
f[x]:=true;
if y<z then
        begin
        for r:=1 to n do
                begin
                if f[r]=false then beat(r,y+1,z);
                end;
        f[x]:=false;
        end
else addopp(z);
end;

procedure search(x,y:longint);
var r,k:longint;
begin
inc(pri[x]);
if y<total then
        begin
        for r:=1 to n do search(r,y+1);
        end
else
        begin
        for k:=(n div 2)+1 to n do
                begin
                fillchar(f,sizeof(f),false);
                for r:=1 to n do win(r,1,k);
                end;
        for k:=(n div 2) to n do
                begin
                fillchar(f,sizeof(f),false);
                for r:=1 to n do beat(r,1,k);
                end;
        end;
end;

begin
assign(input,'assembly.in');reset(input);
assign(output,'assembly.out');rewrite(output);
readln(n,total,m);
for i:=1 to n do readln(b[i],l[i]);
ans:=0;
for i:=1 to n do
        begin
        fillchar(pri,sizeof(pri),0);
        search(i,1);
        end;
writeln(ans:0:6);
close(input);close(Output);
end.
