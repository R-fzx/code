
Var
  InF , OutF                           : Text;
  N , i , j , k , l , Fore , Rear      : LongInt;
  F                                    : Array [ 0 .. 21 , 0 .. 21 ] Of AnsiString;
  St                                   : AnsiString;
  Map                                  : Array [ 0 .. 21 ] Of String;
  Que , Len                            : Array [ 0 .. 401 ] Of LongInt;
  Check                                : Array [ 0 .. 21 , 0 .. 21 , 0 .. 21 ] Of Boolean;
  Hash                                 : Array [ 0 .. 21 , 0 .. 21 ] Of Boolean;

Procedure Push ( x , y     : LongInt );
Begin

  If y = 0 Then Exit;
  Rear := Rear Mod 400 + 1;
  Que [ Rear ] := x;
  Len [ Rear ] := y;
  Hash [ x , y ] := False;

End;

Begin

  Assign ( InF , 'codes.in' );
  ReSet ( InF );

  ReadLn ( InF , N );
  For i := 1 To N Do
    ReadLn ( InF , Map [ i ] );

  Close ( InF );

  FillChar ( Check , SizeOf ( Check ) , False );

  For i := 1 To N Do
    For j := 1 To N Do
      For k := 1 To Length ( Map [ i ] ) Do Begin

        If Length ( Map [ j ] ) >= Length ( Map [ i ] ) - k + 1 
          Then l := Length ( Map [ i ] ) - k + 1
        Else l := Length ( Map [ j ] );

        If Copy ( Map [ i ] , k , l ) = Copy ( Map [ j ] , 1 , l )
          Then Check [ i , j , k ] := True;

      End;

  For i := 1 To N Do
    For j := 0 To Length ( Map [ i ] ) Do
      F [ i , j ] := '';

  For i := 1 To N Do
    For j := i + 1 To N Do
      If Length ( Map [ i ] ) > Length ( Map [ j ] ) Then Begin
        If Check [ j , i , 1 ]
          Then F [ i , Length ( Map [ i ] ) - Length ( Map [ j ] ) ] := Map [ i ];
      End
      Else Begin
        If Check [ i , j , 1 ] 
          Then F [ j , Length ( Map [ j ] ) - Length ( Map [ i ] ) ] := Map [ j ];
      End;

  Fore := 0;
  Rear := 0;
  FillChar ( Hash , SizeOf ( Hash ) , True );
  For i := 1 To N Do
    For j := 1 To Length ( Map [ i ] ) Do
      If F [ i , j ] <> '' Then Push ( i , j );

  While Fore <> Rear Do Begin

    Fore := Fore Mod 400 + 1;
    i := Que [ Fore ];
    j := Len [ Fore ];
    For k := 1 To N Do Begin

      If ( Length ( Map [ k ] ) <= j ) And ( Check [ i , k , Length ( Map [ i ] ) - j + 1 ] ) Then Begin

        l := j - Length ( Map [ k ] );
        If ( F [ i , l ] = '' ) Or ( Length ( F [ i , l ] ) > Length ( F [ i , j ] ) ) Or ( ( Length ( F [ i , l ] ) = Length ( F [ i , j ] ) ) And ( F [ i , l ] > F [ i , j ] ) )
          Then Begin F [ i , l ] := F [ i , j ]; If Hash [ i , l ] Then Push ( i , l ); End;

      End
      Else If ( Length ( Map [ k ] ) > j ) And ( Check [ i , k , Length ( Map [ i ] ) - j + 1 ] ) Then Begin

        l := Length ( Map [ k ] ) - j;
        St := Copy ( Map [ k ] , Length ( Map [ k ] ) - l + 1 , l );
        If ( F [ k , l ] = '' ) Or ( Length ( F [ k , l ] ) > Length ( F [ i , j ] + St ) ) Or ( ( Length ( F [ k , l ] ) = Length ( F [ i , j ] + St ) ) And ( F [ k , l ] > F [ i , j ] + St ) )
          Then Begin F [ k , l ] := F [ i , j ] + St; If Hash [ k , l ] Then Push ( k , l ); End;

      End;

    End;

  End;

  St := '';
  For i := 1 To N Do
    If F [ i , 0 ] <> '' Then
      If ( St = '' ) Or ( Length ( St ) > Length ( F [ i , 0 ] ) ) Or ( ( Length ( St ) = Length ( F [ i , 0 ] ) ) And ( St > F [ i , 0 ] ) )
        Then St := F [ i , 0 ];

  Assign ( OutF , 'codes.out' );
  ReWrite ( OutF );

  WriteLn ( OutF , Length ( St ) );
  WriteLn ( OutF , St );

  Close ( OutF );

End.