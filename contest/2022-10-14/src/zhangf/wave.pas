const
  inf = 'wave.in';
  ouf = 'wave.out';
  maxn = 20 + 1;

var
  i,j,k,n,m,p,q,Test,st,ed:longint;
  f:array[0..maxn,0..maxn,0..1] of int64;
  wr,d,tmp:array[0..maxn] of longint;
  b:array[0..maxn] of boolean;
  c,ans,now:int64;
  f1,f2:text;

begin
  assign(f1,inf); reset(f1);
  assign(f2,ouf); rewrite(f2);

  readln(f1,Test);
  while Test > 0 do
    begin
      readln(f1,n,c);

      if n = 1 then
        begin
          writeln(f2,1);
          continue;
        end;

      fillchar(f,sizeof(f),0);
      f[n,1,0]:=1;
      f[n,1,1]:=1;
      f[n - 1,1,0]:=1;
      f[n - 1,2,1]:=1;
      for i:=n - 2 downto 1 do
        for p:=1 to n - i do
          begin
            // k = 0
            for j:=1 to p do
              if j <> n - i + 1 then
              f[i,j,0]:=f[i,j,0] + f[i + 1,p,1];
            // k = 1
            for j:=p + 1 to n - i + 1 do
              if j <> 1 then
              f[i,j,1]:=f[i,j,1] + f[i + 1,p,0];
          end;

      fillchar(b,sizeof(b),false);
      fillchar(d,sizeof(d),0);
      now:=c;
      for i:=1 to n do
        begin
          if now - f[1,i,1] <= 0 then
            begin
              d[1]:=i;
              b[i]:=true;
              p:=1;
              break;
            end;
          now:=now - f[1,i,1];
          if now - f[1,i,0] <= 0 then
            begin
              d[1]:=i;
              b[i]:=true;
              p:=0;
              break;
            end;
          now:=now - f[1,i,0];
        end;
      tmp[1]:=d[1];
      for i:=2 to n do
        begin
          p:=1 - p;
          if p = 0 then
            begin
              st:=1;
              ed:=tmp[i - 1] - 1;
            end
          else
            begin
              st:=tmp[i - 1];
              ed:=n - i + 1;
            end;

          for j:=st to ed do
            begin
              if now - f[i,j,p] <= 0 then begin k:=j; break; end;
              now:=now - f[i,j,p];
            end;
          tmp[i]:=k;
          for j:=1 to n do
            begin
              if not b[j] then dec(k);
              if k = 0 then
                begin
                  d[i]:=j;
                  b[j]:=true;
                  k:=-1;
                end;
            end;
        end;

      for i:=1 to n - 1 do
        write(f2,d[i],' ');
      writeln(f2,d[n]);

      dec(Test);
    end;

  close(f1);
  close(f2);
end.
