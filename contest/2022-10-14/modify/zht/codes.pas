var
  inp,outp:text;
  n,m,i,j,k,l,long:longint;
  a,ans:array[1..20] of string;
  len:array[1..20] of longint;
  h:array[1..1000] of boolean;
  s,q:string;

function calc(x:string):longint;
var
  i,j,ss:longint;
  s:string;
begin
  s:='';ss:=0;
  for i:=1 to length(x) do
    if x[i]='0' then s:=s+'1' else s:=s+'2';
  for i:=1 to length(s) do
    begin
      val(s[i],j);
      inc(ss,j*i);
    end;
  exit(ss);
end;

function check(p:longint):boolean;
var
  i,j:longint;
  st:string;
begin
  if p>length(s) then exit(true);
  for i:=p to length(s)+1 do
    begin
      st:=copy(s,p,i-p+1);
      if h[calc(st)] then check(i+1);
    end;
  if i>length(s) then exit(false);
end;

procedure dfs(len:longint);
var
   i,j,k:longint;
   q:string;
begin
   if len>long then
     begin
       if check(1) then
         begin
           writeln(outp,length(s));
           writeln(outp,s);
           close(inp);close(outp);
           halt;
         end;
       exit;
     end;
   for i:=0 to 1 do
    begin
     str(i,q);
     s:=s+q;
     dfs(len+1);
     delete(s,length(s),1);
    end;
end;


begin
  assign(inp,'codes.in');reset(inp);
  assign(outp,'codes.out');rewrite(outp);
  readln(inp,n);
  fillchar(h,sizeof(h),false);
  for i:=1 to n do
    begin
      readln(inp,a[i]);
      while pos(' ',a[i])<>0 do delete(a[i],pos(' ',a[i]),1);
      len[i]:=length(a[i]);
      h[calc(a[i])]:=true;
    end;
  long:=0;
  while true do
    begin
      inc(long);
      s:='';
      dfs(1);
    end;

end.
