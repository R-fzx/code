program wave;
var
  fin,fout:text;
  m,n,c,i,t:longint;
  used:array[0..20]of boolean;
  a:array[0..20]of integer;
  yes:boolean;
procedure search(x:longint);
var
  j:longint;
  ok:boolean;
begin
  if x=n+1 then
    begin
      inc(t);
      if t=c then
        begin
          for j:=1 to n do
            write(fout,a[j],' ');
          yes:=true;
        end;
    end
    else
      begin
        yes:=false;
        for j:=1 to n do
          if used[j] then
            begin
              ok:=true;
              if x>=3 then
                if((j>a[x-1])and(a[x-1]>a[x-2]))or((j<a[x-1])and(a[x-1]<a[x-2]))then
                  ok:=false;
              if ok then
                begin
                  a[x]:=j;
                  used[j]:=false;
                  search(x+1);
                  used[j]:=true;
                end;
              if yes then break;
            end;
        if yes then exit;
      end;
end;
begin
  assign(fin,'wave.in'); reset(fin);
  assign(fout,'wave.out'); rewrite(fout);
  readln(fin,m);
  for i:=1 to m do
    begin
      readln(fin,n,c);
      fillchar(used,sizeof(used),true);
      t:=0;
      search(1);
      writeln(fout);
    end;
  close(fin); close(fout);
end.
