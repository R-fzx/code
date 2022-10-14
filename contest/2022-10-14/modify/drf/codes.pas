var
   i,j,k,l,m,n,x,y:longint;

   st:array[1..20] of string[20];

   f:array[1..20,0..20] of longint;

   s:array[1..20,0..20] of {ansi}string;

   v:array[1..20,0..20] of boolean;

   fin,fout:text;

   qx,qy:array[1..100000] of longint;

   open,closed:longint;

   mins:{ansi}string;

   min:longint;

begin

   assign (fin,'codes.in'); reset (fin);

   assign (fout,'codes.out'); rewrite (fout);

      readln (fin,n);

      for i:=1 to n do

      readln (fin,st[i]);

      fillchar (f,sizeof(f),$7f);

      for i:=1 to n do

      begin

      f[i,length(st[i])]:=0;

      s[i,length(st[i])]:='';

      v[i,length(st[i])]:=true;

      qx[i]:=i;

      qy[i]:=length(st[i]);

      end;

      min:=maxlongint;

   open:=0; closed:=n;

   while open<closed do

      begin

      inc (open);

      x:=qx[open];

      y:=qy[open];

      v[x,y]:=false;

      if f[x,y]>min then

         begin

         writeln (fout,min);

         writeln (fout,mins);

         close (fin);

         close (fout);

         halt;

         end;

      for i:=1 to n do

      if (y=length(st[x]))and(i=x) then continue else

      begin

         if (y-length(st[i]) >= 0)and(st[i]=copy(st[x],length(st[x])-y+1,length(st[i]))) then

         if f[x,y-length(st[i])]>f[x,y]+length(st[i]) then

            begin

            f[x,y-length(st[i])]:=f[x,y]+length(st[i]);

            s[x,y-length(st[i])]:=s[x,y]+st[i];

               if v[x,y-length(st[i])]=false then

                  begin

                  v[x,y-length(st[i])]:=true;

                  inc (closed);

                  qx[closed]:=x;

                  qy[closed]:=y-length(st[i]);

                  end;

               if y-length(St[i])=0 then

                  begin

                  if mins='' then

                  begin

                  mins:=s[x,y-length(st[i])];

                  min:=f[x,y-length(st[i])]; end else

                  if (min>f[x,y-length(st[i])])or((mins>s[x,y-length(st[i])])and(min=f[x,y-length(st[i])])) then

                  begin

                  mins:=s[x,y-length(st[i])];

                  min:=f[x,y-length(st[i])];

                  end;

                  end;

            end;

        if (length(st[i])-y>0)and(copy(st[i],1,y)=copy(st[x],length(st[x])-y+1,y)) then

        if f[i,length(st[i])-y]>f[x,y]+y then

           begin

           f[i,length(st[i])-y]:=f[x,y]+y;

           s[i,length(st[i])-y]:=s[x,y]+copy (st[x],length(st[x])-y+1,y);

              if v[i,length(st[i])-y]=false then

                 begin

                 v[i,length(st[i])-y]:=true;

                 inc (closed);

                 qx[closed]:=i;

                 qy[closed]:=length(st[i])-y;

                 end;

           end;

      end;

      end;

      writeln (fout,min);

      writeln (fout,mins);

   close (fin);

   close (fout);

end.
