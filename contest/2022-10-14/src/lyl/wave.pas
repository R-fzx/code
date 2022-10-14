var
  f:array[1..20,1..20,0..1]of int64;{0 Ao 1 Tu}
  n,m,i,j,t,p,x:longint;
  k:int64;
  a:array[1..20]of boolean;

function get(k:longint):longint;
var
  i,j:longint;
begin
  j:=0;
  for i:=1 to n do
   begin
    if not a[i] then inc(j);
    if j=k then exit(i);
   end;
end;



begin
  assign(input,'wave.in');reset(input);
  assign(output,'wave.out');rewrite(output);
  fillchar(f,sizeof(F),0);
  f[1,1,0]:=1;f[1,1,1]:=1;
  for i:=2 to 20 do
   for j:=1 to i do
    begin
      for p:=1 to j-1 do
       f[i,j,1]:=f[i,j,1]+f[i-1,p,0];
      for p:=j to i do
       f[i,j,0]:=f[i,j,0]+f[i-1,p,1];
    end;
  readln(m);
  for t:=1 to m do
   begin
     readln(n,k);
     fillchar(a,sizeof(a),0);
     p:=-1;
     x:=-1;
     for i:=n downto 1 do
      begin
        for j:=1 to i do
         begin
          if (p<>1)and(  (x=-1)or(j>=x) ) then
           begin
             if f[i,j,1]<k then k:=k-f[i,j,1] else
             begin
               x:=get(j);
               a[x]:=true;
               if p=-1 then write(x) else write(' ',x);
               x:=j;
               p:=1;
               break;
             end;
           end;{if}
          if (p<>0)and(  (x=-1)or(j<x) ) then
           begin
             if f[i,j,0]<k then k:=k-f[i,j,0] else
              begin
                x:=get(j);
                a[x]:=true;
                if p=-1 then write(x) else write(' ',x);
                p:=0;
                x:=j;
                break;
              end;
           end;{if}

         end;{j}

      end;{i}
     writeln;
   end;{t}
  close(input);
  close(output);

end.
