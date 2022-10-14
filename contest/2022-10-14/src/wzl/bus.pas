var sum:int64;
    n,a,min,i:longint;
    fi,fo:text;
begin
  assign(fi,'bus.in');reset(fi);
    readln(fi,n);
    read(fi,a);
    min:=a;
    sum:=int64(sum)+min;
    for i:=2 to n do begin
      read(fi,a);
      if a<min then min:=a;
      sum:=int64(sum)+min;
    end;
  close(fi);
  assign(fo,'bus.out');rewrite(fo);
    writeln(fo,int64(sum));
  close(fo);
end.
