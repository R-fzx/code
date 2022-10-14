
Var
  InF , OutF                           : Text;
  N , T , M , i , j , k , Ans          : LongInt;
  A , Now                              : Array [ 0 .. 20 ] Of LongInt;
  Check                                : Array [ 0 .. 20 ] Of Boolean;

Procedure Dfs ( Dep     : LongInt );
Var
  i , j                                : LongInt;

Begin

  If Ans >= M Then Exit;

  If Dep > N Then Begin 
    Inc ( Ans ); 
    Now := A;
    Exit; 
  End;

  For i := 1 To N Do
    If Check [ i ] Then Begin

      A [ Dep ] := i;
      Check [ i ] := False;
      If ( Dep > 2 ) Then
        If ( ( i > A [ Dep - 1 ] ) And ( A [ Dep - 1 ] < A [ Dep - 2 ] ) ) Or
           ( ( i < A [ Dep - 1 ] ) And ( A [ Dep - 1 ] > A [ Dep - 2 ] ) )
          Then Dfs ( Dep + 1 );

      If Dep < 3 Then Dfs ( Dep + 1 );
      Check [ i ] := True;

    End;

End;

Begin

  Assign ( InF , 'wave.in' );
  ReSet ( InF );
  Assign ( OutF , 'wave.out' );
  ReWrite ( OutF );

  Read ( InF , T );
  While T > 0 Do Begin

    Dec ( T );
    FillChar ( Check , SizeOf ( Check ) , True );
    Read ( InF , N , M );
    Ans := 0;
    Dfs ( 1 );

    For i := 1 To N - 1 Do
      Write ( OutF , Now [ i ] , ' ' );
    WriteLn ( OutF , Now [ N ] );

  End;

  Close ( InF );
  Close ( OutF );

End.