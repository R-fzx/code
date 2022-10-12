program Castle;
var i,p,m,n,ans,x,y,z:longint;
dui:array[0..2000] of integer;
f:array[0..1000] of boolean;
g,d,dis:array[0..1000,0..1000] of longint;
way:array[0..1000,0..2] of integer;
son:array[0..1000,0..1000] of integer;

procedure spfa;
var r,k,st,en:longint;
begin
g[1,1]:=0;fillchar(f,sizeof(f),false);
dui[1]:=1;st:=1;en:=2;f[1]:=true;
while st<>en do
        begin
        k:=dui[st];inc(st);f[k]:=false;
        for r:=1 to n do
                begin
                if(r<>k)and(g[k,r]<>maxlongint) then
                        begin
                        if g[1,k]+g[k,r]<g[1,r] then
                                begin
                                g[1,r]:=g[1,k]+g[k,r];
                                if f[r]=false then
                                        begin
                                        dui[en]:=r;inc(en);f[r]:=true;
                                        end;
                                end;
                        end;
                end;
        end;
end;

procedure spfas;
var r,k,l,st,en:longint;
ha:array[0..1000] of boolean;
line:array[0..1000] of integer;
begin
line[1]:=1;st:=1;en:=2;
for r:=1 to n do
        begin
        for k:=1 to n do
                begin
                dis[r,k]:=maxlongint;dis[r,k]:=d[r,k];
                end;
        end;
dis[1,1]:=0;
fillchar(ha,sizeof(ha),false);ha[1]:=true;
while st<>en do
        begin
        k:=line[st];inc(st);ha[k]:=false;
        for r:=1 to n-1 do
                begin
                if(way[r,1]=k)or(way[r,2]=k)then
                        begin
                        if way[r,1]<>k then l:=way[r,1] else l:=way[r,2];
                        if dis[1,k]+dis[k,l]<dis[1,l] then
                                begin
                                dis[1,l]:=dis[1,k]+dis[k,l];
                                if ha[l]=false then
                                        begin
                                        line[en]:=l;inc(en);ha[l]:=true;
                                        end;
                                end;
                        end;
                end;
        end;
end;

function judge:boolean;
var r,k:longint;
begin
for r:=1 to n do
        begin
        if dis[1,r]<>g[1,r] then exit(false);
        end;
exit(true);
end;

procedure search(x,y,z:longint);
var r,k:longint;
begin
if y=n then
        begin
        if z=n-1 then
                begin
                spfas;
                if judge then inc(ans);
                end;
        end
else
        begin
        for r:=1 to son[x,0] do
                begin
                k:=son[x,r];
                if f[k]=false then
                        begin
                        f[k]:=true;way[z+1,1]:=x;way[z+1,2]:=k;
                        search(k,y+1,z+1);
                        f[k]:=false;
                        end;
                end;
        end;
end;

begin
assign(input,'Castle.in');reset(input);
assign(output,'Castle.out');rewrite(output);
readln(n,m);ans:=0;
for i:=1 to n do
        begin
        for p:=1 to n do
                begin
                g[i,p]:=maxlongint;d[i,p]:=maxlongint;
                end;
        end;
for i:=1 to m do
        begin
        readln(x,y,z);
        inc(son[x,0]);son[x,son[x,0]]:=y;
        inc(son[y,0]);son[y,son[y,0]]:=x;
        if z<g[x,y] then
                begin
                g[x,y]:=z;g[y,x]:=z;d[x,y]:=z;d[y,x]:=z;
                end;
        end;
spfa;
fillchar(f,sizeof(f),false);
f[1]:=true;
fillchar(way,sizeof(way),0);
search(1,1,0);
writeln(ans);
close(input);close(output);
end.
