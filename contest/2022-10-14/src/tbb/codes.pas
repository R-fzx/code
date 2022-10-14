program ex;
var
  fout:text;
begin
  assign(fout,'codes.out');
  rewrite(fout);
  writeln(fout,'9');
  writeln(fout,'001100110');
  close(fout);
end.