program t2;
var r,ans:double;

begin
assign(input,'ユイ.in');reset(input);
assign(output,'ユイ.out');rewrite(output);
readln(r);
ans:=r*7/16;
writeln(ans:0:6);
close(input);close(output);
end.