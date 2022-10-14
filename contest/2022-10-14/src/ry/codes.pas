Program Raoyu;
Var  Q:Array[1..1000000,1..3]of Longint;
     Match:Array[1..20,1..20,1..20]of Boolean;
     F:Array[0..5000,1..20,1..20]of Boolean;
     N,I,J,K:Longint;
     TmpS:String;
     Fa:Array[1..1000000]of Longint;
     InF,OutF:Text;
     S:Array[1..20]of String;
     L:Array[1..20]of Longint;
     Len,Ans,AnsR,Head,Tail,x,y,z:Longint;
     Tmp,AnsS:AnsiString;

Procedure Dfs(p,x,y,z:Longint);
Var xx,yy,zz,pp:Longint;
    Flag:Boolean;
Begin
  If(p=0)Then
    Exit;
  pp:=Fa[p];
  Flag:=pp>0;
  pp:=Abs(pp);
  xx:=Q[pp,1]; yy:=Q[pp,2]; zz:=Q[pp,3];
  If(Flag)Then
    Dfs(pp,xx,y,zz)
  Else Begin
    Dfs(pp,xx,yy,zz);
    Tmp:=Tmp+Copy(S[y],L[y]-z+1,z);
  End;
End;

Begin
  Assign(InF,'codes.in');Reset(InF);
  Assign(OutF,'codes.out');Rewrite(OutF);

  Readln(InF,N);
  For I:=1 to N do
  Begin
    Readln(InF,S[I]);
    L[I]:=Length(S[I]);
  End;

  For I:=1 to N do
    For J:=1 to N do
      For K:=1 to L[J] do
      Begin
        TmpS:=Copy(S[J],L[J]-K+1,K);
        If(Pos(TmpS,S[I])=1)Or(Pos(S[I],TmpS)=1)Then
          Match[I,J,K]:=True
        Else Match[I,J,K]:=False;
      End;

  Fillchar(F,Sizeof(F),False);
  For I:=1 to N do
    F[0,I,L[I]]:=True;
  Ans:=MaxLongint Div 2;
  AnsS:='';
  Head:=1;
  Tail:=N;
  For I:=1 to N do
  Begin
    Q[I,1]:=0;
    Q[I,2]:=I;
    Q[I,3]:=L[I];
  End;

  While(Head<=Tail)And(Q[Head,1]<=Ans)do
  Begin
    x:=Q[Head,1];
    y:=Q[Head,2];
    z:=Q[Head,3];
    For I:=1 to N do
      If(Match[I,y,z])Then
        If(L[I]<z)Then
        Begin
          If(F[x+L[I],y,z-L[I]])Then
            Continue;
          Inc(Tail);
          Q[Tail,1]:=x+L[I];
          Q[Tail,2]:=y;
          Q[Tail,3]:=z-L[I];
          F[x+L[I],y,z-L[I]]:=True;
          Fa[Tail]:=Head;
        End
        Else If(L[I]>z)Then
        Begin
          If(F[x+z,I,L[I]-z])Then
            Continue;
          Inc(Tail);
          Q[Tail,1]:=x+z;
          Q[Tail,2]:=I;
          Q[Tail,3]:=L[I]-z;
          F[x+z,I,L[I]-z]:=True;
          Fa[Tail]:=-Head;
        End
        Else If(y<>I)Then
        Begin
          Len:=x+z;
          Inc(Tail);
          Q[Tail,1]:=x+z;
          Q[Tail,2]:=y;
          Q[Tail,3]:=0;
          Fa[Tail]:=Head;
          Tmp:='';
          Dfs(Tail,Q[Tail,1],Q[Tail,2],Q[Tail,3]);
          If(Len<Ans)or(Len=Ans)And((AnsS='')Or(Tmp<AnsS))Then
          Begin
            Ans:=Len;
            AnsS:=Tmp;
          End
        End;
    Inc(Head);
  End;

  Writeln(OutF,Ans);
  Writeln(OutF,AnsS);

  Close(InF);
  Close(OutF);
End.
