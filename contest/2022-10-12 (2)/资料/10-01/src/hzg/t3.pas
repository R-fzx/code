 program t3;
 var i,p,n,r,ans:longint;
 f:array[0..200,0..200] of boolean;
 g:array[0..200] of boolean;

 procedure search(x:longint);
 var r,k:longint;
 begin
 if x=n+1 then inc(ans)
 else
        begin
        for r:=1 to n do
                begin
                if (g[r]=true)and(f[x,r]=true)then
                        begin
                        g[r]:=false;;search(x+1);g[r]:=true;
                        end;
                end;
        end;
 end;

 begin
 assign(input,'t3.in');reset(input);
 assign(output,'t3.out');rewrite(output);
 readln(n);ans:=0;
 fillchar(f,sizeof(f),true);
 for i:=1 to n do
        begin
        for p:=1 to n do
                begin
                read(r);
                if r=1 then f[i,p]:=false;
                end;
        end;
 for i:=1 to n do
        begin
        if f[1,i]=true then
                begin
                fillchar(g,sizeof(g),true);
                g[i]:=false;
                search(2);
                end;
        end;
 writeln(ans);
 close(input);close(output);
 end.
