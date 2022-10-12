program t1;
type
re1=record
num,data:longint;
end;
re2=record
nam,data:longint;
end;
var i,p,n,na,t:longint;
num:array[0..3] of longint;
a,b,c:array[0..500000] of longint;
cool:array[0..3,0..500000] of re2;
g:array[0..500000] of boolean;
ha:array[0..3] of re1;

procedure sort(z,x,y:longint);
var le,ri,mid:longint;
begin
le:=x;ri:=y;mid:=cool[z,(x+y) div 2].data;
while le<=ri do
        begin
        while cool[z,le].data<mid do inc(le);
        while cool[z,ri].data>mid do dec(ri);
        if le<=ri then
                begin
                na:=cool[z,le].nam;t:=cool[z,le].data;
                cool[z,le].nam:=cool[z,ri].nam;
                cool[z,le].data:=cool[z,ri].data;
                cool[z,ri].nam:=na;cool[z,ri].data:=t;
                inc(le);dec(ri);
                end;
        end;
if le<y then sort(z,le,y);
if ri>x then sort(z,x,ri);
end;

procedure find;
var r,k,l,shu:longint;ans,anss:int64;
begin
fillchar(g,sizeof(g),false);ans:=0;anss:=0;
for r:=1 to 3 do
        begin
        k:=ha[r].num;shu:=ha[r].data;l:=n;
        while shu>0 do
                begin
                if g[cool[k,l].nam]=false then
                        begin
                        g[cool[k,l].nam]:=true;inc(ans,cool[k,l].data);
                        inc(anss,a[cool[k,l].nam]);inc(anss,b[cool[k,l].nam]);inc(anss,c[cool[k,l].nam]);
                        dec(l);dec(shu);
                        end
                else dec(l);
                end;
        end;
writeln(ans);writeln(anss);
end;

begin
assign(input,'ゆりっぺ.in');reset(input);
assign(output,'ゆりっぺ.out');rewrite(output);
read(n);
for i:=1 to 3 do
        begin
        ha[i].num:=i;read(ha[i].data);
        end;
readln;
for i:=1 to n do readln(a[i],b[i],c[i]);
if n<ha[1].data+ha[2].data+ha[3].data then writeln('I am a godlike cowcowcow')
else
        begin
        for i:=1 to 2 do
                begin
                for p:=i+1 to 3 do
                        begin
                        if ha[p].data<ha[i].data then
                                begin
                                na:=ha[i].num;t:=ha[i].data;
                                ha[i].num:=ha[p].num;ha[i].data:=ha[p].data;ha[p].num:=na;ha[p].data:=t;
                                end;
                        end;
                end;
        for i:=1 to 3 do
                begin
                for p:=1 to n do
                        begin
                        cool[i,p].nam:=p;
                        if i=1 then cool[i,p].data:=a[p]
                        else
                        if i=2 then cool[i,p].data:=b[p]
                        else cool[i,p].data:=c[p];
                        end;
                end;
        for i:=1 to 3 do sort(i,1,n);
        find;
        end;
close(input);close(output);
end.
