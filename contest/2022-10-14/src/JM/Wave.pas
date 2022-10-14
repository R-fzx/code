var
     fin,fout:text;
     n,m,c,i,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,tot:longint;
     flag8,flag9,flag10,flag11:boolean;
     a2,a3,a4,a5,a6,a7,a8:array[0..3043,0..11] of integer;
     s:array[0..11] of integer;
     a9:array[0..20043,0..11] of integer;
     a10:array[0..143434,0..11] of integer;
     a11:array[0..743434,0..11] of integer;
     b:array[0..43] of boolean;

procedure gogo2(v:longint);
var
     i:longint;
begin
     if v>2 then
       begin
         inc(t2);
	 a2[t2]:=s;
         exit;
       end;
     for i:=1 to 2 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo2(v+1);
           b[i]:=false
         end;
end;

procedure gogo3(v:longint);
var
     i:longint;
begin
     if v>3 then
       begin
         inc(t3);
	 a3[t3]:=s;
         exit
       end;
     for i:=1 to 3 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo3(v+1);
           b[i]:=false
         end;
end;

procedure gogo4(v:longint);
var
     i:longint;
begin
     if v>4 then
       begin
         inc(t4);
	 a4[t4]:=s;
         exit
       end;
     for i:=1 to 4 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo4(v+1);
           b[i]:=false
         end;
end;

procedure gogo5(v:longint);
var
     i:longint;
begin
     if v>5 then
       begin
         inc(t5);
	 a5[t5]:=s;
         exit
       end;
     for i:=1 to 5 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo5(v+1);
           b[i]:=false
         end;
end;

procedure gogo6(v:longint);
var
     i:longint;
begin
     if v>6 then
       begin
         inc(t6);
	 a6[t6]:=s;
         exit
       end;
     for i:=1 to 6 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo6(v+1);
           b[i]:=false
         end;
end;

procedure gogo7(v:longint);
var
     i:longint;
begin
     if v>7 then
       begin
         inc(t7);
	 a7[t7]:=s;
         exit
       end;
     for i:=1 to 7 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo7(v+1);
           b[i]:=false
         end;
end;

procedure gogo8(v:longint);
var
     i:longint;
begin
     if v>8 then
       begin
         inc(t8);
	 a8[t8]:=s;
         exit
       end;
     for i:=1 to 8 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo8(v+1);
           b[i]:=false
         end;
end;

procedure gogo9(v:longint);
var
     i:longint;
begin
     if v>9 then
       begin
         inc(t9);
	 a9[t9]:=s;
         exit
       end;
     for i:=1 to 9 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo9(v+1);
           b[i]:=false
         end;
end;

procedure gogo10(v:longint);
var
     i:longint;
begin
     if v>10 then
       begin
         inc(t10);
	 a10[t10]:=s;
         exit
       end;
     for i:=1 to 10 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo10(v+1);
           b[i]:=false
         end;
end;

procedure gogo11(v:longint);
var
     i:longint;
begin
     if v>11 then
       begin
         inc(t11);
	 a11[t11]:=s;
         exit
       end;
     for i:=1 to 11 do
       if b[i]=false then
         begin
           if v>2 then
             if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
           s[v]:=i;
           b[i]:=true;
           gogo11(v+1);
           b[i]:=false
         end;
end;
procedure do1;
begin
     writeln(fout,1);
end;

procedure do2;
begin
     writeln(fout,a2[c,1],' ',a2[c,2]);
end;

procedure do3;
begin
     for i:=1 to n-1 do write(fout,a3[c,i],' ');
     writeln(fout,a3[c,n]);
end;

procedure do4;
begin
     for i:=1 to n-1 do write(fout,a4[c,i],' ');
     writeln(fout,a4[c,n]);
end;

procedure do5;
begin
     for i:=1 to n-1 do write(fout,a5[c,i],' ');
     writeln(fout,a5[c,n]);
end;

procedure do6;
begin
     for i:=1 to n-1 do write(fout,a6[c,i],' ');
     writeln(fout,a6[c,n]);
end;

procedure do7;
begin
     for i:=1 to n-1 do write(fout,a7[c,i],' ');
     writeln(fout,a7[c,n]);
end;

procedure do8;
begin
     if flag8=false then
       begin
         fillchar(b,sizeof(b),0);
         gogo8(1);
         flag8:=true;
       end;
     for i:=1 to n-1 do write(fout,a8[c,i],' ');
     writeln(fout,a8[c,n]);
end;

procedure do9;
begin
     if flag9=false then
       begin
         fillchar(b,sizeof(b),0);
         gogo9(1);
         flag9:=true;
       end;
     for i:=1 to n-1 do write(fout,a9[c,i],' ');
     writeln(fout,a9[c,n]);
end;

procedure do10;
begin
     if flag10=false then
       begin
         fillchar(b,sizeof(b),0);
         gogo10(1);
         flag10:=true;
       end;
     for i:=1 to n-1 do write(fout,a10[c,i],' ');
     writeln(fout,a10[c,n]);
end;

procedure do11;
begin
     if flag11=false then
       begin
         fillchar(b,sizeof(b),0);
         gogo11(1);
         flag11:=true;
       end;
     for i:=1 to n-1 do write(fout,a11[c,i],' ');
     writeln(fout,a11[c,n]);
end;

procedure gogo(v:longint);
var
i:longint;
begin
if tot>=c then exit;
if v>n then
begin
inc(tot);
if tot=c then
begin
for i:=1 to n-1 do write(fout,s[i],' ');
writeln(fout,s[n]);
end;
exit;
end;
for i:=1 to n do
if b[i]=false then
begin
if v>2 then if (s[v-2]>s[v-1])and(s[v-1]>i)or(s[v-2]<s[v-1])and(s[v-1]<i) then continue;
s[v]:=i;
b[i]:=true;
gogo(v+1);
b[i]:=false
end;
end;

procedure gg;
begin
fillchar(b,sizeof(b),0);
tot:=0;
      gogo(1);
end;

begin
     assign(fin,'wave.in');reset(fin);
     assign(fout,'wave.out');rewrite(fout);
     readln(fin,m);
     fillchar(b,sizeof(b),0);gogo2(1);
     fillchar(b,sizeof(b),0);gogo3(1);
     fillchar(b,sizeof(b),0);gogo4(1);
     fillchar(b,sizeof(b),0);gogo5(1);
     fillchar(b,sizeof(b),0);gogo6(1);
     fillchar(b,sizeof(b),0);gogo7(1);
     while m>0 do
     begin
       dec(m);
       readln(fin,n,c);
       case n of
       1:do1;
       2:do2;
       3:do3;
       4:do4;
       5:do5;
       6:do6;
       7:do7;
       8:do8;
       9:do9;
       10:do10;
       11:do11;
       else gg;
       end;
     end;
     close(fin);
     close(fout);
end.
