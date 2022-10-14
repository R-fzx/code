var
  a:array[0..200000]of longint;
  ans:int64;
  i,j,k,n:longint;
begin
  assign(input,'bus.in');reset(input);
  assign(output,'bus.out');rewrite(output);
  readln(n);
  for i:=1 to n do
   read(a[i]);
  readln;
  close(input);

  ans:=a[1];
  i:=1;
  while i<n do
   begin
     j:=i+1;
     while (j<=n)and(a[j]>=a[i]) do
      begin
        ans:=ans+a[i];
        inc(j);
      end;
     i:=j;
     if i<=n then ans:=ans+a[i];
   end;
  writeln(ans);
  close(output);

end.
