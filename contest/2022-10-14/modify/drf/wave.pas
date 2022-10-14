var

   n,m,i,j,k,l,o,zero,p,s,e:longint;

   c,je,x,count:int64;

   f:array[1..20,1..20,0..1] of int64;

   a:array[1..20] of longint;

   v:array[1..20] of boolean;

   o1:boolean;

   fin,fout:text;

procedure find;

var

   j,k:longint;

begin

for j:=n downto 1 do

           for k:=1 downto 0 do

           if f[1,j,k]+count<c then count:=count+f[1,j,k] else

              begin

              zero:=k;

              x:=j;

              o1:=true;

              exit;

              end;

end;

begin

   assign (fin,'wave.in'); reset (fin);

   assign (fout,'wave.out'); rewrite (fout);

      readln (fin,m);

      for l:=1 to m do

         begin

         readln (fin,n,c);

         count:=0;

         zero:=0;

         o1:=false;

         x:=0;

         fillchar (f,sizeof(f),0);

         fillchar (a,sizeof(a),0);

         fillchar (v,sizeof(v),false);

         f[n,1,1]:=1;

         f[n,1,0]:=1;

           for i:=n-1 downto 1 do

           for k:=0 to 1 do

              begin

              if k=1 then

                 begin

                 for j:=1 to n-i do

                 for o:=j to n-i do

                    f[i,j,k]:=f[i,j,k]+f[i+1,o,0];

                 end;

              if k=0 then

                 begin

                 for j:=2 to n-i+1 do

                 for o:=1 to j-1 do

                    f[i,j,k]:=f[i,j,k]+f[i+1,o,1];

                 end;

              end;

           find;

           je:=x;

           a[1]:=n-x+1;

           v[a[1]]:=true;

           for i:=2 to n do

           begin

           p:=0;

           zero:=1-zero;

           if zero=0 then

              begin

              s:=je;

              e:=n-i+1;

              end else

                 begin

                 s:=1;

                 e:=je-1;

                 end;

           for j:=e downto s do

              if count+f[i,j,zero]<c then

              count:=count+f[i,j,zero] else

                 begin

                 x:=j;

                 break;

                 end;

              je:=x;

         {  if zero=0 then

              begin

              s:=1;

              e:=a[i-1]-1;

              end else

                 begin

                 s:=a[i-1]+1;

                 e:=n;

                 end;  }

           for j:=n downto 1 do

           begin

           if v[j]=false then inc (p);

           if p=x then

              begin

              a[i]:=j;

              v[a[i]]:=true;

              break;

              end;

           end;

           end;

      for i:=1 to n do

      write (fout,a[i],' ');

      writeln (Fout);

   end;

   close (fin);

   close (fout);

end.
