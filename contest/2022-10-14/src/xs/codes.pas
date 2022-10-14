type
  w=record
      s:string;
      length:longint;
    end;
var
  a:array[0..20]of string;
  f:array[1..20,1..20,1..20,1..20]of w;
  b:array[1..20,1..21]of boolean;
  g:array[1..20,1..21]of w;
  i,j,k,l,m,n,mini,minj:longint;
  min:w;
  s1,s2,ans:string;
  fin,fout:text;
begin
  assign(fin,'codes.in');
  reset(fin);
  readln(fin,n);
  for i:=1 to n do
    readln(fin,a[i]);
  close(fin);
  for i:=1 to n do
    for j:=1 to length(a[i]) do
      for k:=1 to n do
        for l:=1 to length(a[k])+1 do
          with f[i,j,k,l] do
            begin
              length:=3000;
            end;
  for i:=1 to n do
    for j:=1 to length(a[i]) do
      for k:=1 to n do
        begin
          s1:=copy(a[i],j,length(a[i])-j+1);
          s2:=a[k];
          if s1=s2 then
            begin
              if i=k then continue;
              f[i,j,k,length(s2)+1].length:=0;
              f[i,j,k,length(s2)+1].s:='';
              continue;
            end;
          if pos(s1,s2)=1 then
            begin
              delete(s2,1,length(s1));
              f[i,j,k,length(s1)+1].length:=length(s2);
              f[i,j,k,length(s1)+1].s:=s2;
              continue;
            end;
          if pos(s2,s1)=1 then
            begin
              delete(s1,1,length(s2));
              f[i,j,i,length(s2)+j].length:=0;
              f[i,j,i,length(s2)+j].s:='';
            end;
        end;
  fillchar(b,sizeof(b),true);
  for i:=1 to n do
    for j:=2 to length(a[i])+1 do
      g[i,j].length:=3000;
  for i:=1 to n do
    begin
      g[i,1].length:=length(a[i]);
      g[i,1].s:=a[i];
    end;
  repeat
    min.length:=2999;
    for i:=1 to n do
      for j:=1 to length(a[i])+1 do
        if b[i,j] then
          if (min.length>g[i,j].length)or(min.length=g[i,j].length)and(min.s>g[i,j].s) then
            begin
              mini:=i;
              minj:=j;
              min:=g[i,j];
            end;
    if minj=length(a[mini])+1 then
      begin
        ans:=min.s;
        break;
      end;
    b[mini,minj]:=false;
    for i:=1 to n do
      for j:=1 to length(a[i])+1 do
        if b[i,j] then
          if (min.length+f[mini,minj,i,j].length<g[i,j].length)or(min.length+f[mini,minj,i,j].length=g[i,j].length)and(min.s+f[mini,minj,i,j].s<g[i,j].s) then
            begin
              g[i,j].length:=min.length+f[mini,minj,i,j].length;
              g[i,j].s:=min.s+f[mini,minj,i,j].s;
            end;
  until false;
  assign(fout,'codes.out');
  rewrite(fout);
  writeln(fout,length(ans));
  writeln(fout,ans);
  close(fout);
end.
