var i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,j,k,n,m,total,c:longint;
    a:array[0..30] of integer;
    fa,fb:text;
procedure b3;
begin
 for i1:=1 to n do
              for i2:=1 to n do
                  for i3:=1 to n do
                        if ((i1<i2) and (i3<i2)) or ((i1>i2) and (i3>i2)) then
                             begin
                               inc(total);
                               if total=c then begin
                                  writeln(fb,i1,' ',i2,' ',i3) ;
                                  exit;
                                end;
                             end;
end;

procedure b4;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                   if ((i1<i2) and (i3<i2) and (i4>i3)) or ((i1>i2) and (i3>i2) and (i4<i3)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4) ;
                                    exit;
                                   end;
                             end;
end;

procedure b5;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                 for i5:=1 to n do
                     if i5<>i1 then if i5<>i2 then if i5<>i3 then if i5<>i4 then
                   if ((i1<i2) and (i3<i2) and (i4>i3) and (i5<i4)) or ((i1>i2) and (i3>i2) and (i4<i3) and (i5>i4)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4,' ',i5) ;
                                    exit;
                                   end;
                             end;
end;

procedure b6;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                 for i5:=1 to n do
                     if i5<>i1 then if i5<>i2 then if i5<>i3 then if i5<>i4 then
                  for i6:=1 to n do
                     if i6<>i1 then if i6<>i2 then if i6<>i3 then if i6<>i4 then if i6<>i5 then
                   if ((i1<i2) and (i3<i2) and (i4>i3) and (i5<i4) and (i6>i5)) or ((i6<i5) and (i1>i2) and (i3>i2) and (i4<i3) and (i5<i4)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4,' ',i5,' ',i6) ;
                                    exit;
                                   end;
                             end;
end;

procedure b7;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                 for i5:=1 to n do
                     if i5<>i1 then if i5<>i2 then if i5<>i3 then if i5<>i4 then
                  for i6:=1 to n do
                     if i6<>i1 then if i6<>i2 then if i6<>i3 then if i6<>i4 then if i6<>i5 then
                   for i7:=1 to n do
                     if i7<>i1 then if i7<>i2 then if i7<>i3 then if i7<>i4 then if i7<>i5 then if i7<>i6 then
                   if ((i1<i2) and (i3<i2) and (i4>i3) and (i5<i4) and (i6>i5) and (i7<i6)) or ((i7>i6) and (i6<i5) and (i1>i2) and (i3>i2) and (i4<i3) and (i5>i4)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4,' ',i5,' ',i6,' ',i7) ;
                                    exit;
                                   end;
                             end;
end;

procedure b8;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                 for i5:=1 to n do
                     if i5<>i1 then if i5<>i2 then if i5<>i3 then if i5<>i4 then
                  for i6:=1 to n do
                     if i6<>i1 then if i6<>i2 then if i6<>i3 then if i6<>i4 then if i6<>i5 then
                   for i7:=1 to n do
                     if i7<>i1 then if i7<>i2 then if i7<>i3 then if i7<>i4 then if i7<>i5 then if i7<>i6 then
                    for i8:=1 to n do
                     if i8<>i1 then if i8<>i2 then if i8<>i3 then if i8<>i4 then if i8<>i5 then if i8<>i6 then if i8<>i7 then
                         if ((i1<i2) and (i3<i2) and (i4>i3) and (i5<i4) and (i6>i5) and (i7<i6) and (i8>i7)) or ((i8<i7) and (i7>i6) and (i6<i5) and (i1>i2) and (i3>i2) and (i4<i3) and (i5>i4)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4,' ',i5,' ',i6,' ',i7,' ',i8) ;
                                    exit;
                                   end;
                             end;
end;

procedure b9;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                 for i5:=1 to n do
                     if i5<>i1 then if i5<>i2 then if i5<>i3 then if i5<>i4 then
                  for i6:=1 to n do
                     if i6<>i1 then if i6<>i2 then if i6<>i3 then if i6<>i4 then if i6<>i5 then
                   for i7:=1 to n do
                     if i7<>i1 then if i7<>i2 then if i7<>i3 then if i7<>i4 then if i7<>i5 then if i7<>i6 then
                    for i8:=1 to n do
                     if i8<>i1 then if i8<>i2 then if i8<>i3 then if i8<>i4 then if i8<>i5 then if i8<>i6 then if i8<>i7 then
                    for i9:=1 to n do
                     if i9<>i1 then if i9<>i2 then if i9<>i3 then if i9<>i4 then if i9<>i5 then if i9<>i6 then if i9<>i7 then if i9<>i8 then
                         if ((i1<i2) and (i3<i2) and (i4>i3) and (i5<i4) and (i6>i5) and (i7<i6) and (i8>i7)) or ((i8<i7) and (i7>i6) and (i6<i5) and (i1>i2) and (i3>i2) and (i4<i3) and (i5>i4)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4,' ',i5,' ',i6,' ',i7,' ',i8,' ',i9) ;
                                    exit;
                                   end;
                             end;
