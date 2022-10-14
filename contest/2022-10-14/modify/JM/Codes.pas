var
	i,j,n,op,cl,x,y,len:longint;
	fin,fout:text;
	r,p:array[0..43,0..43] of ansistring;
	q:array[0..100043,1..2] of longint;
	f:array[0..43,0..43] of longint;
	s:array[0..43] of string;
        vis:array[0..43,0..43] of boolean;
	ans:ansistring;

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

	fillchar(f,sizeof(f),43);
	for i:=1 to n do
		for j:=1 to n do
			if i<>j then
				if pos(s[i],s[j])=1 then
					begin
						f[j,length(s[i])]:=length(s[i]);
						inc(cl);
						q[cl,1]:=j;q[cl,2]:=length(s[i]);
						p[j,length(s[i])]:=s[i];
						r[j,length(s[i])]:=s[j];
						vis[j,length(s[i])]:=true;
					end;

	repeat
		inc(op);
		x:=q[op,1];y:=q[op,2];
		for i:=1 to n do
			if pos(s[i],copy(s[x],y+1,length(s[x])-y))=1 then
				begin
					if (f[x,y]+length(s[i])<f[x,y+length(s[i])])or
					(f[x,y]+length(s[i])=f[x,y+length(s[i])])and
					(p[x,y]+s[i]<p[x,y+length(s[i])]) then
						begin
							f[x,y+length(s[i])]:=f[x,y]+length(s[i]);
							p[x,y+length(s[i])]:=p[x,y]+s[i];
							r[x,y+length(s[i])]:=r[x,y];
							if vis[x,y+length(s[i])]=false then
								begin
									inc(cl);
									q[cl,1]:=x;q[cl,2]:=y+length(s[i]);
									vis[x,y+length(s[i])]:=true;
								end;

						end;
				end
			else
				if pos(copy(s[x],y+1,length(s[x])-y),s[i])=1 then
					begin
						if (f[x,y]+length(s[x])-y<f[i,length(s[x])-y])or
						(f[x,y]+length(s[x])-y=f[i,length(s[x])-y])and
						(p[x,y]+s[i]<r[i,length(s[x])-y]) then
							begin
								f[i,length(s[x])-y]:=f[x,y]+length(s[x])-y;
								r[i,length(s[x])-y]:=p[x,y]+s[i];
								p[i,length(s[x])-y]:=r[x,y];
								if vis[i,length(s[x])-y]=false then
									begin
										inc(cl);
										q[cl,1]:=i;q[cl,2]:=length(s[x])-y;
										vis[i,length(s[x])-y]:=true;
									end;
							end;
					end;
		vis[x,y]:=false;
	until op>=cl;

	len:=maxlongint;
	for i:=1 to n do
		if f[i,length(s[i])]<len then
			begin
				len:=f[i,length(s[i])];
				ans:=p[i,length(s[i])];
			end
		else
			if f[i,length(s[i])]=len then
				begin
					if p[i,length(s[i])]<ans then ans:=p[i,length(s[i])]
				end;

	assign(fout,'codes.out');rewrite(fout);
	writeln(fout,len);
	writeln(fout,ans);
	close(fout)
end.
