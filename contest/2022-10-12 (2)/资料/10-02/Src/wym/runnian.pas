var y:integer;
begin
	readln(y);
	writeln((y mod 4=0)and not((y mod 100=0)xor(y mod 400=0)));
end.