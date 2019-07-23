#include <iostream>
using namespace std;
int grid[4][4]={32};

void setGridIndex(int idx,int sign){
	int row=idx/3,col=idx%3;
	grid[row][col]=sign;
}

int getGridIndex(int idx){
	int row=idx/3,col=idx%3;
	return grid[row][col];
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
	for(int i = 0;i<3;i++)
	{
		printf(" %c || %c || %c \n",getGridIndex(i*3),getGridIndex(i*3+1),getGridIndex(i*3+2));
		if(i<2){
			printf("=============\n");
		}
	}
}
//This method doesnt take any input. it returns the player who won the game or zero if its a tie.
int play(){
	int index,sign;
		for(int i=0;i<9;i++){
			if(i%2==0){
				//player 1
				showbox();
		    	scanf("%d",&index);
			    setGridIndex(index,(int)'x');
			    if(isWinner((int)'x')){
			    	printf("player 1 wins!!!!.....");
			    	return 1;
				}
	    	}
	    	
	    	else
	    	{
	    		//player 2
	    		showbox();
		    	scanf("%d",&index);
			    setGridIndex(index,(int)'o');
			    if(isWinner((int)'o')){
			    	printf("player 2 wins!!!!.....");
			    	return 2;
				}
			}
			
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
