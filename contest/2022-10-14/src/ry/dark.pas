Program Raoyu;
Var  Ans,Tmp:Double;
     X,Y:Array[1..200000]of Double;
     N,I,J:Longint;
     InF,OutF:Text;

Begin
  Assign(InF,'dark.in');Reset(InF);
  Assign(OutF,'dark.out');Rewrite(OutF);
  Readln(InF,N);
  For I:=1 to N do
    Readln(InF,X[I],Y[I]);
  Ans:=Sqrt(Sqr(X[1]-X[2])+Sqr(Y[1]-Y[2]));
  For I:=1 to N do
    For J:=1 to I-1 do
    Begin
      Tmp:=Sqrt(Sqr(X[I]-X[J])+Sqr(Y[I]-Y[J]))/2;
      If(Tmp<Ans)Then
        Ans:=Tmp;
    End;
  Writeln(OutF,Ans:0:2);
  Close(InF);
  Close(OutF);
End.
