var

   i,j,n,k:longint;

   a:array[1..100000] of longint;

   minx,minn:array[1..100000] of longint;

   fin,fout:text;

   ans,min:int64;

begin

   assign (fin,'bus.in'); reset (fin);

   assign (fout,'bus.out'); rewrite (fout);

      readln (fin,n);

      min:=maxlongint;

      for i:=1 to n do

      begin

         read (fin,a[i]);

         if a[i]<min then

            begin

            minx[i]:=a[i];

            minn[i]:=i;

            min:=a[i];

            end else

               begin

               minx[i]:=minx[i-1];

               minn[i]:=minn[i-1];

               end;

      end;

      j:=n;

      while j<>0 do

         begin

         ans:=ans+minx[j]*(j-minn[j]+1);

         j:=minn[j]-1;

         end;

      writeln (fout,ans);

   close (fin);

   close (fout);

end.

