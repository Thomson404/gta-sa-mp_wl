/*******************************************************************************
 Spectate System (With player scrolling and automatic vehicle changes)
 Created 2007 - HAMM3R
 -
 Original code by kyeman - 2007
 Update to 0.2.1 R2 by tafi
 Update to 0.3 & advanced by yezizhu
*******************************************************************************/

#include <a_samp>

#define COLOR_BASIC 0x0066FFAA
#define COLOR_RED 0xAA3333AA
#define COLOR_GREY 0xAFAFAFAA

#define ADMIN_SPEC_TYPE_NONE 0
#define ADMIN_SPEC_TYPE_PLAYER 1
#define ADMIN_SPEC_TYPE_VEHICLE 2

new gSpectateID[MAX_PLAYERS];
new gSpectateType[MAX_PLAYERS];
//new Float:gSpectatePos[MAX_PLAYERS][3];

stock Spec_Help(playerid){
	#define SPEC_HELP_DIALOG_CAPTION	"���Ӱ���"
	#define SPEC_HELP_DIALOG_INFO		"����:\n  �����ӣ���������/tv,֮��tabѡ��Ҫ�ۿ�����ҡ�\n  ����ʹ��/tv [���id]�۲�ָ����ҡ�\n  �ص��ӣ���tabѡ���Լ������˳���\n"
	#define SPEC_HELP_DIALOG_BUTTON1	"ȷ��"
	#define SPEC_HELP_DIALOG_BUTTON2	"ȡ��"
	ShowPlayerDialog(playerid, 1, DIALOG_STYLE_LIST,SPEC_HELP_DIALOG_CAPTION, SPEC_HELP_DIALOG_INFO, SPEC_HELP_DIALOG_BUTTON1, SPEC_HELP_DIALOG_BUTTON2);
}


forward Spec_isPlayerSpecing(playerid);
public Spec_isPlayerSpecing(playerid){
	return gSpectateType[playerid];
}

//Spec a player
static
	pOrginalVirtualWorld[MAX_PLAYERS];
stock StartSpectate(playerid, specid)
{
	for(new x=0; x<MAX_PLAYERS; x++) {
	    if(GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] == playerid) {
	       AdvanceSpectate(x);
		}
	}
	if(IsPlayerInAnyVehicle(specid)) {
		SetPlayerInterior(playerid,GetPlayerInterior(specid));
		TogglePlayerSpectating(playerid, 1);
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(specid));
		gSpectateID[playerid] = specid;
		gSpectateType[playerid] = ADMIN_SPEC_TYPE_VEHICLE;
	}
	else {
		SetPlayerInterior(playerid,GetPlayerInterior(specid));
		TogglePlayerSpectating(playerid, 1);
		PlayerSpectatePlayer(playerid, specid);
		gSpectateID[playerid] = specid;
		gSpectateType[playerid] = ADMIN_SPEC_TYPE_PLAYER;
	}
	if(GetPlayerVirtualWorld(specid) != GetPlayerVirtualWorld(playerid)){
		//pOrginalVirtualWorld[playerid] = GetPlayerVirtualWorld(playerid);
		SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(specid));
		SendClientMessage(playerid, COLOR_RED, "[����]���ڵ���������� - ����ѡ��۲�����");
	}
	new string[100], name[24];
	GetPlayerName(specid,name,sizeof(name));
	format(string,sizeof(string),"~n~~n~~n~~n~~n~~n~~n~~n~~w~%s - ID:%d", name,specid);
	GameTextForPlayer(playerid,string,1000,3);
}

stock StopSpectate(playerid)
{
	TogglePlayerSpectating(playerid, 0);
	gSpectateID[playerid] = INVALID_PLAYER_ID;
	gSpectateType[playerid] = ADMIN_SPEC_TYPE_NONE;
	SendClientMessage(playerid, COLOR_RED, "[����]�����ѹر�");
	GameTextForPlayer(playerid,"~n~~n~~n~~n~~n~~n~~n~~n~~w~Spectate off",1000,3);
	SetPlayerVirtualWorld(playerid,pOrginalVirtualWorld[playerid]);
	//SetPlayerPos(playerid,gSpectatePos[playerid][0],gSpectatePos[playerid][1],gSpectatePos[playerid][2]+2);
	return 1;
}


