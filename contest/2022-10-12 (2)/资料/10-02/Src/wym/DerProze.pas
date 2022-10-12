var yyyy,mm,dd,y,m,d:integer;
	k:longint;
begin
	assign(input,'DerProze.in');reset(input);
	assign(output,'DerProze.out');rewrite(output);
	readln(yyyy,mm,dd);
	y:=1;m:=1;d:=1;k:=0;
	while not((y=yyyy)and(m=mm)and(d=dd)) do begin
		inc(d);inc(k);k:=k mod 7;
		if (d=32)and((m=1)or(m=3)or(m=5)or(m=7)or(m=8)or(m=10)or(m=12)) then begin
			inc(m);d:=1;
		end else if (d=31)and((m=4)or(m=6)or(m=9)or(m=11)) then begin
			inc(m);d:=1;
		end else if (m=2)then 
			if (((y mod 4=0)and not((y mod 100=0)xor(y mod 400=0)))and(d=30)) or 
				(not ((y mod 4=0)and not((y mod 100=0)xor(y mod 400=0)))and(d=29)) then begin
					inc(m);d:=1;
				end;
		if m=13 then begin inc(y);m:=1;end;
	end;
	case k of
		2:writeln('wednesday');
		3:writeln('thursday');
		4:writeln('friday');
		5:writeln('saturday');
		6:writeln('sunday');
		0:writeln('monday');
		1:writeln('tuesday');
		else writeln(k);
	end;
	close(input);close(output);
end.