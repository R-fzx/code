using System;
using System.IO;

public class fa
{
	public static int[] a=new int[200010];
}

public class number
{
	StreamReader fin=new StreamReader("magician.in");
	public void read(ref int a,ref int b)
	{
		string s=fin.ReadLine();
		int n=s.Length;
		a=0; b=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==' ') {a=b; b=0;}
			else b=b*10+s[i]-'0';
		}
	}
}

public class magician
{
	static StreamWriter fout=new StreamWriter("magician.out");
	public static int get(int x)
	{
		if(x==fa.a[x]) return x;
		return fa.a[x]=get(fa.a[x]);
	}
	public static void Main()
	{
		int n=0,m=0,x=0,y=0,ans=1,mod=1000000009;
		number scanf=new number();
		scanf.read(ref n,ref m);
		for(int i=1;i<=n;i++) fa.a[i]=i;
		for(int i=1;i<=m;i++)
		{
			scanf.read(ref x,ref y);
			if(get(x)==get(y)) ans=ans*2%mod;
			else fa.a[get(y)]=get(x);
			fout.WriteLine("{0}",ans-1);
		}
		fout.Close();
	}
}