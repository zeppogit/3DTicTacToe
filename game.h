//John Self
//Header file for Rick Sweeney's class GAME
//lab 11

#include <iostream>
#include <cstdlib>  // free(), system(), rand() , srand()
#include <ctime> //time()

using namespace std;  // for   cout , cin, rand(), srand()

class Game
{
// data member declarations

public:  
    	int next=0;  //who is next   
	int turns=0;  //play(), chk_draw() //changed from Lab 9 to "turns" for ease in search within code
	int imenu;  //playerTurn(), chk_winner(), play()
	int y;  //computerTurn()

public:
	Game()  // constructor  
    	{
    	}

   	 ~Game() //destructor    // NOTE: placement per book given using one file vs two
	{
	}
	
    	//class members
	char cPlace1[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};  //chk_winner , playerTurn, computerTurn, displayBoard

		//changed from Lab9, cPlace to cPlace1 and made public instead of private
	
	//methods:
	void firstTurn();  // determines who gets the first turn, computer or player // inherited by TTT_3D class
	void displayBoard();  
    	void play();  // plays the game
    	void computerTurn();  // computer takes turn
    	void playerTurn();  // implements players turn
    	void chk_winner();  //checks for winner
    	void chk_draw();  //checks for full board draw

    	};

	Game TicTacTow;  //create object TicTacToe

	//========================================================================================

	void Game::firstTurn()         // randomly determinse whether computer or player takes the first turn
	{
	srand(time(0));
	next =  (rand() % 2);
	if (next)
	    cout<<" John's Comp has been selected to go first.\n";    
	else 
    	{
	    cout<<" Rick's computer has been selected to go first.\n";
	}
	    
	};//end firstturn  method

	//========================================================================================

	void Game::displayBoard() 
	{
 	cout<<"\n\n"
        <<"        |     |\n"
        <<"     " << cPlace1[0] <<"  |  " <<cPlace1[1] <<"  |  " <<cPlace1[2] <<"\n"
        <<"   _____|_____|_____\n"
	    <<"        |     |\n"
	    <<"     " << cPlace1[3] <<"  |  " <<cPlace1[4] <<"  |  " <<cPlace1[5] <<"\n"
	    <<"   _____|_____|_____\n"
	    <<"        |     |\n"
	    <<"     " << cPlace1[6] <<"  |  " <<cPlace1[7] <<"  |  " <<cPlace1[8] <<"\n"
	    <<"        |     |\n\n";  
	}

	//========================================================================================

	void Game::computerTurn()
	{
	srand(time(0));

	do {
	    y=(rand() % 9);  
	}while  ((cPlace1[y] == 'X') || (cPlace1[y] == 'O'));
	
    	cPlace1[y] = 'O';
    	cout << " The computer's move is:  \n\n";
	displayBoard();
	
	}

	//========================================================================================

	void Game::playerTurn()
	{	   
	cout <<" Please select the square in which you want to place an X (1-9):  ";
	    cin >> imenu;
	    
	    while (	(cPlace1[imenu-1] == 'X') || (cPlace1[imenu-1] == 'O') )
	    {
         	cout<<"\n\n You must choose another location.  This one has already been selected. \n\n";
       	 	cout <<" Please select the square in which you want to place an X (1-9):  "; 
         	cin >> imenu;
	    } // end while	
       
    	cPlace1[imenu-1] = 'X';
	}

	//========================================================================================

	void Game::chk_winner()
	{
		if (
		((cPlace1[0] == cPlace1[1] ) && (cPlace1[1] == cPlace1[2])) || 
		((cPlace1[3] == cPlace1[4] ) && (cPlace1[4] == cPlace1[5])) || 
		((cPlace1[6] == cPlace1[7] ) && (cPlace1[7] == cPlace1[8])) || 
		((cPlace1[0] == cPlace1[3] ) && (cPlace1[3] == cPlace1[6])) || 
		((cPlace1[1] == cPlace1[4] ) && (cPlace1[4] == cPlace1[7])) || 
		((cPlace1[2] == cPlace1[5] ) && (cPlace1[5] == cPlace1[8])) || 
		((cPlace1[0] == cPlace1[4] ) && (cPlace1[4] == cPlace1[8])) || 
		((cPlace1[6] == cPlace1[4] ) && (cPlace1[4] == cPlace1[2])) )
        		{
        			imenu=10;
        		}
	}
	//========================================================================================

	void Game::chk_draw()
	{
	turns++;
	if (turns == 9) 
	    {
	   	cout<<" The game has ended in a draw.\n\n";
    	    }
	}

	//========================================================================================

	void Game::play()
{
	imenu = 0; // for switch in player's turn
    	next = 0;  //will determine if player or computer is next ( zero or one)

    	cout<<"\n      TIC TAC TOE\n\n";
    
    	cout<<" You will make your mark on the board with \"X\".  The computer will use \"O\".\n\n"
        <<" A random selection is made to see who goes first. \n\n";
    
    	firstTurn(); //calls function to determine who goes first (value of 'next variable')
    
    	do {  

      	    displayBoard();  

      
      	    if (next == 0 )
	    {
	     	computerTurn();  // take computer's turn ; 
	           
             	if (turns >= 3) 
	     	    {
	     	    chk_winner();
	      	  if (imenu == 10)	 
		    {
	      	        cout<< "\n\nThe computer wins!\n\n";
	      	        break;
	       	    } //end if
	         } // end if

	    next = 1;
	    chk_draw();
	     
      	    } //end if
      
      	    if (next == 1  ) 
	    {
	     playerTurn();  // accepts player's turn 
	     
	       if (turns >= 3) 
	       {
	         chk_winner();
	         if (imenu == 10)
		 {
	      	   displayBoard();
		   cout<< "\n\n You are the winnner!\n\n";
	      	   break;
	       	 }// end if
	       }//end if
		 
	    next = 0;
	    chk_draw();
	     
            } //end if

          } while (imenu!=10); //end do while loop
	}

	//========================================================================================

