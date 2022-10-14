
Type
  Node                                 = Record

                                           x , y     : Double;

                                         End;

Var
  InF , OutF                           : Text;
  N , i , j , k , l                    : LongInt;
  Map , Now                            : Array [ 0 .. 200001 ] Of Node;
  Ans , Tmp                            : Double;

Function Dis ( x1 , y1 , x2 , y2     : Double )     : Double;
Begin

  Exit ( Sqrt ( Sqr ( x1 - x2 ) + Sqr ( y1 - y2 ) ) );

End;

Procedure Swap ( Var a , b     : Node );
Var
  Tmp                                  : Node;

Begin

  Tmp := a;
  a := b;
  b := Tmp;

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

Procedure Calc ( l , r     : LongInt; Var t     : Double );
Var
  Mid , i , j , p , q                  : LongInt;
  Tmp , x1 , x2 , Min , mx             : Double;

Begin

  If r - l < 2 Then Begin

    If l <> r Then t := Dis ( Map [ l ].x , Map [ l ].y , Map [ r ].x , Map [ r ].y )
    Else t := 1E100;
    If Map [ l ].y > Map [ r ].y Then Swap ( Map [ l ] , Map [ r ] );

    Exit;

  End;

  Mid := ( l + r ) >> 1;
  Calc ( l , Mid , x1 );
  Calc ( Mid + 1 , r , x2 );
  If x1 < x2 Then Min := x1
  Else Min := x2;
  mx := Map [ Mid ].x;
  t := Min;

  i := l;
  j := Mid + 1;
  p := l - 1;

  While p < r Do Begin

    Inc ( p );
    If ( j > r ) Or ( Map [ i ].y < Map [ j ].y ) Then Begin Now [ p ] := Map [ i ]; Inc ( i ); End
    Else Begin Now [ p ] := Map [ j ]; Inc ( j ); End;

  End;

  p := l - 1;
  For i := l To r Do
    If ( mx - Min < Map [ i ].x ) And ( Map [ i ].x < mx + Min ) Then Begin

      Inc ( p );
      Now [ p ] := Map [ i ];

    End;

  For i := l To p Do
    For j := 1 To 3 Do
      If i + j <= p Then Begin

        Tmp := Dis ( Now [ i ].x , Now [ i ].y , Now [ i + j ].x , Now [ i + j ].y );
        If Tmp < t Then t := Tmp;

      End
      Else Break;

End;

Begin

  Assign ( InF , 'dark.in' );
  ReSet ( InF );

  Read ( InF , N );
  For i := 1 To N Do
    Read ( InF , Map [ i ].x , Map [ i ].y );

  Close ( InF );

  Ans := 1E100;

  RandoMize;
  QSort ( 1 , N );

  Calc ( 1 , N , Ans );

  Assign ( OutF , 'dark.out' );
  ReWrite ( OutF );

  WriteLn ( OutF , Ans / 2 : 0 : 2 );

  Close ( OutF );

End.