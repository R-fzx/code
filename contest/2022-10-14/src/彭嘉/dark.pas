{
dark
pj
11.9
}

var
  fin,fout:text;
  n,i,j:longint;
  x,y,hash:array[0..199999]of longint;
  ans,t:double;

begin
assign(fin,'dark.in');reset(fin);
assign(fout,'dark.out');rewrite(fout);

 readln(fin,n);//do behind begin
 for i:=0 to n-1 do hash[i]:=-500000;
 ans:=500000;
 for i:=0 to n-1 do
  begin
   read(fin,x[i],y[i]);
   if hash[x[i]]=(x[i]+y[i]) then
    begin
     writeln(fout,'0.00');
     close(fout);
     exit;
    end
    else
     hash[x[i]]:=x[i]+y[i];
  end;

  for i:=0 to n-2 do //solve
   for j:=i+1 to n-1 do
    begin
     t:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
     if t<ans then
      ans:=t;
    end;

  writeln(fout,ans/2:0:2);//output

close(fin);close(fout);
end.
