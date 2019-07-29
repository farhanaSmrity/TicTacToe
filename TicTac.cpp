#include <iostream>
#include<windows.h>
using namespace std;
int grid[4][4]={32};


// sign is set on that grid at the index
void setGridIndex(int idx,int sign){
	int row=idx/3,col=idx%3;
	grid[row][col]=sign;
}


//it's return the value on that grid at the index
int getGridIndex(int idx){
	int row=idx/3,col=idx%3;
	return grid[row][col];
}


bool isValidInput(int index){
	
	//range check (0-8)
	if(!(index>=0  && index<9)) 
	{
		return false;
	}
	//overlap check
	if(getGridIndex(index)==32)
	{
		return true;
	}
	
}
bool isWinner(int sign)
{
	if(grid[0][0]==grid[0][1] && grid[0][1]==grid[0][2] && grid[0][0]==sign ||\
	grid[1][0]==grid[1][1] && grid[1][1]==grid[1][2] && grid[1][0]==sign ||\
	grid[2][0]==grid[2][1] && grid[2][1]==grid[2][2] && grid[2][0]==sign ||\
	grid[0][0]==grid[1][0] && grid[1][0]==grid[2][0] && grid[0][0]==sign ||\
	grid[0][1]==grid[1][1] && grid[1][1]==grid[2][1] && grid[0][1]==sign ||\
	grid[0][2]==grid[1][2] && grid[1][2]==grid[2][2] && grid[0][2]==sign ||\
	grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[0][0]==sign ||\
	grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[0][2]==sign )
	{
		return true;
	}
	else
	return false;
}

void reset(){
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			grid[i][j]=32;
		}
	}
}
/*
Grid calculation
  0 1 2 = 0*3 0*3+1 0*3+2 
  3 4 5 = 1*3 1*3+1 1*3+2
  6 7 8 = 2*3 2*3+1 2*3+2
*/

/*
	  ||  ||  
	==========
	  ||  ||
	==========
	  ||  ||
*/

void showbox()
{
	system("CLS");
	printf("\n\n\n");
	for(int i = 0;i<3;i++)
	{
		
		printf("\t\t\t\t\t\t %c || %c || %c \n",getGridIndex(i*3),getGridIndex(i*3+1),getGridIndex(i*3+2));
		if(i<2){
			printf("\t\t\t\t\t\t=============\n");
		}
	}
}
//This method doesnt take any input. it returns the player who won the game or zero if its a tie.
int play(){
	int index,sign,player;
		for(int i=0;i<9;i++){
			if(i%2==0){
				sign='x';
				player=1;	
	    	}
	    	else
	    	{
	    		sign='o';
	    		player=2;
			}
			do{
				showbox();
	    		printf("\n\t\t\t\t\tplayer%d put your input from 0-8:",player);
		    	scanf("%d",&index);
				setGridIndex(index,sign);
				if(isWinner(sign)){
			    	printf("player %d wins!!!!.....",player);
			    return player;
		    	}	
			}while(1); //ffiixx  rrequired
			
		}
}



int main() {
	/*int item[100][100]; // 0 1 2 .... n // a00 a01 a02 //a10 a11 a12 //1
	int n=3; 
	for(int i=0;i<n;i++){ //n
		//some task   //n
		for(int j=0;j<n;j++){//n*n
			scanf("%d",&item[i][j]);//n*n
		}
	}
	printf("Price of 10 items: \n");
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++){
			printf("");
		}
		printf("\n");
	}*/
	
	reset();
	play();
	//showbox();
	return 0;
}