class TTT_3D : public Game  // created TTT_3D class that inherits members from Game class
{
//data members
public:  	
         char cPlace2[9] = { '1', '2', '3' , '4', '5', '6' , '7', '8', '9'};
	char cPlace3[9] = { '1', '2', '3' , '4', '5', '6' , '7', '8', '9'};

	int x = 0; // use in chk3inRow()
	int iboard; //use in computerTurn3D() and in playerTurn3D()
	int iWins; // holds number of three-in-a-rows of both X and O after checking all possible in chk3inRow()
	int iPoints; // point(s) scored by a turn
	int iCompWins;  // points accumulated by computer for each three-in-a-row of "O".
	int iPlayerWins; // points accumulated by player for each three-in-a-row of "X".
	char cMisc;
	//INHERIT BELOW FROM GAME CLASS:
	//int next;  //who is next  
	//int turns;  //play3D(), chk_draw()  
	//int imenu;  //playerTurn3D(), chk3_winner(), play3D() , imenu = 46 exits program
	//int y;  //computerTurn()

// method members
	void display3Boards(); 
    void play3D(); //play game of 3D Tic Tac Toe
    void computerTurn3D();
    void playerTurn3D();
    void chk3inRow();
    void chk_full_win_draw();
    //void firstTurn() is INHERITED FROM GAME CLASS

};

