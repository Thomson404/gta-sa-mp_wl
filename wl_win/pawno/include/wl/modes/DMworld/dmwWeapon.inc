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

	ʹ�ø�����֤����������������Ȩ�ޣ���ѣ��κ��˿��Եõ����������������ĵ���һ��������
	���Ҿ�Ӫ�����������κ����ƣ����������Ƶ�ʹ�á����ơ��޸ġ��ϲ������桢���С����Ŵ���֤�顢���߳��۸������Ŀ�����Ȩ����
	ͬʱ���������Щ�������û�������ЩȨ����ʹ����������������  
	
	���ϵİ�Ȩ֪ͨ��Ȩ��֪ͨӦ�ð��������и������Ŀ����л�������������������ʵ�����С�
	
	�������������������ṩ��û���κ���ʽ�ĵ�������������ȷ�ػ��߰����ģ�������Щ���ǲ�����ҵ���ʵĵ��������ơ�
	�ʺ�һ���ض�����;���Ҳ����ַ������ߺͰ�Ȩ���������κγ��϶�ʹ�ø������漰���κ�Ҫ���𺦻����������ζ���Ӧ����
	�����������������û���ֻ�Ǻ�ͬ��ʽ��������Ȩ����������ʽ�������������������÷�Χ�ڡ������������ϵ����������ʹ�û�����������������������Ϊ��  
	=====================================   
*/	



new stock
	g_dmweaponDialogID = 1337 , 
	g_dmwweaponDialog[MAX_DIALOG_STR], 
	g_dmwweaponName[][32] = {
		{	"BrasskNuckle"	} ,
		{	"GolfClub"	} ,
		{	"Nightstick"	} ,
		{	"Knife"	} ,
		{	"Bat"	} ,
		{	"Shovel"	} ,
		{	"Poolstick"	} ,
		{	"Katana"	} ,
		{	"Chainsaw"	} ,
		{	"Dildo"	} ,
		{	"Dildo2"	} ,
		{	"Vibrator"	} ,
		{	"Vibrator2"	} ,
		{	"Flower"	} ,
		{	"Cane"	} ,
		{	"Grenade"	} ,
		{	"Teargas"	} ,
		{	"Moltov"	} ,
		{	"Colt45"	} ,
		{	"Slienced"	} ,
		{	"Deagle"	} ,
		{	"Shotgun"	} ,
		{	"Sawedoff"	} ,
		{	"ShotSPA"	} ,
		{	"uzi"	} ,
		{	"mp5"	} ,
		{	"ak47"	} ,
		{	"m4"	} ,
		{	"tec9"	} ,
		{	"rifle"	} ,
		{	"sniper"	} ,
		{	"rocketluncher"	} ,
		{	"heatseeker"	} ,
		{	"flamethrower"	} ,
		{	"minigun"	} ,
		{	"satchel"	} ,
		{	"bomb"	} ,
		{	"spraycan"	} ,
		{	"fierextinguisher"	} ,
		{	"camera"	} ,
		{	"parachute"	} 
	},
	g_dmwweaponID[] = {
		WEAPON_BRASSKNUCKLE,				
		WEAPON_GOLFCLUB,					
		WEAPON_NITESTICK,				
		WEAPON_KNIFE,					
		WEAPON_BAT,						
		WEAPON_SHOVEL,					
		WEAPON_POOLSTICK,				
		WEAPON_KATANA,					
		WEAPON_CHAINSAW,					
		WEAPON_DILDO,					
		WEAPON_DILDO2,					
		WEAPON_VIBRATOR,					
		WEAPON_VIBRATOR2,				
		WEAPON_FLOWER,					
		WEAPON_CANE	,					
		WEAPON_GRENADE,					
		WEAPON_TEARGAS,					
		WEAPON_MOLTOV,					
		WEAPON_COLT45,					
		WEAPON_SILENCED	,				
		WEAPON_DEAGLE,					
		WEAPON_SHOTGUN,					
		WEAPON_SAWEDOFF,					
		WEAPON_SHOTGSPA,					
		WEAPON_UZI,						
		WEAPON_MP5,						
		WEAPON_AK47,						
		WEAPON_M4,						
		WEAPON_TEC9,						
		WEAPON_RIFLE,					
		WEAPON_SNIPER,					
		WEAPON_ROCKETLAUNCHER,			
		WEAPON_HEATSEEKER,				
		WEAPON_FLAMETHROWER,				
		WEAPON_MINIGUN,					
		WEAPON_SATCHEL,					
		WEAPON_BOMB,						
		WEAPON_SPRAYCAN,					
		WEAPON_FIREEXTINGUISHER,			
		WEAPON_CAMERA,					
		WEAPON_PARACHUTE				
	};

