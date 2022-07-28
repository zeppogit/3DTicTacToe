// Lab 11
//John Self and Rick Sweeney
//Combination between John's player class and Rick's game class
//with Combination being a derived class of both

//************************************ This file must be used with the player.h  and the  game.h header files *****************************************

#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include "player.h"
#include "game.h"

using namespace std;

class Combined : public Player, public Game {					//derived class from both classes
	
	public:
		void conversion(Combined&, TTT_3D&);
		void combComp(TTT_3D&, Combined&);
		
	public:
		int Rwins;
		int Jwins;
		int draws;
};

void Combined::conversion(Combined& myCombo, TTT_3D& mytt3d){		//function to convert john's computer to rick's game
	
	int var = myCombo.computerTurn2();
	
	
	if (var<=9){												// converts a random integer 27 into a 3X9 random
		mytt3d.iboard=1;
		y=(var -1);
	}
	else if ((var>9) && (var<=18)){
		mytt3d.iboard=2;
		y=(var -10);
	}
	else if ((var>18) && (var<=27)){
		mytt3d.iboard=3;
		y=(var -19);
	}
}

void Combined::combComp(TTT_3D& mytt3d, Combined& myCombo){			//function used to test if spaces are occupied, and sets the X for john's comp turn
		mytt3d.x=0;
	do{
		
		myCombo.conversion(myCombo, mytt3d);
		
	if (mytt3d.iboard == 1)
		{ 
		      
		    if ((mytt3d.cPlace1[y] == 'X') || (mytt3d.cPlace1[y] == 'O')){
		    	
		    	continue;
		    	
			}
	    		
			else
			{
				
				mytt3d.cPlace1[y] = 'X';
				mytt3d.x=4;
			}//end else
			
		} //end if  
		 
	
		else if (mytt3d.iboard == 2)
		{
		    
		    if ((mytt3d.cPlace2[y] == 'X') || (mytt3d.cPlace2[y] == 'O')){
		    	continue;
			}
	    			    
			else 
			{
				mytt3d.cPlace2[y] = 'X';
				mytt3d.x=4; 
			}//end else
		}
	    else if (mytt3d.iboard == 3) 
	    {
		     
		    if ((mytt3d.cPlace3[y] == 'X') || (mytt3d.cPlace3[y] == 'O')){
		    	continue;
			}
	    			    
			else 
			{
				mytt3d.cPlace3[y] = 'X';
				mytt3d.x=4;
			}//end else
		} //end else if
	
} 		while (mytt3d.x != 4);													 // end of do-while loop
	
	cout << "John's Comp  move is:  " << "Board " << mytt3d.iboard << " , position "<< y +1 <<endl;	//announces john's comp turn move
	mytt3d.turns = mytt3d.turns + 1;
		}




int main(){									//start of main 
	
	Player player2;							//object from john's class
	Game game2;								//object from rick's class
	Combined combo;							//object from derived class
	TTT_3D tt3d;							//object from rick's original derived class
	combo.Jwins =0;
	combo.Rwins =0;
	int gameCounter =0;

for(int i =0;i<10;i++)	{							//loop for 10 game plays

	int cMisc;
	tt3d.imenu= 0; // inherited : receives choice of placement of X or O ; imenu=46 exits program
    tt3d.next = 0;  //inherited : will determine if player or computer is next ( zero or one)
	tt3d.x=0; // use in chk3inRow()
	tt3d.iCompWins=0; //total number of computer three-in-row O's
	tt3d.iPlayerWins=0;// total number of player three-in-a-row X's
	tt3d.iWins=0;
	tt3d.turns=0;
    cout<<"\n      TIC TAC TOE\n\n";
    
    cout<<" You will make your mark on the board with \"X\".  The computer will use \"O\".\n\n"
        <<" A random selection is made to see who goes first. \n\n";
    
    tt3d.firstTurn(); //calls function to determine who goes first (value of 'next variable')

    do {  

      tt3d.display3Boards(); 
	   
      
      if (tt3d.next == 0 )
	  {
	  //	system ("pause");
	     tt3d.computerTurn3D();  // take computer's turn ; 
	           
		 if (tt3d.turns >= 5) 
	     {
	     	tt3d.chk3inRow();
	     	tt3d.chk_full_win_draw();
	        if (tt3d.imenu == 46) // value set to 46 in chk_full_win_draw if end of game determined
				 	{
			      	 	break;
			       	}// end if 
	     } // end if	     
	     tt3d.next = 1;	     
      } //end if
      
      if (tt3d.next == 1  ) 
	  {
	  		
	  		combo.conversion(combo,tt3d);
	  		
	  		combo.combComp(tt3d,combo);
	  		
	     

	     if (tt3d.turns >= 5) 
	     {
	        tt3d.chk3inRow();
	        tt3d.chk_full_win_draw();
	        if (tt3d.imenu == 46)  // value set to 46 in chk_full_win_draw if end of game determined
				 	{
			      	 	break;
			       	}// end if  
		 } //end if		 
	     tt3d.next = 0;     
      } //end if

    } while (tt3d.imenu!=46); //end do while loop
    
    if (tt3d.iCompWins < tt3d.iPlayerWins){				//sets wins for end of each game
    	combo.Jwins=combo.Jwins+1;
	}
	
	if (tt3d.iCompWins > tt3d.iPlayerWins){
		combo.Rwins=combo.Rwins+1;
	}
	if(tt3d.iCompWins==tt3d.iPlayerWins){
		combo.draws=combo.draws+1;
	}
	

	tt3d.cPlace1[0]=tt3d.cPlace2[0]=tt3d.cPlace3[0]='1';									//re-initialize the arrays
	tt3d.cPlace1[1]=tt3d.cPlace2[1]=tt3d.cPlace3[1]='2';
	tt3d.cPlace1[2]=tt3d.cPlace2[2]=tt3d.cPlace3[2]='3';
	tt3d.cPlace1[3]=tt3d.cPlace2[3]=tt3d.cPlace3[3]='4';
	tt3d.cPlace1[4]=tt3d.cPlace2[4]=tt3d.cPlace3[4]='5';
	tt3d.cPlace1[5]=tt3d.cPlace2[5]=tt3d.cPlace3[5]='6';
	tt3d.cPlace1[6]=tt3d.cPlace2[6]=tt3d.cPlace3[6]='7';
	tt3d.cPlace1[7]=tt3d.cPlace2[7]=tt3d.cPlace3[7]='8';
	tt3d.cPlace1[8]=tt3d.cPlace2[8]=tt3d.cPlace3[8]='9';
	gameCounter++;
}				//                  end of for loop

	if(combo.Jwins>combo.Rwins){
		cout << endl << "John's computer wins with a score of "<<combo.Jwins<<" to "<<combo.Rwins <<" with "<<combo.draws<<" draws"<< endl;		//announcements for winner after 10 games
	}
	if(combo.Jwins<combo.Rwins){
		cout << endl << "Rick's computer wins with a score of "<<combo.Rwins<<" to "<<combo.Jwins <<" with "<<combo.draws<<" draws"<< endl;
	}
	 if (combo.Jwins==combo.Rwins){
		cout<< endl << "It's a draw, no one wins"<< endl;
	}
	cout << endl << "The number of games that were played is "<<gameCounter<<endl;
    cout<<"\n Exiting 3D Tic Tac Toe.";
	
	
	
	return 0;
}
