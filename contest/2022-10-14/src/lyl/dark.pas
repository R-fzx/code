var i,j,n,m,a,b,c,d:longint;
    x,y:array[0..200000] of double;
    min,k:extended;
begin
  assign(input,'dark.in');
  assign(output,'dark.out');
  reset(input);
  rewrite(output);

  readln(n);
  min:=1e100;
  for i:=1 to n do
   begin
     readln(x[i],y[i]);
     for j:=i-1 downto 1 do
       begin
        k:=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        if k<min then
            min:=k;
       end;
   end;
  writeln(min:0:2);

  close(input);
  close(output);
end.
