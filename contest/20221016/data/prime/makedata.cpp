/*
* Copyright (c) 2012��ŷ������
* All rights reserved.
*
* �ļ����ƣ�makedata
* �ļ���ʶ��makedata
* ժ    Ҫ�����ñ�̵�Exe�ļ����ɲ������ݡ�
*
* ��ǰ�汾��1.0
* ��    �ߣ�ŷ������
* ������ڣ�2012��5��13��
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

const char *filename="prime";  //���ļ���
const char *extin=".in";      //�����ļ���չ��
const char *extout=".out";    //����ļ���չ��
const char *extexe=".exe";   //��ִ���ļ��� 
const int imin=4;        //��С���������±�
const int imax=10;       //�����������±�

char filein[maxlen]="", fileout[maxlen]="", fileexe[maxlen]="";//�����ļ�������ļ���ִ���ļ���

void makedatain(int index)//������������ 
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

/*���²��޸�********************************************************/ 

void makefilein(char *filein, int index)//���ɵ�index�������ļ� 
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
    char fileini[maxlen],fileouti[maxlen],index[maxlen];//��i����������ļ��� 
    
    for (int i=imin;i<=imax;i++)
    {
        itoa(i,index,10);
        memset(fileini,0,sizeof(fileini));
        strcat(fileini,filename);//�����ļ��� 
        strcat(fileini,index);
        strcat(fileini,extin);

        memset(fileouti,0,sizeof(fileouti));
        strcat(fileouti,filename);
        strcat(fileouti,index);
        strcat(fileouti,extout);

        //ɾ��ԭ�����ļ� 
        DeleteFile(filein);
        DeleteFile(fileout);
        DeleteFile(fileini);
        DeleteFile(fileouti);
        
        //������������  
        makefilein(filein,i);
        
        //����fileexe��������ļ� 
        //system(fileexe);
        winexecandwait(fileexe);
        
        //����Ϊ��i������������� 
        rename(filein,fileini); 
        rename(fileout,fileouti); 
    }
    
    return 0;
}
