{$m 64000000}
program ex_1;
var i,j,k,n,m,l,h,t,ans:longint;
    f:array[0..20,0..20] of longint;
    ip,op:text;
    g:array[0..20] of string;
    v:array[0..20,0..20,0..20] of boolean;
    q1,q2,q3,q4,q5:array[0..500000] of longint;
    s,sa:ansistring;
procedure dfs(x,y:longint);
var i,j,k:longint;
begin
  if x=0 then exit;
  k:=q4[x];
  s:=copy(g[q1[x]],1,y)+s;
  if k=0 then exit else
    if q5[x]=1 then dfs(k,length(g[q1[k]])-q2[k]) else
      dfs(k,0);
end;
begin
  assign(ip,'codes.in');
  reset(ip);
  assign(op,'codes.out');
  rewrite(op);
  readln(ip,n);
  for i:=1 to n do readln(ip,g[i]);
  for i:=1 to n do
    for j:=1 to length(g[i]) do
      for k:=1 to n do begin
        v[i,j,k]:=true;
        if j>=length(g[k]) then
          if copy(g[i],length(g[i])-j+1,length(g[k]) )
            <>g[k] then v[i,j,k]:=false
          else
        else
          if copy(g[i],length(g[i])-j+1,j)
            <>copy(g[k],1,j) then v[i,j,k]:=false;
      end;
  fillchar(f,sizeof(f),$7f);
  for i:=1 to n do begin
    inc(t);
    q1[t]:=i;
    q2[t]:=length(g[i]);
    q3[t]:=length(g[i]);
    f[q1[t],q2[t]]:=q3[t];
  end;
  ans:=maxlongint div 2;
  repeat
    inc(h);
    if f[q1[h],q2[h]]<>q3[h] then continue;
    if q3[h]>ans then continue;
    for i:=1 to n do
      if (i<>h) then
      if v[q1[h],q2[h],i] then
        if length(g[i])>q2[h] then begin
          inc(t);
          q1[t]:=i;
          q2[t]:=length(g[i])-q2[h];
          q3[t]:=q3[h]+q2[t];
          q4[t]:=h;
          q5[t]:=1;
          if f[q1[t],q2[t]]>q3[t] then f[q1[t],q2[t]]:=q3[t] else
            dec(t);
        end else
          if length(g[i])<q2[h] then begin
            inc(t);
            q1[t]:=q1[h];
            q2[t]:=q2[h]-length(g[i]);
            q3[t]:=q3[h];
            q4[t]:=h;
            if f[q1[t],q2[t]]>q3[t] then f[q1[t],q2[t]]:=q3[t] else
              dec(t);
          end else
            if q3[h]<=ans then begin
              s:='';
              dfs(h,length(g[q1[h]]));
              if q3[h]<ans then begin
               ans:=q3[h];
               sa:=s;
              end else
                if s<sa then sa:=s;
            end;
  until h>=t;
  writeln(op,ans);
  writeln(op,sa);
  close(ip);
  close(op);
end.