end;

procedure b10;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                 for i5:=1 to n do
                     if i5<>i1 then if i5<>i2 then if i5<>i3 then if i5<>i4 then
                  for i6:=1 to n do
                     if i6<>i1 then if i6<>i2 then if i6<>i3 then if i6<>i4 then if i6<>i5 then
                   for i7:=1 to n do
                     if i7<>i1 then if i7<>i2 then if i7<>i3 then if i7<>i4 then if i7<>i5 then if i7<>i6 then
                    for i8:=1 to n do
                     if i8<>i1 then if i8<>i2 then if i8<>i3 then if i8<>i4 then if i8<>i5 then if i8<>i6 then if i8<>i7 then
                    for i9:=1 to n do
                     if i9<>i1 then if i9<>i2 then if i9<>i3 then if i9<>i4 then if i9<>i5 then if i9<>i6 then if i9<>i7 then if i9<>i8 then
                    for i10:=1 to n do
                     if i10<>i1 then if i10<>i2 then if i10<>i3 then if i10<>i4 then if i10<>i5 then if i10 <>i6 then if i10<>i7 then if i10<>i8 then if i10<>i9 then
                         if ((i1<i2) and (i3<i2) and (i4>i3) and (i5<i4) and (i6>i5) and (i7<i6) and (i8>i7)) or ((i8<i7) and (i7>i6) and (i6<i5) and (i1>i2) and (i3>i2) and (i4<i3) and (i5>i4)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4,' ',i5,' ',i6,' ',i7,' ',i8,' ',i9,' ',i10) ;
                                    exit;
                                   end;
                             end;
end;

procedure b11;
begin
 for i1:=1 to n do
      for i2:=1 to n do
        if i1<>i2 then
            for i3:=1 to n do
               if i1<> i3 then
                  if i3<> i2 then
               for i4:=1 to n do
                 if i3<> i4 then if i4<>i1 then if i4<>i2 then
                 for i5:=1 to n do
                     if i5<>i1 then if i5<>i2 then if i5<>i3 then if i5<>i4 then
                  for i6:=1 to n do
                     if i6<>i1 then if i6<>i2 then if i6<>i3 then if i6<>i4 then if i6<>i5 then
                   for i7:=1 to n do
                     if i7<>i1 then if i7<>i2 then if i7<>i3 then if i7<>i4 then if i7<>i5 then if i7<>i6 then
                    for i8:=1 to n do
                     if i8<>i1 then if i8<>i2 then if i8<>i3 then if i8<>i4 then if i8<>i5 then if i8<>i6 then if i8<>i7 then
                    for i9:=1 to n do
                     if i9<>i1 then if i9<>i2 then if i9<>i3 then if i9<>i4 then if i9<>i5 then if i9<>i6 then if i9<>i7 then if i9<>i8 then
                    for i10:=1 to n do
                     if i10<>i1 then if i10<>i2 then if i10<>i3 then if i10<>i4 then if i10<>i5 then if i10 <>i6 then if i10<>i7 then if i10<>i8 then if i10<>i9 then
                    for i11:=1 to n do
                     if i11<>i1 then if i11<>i2 then if i11<>i3 then if i11<>i4 then if i11<>i5 then if i11<>i6 then if i11<>i7 then if i11<>i8 then if i11<>i9 then if i11<>i10 then
                         if ((i1<i2) and (i3<i2) and (i4>i3) and (i5<i4) and (i6>i5) and (i7<i6) and (i8>i7)) or ((i8<i7) and (i7>i6) and (i6<i5) and (i1>i2) and (i3>i2) and (i4<i3) and (i5>i4)) then
                             begin
                               inc(total);
                               if total=c then begin
                                    writeln(fb,i1,' ',i2,' ',i3,' ',i4,' ',i5,' ',i6,' ',i7,' ',i8,' ',i9,' ',i10,' ',i11) ;
                                    exit;
                                   end;
                             end;
end;

begin
  assign(fa,'wave.in');
  assign(fb,'wave.out');
  reset(fa);
  rewrite(fb);
    readln(fa,m);
    for k:=1 to m do
     begin
       total:=0;
       readln(fa,n,c);
       case n of
         1:writeln(fb,1);
         2:if c=1 then writeln(fb,1,' ',2) else writeln(fb,2,' ',1);
         3:b3;
         4:b4;
         5:b5;
         6:b6;
         7:b7;
         8:b8;
         9:b9;
         10:b10;
         11:b11
       else begin
         for j:=1 to n-1 do
               write(fb,j,' ');
         writeln(fb,j);
        end;
      end;
     end;
  close(fa);
  close(fb);
end.
