var
  n,i,j,k:longint;
  x,y:array[1..200000]of longint;
  ans:double;
begin
  assign(input,'dark.in');reset(input);
  assign(output,'dark.out');rewrite(output);
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  ans:=1e15;
  for i:=1 to n-1 do
   for j:=i+1 to n do
     if sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))<ans then
       ans:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
  writeln(ans:0:2);
  close(input);
  close(output);
end.