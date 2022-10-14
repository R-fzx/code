var
  inp,outp:text;
  i,j,n,k,m,p,t,o,x,y:longint;
  f:array[0..20,0..20,0..1] of int64;
  used:array[1..20] of boolean;
  c:int64;

function get(d:longint):longint;
var
  i,j:longint;
begin
  j:=0;
  for i:=1 to n do
    begin
     if not used[i] then inc(j);
     if j=d then exit(i);
    end;
end;


begin
  assign(inp,'wave.in');reset(inp);
  assign(outp,'wave.out');rewrite(outp);
  f[1,1,0]:=1;f[1,1,1]:=1;
  for i:=2 to 20 do
   for j:=1 to i do
    begin
      for k:=j to i-1 do
       f[i,j,0]:=f[i,j,0]+f[i-1,k,1];
      for k:=1 to j-1 do
       f[i,j,1]:=f[i,j,1]+f[i-1,k,0];
    end;
  readln(inp,m);
  for o:=1 to m do
    begin
      readln(inp,n,c);
      fillchar(used,sizeof(used),0);
      p:=-1;y:=-1;
      for i:=n downto 1 do
       for j:=1 to i do
         begin
           if (p<>1) and ((y=-1)or(j>=y))then
            if f[i,j,1]<c then c:=c-f[i,j,1]
             else
               begin
                 x:=get(j);
                 used[x]:=true;
                 if p=-1 then write(outp,x) else write(outp,' ',x);
                 y:=j;
                 p:=1;
                 break;
               end;
           if (p<>0) and ((y=-1)or(j<y))then
            if f[i,j,0]<c then c:=c-f[i,j,0]
             else
               begin
                 x:=get(j);
                 used[x]:=true;
                 if p=-1 then write(outp,x) else write(outp,' ',x);
                 y:=j;
                 p:=0;
                 break;
               end;
         end;
      writeln(outp);
    end;
  close(inp);close(outp);
end.