//Advancing spectated player to next valid player: FORWARD
stock AdvanceSpectate(playerid)
{
    if(ConnectedPlayers() == 2) { StopSpectate(playerid); return 1; }
	if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING && gSpectateID[playerid] != INVALID_PLAYER_ID) {
	    for(new x=gSpectateID[playerid]+1; x<=MAX_PLAYERS; x++) {
	    	if(x == MAX_PLAYERS) { x = 0; }
	        if(IsPlayerConnected(x) && x != playerid) {
				if(GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] != INVALID_PLAYER_ID ||
					(GetPlayerState(x) != 1 && GetPlayerState(x) != 2 && GetPlayerState(x) != 3))
				{
					continue;
				}
				else {
					StartSpectate(playerid, x);
					break;
				}
			}
		}
	}
	return 1;
}

//Advancing spectated player to next valid player: BACKWARDS
stock ReverseSpectate(playerid)
{
    if(ConnectedPlayers() == 2) { StopSpectate(playerid); return 1; }
	if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING && gSpectateID[playerid] != INVALID_PLAYER_ID) {
	    for(new x=gSpectateID[playerid]-1; x>=0; x--) {
	    	if(x == 0) { x = MAX_PLAYERS; }
	        if(IsPlayerConnected(x) && x != playerid) {
				if(GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] != INVALID_PLAYER_ID ||
					(GetPlayerState(x) != 1 && GetPlayerState(x) != 2 && GetPlayerState(x) != 3))
				{
					continue;
				}
				else {
					StartSpectate(playerid, x);
					break;
				}
			}
		}
	}
	return 1;
}

//Returns number of connected players
stock ConnectedPlayers()
{
	new count;
	for(new x=0; x<MAX_PLAYERS; x++) {
	    if(IsPlayerConnected(x)) {
			count++;
		}
	}
	return count;
}



public OnFilterScriptInit(){
    print("====Spectate system loaded successfully.====");
	return true;
}

public OnFilterScriptExit(){
	print("====Spectate system unloaded.====");
	return true;
}



public OnPlayerSpawn(playerid){
	if(gSpectateType[playerid] != ADMIN_SPEC_TYPE_NONE){
		//SetPlayerPos(playerid,gSpectatePos[playerid][0],gSpectatePos[playerid][1],gSpectatePos[playerid][2]+2);
		gSpectateType[playerid] = ADMIN_SPEC_TYPE_NONE;
	}
	return true;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source){
	if(gSpectateType[playerid] != ADMIN_SPEC_TYPE_NONE && source == CLICK_SOURCE_SCOREBOARD){
		new
			cmdtext[10];
		format(cmdtext,10,"/tv %d",clickedplayerid);
		if(!IsPlayerConnected(clickedplayerid)){
			SendClientMessage(playerid, COLOR_RED, "[����]��Ҫ�۲����Ҳ�����");
		}else{
			OnPlayerCommandText(playerid,cmdtext);
		}
		/*
		new
			specer = playerid,
			specee = clickedplayerid;
		if(specer == specee){
			StopSpectate(playerid);
		}else if(GetPlayerState(specee) == PLAYER_STATE_SPECTATING && gSpectateID[specee] != INVALID_PLAYER_ID) {
	   		SendClientMessage(playerid, COLOR_RED, "[����]��Ҫ�۲��������ڿ�����");
		}else if(GetPlayerState(specee) == PLAYER_STATE_NONE || GetPlayerState(specee) == PLAYER_STATE_WASTED || GetPlayerState(specee) == PLAYER_STATE_SPAWNED){
 			SendClientMessage(playerid, COLOR_RED, "[����]��Ҫ�۲����һ�û����.");
		}else{
			StartSpectate(specer, specee);
		}
		*/
	}
	return true;
}
			