void TTT_3D::display3Boards() 
{
 	cout<<"\n"
        <<"           |     |\n"
        <<"      __" << cPlace1[0] <<"__|__" <<cPlace1[1] <<"__|__" <<cPlace1[2] <<"__\n"
	    <<"           |     |\n"
	    <<"  1   __" << cPlace1[3] <<"__|__" <<cPlace1[4] <<"__|__" <<cPlace1[5] <<"__\n"
	    <<"           |     |\n"
	    <<"        " << cPlace1[6] <<"  |  " <<cPlace1[7] <<"  |  " <<cPlace1[8] <<"\n"
 	    //<< endl
        <<"\t\t          |     |\n"
        <<"\t\t     __" << cPlace2[0] <<"__|__" <<cPlace2[1] <<"__|__" <<cPlace2[2] <<"__\n"
	    <<"\t\t          |     |\n"
	    <<"\t\t2    __" << cPlace2[3] <<"__|__" <<cPlace2[4] <<"__|__" <<cPlace2[5] <<"__\n"
	    <<"\t\t          |     |\n"
	    <<"\t\t       " << cPlace2[6] <<"  |  " <<cPlace2[7] <<"  |  " <<cPlace2[8] <<"\n"	    
    	//<<endl
    	<<"\t\t\t\t           |     |\n"
        <<"\t\t\t\t      __" << cPlace3[0] <<"__|__" <<cPlace3[1] <<"__|__" <<cPlace3[2] <<"__\n"
	    <<"\t\t\t\t           |     |\n"
	    <<"\t\t\t\t3     __" << cPlace3[3] <<"__|__" <<cPlace3[4] <<"__|__" <<cPlace3[5] <<"__\n"
	    <<"\t\t\t\t           |     |\n"
	    <<"\t\t\t\t        " << cPlace3[6] <<"  |  " <<cPlace3[7] <<"  |  " <<cPlace3[8] <<"\n"	    
    	<<endl;
}

//===================================================================================================
void TTT_3D::computerTurn3D()
{
	srand(time(0));
	do 
	{	
		x=0;
		iboard=(rand() % 3) + 1;
		if (iboard == 1)
		{
		    y=(rand() % 9);  
		    if ((cPlace1[y] == 'X') || (cPlace1[y] == 'O'))
	    		continue;
			else 
			{
				cPlace1[y] = 'O';
				x=4;
			}//end else
		} //end if  
		   
		else if (iboard == 2)
		{
		    y=(rand() % 9);  
		    if ((cPlace2[y] == 'X') || (cPlace2[y] == 'O'))
	    		continue;	    
			else 
			{
				cPlace2[y] = 'O';
				x=4;
			}//end else
		}
	    else if (iboard == 3) 
	    {
		    y=(rand() % 9);  
		    if ((cPlace3[y] == 'X') || (cPlace3[y] == 'O'))
	    		continue;		    
			else 
			{
				cPlace3[y] = 'O';
				x=4;
			}//end else
		} //end else if
	} while (x != 4);  //end do while
	
    cout << " Rick's computer move is:  "
         << " Board " <<this->iboard <<", position " <<y + 1 <<endl;
    turns = turns + 1;
	display3Boards();
			
}//end computerTurn3D() definition
//=====================================================================================================

void TTT_3D::playerTurn3D()
{	 
	iboard=0;
	do{
		cout <<" Please select on which of the three boards you want to place your X (1-3):  ";
		cin >> iboard;
		cout <<" Please select the square in which you want to place an X (1-9):  ";
	    cin >> imenu;
	    
	    if (iboard == 1) 
	    {
		    if ( (cPlace1[imenu-1] == 'X') || (cPlace1[imenu-1] == 'O') )
		    {
		         cout<<"\n\n You must choose another location.  This one has already been selected. \n\n";
		       	 iboard=0;
				 	
			} // end if
		       
		    else  cPlace1[imenu-1] = 'X';
		}// end if 
		else if (iboard == 2)
	    {
		    if (	(cPlace2[imenu-1] == 'X') || (cPlace2[imenu-1] == 'O') )
		    {
		         cout<<"\n\n You must choose another location.  This one has already been selected. \n\n";
		       	 iboard=0;

			} // end if	
		       
		    else cPlace2[imenu-1] = 'X';
		} // end if
		else if (iboard == 3)
	    {
		    if (	(cPlace3[imenu-1] == 'X') || (cPlace3[imenu-1] == 'O') )
		    {
		       	 iboard=0;		         
				 cout<<"\n\n You must choose another location.  This one has already been selected. \n\n";

			} // end if	
		       
		    else cPlace3[imenu-1] = 'X';
		} //end if 
	} while (iboard == 0); //end do while stmt
    turns = turns + 1;	

} //end playerTurn3D()
//=========================================================================================================

