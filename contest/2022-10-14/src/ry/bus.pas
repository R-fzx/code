Program Raoyu;
Var  A:Array[1..100001]of Qword;
     N,I:Longint;
     Ans:Qword;
     InF,OutF:Text;
Begin
  Assign(InF,'bus.in');Reset(InF);
  Assign(OutF,'bus.out');Rewrite(OutF);

  Readln(InF,N);
  For I:=1 to N do
    Read(InF,A[I]);
  Ans:=A[1];
  For I:=2 to N do
    If(A[I-1]<A[I])Then
    Begin
      A[I]:=A[I-1];
      Inc(Ans,A[I]);
    End
    Else Inc(Ans,A[I]);
  Writeln(OutF,Ans);

  Close(InF);
  Close(OutF);
End.