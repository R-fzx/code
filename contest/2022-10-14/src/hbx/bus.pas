var i,j,k,n:longint;
    p,ans:qword;
    fa,fb:text;
begin
  assign(fa,'bus.in');
  assign(fb,'bus.out');
  reset(fa);
  rewrite(fb);
    readln(fa,n);
    p:=maxlongint;
    ans:=0;
    k:=0;
    for i:=1 to n do
       begin
          read(fa,k);
          if k<p then
              begin
               ans:=ans+k;
               p:=k;
              end
           else
              ans:=ans+p;
       end;
    writeln(fb,ans);
  close(fa);
  close(fb);
end.