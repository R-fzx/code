{
bus
pj
11.9
}

var
  fin,fout:text;
  n,i,j,j2,k,i2,min,max:longint;
  a:array[1..100000]of longint;
  ans:double;

procedure init;
begin
assign(fin,'bus.in');reset(fin);
 readln(fin,n);
 for i:=1 to n do read(fin,a[i]);
 i:=0;
close(fin);
end;

procedure main;
begin
 k:=1;
 min:=a[k];
 max:=a[k];

 while i<n do
  begin

   for j:=k to n do
    if a[j]<=min then
     begin
      min:=a[j];
      i:=j;
      ans:=ans+(i-k)*a[k];
      k:=i;
     end;

   max:=a[k];
   for j2:=k to n do
    if a[j2]>max then
     begin
      i2:=j2;
      if i2=n then
       begin
        ans:=ans+(i2-k)*a[k];
        i:=i2;
        break;
       end;
     end;

   if i=n then ans:=ans+a[k];

  end;//end while

end;

procedure print;
begin
assign(fout,'bus.out');rewrite(fout);
 writeln(fout,ans:0:0);
close(fout);
end;

begin
 init;
 main;
 print;
end.
