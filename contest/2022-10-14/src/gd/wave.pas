var fin,fou:text;
begin
assign(fin,'dark.in');
assign(fou,'dark.out');
reset(fin);
rewrite(fou);
close(fin);
close(fou);
end.
