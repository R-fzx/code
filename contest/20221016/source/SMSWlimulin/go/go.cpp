/*
*********************************
*        øÒ¿«µÁæ∫æ„¿÷≤ø 
*
*           TheBian
*  
*********************************
*/
#define B85 find(i,min(a[i],l),max(r,a[i]),time+dis[pos][i],ans+b[i]);
#define B84 find(i,min(l,a[i]),max(a[i],r),time+dis[pos][i],ans+b[i]);
#define B83 find(l,min(a[l],k),max(a[l],k),abs(a[l]-k)+1,b[l]);
#define B82 find(r,min(a[r],k),max(a[r],k),abs(a[r]-k)+1,b[r]);
#define B81 scanf("%lld%lld%lld",&a[i],&b[i],&t[i]);
#define B80 if(a[i]<=k&&abs(a[i]-k)+1<=t[i])l=i;
#define B7F if(a[i]>=k&&abs(a[i]-k)+1<=t[i])r=i;
#define B7E if(dis[pos][i]+time>t[i])continue;
#define B7D scanf("%lld%lld%lld",&n,&k,&m);
#define B7C freopen("go.out","w",stdout);
#define B7B if(a[i]>=l&&a[i]<=r)continue;
#define B7A freopen("go.in","r",stdin);
#define B79 dis[i][j]=abs(a[i]-a[j]);
#define B78 a[MAXN],b[MAXN],t[MAXN];
#define B77 printf("%lld\n",sum);
#define B76 i=pos+1;i<=m;++i)
#define B75 i=pos-1;i>=1;--i)
#define B74 sum=max(ans,sum);
#define B73 dis[MAXN][MAXN];
#define B72 j=1;j<=m;++j)
#define B71 i=m;i>=1;--i)
#define B70 if(time>2000)
#define B6F i=1;i<=m;++i)
#define B6E ___0xffff___
#define B6D 0x634b7935
#define B6C 0x634ccaf1
#define B6B find(long
#define B6A namespace
#define B69 time,long
#define B68 l=0,r=0;
#define B67 pos,long
#define B66 for(long
#define B65 if(l!=0)
#define B64 if(r!=0)
#define B63 return;
#define B62 break;
#define B61 l,long
#define B60 n,k,m;
#define B5F r,long
#define B5E return
#define B5D printf
#define B5C sum=0;
#define B5B using
#define B5A 0xc3
#define B59 0xc6
#define B58 0xc7
#define B57 0xc8
#define B56 0xca
#define B55 0xcb
#define B54 0xcc
#define B53 0xce
#define B52 0xcf
#define B51 0xd0
#define B50 0xd1
#define B4F 0xd2
#define B4E 0xd3
#define B4D 0xd4
#define B4C 0xd5
#define B4B 0xd7
#define B4A 0xda
#define B49 0xde
#define B48 0xdf
#define B47 0xe7
#define B46 0xe8
#define B45 0xeb
#define B44 0xf7
#define B43 0xf8
#define B42 0xfa
#define B41 0xfd
#define B40 ans)
#define B3F char
#define B3E else
#define B3D "%s"
#define B3C "\n"
#define B3B 0x20
#define B3A 0x23
#define B39 0x2d
#define B38 0x2e
#define B37 0x2f
#define B36 0x3a
#define B35 0x61
#define B34 0x62
#define B33 0x63
#define B32 0x64
#define B31 0x65
#define B30 0x66
#define B2F 0x68
#define B2E 0x6d
#define B2D 0x6f
#define B2C 0x70
#define B2B 0x73
#define B2A long
#define B29 main
#define B28 0x74
#define B27 0x78
#define B26 0xa7
#define B25 0xa8
#define B24 0xaa
#define B23 0xb1
#define B22 0xb4
#define B21 0xb5
#define B20 0xb7
#define B1F std;
#define B1E 0xb9
#define B1D 0xbc
#define B1C time
#define B1B 0xc1
#define B1A 0xc2
#define B19 void
#define B18 int
#define B17 0xa
#define B16 0x0
#define B15 ()
#define B14 &&
#define B13 if
#define B12 0;
#define B11 d,
#define B10 =
#define BF )
#define BE (
#define BD >
#define BC [
#define BB ]
#define BA a
#define B9 ;
#define B8 b
#define B7 c
#define B6 <
#define B5 d
#define B4 0
#define B3 ,
#define B2 e
#define B1 {
#define B0 }
#include <time.h>
#include<bits/stdc++.h>
#define MAXN 6101
#define B86 B5B B6A B1F B2A B2A B78 B2A B2A B73 B2A
#define B87 B2A B60 B2A B2A B5C B19 B6B B2A B67 B2A
#define B88 B61 B2A B5F B2A B69 B2A B40 B1 B74 B70
#define B89 B63 B66 B2A B75 B1 B7B B7E B85 B62 B0
#define B8A B66 B2A B76 B1 B7B B7E B84 B62 B0 B5E
#define B8B B9 B0 B18 B6E B15 B1 B7A B7C B7D B66
#define B8C B2A B6F B1 B81 B0 B66 B2A B6F B1 B66
#define B8D B2A B72 B1 B79 B0 B0 B2A B2A B68 B66
#define B8E B2A B6F B80 B66 B2A B71 B7F B65 B83 B64
#define B8F B82 B77 B5E B12 B0 B18 B29 BE BF B1
#define B90 B13 BE B1C BE B4 BF BD B6D B14 B1C
#define B91 BE B4 BF B6 B6C BF B1 B6E BE BF
#define B92 B9 B0 B3E B1 B3F BA BC BB B10 B1
#define B93 BE B3F BF B3A B3 BE B3F BF B3B B3
#define B94 BE B3F BF B22 B3 BE B3F BF B42 B3
#define B95 BE B3F BF B1A B3 BE B3F BF B45 B3
#define B96 BE B3F BF B56 B3 BE B3F BF B23 B3
#define B97 BE B3F BF B51 B3 BE B3F BF B26 B3
#define B98 BE B3F BF B1E B3 BE B3F BF B41 B3
#define B99 BE B3F BF B59 B3 BE B3F BF B4A B3
#define B9A BE B3F BF B4F B3 BE B3F BF B50 B3
#define B9B BE B3F BF B53 B3 BE B3F BF B49 B3
#define B9C BE B3F BF B20 B3 BE B3F BF B25 B3
#define B9D BE B3F BF B4D B3 BE B3F BF B55 B3
#define B9E BE B3F BF B51 B3 BE B3F BF B51 B3
#define B9F BE B3F BF B3B B3 BE B3F BF B3A B3
#define BA0 BE B3F BF B16 B0 B9 B3F B8 BC BB
#define BA1 B10 B1 BE B3F BF B3A B3 BE B3F BF
#define BA2 B3B B3 BE B3F BF B57 B3 BE B3F BF
#define BA3 B47 B3 BE B3F BF B51 B3 BE B3F BF
#define BA4 B46 B3 BE B3F BF B1D B3 BE B3F BF
#define BA5 B54 B3 BE B3F BF B51 B3 BE B3F BF
#define BA6 B43 B3 BE B3F BF B56 B3 BE B3F BF
#define BA7 B1E B3 BE B3F BF B4E B3 BE B3F BF
#define BA8 B5A B3 BE B3F BF B58 B3 BE B3F BF
#define BA9 B45 B3 BE B3F BF B1B B3 BE B3F BF
#define BAA B24 B3 BE B3F BF B52 B3 BE B3F BF
#define BAB B21 B3 BE B3F BF B4B B3 BE B3F BF
#define BAC B44 B3 BE B3F BF B4C B3 BE B3F BF
#define BAD B48 B3 BE B3F BF B3B B3 BE B3F BF
#define BAE B3A B3 BE B3F BF B16 B0 B9 B3F B7
#define BAF BC BB B10 B1 BE B3F BF B39 B3 BE
#define BB0 B3F BF B39 B3 BE B3F BF B3B B3 BE
#define BB1 B3F BF B2F B3 BE B3F BF B28 B3 BE
#define BB2 B3F BF B28 B3 BE B3F BF B2C B3 BE
#define BB3 B3F BF B2B B3 BE B3F BF B36 B3 BE
#define BB4 B3F BF B37 B3 BE B3F BF B37 B3 BE
#define BB5 B3F BF B33 B3 BE B3F BF B2D B3 BE
#define BB6 B3F BF B32 B3 BE B3F BF B31 B3 BE
#define BB7 B3F BF B30 B3 BE B3F BF B2D B3 BE
#define BB8 B3F BF B27 B3 BE B3F BF B38 B3 BE
#define BB9 B3F BF B28 B3 BE B3F BF B35 B3 BE
#define BBA B3F BF B2D B3 BE B3F BF B34 B3 BE
#define BBB B3F BF B35 B3 BE B3F BF B2D B3 BE
#define BBC B3F BF B38 B3 BE B3F BF B33 B3 BE
#define BBD B3F BF B2D B3 BE B3F BF B2E B3 BE
#define BBE B3F BF B3B B3 BE B3F BF B39 B3 BE
#define BBF B3F BF B39 B3 BE B3F BF B17 B3 BE
#define BC0 B3F BF B16 B0 B9 B3F B5 BC BB B10
#define BC1 B3D B9 B3F B2 BC BB B10 B3C B9 B5D
#define BC2 BE B11 BA BF B9 B5D BE B2 BF B9
#define BC3 B5D BE B11 B8 BF B9 B5D BE B2 BF
#define BC4 B9 B5D BE B11 B7 BF B9 B0 B5E B12
#define BC5 B0 
#define BC6 B86 B87 B88 B89 B8A B8B B8C B8D B8E B8F
#define BC7 B90 B91 B92 B93 B94 B95 B96 B97 B98 B99
#define BC8 B9A B9B B9C B9D B9E B9F BA0 BA1 BA2 BA3
#define BC9 BA4 BA5 BA6 BA7 BA8 BA9 BAA BAB BAC BAD
#define BCA BAE BAF BB0 BB1 BB2 BB3 BB4 BB5 BB6 BB7
#define BCB BB8 BB9 BBA BBB BBC BBD BBE BBF BC0 BC1
#define BCC BC2 BC3 BC4 BC5 
#define BCD BC6 BC7 BC8 BC9 BCA BCB BCC 
#define BCE(__FOX__) __FOX__
BCE(BCD)