dmwweapon:struct(){
	if(!fexist("wl/DMWorld/gunprice.ini")){ 
		print (" Error: File wl/DMWorld/gunprice.ini not exist, init failed.");
		abort();
	}
	
	gini_open("wl/DMWorld/gunprice.ini");
	for(new i,j = sizeof(g_dmwweaponID),price,amount,set; i < j;i++){
		sscanf(gini_reads(g_dmwweaponName[i]),"p,iii",price,amount,set);
		//if(set){
			SetGVarInt("wl_dmw_weapon_price",price,g_dmwweaponID[i]);
			SetGVarInt("wl_dmw_weapon_amount",amount,g_dmwweaponID[i]);
			SetGVarInt("wl_dmw_weapon_set",set,g_dmwweaponID[i]);	
		//}
	}
	gini_close();
	new	
		tmpstr[256];
	//format(g_dmwweaponDialog,sizeof(g_dmwweaponDialog),"[����]           [��ҩ]  [����]\n");
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_BRASSKNUCKLE)){
		format(tmpstr,sizeof(tmpstr),"ȭ��               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_BRASSKNUCKLE),GetGVarInt("wl_dmw_weapon_price",WEAPON_BRASSKNUCKLE));
		strcat(g_dmwweaponDialog,tmpstr);
	//}
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_GOLFCLUB)){
		format(tmpstr,sizeof(tmpstr),"�߶������  %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_GOLFCLUB),GetGVarInt("wl_dmw_weapon_price",WEAPON_GOLFCLUB));
		strcat(g_dmwweaponDialog,tmpstr);
	//}
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_NITESTICK)){
		format(tmpstr,sizeof(tmpstr),"����               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_NITESTICK),GetGVarInt("wl_dmw_weapon_price",WEAPON_NITESTICK));
		strcat(g_dmwweaponDialog,tmpstr);
	//}
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_KNIFE)){
		format(tmpstr,sizeof(tmpstr),"{FF0000}С��               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_KNIFE),GetGVarInt("wl_dmw_weapon_price",WEAPON_KNIFE));
		strcat(g_dmwweaponDialog,tmpstr);
	//}
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_BAT)){
		format(tmpstr,sizeof(tmpstr),"���               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_BAT),GetGVarInt("wl_dmw_weapon_price",WEAPON_BAT));
		strcat(g_dmwweaponDialog,tmpstr);
	//}
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SHOVEL)){
		format(tmpstr,sizeof(tmpstr),"����               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SHOVEL),GetGVarInt("wl_dmw_weapon_price",WEAPON_SHOVEL));
		strcat(g_dmwweaponDialog,tmpstr);
	//}	
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_POOLSTICK)){
		format(tmpstr,sizeof(tmpstr),"����               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_POOLSTICK),GetGVarInt("wl_dmw_weapon_price",WEAPON_POOLSTICK));
		strcat(g_dmwweaponDialog,tmpstr);
	//}	
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_KATANA)){
		format(tmpstr,sizeof(tmpstr),"�ձ���           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_KATANA),GetGVarInt("wl_dmw_weapon_price",WEAPON_KATANA));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_CHAINSAW)){
		format(tmpstr,sizeof(tmpstr),"{FF0000}���               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_CHAINSAW),GetGVarInt("wl_dmw_weapon_price",WEAPON_CHAINSAW));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_DILDO)){
		format(tmpstr,sizeof(tmpstr),"�󽫾�           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_DILDO),GetGVarInt("wl_dmw_weapon_price",WEAPON_DILDO));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_DILDO2)){
		format(tmpstr,sizeof(tmpstr),"�ҽ���           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_DILDO2),GetGVarInt("wl_dmw_weapon_price",WEAPON_DILDO2));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_VIBRATOR)){
		format(tmpstr,sizeof(tmpstr),"������           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_VIBRATOR),GetGVarInt("wl_dmw_weapon_price",WEAPON_VIBRATOR));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_VIBRATOR2)){
		format(tmpstr,sizeof(tmpstr),"�󽫾�           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_VIBRATOR2),GetGVarInt("wl_dmw_weapon_price",WEAPON_VIBRATOR2));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_FLOWER)){
		format(tmpstr,sizeof(tmpstr),"�ʻ�               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_FLOWER),GetGVarInt("wl_dmw_weapon_price",WEAPON_FLOWER));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_CANE)){
		format(tmpstr,sizeof(tmpstr),"����               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_CANE),GetGVarInt("wl_dmw_weapon_price",WEAPON_CANE));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_GRENADE)){
		format(tmpstr,sizeof(tmpstr),"{FF0000}����               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_GRENADE),GetGVarInt("wl_dmw_weapon_price",WEAPON_GRENADE));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_TEARGAS)){
		format(tmpstr,sizeof(tmpstr),"���ᵯ           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_TEARGAS),GetGVarInt("wl_dmw_weapon_price",WEAPON_TEARGAS));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_MOLTOV)){
		format(tmpstr,sizeof(tmpstr),"{FF0000}ȼ�յ�           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_MOLTOV),GetGVarInt("wl_dmw_weapon_price",WEAPON_MOLTOV));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_COLT45)){
		format(tmpstr,sizeof(tmpstr),"��ǹ               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_COLT45),GetGVarInt("wl_dmw_weapon_price",WEAPON_COLT45));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SILENCED)){
		format(tmpstr,sizeof(tmpstr),"������ǹ       %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SILENCED),GetGVarInt("wl_dmw_weapon_price",WEAPON_SILENCED));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_DEAGLE)){
		format(tmpstr,sizeof(tmpstr),"{00FF00}ɳĮ֮ӥ       %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_DEAGLE),GetGVarInt("wl_dmw_weapon_price",WEAPON_DEAGLE));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SHOTGUN)){
		format(tmpstr,sizeof(tmpstr),"����ǹ           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SHOTGUN),GetGVarInt("wl_dmw_weapon_price",WEAPON_SHOTGUN));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SAWEDOFF)){
		format(tmpstr,sizeof(tmpstr),"��������ǹ   %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SAWEDOFF),GetGVarInt("wl_dmw_weapon_price",WEAPON_SAWEDOFF));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SHOTGSPA)){
		format(tmpstr,sizeof(tmpstr),"{00FF00}ս������ǹ   %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SHOTGSPA),GetGVarInt("wl_dmw_weapon_price",WEAPON_SHOTGSPA));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_UZI)){
		format(tmpstr,sizeof(tmpstr),"uzi���ǹ       %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_UZI),GetGVarInt("wl_dmw_weapon_price",WEAPON_UZI));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_MP5)){
		format(tmpstr,sizeof(tmpstr),"mp5                 %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_MP5),GetGVarInt("wl_dmw_weapon_price",WEAPON_MP5));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_AK47)){
		format(tmpstr,sizeof(tmpstr),"AK47               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_AK47),GetGVarInt("wl_dmw_weapon_price",WEAPON_AK47));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_M4)){
		format(tmpstr,sizeof(tmpstr),"{00FF00}M4                   %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_M4),GetGVarInt("wl_dmw_weapon_price",WEAPON_M4));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_TEC9)){
		format(tmpstr,sizeof(tmpstr),"Tec9���ǹ   %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_TEC9),GetGVarInt("wl_dmw_weapon_price",WEAPON_TEC9));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_RIFLE)){
		format(tmpstr,sizeof(tmpstr),"��ǹ               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_RIFLE),GetGVarInt("wl_dmw_weapon_price",WEAPON_RIFLE));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SNIPER)){
		format(tmpstr,sizeof(tmpstr),"�ѻ�ǹ           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SNIPER),GetGVarInt("wl_dmw_weapon_price",WEAPON_SNIPER));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_ROCKETLAUNCHER)){
		format(tmpstr,sizeof(tmpstr),"{FF0000}�����           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_ROCKETLAUNCHER),GetGVarInt("wl_dmw_weapon_price",WEAPON_ROCKETLAUNCHER));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_HEATSEEKER)){
		format(tmpstr,sizeof(tmpstr),"��Ѱ���       %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_HEATSEEKER),GetGVarInt("wl_dmw_weapon_price",WEAPON_HEATSEEKER));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_FLAMETHROWER)){
		format(tmpstr,sizeof(tmpstr),"�����           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_FLAMETHROWER),GetGVarInt("wl_dmw_weapon_price",WEAPON_FLAMETHROWER));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_MINIGUN)){
		format(tmpstr,sizeof(tmpstr),"{FF0000}�����           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_MINIGUN),GetGVarInt("wl_dmw_weapon_price",WEAPON_MINIGUN));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SATCHEL)){
		format(tmpstr,sizeof(tmpstr),"{FF0000}����ըҩ��   %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SATCHEL),GetGVarInt("wl_dmw_weapon_price",WEAPON_SATCHEL));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_BOMB)){
		format(tmpstr,sizeof(tmpstr),"������           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_BOMB),GetGVarInt("wl_dmw_weapon_price",WEAPON_BOMB));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_SPRAYCAN)){
		format(tmpstr,sizeof(tmpstr),"����               %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_SPRAYCAN),GetGVarInt("wl_dmw_weapon_price",WEAPON_SPRAYCAN));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_FIREEXTINGUISHER)){
		format(tmpstr,sizeof(tmpstr),"�����           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_FIREEXTINGUISHER),GetGVarInt("wl_dmw_weapon_price",WEAPON_FIREEXTINGUISHER));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_CAMERA)){
		format(tmpstr,sizeof(tmpstr),"�����           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_CAMERA),GetGVarInt("wl_dmw_weapon_price",WEAPON_CAMERA));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
	//if(GetGVarInt("wl_dmw_weapon_set",WEAPON_PARACHUTE)){
		format(tmpstr,sizeof(tmpstr),"����ɡ           %04d   %04d\n",GetGVarInt("wl_dmw_weapon_amount",WEAPON_PARACHUTE),GetGVarInt("wl_dmw_weapon_price",WEAPON_PARACHUTE));
		strcat(g_dmwweaponDialog,tmpstr);
	//}				
				
					
	/*	
	format(g_dmwweaponDialog,sizeof(g_dmwweaponDialog),"[�������] [����/����] [��������]\n");
	for(new i,j = sizeof(g_dmwweaponID),tmpstr[MAX_MSG_STR];i < j;i++){
		format(tmpstr,sizeof(tmpstr),"|%d|%d|%24s\n",GetGVarInt("wl_dmw_weapon_price",g_dmwweaponID[i]),GetGVarInt("wl_dmw_weapon_amount",g_dmwweaponID[i]),g_dmwweaponName[i]);
		strcat(g_dmwweaponDialog,tmpstr);
	}
	*/
}
dmwweapon:DialogResponse(playerid,dialogid,response,listitem){	
	if(dialogid == g_dmweaponDialogID && response){
		if(listitem > 0 && listitem <= sizeof(g_dmwweaponID)){
			new
				index = listitem;
			
			if(!GetGVarInt("wl_dmw_weapon_set",g_dmwweaponID[index])){
				dmw:send(playerid,"dmw_dialog_buyweapon_denied_notsale");
				return;
			}	
			
			new
				price = GetGVarInt("wl_dmw_weapon_price",g_dmwweaponID[index]),
				amount = GetGVarInt("wl_dmw_weapon_amount",g_dmwweaponID[index]);
			if(dmwscore:getPlayerGang(playerid) - price < 0){
				dmw:send(playerid,"dmw_dialog_buyweapon_denied_outofscore");
				return;
			}
			dmwscore:amountedPlayerGang(playerid, 0 - price);
			
			new
				weaponid,ammo;
			GetPlayerWeaponData(playerid,Weapon_getSlotfromID(g_dmwweaponID[index]),weaponid,ammo);
			GivePlayerWeapon(playerid,g_dmwweaponID[index],amount);
			dmwweapon:cache_set(playerid,g_dmwweaponID[index],amount+ammo);
			gang:sendgang(gang:getPlayerGang(playerid),"dmw_dialog_buyweapon_pass",pName(playerid),playerid,price,g_dmwweaponName[index],amount);
		}
	}
}
dmwweapon:cache_set(playerid,weaponid,ammo){
	SetGVarInt("wl_dmw_pweapon_weaponid",weaponid,getDoubleRelationList(playerid,Weapon_getSlotfromID(weaponid)));
	SetGVarInt("wl_dmw_pweapon_ammo",ammo,getDoubleRelationList(playerid,Weapon_getSlotfromID(weaponid)));
}
dmwweapon:cache_reset(playerid){
	for(new i;i < MAX_WEAPON_SLOT;i++){
		SetGVarInt("wl_dmw_pweapon_weaponid",0,getDoubleRelationList(playerid,i));
		SetGVarInt("wl_dmw_pweapon_ammo",0,getDoubleRelationList(playerid,i));
	}
}
dmwweapon:cache_delete(playerid){
	for(new i;i < MAX_WEAPON_SLOT;i++){
		DeleteGVar("wl_dmw_pweapon_weaponid",getDoubleRelationList(playerid,i));
		DeleteGVar("wl_dmw_pweapon_ammo",getDoubleRelationList(playerid,i));
	}
}

/*
dmwweapon:save_struct(){
	{
		db_processstart("ALTER TABLE player_account ADD COLUMN dmw_weapon TEXT NOT NULL DEFAULT '0';");
		db_processthenfree(db_user);
	}
	{
		db_processstart("SELECT id,dmw_weapon FROM player_account;");
		db_processthengetresult(db_user);
		for(new i,j = db_num_rows(dbr),id[11],weaponid[MAX_WEAPON_SLOT][11],ammo[MAX_WEAPON_SLOT][11]; i < j;i++){
			db_get_field_assoc(dbr,"id",id,sizeof(id));
			for(new k; k < MAX_WEAPON_SLOT; k++){
				db_get_field_assoc(dbr,"dmw_weapon",weaponid,sizeof(weapondata));
				SetGVarInt("wl_user_dmw_slotweapon",,getDoubleRelationList(playerid,k));
			
			for(new k,odd=1; weapondata[k];k++){
				if(k == ';')odd++;
				if(odd%2 == 1){
					SetGVarInt("wl_user_dmw_slotweapon",getDoubleRelationList(playerid,))
					
			for(new k; k < MAX_WEAPON_SLOT;k++){
				if(GetGVarInt("wl_user_dmw_slotweaponid",getDoubleRelationList(playerid,k))){
*/
/*		
dmwweapon:playerDisconnect(playerid,reason){
	new
		weaponid,ammo;
	for(new i;i<13;i++){
		GetPlayerWeaponData(playerid,i,weaponid,ammo);
		printf( "%05d %05d %05d",i,weaponid,ammo);
	}
}
*/

dmwweapon:Command_ShowDialog(playerid){
	new
		zonegangid = zone:getOwnedGang(zone:getPlayerZoneByPosition(playerid)),
		playergangid = gang:getPlayerGang(playerid);
	if(!dmw:getPlayer(playerid)){
		dmw:send(playerid,"cmd_dmw_buyweapon_denied_notindmw");
		return;
	}		
	if(zonegangid == INVALID_GANG_ID){
		dmw:send(playerid,"cmd_dmw_buyweapon_denied_notinzone");
		return;
	}
	if(playergangid == INVALID_GANG_ID){
		dmw:send(playerid,"cmd_dmw_buywewapon_denied_notingang");
		return;
	}
	if(zonegangid != playergangid){
		dmw:send(playerid,"cmd_dmw_buywewapon_denied_notinselfzone");
		return;
	}
	ShowPlayerDialog(playerid, g_dmweaponDialogID, DIALOG_STYLE_LIST, "    ��������             ��ҩ���� ��Ҫ����", g_dmwweaponDialog, "ѡ��", "ȡ��");
}

dmwweapon:cache_playerDeath(playerid){
	dmwweapon:cache_reset(playerid);
}
dmwweapon:cache_playerSpawn(playerid){
	dmwweapon:cache_reset(playerid);
}
/*
dmwweapon:cache_playerLeaveDMW(playerid){
	dmwweapon:cache_delete(playerid);
}
*/
dmwweapon:cache_playerConnect(playerid){
	dmwweapon:cache_delete(playerid);
}	
dmwweapon:cache_playerDisconnect(playerid){
	dmwweapon:cache_delete(playerid);
}