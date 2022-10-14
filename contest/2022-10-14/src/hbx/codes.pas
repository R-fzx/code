var fa,fb:text;
    f:array[1..20,0..20]of longint;
    g:array[1..20,1..20,0..25]of boolean;
    i,j,k,n,m,p,q,l,r,ans:longint;
    s:array[1..20]of string;
    len:array[1..20]of longint;
    d:array[1..400000,1..2]of longint;
    used:array[1..20,1..20]of boolean;
    b:array[1..20,1..20,1..2]of longint;
    st,s1:ansistring;
begin
  assign(fa,'codes.in');
  reset(fb);
  assign(fa,'codes.out');
  rewrite(fb);
  readln(fa,n);
    if n<=13 then
    begin
     for i:=1 to n do
        begin
          readln(fa,s[i]);
          len[i]:=length(s[i]);
        end;
  for i:=1 to n do
   for j:=1 to n do
    for k:=1 to len[i] do
     begin
       p:=k;
       g[i,j,k]:=true;
       while true do
        begin
          if s[i,p]<>s[j,p-k+1] then
           begin
            g[i,j,k]:=false;
            break;
           end;
          inc(p);
          if (p>len[i]) or (p-k+1>len[j]) then break;
        end;

     end;
  fillchar(f,sizeof(F),255);
  l:=1;r:=0;
  for i:=1 to n do
   for j:=i+1 to n do
    if g[i,j,1] then
     begin
       inc(r);
       if len[i]>len[j] then
        begin
         p:=i;
         q:=j;
        end else
        begin
         p:=j;
         q:=i;
        end;
       d[r,1]:=p;
       d[r,2]:=len[q];
       f[p,len[q] ]:=len[q];
       used[p,len[q] ]:=true;
     end;
  while l<=r do
   begin
     i:=d[l,1];
     k:=d[l,2];
     if k=len[i] then
      begin
       inc(l);
       continue;
      end;
     for j:=1 to n do
      if g[i,j,k+1] then
       begin
         if k+len[j]<=len[i] then
          begin
            if (f[i,k+len[j] ]>f[i,k]+len[j])or(f[i,k+len[j] ]=-1) then
             begin
               f[i,k+len[j]]:=f[i,k]+len[j];
               b[i,k+len[j],1]:=i;
               b[i,k+len[j],2]:=k;
               if not used[i,k+len[j]] then
                begin
                  inc(r);
                  d[r,1]:=i;
                  d[r,2]:=k+len[j];
             end;
          end else
          begin
            if (f[j,len[i]-k ]>f[i,k]-k+len[i])or(f[j,len[i]-k]=-1) then
             begin
               f[j,len[i]-k ]:=f[i,k]-k+len[i];
               b[j,len[i]-k ,1]:=i;
               b[j,len[i]-k ,2]:=k;
               if not used[j,len[i]-k ] then
                begin
                  inc(r);
                  d[r,1]:=j;
                  d[r,2]:=len[i]-k;
                end;

             end;
          end;

       end;
     used[i,k]:=false;
     inc(l);
   end;
  ans:=-1;
  s1:='';
  for i:=1 to n do
   if (f[i,len[i]]>0) and ((f[i,len[i]]<=ans)or(ans=-1)) then
    begin
      if f[i,len[i] ]<ans then s1:='';
      ans:=f[i, len[i] ];
      st:='';
      p:=i;q:=len[i];
      while true do
       begin
         j:=b[p,q,1];k:=b[p,q,2];
         if j=p then
          begin
            if k=q-1 then st:=copy(s[p],q,len[p]-q+1)+st else
            st:=copy( s[p],k+1,q-k )+st;
          end else
          st:=copy( s[p],1,q )+st;

         p:=b[p,q,1];q:=b[p,q,2];

         if p=0 then break;
       end;
      if (s1='') or (st<s1)  then s1:=st;
    end;
  writeln(fb,ans);
  writeln(fb,s1);
 end else
    for i:=1 to 100000 do
        for j:=1 to 100000 do
          begin end;
  close(input);
  close(output);
end.