void TTT_3D::chk3inRow()//counts all 3 in rows. If count is more than total points, difference is given in points to who made last move
{
	iWins=0;
	iPoints=0;
	cMisc={NULL}; // used to store a value used to trigger pause in game play, in play 3D(), after printing new score
	if  ((cPlace1[0] == cPlace1[1] ) && (cPlace1[1] == cPlace1[2]))  //board 1 horizontal plane
		iWins = iWins + 1;
	if	((cPlace1[3] == cPlace1[4] ) && (cPlace1[4] == cPlace1[5])) 
		iWins = iWins + 1;
	if	((cPlace1[6] == cPlace1[7] ) && (cPlace1[7] == cPlace1[8]))  
		iWins = iWins + 1;
	if	((cPlace1[0] == cPlace1[3] ) && (cPlace1[3] == cPlace1[6]))  
		iWins = iWins + 1;
	if	((cPlace1[1] == cPlace1[4] ) && (cPlace1[4] == cPlace1[7]))  
		iWins = iWins + 1;
	if	((cPlace1[2] == cPlace1[5] ) && (cPlace1[5] == cPlace1[8]))  
		iWins = iWins + 1;
	if	((cPlace1[0] == cPlace1[4] ) && (cPlace1[4] == cPlace1[8]))  
		iWins = iWins + 1;
	if	((cPlace1[6] == cPlace1[4] ) && (cPlace1[4] == cPlace1[2])) 
		iWins = iWins + 1;		
	if	((cPlace2[0] == cPlace2[1] ) && (cPlace2[1] == cPlace2[2]))  //board 2 horizontal plane
		iWins = iWins + 1;
	if	((cPlace2[3] == cPlace2[4] ) && (cPlace2[4] == cPlace2[5]))  
		iWins = iWins + 1;
	if	((cPlace2[6] == cPlace2[7] ) && (cPlace2[7] == cPlace2[8]))  
		iWins = iWins + 1;
	if	((cPlace2[0] == cPlace2[3] ) && (cPlace2[3] == cPlace2[6]))  
		iWins = iWins + 1;
	if	((cPlace2[1] == cPlace2[4] ) && (cPlace2[4] == cPlace2[7]))  
		iWins = iWins + 1;
	if	((cPlace2[2] == cPlace2[5] ) && (cPlace2[5] == cPlace2[8]))  
		iWins = iWins + 1;
	if	((cPlace2[0] == cPlace2[4] ) && (cPlace2[4] == cPlace2[8]))  
		iWins = iWins + 1;
	if	((cPlace2[6] == cPlace2[4] ) && (cPlace2[4] == cPlace2[2])) 
		iWins = iWins + 1;
	if	((cPlace3[0] == cPlace3[1] ) && (cPlace3[1] == cPlace3[2]))  //board 3 horizontal plane
		iWins = iWins + 1;
	if	((cPlace3[3] == cPlace3[4] ) && (cPlace3[4] == cPlace3[5]))  
		iWins = iWins + 1;
	if	((cPlace3[6] == cPlace3[7] ) && (cPlace3[7] == cPlace3[8]))  
		iWins = iWins + 1;
	if	((cPlace3[0] == cPlace3[3] ) && (cPlace3[3] == cPlace3[6]))  
		iWins = iWins + 1;
	if	((cPlace3[1] == cPlace3[4] ) && (cPlace3[4] == cPlace3[7]))  
		iWins = iWins + 1;
	if	((cPlace3[2] == cPlace3[5] ) && (cPlace3[5] == cPlace3[8]))  
		iWins = iWins + 1;
	if	((cPlace3[0] == cPlace3[4] ) && (cPlace3[4] == cPlace3[8]))  
		iWins = iWins + 1;
	if	((cPlace3[6] == cPlace3[4] ) && (cPlace3[4] == cPlace3[2])) 		
		iWins = iWins + 1;
	if	( ( (cPlace1[0] == 'X') || (cPlace1[0] == 'O')) && (cPlace1[0] == cPlace2[0] ) && (cPlace2[0] == cPlace3[0]))  //vertical columns
		iWins = iWins + 1;
	if	( ( (cPlace1[1] == 'X') || (cPlace1[1] == 'O')) && (cPlace1[1] == cPlace2[1] ) && (cPlace2[1] == cPlace3[1]))  
		iWins = iWins + 1;
	if	( ( (cPlace1[2] == 'X') || (cPlace1[2] == 'O')) && (cPlace1[2] == cPlace2[2] ) && (cPlace2[2] == cPlace3[2]))  
		iWins = iWins + 1;
	if	( ((cPlace1[3] == 'X') || (cPlace1[3] == 'O'))&& (cPlace1[3] == cPlace2[3] ) && (cPlace2[3] == cPlace3[3]))  
		iWins = iWins + 1;
	if	( ((cPlace1[4] == 'X') || (cPlace1[4] == 'O')) && (cPlace1[4] == cPlace2[4] ) && (cPlace2[4] == cPlace3[4]))  
		iWins = iWins + 1;
	if	( ( (cPlace1[5] == 'X') || (cPlace1[5] == 'O')) && (cPlace1[5] == cPlace2[5] ) && (cPlace2[5] == cPlace3[5]))  		
		iWins = iWins + 1;
	if	( ( (cPlace1[6] == 'X') || (cPlace1[6] == 'O')) && (cPlace1[6] == cPlace2[6] ) && (cPlace2[6] == cPlace3[6]))  
		iWins = iWins + 1;
	if	(  ((cPlace1[7] == 'X') || (cPlace1[7] == 'O')) && (cPlace1[7] == cPlace2[7] ) && (cPlace2[7] == cPlace3[7]))  
		iWins = iWins + 1;
	if	(( (cPlace1[8] == 'X') || (cPlace1[8] == 'O')) && (cPlace1[8] == cPlace2[8] ) && (cPlace2[8] == cPlace3[8]))  
		iWins = iWins + 1;
	if	((cPlace1[0] == cPlace2[3] ) && (cPlace2[3] == cPlace3[6]))  //vertical diagnonals front to back plane
		iWins = iWins + 1;
	if	((cPlace1[6] == cPlace2[3] ) && (cPlace2[3] == cPlace3[0]))  
		iWins = iWins + 1;
	if	((cPlace1[1] == cPlace2[4] ) && (cPlace2[4] == cPlace3[7]))  
		iWins = iWins + 1;
	if	((cPlace1[7] == cPlace2[4] ) && (cPlace2[4] == cPlace3[1]))  
		iWins = iWins + 1;
	if	((cPlace1[2] == cPlace2[5] ) && (cPlace2[5] == cPlace3[8]))  
		iWins = iWins + 1;
	if	((cPlace1[8] == cPlace2[5] ) && (cPlace2[5] == cPlace3[2]))  					
		iWins = iWins + 1;
	if	((cPlace1[0] == cPlace2[1] ) && (cPlace2[1] == cPlace3[2]))  //vertical diagnonals right to left plane
		iWins = iWins + 1;
	if	((cPlace1[2] == cPlace2[1] ) && (cPlace2[1] == cPlace3[0]))  
		iWins = iWins + 1;
	if	((cPlace1[3] == cPlace2[4] ) && (cPlace2[4] == cPlace3[5]))  
		iWins = iWins + 1;
	if	((cPlace1[5] == cPlace2[4] ) && (cPlace2[4] == cPlace3[3]))  
		iWins = iWins + 1;
	if	((cPlace1[6] == cPlace2[7] ) && (cPlace2[7] == cPlace3[8]))  
		iWins = iWins + 1;
	if	((cPlace1[8] == cPlace2[7] ) && (cPlace2[7] == cPlace3[6]))  			
		iWins = iWins + 1;		
	if	((cPlace1[0] == cPlace2[4] ) && (cPlace2[4] == cPlace3[8]))  //vertical diagnonals cross cube 
		iWins = iWins + 1;
	if	((cPlace1[8] == cPlace2[4] ) && (cPlace2[4] == cPlace3[0]))  
		iWins = iWins + 1;
	if	((cPlace1[2] == cPlace2[4] ) && (cPlace2[4] == cPlace3[6]))  
		iWins = iWins + 1;
	if	((cPlace1[6] == cPlace2[4] ) && (cPlace2[4] == cPlace3[2]))  	
		iWins = iWins + 1;
	if (iWins > (iCompWins + iPlayerWins))	
    {
    	if (next == 0) 
		{
				iPoints = (iWins - (iCompWins + iPlayerWins));
				iCompWins = iCompWins + iPoints;
				cout <<"\n Rick's computer scores " <<(int) iPoints << endl
					 <<" The score is now Rick's Computer:  " << iCompWins <<"   John's Comp':  " << iPlayerWins << endl;
				cMisc=1; // used in play3D() to pause game so you don't have to scroll back to read score print out above
		}// end if
    	else if (next == 1) 
		{
				iPoints =  (iWins - (iCompWins + iPlayerWins));
				iPlayerWins = iPlayerWins  + iPoints;
				cout <<"\n John's comp' scores " <<(int) iPoints  << endl
					 <<" The score is now Rick's Computer:  " << iCompWins <<"   John's comp':  " << iPlayerWins << endl;
				cMisc=1;  // used in play3D() to pause game so you don't have to scroll back to read score print out above		 
		}// end if	
    } // end if
        
//	}// end if

}// end chk3inRow() definition

