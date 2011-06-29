/*
								The MIT License  
								
	Copyright (c) <2010> <yezizhu>  
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:  

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.  
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.  
	==================================
	��Ȩ(c) <2010> <yezizhu>  

	ʹ�ø����֤���������������Ȩ�ޣ���ѣ��κ��˿��Եõ���������������ĵ���һ��������
	���Ҿ�Ӫ����������κ����ƣ����������Ƶ�ʹ�á����ơ��޸ġ��ϲ������桢���С����Ŵ���֤�顢���߳��۸�����Ŀ�����Ȩ����
	ͬʱ��������Щ������û�������ЩȨ����ʹ����������������  
	
	���ϵİ�Ȩ֪ͨ��Ȩ��֪ͨӦ�ð��������и�����Ŀ����л������������������ʵ�����С�
	
	������������������ṩ��û���κ���ʽ�ĵ�������������ȷ�ػ��߰����ģ�������Щ���ǲ�����ҵ���ʵĵ��������ơ�
	�ʺ�һ���ض�����;���Ҳ����ַ������ߺͰ�Ȩ���������κγ��϶�ʹ�ø�����漰���κ�Ҫ���𺦻����������ζ���Ӧ����
	�����������������û���ֻ�Ǻ�ͬ��ʽ��������Ȩ����������ʽ�������������������÷�Χ�ڡ�����������ϵ���������ʹ�û����������������������Ϊ��  
	=====================================   
*/	

#define WL_MODE_NAME		"wl" //Do not modtify
#define WL_VERSION			"0.6.8.3"
#define WL_BUILD_TIME		"201106280030"

#define MAX_FILE_STR	(256)
#define MAX_MSG_STR		(128)
#define MAX_DIALOG_STR	(2046)
#define MAX_SQL_STR		(1024)

#include <wl\wl_main>

//===========================================================================================//
/*
*	Copyright
*		You can add some more infomation, 
*		but do not remove any COPYRIGHT information.
*/
wl_copyright(){
	printf ("===============================================================================");
	printf ("  GameMode:%s",WL_MODE_NAME);
	printf ("  Version: %s",WL_VERSION);
	printf ("  Build:   %s",WL_BUILD_TIME);
	printf ("  Contributors(Alphabetical order):");
	printf ("    FGJin, fly_luck,  [ITC]dyq  [ITC]fangye  [ITC]Super_wlc  [ITC]RR_LXD");
	printf ("    mk124  Shindo(aka. ssh)  vvg, yezizhu(aka. yzz)");
	printf ("  This is a part of OpenGTA project, visit www.opengta.org for more info.");
	printf ("  Contact us: imyezizhu@opengta.org");
	printf ("  Copyright: yezizhu & GCS Team");
	printf ("===============================================================================");
}
zcmd(wl,playerid,params[]){
	System_send (playerid,"===============================================================================");
	System_send (playerid,"  GameMode:%s",WL_MODE_NAME);
	System_send (playerid,"  Version: %s",WL_VERSION);
	System_send (playerid,"  Build:   %s",WL_BUILD_TIME);
	System_send (playerid,"  Contributors(Alphabetical order):");
	System_send (playerid,"    FGJin, fly_luck,  [ITC]dyq  [ITC]fangye  [ITC]Super_wlc  [ITC]RR_LXD");
	System_send (playerid,"    mk124  Shindo(aka. ssh)  vvg, yezizhu(aka. yzz)");
	System_send (playerid,"  This is a part of OpenGTA project, visit www.opengta.org for more info.");
	System_send (playerid,"  Contact us: imyezizhu@opengta.org");
	System_send (playerid,"  Copyright: yezizhu & GCS Team");
	System_send (playerid,"===============================================================================");	
	return true;
}
/*
*
*
*
*
*/
//===========================================================================================//
stock debug_public_track(str[]){
	//printf("%s",str);
	new y,d,m,h,minute,s;
	getdate(y,d,m);
	gettime(h,minute,s);
	printf("[%04d/%02d/%02d-%02d:%02d:%02d]%s",y,d,m,h,minute,s,str);
}
main(){
	wl_copyright();
}

public OnPlayerLogin(playerid){ debug_public_track("OnPlayerLogin(playerid)");
	dmw_playerLogin(playerid);
	return true;
}

forward autoRestart();
public autoRestart(){ debug_public_track("autoRestart()");
	new
		h,m,s;
	gettime(h,m,s);
	if(h == 7 && m == 50){
		SendRconCommand("exit");
	}
}

AntiDeAMX()
{
    new a[][] =
    {
        "Unarmed (Fist)",
        "Brass K"
    };
    #pragma unused a
}






















