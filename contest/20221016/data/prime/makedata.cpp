/*
* Copyright (c) 2012，欧阳建昭
* All rights reserved.
*
* 文件名称：makedata
* 文件标识：makedata
* 摘    要：利用标程的Exe文件生成测试数据。
*
* 当前版本：1.0
* 作    者：欧阳建昭
* 完成日期：2012年5月13日
*
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<ctime>

using namespace std;

const int maxlen=256;

const char *filename="prime";  //主文件名
const char *extin=".in";      //输入文件扩展名
const char *extout=".out";    //输出文件扩展名
const char *extexe=".exe";   //可执行文件名 
const int imin=4;        //最小测试数据下标
const int imax=10;       //最大测试数据下标

char filein[maxlen]="", fileout[maxlen]="", fileexe[maxlen]="";//输入文件，输出文件，执行文件名

void makedatain(int index)//生成输入数据 
{
	//int n = (double)rand() / RAND_MAX * 1000 + 99000;
	//int m = (double)rand() / RAND_MAX * 1000 + 99000;
    int t = 500;
    printf("%d\n",t);
    for(int i = 1;i <= t;i++)
    {
    	int n = (rand()%31000 + 1)*(rand()%32000 + 1);
    	printf("%d\n",n);
	}
}

/*以下不修改********************************************************/ 

void makefilein(char *filein, int index)//生成第index组输入文件 
{
     freopen(filein,"w",stdout);
     makedatain(index);
     fclose(stdout);
}

void initfilename()
{
     strcat(filein,filename);
     strcat(filein,extin);
     
     strcat(fileout,filename);
     strcat(fileout,extout);
     
     strcat(fileexe,filename);
     strcat(fileexe,extexe);
}

DWORD winexecandwait(char *filename, int visibility=0)
{
    char szappname[512],szcurdir[512];
    STARTUPINFO startupinfo;
    PROCESS_INFORMATION processinfo;
    
    strcpy(szappname,filename);
    GetCurrentDirectory(MAX_PATH,szcurdir); 
    memset(&startupinfo,0,sizeof(startupinfo));
    startupinfo.cb=sizeof(startupinfo);
    startupinfo.dwFlags=STARTF_USESHOWWINDOW;
    startupinfo.wShowWindow=visibility;
    if (!CreateProcess(NULL,szappname,NULL,NULL,false,CREATE_NEW_CONSOLE |
       NORMAL_PRIORITY_CLASS, NULL, szcurdir, &startupinfo, &processinfo))
    {
        return 0;
    }
    else
    {
        WaitForSingleObject(processinfo.hProcess,INFINITE);
        DWORD result=0;
        GetExitCodeProcess(processinfo.hProcess,&result);
        return result;
    }
}

int main()
{
    srand(time(NULL));
    initfilename();
    char fileini[maxlen],fileouti[maxlen],index[maxlen];//第i组输入输出文件名 
    
    for (int i=imin;i<=imax;i++)
    {
        itoa(i,index,10);
        memset(fileini,0,sizeof(fileini));
        strcat(fileini,filename);//生成文件名 
        strcat(fileini,index);
        strcat(fileini,extin);

        memset(fileouti,0,sizeof(fileouti));
        strcat(fileouti,filename);
        strcat(fileouti,index);
        strcat(fileouti,extout);

        //删除原来的文件 
        DeleteFile(filein);
        DeleteFile(fileout);
        DeleteFile(fileini);
        DeleteFile(fileouti);
        
        //生成输入数据  
        makefilein(filein,i);
        
        //调用fileexe生成输出文件 
        //system(fileexe);
        winexecandwait(fileexe);
        
        //改名为第i组输入输出数据 
        rename(filein,fileini); 
        rename(fileout,fileouti); 
    }
    
    return 0;
}
