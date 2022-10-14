var
	fin,fout:text;
	n,i:longint;
	ans,min,x:int64;

begin
	assign(fin,'bus.in');reset(fin);
	readln(fin,n);

	min:=maxlongint;
	for i:=1 to n do
	begin
		read(fin,x);
		if x<min then
			begin
				ans:=ans+x;
				min:=x;
			end
		else
			begin	
				ans:=ans+min
			end;
	end;
	close(fin);

	assign(fout,'bus.out');rewrite(fout);
	writeln(fout,ans);
	close(fout)

end.