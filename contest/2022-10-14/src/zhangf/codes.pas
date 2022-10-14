const
  inf = 'codes.in';
  ouf = 'codes.out';
  maxn = 20 + 1;
  maxL = 20 + 1;
  maxdl = maxn * maxL;

type
  point = ^pointer;
  pointer = record
    v:longint;
    next:point;
  end;

var
  i,j,k,n,m,p,q,open,closed,minlen:longint;
  f:array[0..maxn,0..maxL] of longint;
  fs:array[0..maxn,0..maxL] of ansistring;
  s:array[0..maxn] of ansistring;
  cs:array[0..maxn,0..maxL] of ansistring;
  len:array[0..maxn] of longint;
  ans,tmp,t:ansistring;
  z:array[0..maxn,0..maxL,0..maxL] of boolean;
  g:array[0..maxn,0..maxL,0..maxn] of boolean;
  map:array[0..maxn,0..maxL] of point;
  dl:array[0..maxn * maxL,1..2] of longint;
  indl:array[0..maxn,0..maxL] of boolean;
  u:point;
  flag:boolean;
  f1,f2:text;

procedure push(x,y:longint);
begin
  indl[x,y]:=true;
  open:=open + 1;
  if open > maxdl then open:=1;
  dl[open,1]:=x; dl[open,2]:=y;
end;

begin
  assign(f1,inf); reset(f1);
  assign(f2,ouf); rewrite(f2);

  readln(f1,n);
  for i:=1 to n do
    readln(f1,s[i]);
  close(f1);

  for i:=1 to n do
    for j:=i + 1 to n do
      if s[i] + s[j] > s[j] + s[i] then
        begin
          tmp:=s[i]; s[i]:=s[j]; s[j]:=tmp;
        end;
  for i:=1 to n do
    len[i]:=length(s[i]);
  for i:=1 to n do
    for j:=0 to len[i] do
      cs[i,j]:=copy(s[i],len[i] - j + 1,j);

  fillchar(g,sizeof(g),false);
  fillchar(z,sizeof(z),false);
  for i:=1 to n do
    for j:=1 to len[i] do
      begin
        map[i,j]:=nil;
        z[i,j,j]:=true;
        for k:=1 to n do
          begin
            if (i = k) and (j = len[i]) then continue;
            if len[k] < j then
              if copy(s[i],len[i] - j + 1,len[k]) = s[k] then
                z[i,j,j - len[k]]:=true;
            if len[k] >= j then
              if copy(s[k],1,j) = copy(s[i],len[i] - j + 1,j) then
                begin
                  g[i,j,k]:=true;
                  new(u);
                  u^.v:=k;
                  u^.next:=map[i,j];
                  map[i,j]:=u;
                end;
          end;
      end;

  closed:=0;
  open:=0;
  for i:=1 to n do
    for j:=0 to len[i] do
      begin
        f[i,j]:=maxlongint div 2;
        fs[i,j]:='F';
      end;
  fillchar(indl,sizeof(indl),false);
  for i:=1 to n do
    begin
      f[i,len[i]]:=len[i];
      fs[i,len[i]]:=s[i];
      push(i,len[i]);
    end;
  while closed <> open do
    begin
      inc(closed);
      if closed > maxdl then closed:=1;
      p:=dl[closed,1]; q:=dl[closed,2];
      indl[p,q]:=false;
      for i:=q downto 1 do
        if z[p,q,i] then
          begin
            u:=map[p,i];
            while u <> nil do
              begin
                k:=len[u^.v] - i;
                flag:=false;
                if f[p,q] + k < f[u^.v,k] then flag:=true;
                if (not flag) and (f[p,q] + k = f[u^.v,k]) then
                  if (fs[p,q] + cs[u^.v,k] < fs[u^.v,k]) then
                    flag:=true;
                if flag then
                  begin
                    f[u^.v,k]:=f[p,q] + k;
                    fs[u^.v,k]:=fs[p,q] + cs[u^.v,k];
                    if not indl[u^.v,k] then
                      push(u^.v,k);
                  end;
                u:=u^.next;
              end;
          end;
    end;

  minlen:=maxlongint div 2;
  ans:='F';
  for i:=1 to n do
    begin
      if (f[i,0] < minlen) or ((f[i,0] = minlen) and (fs[i,0] < ans)) then
        begin
          minlen:=f[i,0];
          ans:=fs[i,0];
        end;
    end;
  writeln(f2,minlen);
  writeln(f2,ans);
  close(f2);
end.
