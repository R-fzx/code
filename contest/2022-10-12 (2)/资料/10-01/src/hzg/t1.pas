program t1;
var i,p,n,shu,ha,st,en:longint;ans:int64;
a,father,dui:array[0..1010] of longint;
son:array[0..1000,0..1000] of integer;
f:array[0..1010] of boolean;

procedure search(y:longint);
var r,k,l,w,x:longint;
begin
if y>=n then
        begin
        inc(ans);exit;
        end
else
        begin
        x:=dui[st];
        for r:=1 to son[x,0] do
                begin
                k:=son[x,r];
                if f[k]=false then
                        begin
                        dui[en]:=k;inc(en);f[k]:=true;
                        end;
                end;
        for r:=0 to n do
                begin
                if a[r]=father[x] then break;
                end;
        for l:=r+1 to n do
                begin
                if a[l]=0 then
                        begin
                        a[l]:=x;inc(st);
                        search(y+1);a[l]:=0;dec(st);
                        end;
                end;
        end;
end;

begin
assign(input,'t1.in');reset(input);
assign(output,'t1.out');rewrite(output);
readln(shu);
for ha:=1 to shu do
        begin
        readln(n);
        for i:=1 to n do
                begin
                read(son[i,0]);
                for p:=1 to son[i,0] do
                        begin
                        read(son[i,p]);
                        if p>=2 then father[son[i,p]]:=son[i,p-1]
                        else father[son[i,p]]:=i;
                        end;
                readln;
                end;
        ans:=0;father[1]:=0;
        fillchar(a,sizeof(a),0);fillchar(f,sizeof(f),false);
        dui[1]:=1;st:=1;en:=2;f[1]:=true;
        search(0);
        writeln(ans);
        end;
close(input);close(output);
end.




















