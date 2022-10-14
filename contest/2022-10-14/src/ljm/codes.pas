program codes;
type
  point=^rec;
  rec=record
      st:ansistring;
      next:point;
      end;
const
  p=99997;
  pr=3521;
var
  fin,fout:text;
  i,j,k,n,ansl,l,m:longint;
  a,b:array[0..401]of point;
  st:array[0..21]of ansistring;
  hash:array[0..p]of point;
  s,t,ans:ansistring;
  u,v:point;
  first:boolean;
procedure ins(l:longint; s:ansistring);
var
  q:point;
  ii,jj:longint;
begin
  q:=hash[l];
  while q<>nil do
  begin
    if q^.st=s then
    begin
      ansl:=length(s);
      if not first then
      begin
        ans:=q^.st;
        first:=true;
      end
      else
        if q^.st<ans then ans:=q^.st;
    end;
    q:=q^.next;
  end;
  new(q);
  q^.st:=s; q^.next:=hash[l]; hash[l]:=q;
  jj:=length(s);
  new(q);
  q^.st:=s; q^.next:=b[jj]; b[jj]:=q;
end;

{function sm(s1,s2:ansistring):boolean;
var
  l:longint;
begin
  if length(s1)<length(s2) then exit(true);
  if length(s2)<length(s1) then exit(false);
  for l:=1 to length(s1) do
    if s1[l]<s2[l] then exit(true)
    else
      if s1[l]>s2[l] then exit(false);
  exit(false);
end;        }

begin
  assign(fin,'codes.in');reset(fin);
  assign(fout,'codes.out');rewrite(fout);
  readln(fin,n);
  for i:=1 to n do readln(fin,st[i]);
{  for i:=1 to n-1 do
  begin
    k:=i;
    for j:=i+1 to n do
      if sm(st[k],st[j]) then k:=j;
    t:=st[i]; st[i]:=st[k]; st[k]:=t;
  end;      }
  for i:=1 to n do
  begin
    s:=st[i];
    new(u);
    j:=length(s);
    u^.st:=s; u^.next:=a[j]; a[j]:=u;
    new(u);
    u^.st:=s; u^.next:=b[j]; b[j]:=u;
    new(u);  l:=0;
    for k:=1 to j do
      l:=(l*pr+ord(s[k])-40) mod p;
    u^.st:=s; u^.next:=hash[l]; hash[l]:=u;
  end;
  i:=1;
  while true do
  begin
    first:=false;
    for j:=1 to 20 do
      if j<=i then
      begin
        u:=a[j]; k:=i-j;
        while u<>nil do
        begin
          v:=b[k];
          while v<>nil do
          begin
            s:=v^.st+u^.st;
            l:=0;
            for m:=1 to length(s) do
              l:=(l*pr+ord(s[m])-40) mod p;
            ins(l,s);
            v:=v^.next;
          end;
          u:=u^.next;
        end;
      end
      else break;
    if first then
    begin
      writeln(fout,ansl);
      writeln(fout,ans);
      close(fin);close(fout);
      halt;
    end;
    inc(i);
  end;
end.
