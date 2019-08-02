#include"player.h"
#include<string.h>
void setPlayerName1(char *name){
	for(int i=0;i<10;i++)
   	{
    	playerName1[i]=name[i];
    } 
	
}
char *getPlayerName1(){
	return playerName1;
}

void setPlayerName2(char *name){
	for(int i=0;i<10;i++)
   	{
    	playerName2[i]=name[i];
    } 
}
char *getPlayerName2(){
	return playerName2;
}