//=========================================================================================================

void TTT_3D::chk_full_win_draw()
{
	if (turns == 27) 
	{
	   	if (iCompWins == iPlayerWins)
		{
			cout<<" The game has ended in a draw, with " << iCompWins <<" points each.\n\n";
			imenu=46; //value of 46 will trigger break in loop within play3D() method
		}	
	 	else if (iCompWins > iPlayerWins)
	    {
	      	cout<<" Rick's computer wins by a score of " << iCompWins <<" to " << iPlayerWins <<"!!\n\n";
	      	imenu=46; //value of 46 will trigger break in loop within play3D() method
	    }
		else if (iCompWins < iPlayerWins)
	    {
	     	cout<<" John's comp wins by a score of " << iPlayerWins <<" to " << iCompWins <<"!!\n\n";
	     	imenu=46; //value of 46 will trigger break in loop within play3D() method
		}
	}//end if

} // end chk_full_win_draw() method definition

//=========================================================================================================


void TTT_3D::play3D()
{
	imenu= 0; // inherited : receives choice of placement of X or O ; imenu=46 exits program
    next = 0;  //inherited : will determine if player or computer is next ( zero or one)
	x=0; // use in chk3inRow()
	iCompWins=0; //total number of computer three-in-row O's
	iPlayerWins=0;// total number of player three-in-a-row X's
	iWins=0;
    cout<<"\n      TIC TAC TOE\n\n";
    
    cout<<" You will make your mark on the board with \"X\".  The computer will use \"O\".\n\n"
        <<" A random selection is made to see who goes first. \n\n";
    
    firstTurn(); //calls function to determine who goes first (value of 'next variable')

    do {  

      display3Boards();  
      if (cMisc == 1) // allows player to read new scoring from the previous turn before continuing
      {
      			cout<<" Key any character or number to continue.";
				cin >> cMisc;
				cMisc=0;
      }
      if (next == 0 )
	  {
	     computerTurn3D();  // take computer's turn ; 
	           
		 if (turns >= 5) 
	     {
	     	chk3inRow();
	     	chk_full_win_draw();
	        if (imenu == 46) // value set to 46 in chk_full_win_draw if end of game determined
				 	{
			      	 	break;
			       	}// end if 
	     } // end if	     
	     next = 1;	     
      } //end if
      
      if (next == 1  ) 
	  {
	     playerTurn3D();  // accepts player's turn 

	     if (turns >= 5) 
	     {
	        chk3inRow();
	        chk_full_win_draw();
	        if (imenu == 46)  // value set to 46 in chk_full_win_draw if end of game determined
				 	{
			      	 	break;
			       	}// end if  
		 } //end if		 
	     next = 0;     
      } //end if

    } while (imenu!=46); //end do while loop
    cout<<"\n Exiting 3D Tic Tac Toe.";
}
