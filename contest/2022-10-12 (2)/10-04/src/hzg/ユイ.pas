program t2;
var r,ans:double;

begin
assign(input,'�楤.in');reset(input);
assign(output,'�楤.out');rewrite(output);
readln(r);
ans:=r*7/16;
writeln(ans:0:6);
close(input);close(output);
end.