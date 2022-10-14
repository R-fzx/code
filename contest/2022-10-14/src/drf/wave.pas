var

   n,m,c,i,j,l,count:longint;

   k:boolean;

   fin,fout:text;

   v:array[1..20] of boolean;

   a:array[1..20] of longint;

procedure try (i,i1,i2:longint);

var

   o,p:longint;

begin

if k then exit;

if i=n+1 then

   begin

   inc (count);

   if count = c then

   begin

      for o:=1 to n do

      write (fout,a[o],' ');

   writeln (fout);

   k:=true;

   end;

   exit;

   end;

   for o:=1 to n do

   if v[o]=false then

   if (i<=2)or((i1<o)and(i1<i2))or((i1>o)and(i1>i2)) then

      begin

         v[o]:=true;

         a[i]:=o;

         try (i+1,o,i1);

         v[o]:=false;

         a[i]:=0;

      end;

end;

begin

   assign (fin,'wave.in'); reset (fin);

   assign (fout,'wave.out'); rewrite (fout);

      readln (fin,m);

      for i:=1 to m do

         begin

            readln (fin,n,c);

            k:=false;

            count:=0;

            try (1,0,0);

         end;

   close (fin);

   close (fout);

end.