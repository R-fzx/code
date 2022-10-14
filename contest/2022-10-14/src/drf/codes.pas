var

    i,j,k,l,m,n,count:longint;

    ok:boolean;

    st:array[1..20] of string[20];

    f:array[0..1000000] of boolean;

    s:array[1..20] of longint;

    st1,min:ansistring;

    fin,fout:text;

procedure try (stg:ansistring);

var

   o,p:longint;

   count:int64;

begin

   if l=i then

      begin

      count:=0;

         for o:=1 to length (stg) do

         if stg[o]='0' then

         begin

         count:=count+sqr(sqr((length(stg)-o+1))){*(length(stg)-o+1)*(length(stg)-o+1)};

         count:=count mod 999997;

         end;
      if f[count mod 999997]=true then

         begin

         if ok=true then

         if stg<min then min:=stg;

         if ok=false then

            begin

            ok:=true;

            min:=stg;

            end;

         end else

         f[count mod 999997]:=true;

         exit;

      end;

   if l>i then exit;

   for o:=1 to n do

      if l+s[o]>i then break else

         begin

         l:=l+s[o];

         try (stg+st[o]);

         l:=l-s[o];

         end;

end;


begin

   assign (fin,'codes.in'); reset (fin);

   assign (fout,'codes.out'); rewrite (fout);

      readln (fin,n);

      for i:=1 to n do

         begin

            readln (fin,st[i]);

            s[i]:=length(st[i]);

         end;

      for i:=1 to n-1 do

      for j:=i+1 to n do

         if s[i]>s[j] then

         begin

         l:=s[i]; s[i]:=s[j]; s[j]:=l;

         st1:=st[i]; st[i]:=st[j]; st[j]:=st1;

         end;

      i:=0;

      while ok=false do

         begin

         fillchar (f,sizeof(f),false);

         inc (i);

         l:=0;

         try ('');

         end;

      writeln (fout,i);

      writeln (fout,min);

   close (fin);

   close (fout);

end.