public OnPlayerCommandText(playerid, cmdtext[]){
	if(!strcmp(cmdtext,"/tv",true,3)){
		if(!cmdtext[3]){
			if(gSpectateType[playerid] == ADMIN_SPEC_TYPE_NONE){
				gSpectateType[playerid] = ADMIN_SPEC_TYPE_PLAYER;
				pOrginalVirtualWorld[playerid] = GetPlayerVirtualWorld(playerid);
				TogglePlayerSpectating(playerid, 1);
				Spec_Help(playerid);
				SendClientMessage(playerid, COLOR_RED, "[����]�����Ѵ򿪣��밴tabѡ��");
				//GetPlayerPos(playerid,gSpectatePos[playerid][0],gSpectatePos[playerid][1],gSpectatePos[playerid][2]);
			}else{
				StopSpectate(playerid);
			}
		}else{
			new
				pid = strval(cmdtext[3]);
			if(IsPlayerConnected(pid)){
				if(pid == playerid){
					StopSpectate(playerid);
				}else{
					switch(GetPlayerState(pid)){
						case PLAYER_STATE_NONE,PLAYER_STATE_WASTED,PLAYER_STATE_SPAWNED:{
							SendClientMessage(playerid, COLOR_RED, "[����]��Ҫ�۲����һ�û����.");
						}
						case PLAYER_STATE_SPECTATING:{
							SendClientMessage(playerid, COLOR_RED, "[����]��Ҫ�۲��������ڿ�����");
						}
						default:{
							StartSpectate(playerid,pid);
						}
					}
				}
			}else{
				SendClientMessage(playerid, COLOR_RED, "[����]��Ҫ�۲����Ҳ�����.");
			}
		}
		return true;
	}
	return false;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid){
	// IF ANYONE IS SPECTATING THIS PLAYER, WE'LL ALSO HAVE
	// TO CHANGE THEIR INTERIOR ID TO MATCH
	new x = 0;
	while(x!=MAX_PLAYERS) {
	    if( IsPlayerConnected(x) &&	GetPlayerState(x) == PLAYER_STATE_SPECTATING &&
			gSpectateID[x] == playerid && gSpectateType[x] == ADMIN_SPEC_TYPE_PLAYER )
   		{
   		    SetPlayerInterior(x,newinteriorid);
		}
		x++;
	}
	return true;
}
//Automatically switch to vehicle spec mode when user enters vehicle
public OnPlayerEnterVehicle(playerid, vehicleid) {
	for(new x=0; x<MAX_PLAYERS; x++) {
	    if(GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] == playerid) {
	        TogglePlayerSpectating(x, 1);
	        PlayerSpectateVehicle(x, vehicleid);
	        gSpectateType[x] = ADMIN_SPEC_TYPE_VEHICLE;
		}
	}
	return true;
}


//Sacky's function modified.  makes falls from bikes register as vehicle exit
//Automatically switch to player spec mode when user exits vehicle
public OnPlayerStateChange(playerid, newstate, oldstate){
	if(newstate == PLAYER_STATE_ONFOOT){
		if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER){
			for(new x=0; x<MAX_PLAYERS; x++){
				if(GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] == playerid && gSpectateType[x] == ADMIN_SPEC_TYPE_VEHICLE){
					TogglePlayerSpectating(x, 1);
					PlayerSpectatePlayer(x, playerid);
					gSpectateType[x] = ADMIN_SPEC_TYPE_PLAYER;
				}
			}
		}
	}
	return true;
}

//Advances to next ID when current spectated player dies
public OnPlayerDeath(playerid, killerid, reason){
	for(new x=0; x<MAX_PLAYERS; x++) {
	    if(GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] == playerid) {
	       AdvanceSpectate(x);
		}
	}
	return true;
}

//Advances to next ID when current spectated player quits the server
public OnPlayerDisconnect(playerid, reason){
	for(new x=0; x<MAX_PLAYERS; x++) {
	    if(GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] == playerid) {
	       AdvanceSpectate(x);
		}
	}
	gSpectateType[playerid] = ADMIN_SPEC_TYPE_NONE;
	return true;
}

public OnPlayerConnect(playerid){
	gSpectateType[playerid] = ADMIN_SPEC_TYPE_NONE;
	return true;
}

/*******************************************************************************
 EOF
*******************************************************************************/
