var a:array[1..7]of string;
    xq,y1,m1,d1,i,j,s,r:longint;
begin
  assign(input,'derproze.in');reset(input);
  assign(output,'derproze.out');rewrite(output);
  readln(y1,m1,d1);
  a[1]:='monday';a[2]:='tuesday';a[3]:='wednesday';a[4]:='thursday';
  a[5]:='friday';a[6]:='saturday';a[7]:='sunday';
  s:=0;r:=0;
  for i:=1 to y1 do
    if i<y1
      then if(i mod 400=0)or((i mod 4=0)and(i mod 100<>0))
        then s:=s+366
        else s:=s+365
      else for j:=1 to m1-1 do begin
        case j of
          1,3,5,7,8,10,12:s:=s+31;
          4,6,9,11:s:=s+30;
          2:if(i mod 400=0)or((i mod 4=0)and(i mod 100<>0))
            then s:=s+29
            else s:=s+28;
        end;
      end;
  s:=s+d1;
  repeat
    inc(r);
    inc(xq);
    if xq>7 then xq:=1;
  until r>=s;
  writeln(a[xq]);
  close(input);close(output);
end.
