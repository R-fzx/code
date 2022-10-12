program t2;
var i,p,num,ans,anss:longint;a,b:int64;boo:boolean;

procedure judge(x:longint;y:int64);
var r,k,l:longint;
begin
boo:=false;num:=0;
while y mod x=0 do
        begin
        inc(num);y:=y div x;
        end;
if y=1 then boo:=true;
end;


begin
assign(input,'t2.in');reset(input);
assign(output,'t2.out');rewrite(output);
readln(a,b);
while (a<>0)or(b<>0) do
        begin
        ans:=0;
        while a<=b do
                begin
                anss:=ans;
                for i:=2 to trunc(sqrt(a)) do
                        begin
                        judge(i,a);
                        if boo=true then
                                begin
                                inc(ans,num);break;
                                end;
                        end;
                if ans=anss then inc(ans);
                inc(a);
                end;
        writeln(ans);
        readln(a,b);
        end;
close(input);close(output);
end.







































