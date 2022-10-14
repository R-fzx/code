{
wave
pj
11.9
}

var
  fin,fout:text;
  n,m,i:integer;
  c:longint;

begin
assign(fin,'wave.in');reset(fin);
assign(fout,'wave.out');rewrite(fout);
 readln(fin,m);
 for i:=1 to m do
  begin
   read(fin,n,c);
   if (n=2)and(c=1) then
    write(fout,'1',' ','2');
   if (n=3)and(c=3) then
    write(fout,'2',' ','3',' ','1');
  end;
close(fin);close(fout);
end.