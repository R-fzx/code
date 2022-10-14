
Type
  Node                                 = Record

                                           x , y     : Double;

                                         End;

Var
  InF , OutF                           : Text;
  N , i , j , k , l                    : LongInt;
  Map                                  : Array [ 0 .. 200001 ] Of Node;
  Ans , Tmp                            : Double;

Function Dis ( x1 , y1 , x2 , y2     : Double )     : Double;
Begin

  Exit ( Sqrt ( Sqr ( x1 - x2 ) + Sqr ( y1 - y2 ) ) );

End;

Procedure QSort ( l , r     : LongInt );
Var
  i , j , k                            : LongInt;
  Tmp                                  : Node;

Begin

  k := Random ( r - l + 1 ) + l;
  Tmp := Map [ k ];
  Map [ k ] := Map [ l ];
  i := l;
  j := r;

  While i < j Do Begin

    While ( i < j ) And ( Map [ j ].x > Tmp.x ) Do Dec ( j );
    If i < j Then Begin Map [ i ] := Map [ j ]; Inc ( i ); End;
    While ( i < j ) And ( Map [ i ].x < Tmp.x ) Do Inc ( i );
    If i < j Then Begin Map [ j ] := Map [ i ]; Dec ( j ); End;

  End;

  Map [ i ] := Tmp;
  If l < i - 1 Then QSort ( l , i - 1 );
  If j + 1 < r Then QSort ( j + 1 , r );

End;

Procedure Calc ( l , r     : LongInt );
Var
  Mid , i , j , p , q                  : LongInt;
  Tmp                                  : Double;

Begin

  If r - l <= 2 Then Begin

    For i := l To r Do
      For j := i + 1 To r Do Begin

        Tmp := Dis ( Map [ i ].x , Map [ i ].y , Map [ j ].x , Map [ j ].y );
        If Tmp < Ans Then Ans := Tmp;

      End;

    Exit;

  End;

  Mid := ( l + r ) >> 1;

  i := Mid;
  j := Mid + 1;

  While ( Mid - i < 2 ) And ( i > l ) Do Dec ( i );
  While ( j - Mid - 1 < 2 ) And ( j < r ) Do Inc ( j );
  For p := i To Mid Do
    For q := p + 1 To j Do Begin

      Tmp := Dis ( Map [ p ].x , Map [ p ].y , Map [ q ].x , Map [ q ].y );
      If Tmp < Ans Then Ans := Tmp;

    End;

  Calc ( l , Mid );
  Calc ( Mid + 1 , r );

End;

Begin

  Assign ( InF , 'dark.in' );
  ReSet ( InF );

  Read ( InF , N );
  For i := 1 To N Do
    Read ( InF , Map [ i ].x , Map [ i ].y );

  Close ( InF );

  Ans := 1E100;
  If N <= 5000 Then Begin

    For i := 1 To N Do
      For j := i + 1 To N Do Begin

        Tmp := Dis ( Map [ i ].x , Map [ i ].y , Map [ j ].x , Map [ j ].y );
        If Tmp < Ans Then Ans := Tmp;

      End;

  End;

  RandoMize;
  QSort ( 1 , N );

  Calc ( 1 , N );

  For i := 1 To N - 1 Do Begin

    Tmp := Dis ( Map [ i ].x , Map [ i ].y , Map [ i + 1 ].x , Map [ i + 1 ].y );
    If Tmp < Ans Then Ans := Tmp;

  End;

  For i := 1 To 1000 Do Begin

    k := Random ( N - 1 ) + 1;
    For j := 1 To 20 Do Begin

      l := Random ( N - k ) + k + 1;
      Tmp := Dis ( Map [ k ].x , Map [ k ].y , Map [ l ].x , Map [ l ].y );
      If Tmp < Ans Then Ans := Tmp;

    End;

  End;

  Assign ( OutF , 'dark.out' );
  ReWrite ( OutF );

  WriteLn ( OutF , Ans / 2 : 0 : 2 );

  Close ( OutF );

End.