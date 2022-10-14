var
	i,j,n,op,cl:longint;
	fin,fout:text;
	q:array[0..100043,1..2] of ansistring;
	s:array[0..43] of string;
	ts,s1,s2:ansistring;

procedure print(ans:ansistring);
begin
	assign(fout,'codes.out');rewrite(fout);
        writeln(fout,length(ans));
	writeln(fout,ans);
	close(fout);
        halt
end;

begin
	assign(fin,'codes.in');reset(fin);
	readln(fin,n);
	for i:=1 to n do readln(fin,s[i]);
	close(fin);

	for i:=1 to n-1 do
		for j:=i+1 to n do
			if s[i]+s[j]>s[j]+s[i] then
				begin
					ts:=s[i];s[i]:=s[j];s[j]:=ts;
				end;

	for i:=1 to n do
		for j:=1 to n do
			if i<>j then
				begin
					if pos(s[i],s[j])=1 then
						begin
							inc(cl);
							q[cl,1]:=s[i];q[cl,2]:=s[j];
						end;
				end;

	op:=0;
	repeat
		inc(op);
		s1:=q[op,1];s2:=q[op,2];
		for i:=1 to n do
		begin
			ts:=s1+s[i];
			if ts=s2 then print(ts);
			if length(ts)>length(s2) then
				begin
					if pos(s2,ts)=1 then
						begin
							inc(cl);q[cl,1]:=s2;q[cl,2]:=ts;
						end;
				end
			else
				begin
					if pos(ts,s2)=1 then
						begin
							inc(cl);q[cl,1]:=ts;q[cl,2]:=s2;
						end;
				end;

			ts:=s2+s[i];
			if ts=s1 then print(ts);
			if length(ts)>length(s1) then
				begin
					if pos(s1,ts)=1 then
						begin
							inc(cl);q[cl,1]:=s1;q[cl,2]:=ts;
						end;
				end
			else
				begin
					if pos(ts,s1)=1 then
						begin
							inc(cl);q[cl,1]:=ts;q[cl,2]:=s1;
						end;
				end;

		end;
	until op>=cl;
end.
