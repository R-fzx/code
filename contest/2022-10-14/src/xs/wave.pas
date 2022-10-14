var
  i,j,k,n,t,v:longint;
  now,c:int64;
  w,m:array[1..20,1..20]of int64;
  a:array[1..20]of longint;
  b:array[1..20]of boolean;
  fin,fout:text;
function get(t:longint):longint;
var
  i,g:longint;
begin
  g:=0;
  for i:=1 to 20 do
    if b[i] then
      begin
        inc(g);
        if g=t then
          begin
            b[i]:=false;
            get:=i;
            exit;
          end;
      end;
end;
begin
  m[1,1]:=1;
  w[1,1]:=1;
  for i:=2 to 20 do
    for j:=1 to i do
      begin
        for k:=1 to j-1 do
          inc(w[i,j],m[i-1,k]);
        for k:=j to i-1 do
          inc(m[i,j],w[i-1,k]);
      end;
  assign(fin,'wave.in');
  reset(fin);
  assign(fout,'wave.out');
  rewrite(fout);
  readln(fin,v);
  while not seekeof(fin) do
    begin
      readln(fin,n,c);
      fillchar(a,sizeof(a),0);
      now:=1;
      a[1]:=1;
      fillchar(b,sizeof(b),true);
      for i:=1 to n-1 do
        if w[n,i]+m[n,i]+now>c then
          break
        else
          begin
            inc(a[1]);
            inc(now,w[n,i]+m[n,i]);
          end;
      b[a[1]]:=false;
      if n>=2 then
        begin
          a[2]:=1;
          for i:=1 to n-2 do
            begin

    //    if i=a[1] then inc(a[2]);
            if i<a[1] then
              if m[n-1,i]+now>c then
                break
              else
                begin
                  inc(now,m[n-1,i]);
                  inc(a[2]);
                end
            else
              if w[n-1,i]+now>c then
                break
              else
                begin
                  inc(now,w[n-1,i]);
                  inc(a[2]);
                end;
          end;
          a[2]:=get(a[2]);
        end;
      for i:=3 to n do
        begin
          t:=0;
          for j:=1 to a[i-1] do
            if b[j] then
              inc(t);
          if a[i-1]>a[i-2] then
            begin
              a[i]:=1;
              for j:=1 to t-1 do
                if now+m[n-i+1,j]>c then
                  break
                else
                  begin
                    inc(now,m[n-i+1,j]);
                    inc(a[i]);
                  end;
            end
          else
            begin
              a[i]:=t+1;
              for j:=t+1 to n-i do
                if now+w[n-i+1,j]>c then
                  break
                else
                  begin
                    inc(now,w[n-i+1,j]);
                    inc(a[i]);
                  end;
            end;
          a[i]:=get(a[i]);
        end;
      for i:=1 to n-1 do
        write(fout,a[i],' ');
      writeln(fout,a[n]);
    end;
  close(fin);
  close(fout);
end.
