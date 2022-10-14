Program Raoyu;
Var  A:Array[1..20]of Longint;
     F:Array[1..20]of Boolean;
     M,N,C:Longint;
     Finish:Boolean;
     InF,OutF:Text;

Procedure Dfs(Dep:Longint);
Var I:Longint;
Begin
  If(Finish)Then
    Exit;
  If(Dep=N+1)Then
  Begin
    Dec(C);
    If(C=0)Then
    Begin
      Finish:=True;
      For I:=1 to N-1 do
        Write(OutF,A[I],' ');
      Writeln(OutF,A[N]);
      Exit;
    End;
  End;
  For I:=1 to N do
  Begin
    If(F[I])Then
      Continue;
    If(Dep>=3)Then
      If(A[Dep-2]<A[Dep-1])And(A[Dep-1]<I)Or
        (A[Dep-2]>A[Dep-1])And(A[Dep-1]>I)Then
        Continue;
    F[I]:=True;
    A[Dep]:=I;
    Dfs(Dep+1);
    If(Finish)Then
      Exit;
    F[I]:=False;
  End;
End;

Begin
  Assign(InF,'wave.in');Reset(InF);
  Assign(OutF,'wave.out');Rewrite(OutF);
  Readln(InF,M);
  While(M>0)do
  Begin
    Finish:=False;
    Readln(InF,N,C);
    Fillchar(F,Sizeof(F),False);
    Dfs(1);
    Dec(M);
  End;
  Close(InF);
  Close(OutF);
End.