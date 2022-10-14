
Var 
  InF, OutF                            : Text;
  N , i , j , k                        : LongInt;
  Ans                                  : Int64;

Begin

  Assign ( InF , 'bus.in' );
  ReSet ( InF );
  Read ( InF , N );
  k := MaxLongInt;
  Ans := 0;
  For i := 1 To N Do Begin

    Read ( InF , j );
    If j < k Then k := j;
    Inc ( Ans , k );

  End;

  Close ( InF );

  Assign ( OutF , 'bus.out' );
  ReWrite ( OutF );
  WriteLn ( OutF , Ans );
  Close ( OutF );

End.