#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>

//SNAKE AND LADDER GAME
int pos1=1;
int pos2=1;
//FUNCTION TO GENERATE RANDOM NUMBER ON DICE, BETWEEN 1-6
int randomNumber()
{
	int rem;
	rem=rand()%6 + 1;
	return rem;
}

//FUNCTION TO MAKE CHANGES ON THE BOARD AND DISPLAY THE BOARD
void _board(int cp, int player)
{	
    	//WIN
	if(cp==100)
	{
		printf("*****Congratulations*****\n\n\n%s wins\n",(player==1)?"PLAYER 1":"PLAYER 2");
        pos1=1;
        pos2=1;
		return;
	}
	
	//SNAKES
	if(cp==63)
	{
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 63 TO 18\n");
	    cp=18;
	}
	else if(cp==32)
	{
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 32 TO 10\n");
	    cp=10;
	}
	else if(cp==48)
	{
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 48 TO 26\n");
	    cp=26;
	}
	else if(cp==88)
	{
	    printf("Oops!! That was a nasty bite ");
	    printf("\nSNAKE FROM 88 TO 24\n");
	    cp=24;
	}
	else if(cp==99)
	{
	    printf("DAMN :_)");
	    printf("\nSNAKE FROM 99 TO 1\n");
	    cp=1;
	}
	
	//LADDERS
	else if(cp==4)
	{
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 4 TO 18\n");
	    cp=18;
	}
	else if(cp==60)
	{
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 60 TO 83\n");
	    cp=83;
	}
	else if(cp==70)
	{
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 70 TO 93\n");
	    cp=93;
	}
	else if(cp==28)
	{
	    printf("Weee!! Upp we gooo");
	    printf("\nLADDER AT 28 TO 76\n");
	    cp=76;
	}
	else if(cp==50)
	{
	    printf("Weee!! Upp we gooo ");
	    printf("\nLADDER AT 50 TO 67\n");
	    cp=67;
	}

	//UPDATING POSITIONS
	if(player==1){
	pos1=cp;   
	}
	else{
	pos2=cp;
	}

	//DISPLAY BOARD
	for(int i=0;i<10;i++)
	{
		for(int j=1; j<=10; j++)
		{
		      int curr=(i*10 + j);
		      
		      if(player ==1 && pos1==curr)
		      {
		          printf("*P1*\t");
		      }
		      else if(player ==2 && pos2==curr)
		      {
		          printf("*P2*\t");
		      }
		      else
		      {
		        printf("%d\t",curr);
		      }
		}
		printf("\n\n");
	}
	printf("--------------------------------------------------------------------------\n");
}

void snl()
{
	int dice;
	char ch;
	
	while(true)
	{
	        printf("		** SNAKE AND LADDER GAME** \n	    	   BY GROUP 33\n");
		printf("Snakes:- 63 to 18,\t 32 to 10,\t 48 to 26,\t 88 to 24,\t 99 to 1.\nLadder:- 4 to 14,\t 60 to 83,\t 70 to 93,\t 28 to 76.\n");
		printf("Choose your option\n");
		printf("1. Player 1 plays\n");
		printf("2. Player 2 plays\n");
		printf("3. Exit\n");
		scanf("%s",&ch);
	
	        int fwd=0;
		switch(ch)
		{
		   	//ACCOUNTING FOR TURNS IN EACH CASE 
			case '1':
    			dice=randomNumber();
    			system("cls");
				printf("\t\t\t\tDice = %d\n\n",dice);
				fwd+=dice;
				
				if(dice==6)
				{
				    printf("You have earned a chance to play one more time.\n");
				    dice=randomNumber();
				    printf("\t\t\t\tDice = %d\n\n",dice);
				    fwd+=dice;
				}
				
				if(pos1+ fwd>=101)
				{
				    fwd=0;
				    printf("Overshoot!! Turn Ended...\n\n");
				    _board(pos1,1);
				    continue;
				}
				else
				{
					_board(pos1+fwd,1);
				}
				printf("Player 2 position is %d\n\n",pos2);
			
			break;
			
			case '2':
    			dice=randomNumber();
    			system("cls");
				printf("\t\t\t\tDice = %d\n\n",dice);
				fwd+=dice;
				
				if(dice==6)
				{
				    printf("Dice = 6: You have earned a chance to play one more time.\n");
				    dice=randomNumber();
				    printf("\t\t\t\tDice = %d\n\n",dice);
				    fwd+=dice;
				}
				
				if(pos2+ fwd>=101)
				{
				    fwd=0;
				    printf("Overshoot!! Turn Ended...\n\n");
				    _board(pos1,1);
				    continue;
				}
				else
				{
					_board(pos2+fwd,2);
				}
				printf("Player 1 position is %d\n\n",pos1);
				
			break;
			
			case '3':
                pos1=1;
                pos2=1;
			    return;		    
			break;
			
			default:
			    printf("Incorrect choice.Try Again\n");			 
			break;				
		}		
	}	
}

//SUDOKU SOLVER
void printmesh(int mesh[9][9])
// function to print the given mesh problem
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", mesh[i][j]);
        }
        printf("\n");
    }
}

bool accept(int mesh[9][9], int row, int col, int num)
// funtion to check if the number is a valid entry by checking its repeatedness in row, column and 3 x 3 mesh
{
    for (int i = 0; i < 0; i++) // checking repeatedness in row and column
    {
        if (mesh[row][i] == num || mesh[i][col] == num)
        {
            return 0;
        }
        // checking repetetion in 3 x 3 grid
        int initialrow = row - row % 3;
        int initialcol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (mesh[initialrow + i][initialcol + j] == num)
                {
                    return 0; // return 0 (false) if repetetion
                }
                else
                {
                    return 1; // return 1(true) if no repetetion
                }
            }
        }
    }
}

int findvacantposition(int mesh[9][9], int *row, int *col)
// function to find the unoccupied position in the mesh by moving across 9 x 9 mesh
{
    for (*row = 0; *row < 9; (*row)++)
        for (*col = 0; *col < 9; (*col)++)
            if (mesh[*row][*col] == 0)
                return 1;
    return 0;
}

int solvesudoku(int mesh[9][9])
{
    int row, col;
    if (findvacantposition(mesh, &row, &col))
    {
        return 1;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (accept(mesh, row, col, i))
        {
            mesh[row][col] = i;
            if (solvesudoku(mesh))
            {
                return 1;
            }
            else
            {
                mesh[row][col] = 0;
            }
        }
    }
    return 0;
}
int checksol(int sol[9][9])
// checing if there is any repetetion in row and column in the solution matrix
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = j + 1; k < 9; k++)
            {
                if (sol[i][j] == sol[i][k])
                {
                    return 0; // returning 0 if repetetion
                }
            }
        }
    }

    return 1; // returning 1 if no repetetion
}

int smallgridcheck(int sol[9][9])
// function to check repetetion in small 3 x 3 grid
{

    for (int i = 0; i < 9; i = i + 3)
    {
        for (int j = 0; j < 9; j = j + 3)
        {
            int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            for (int row = i; row < i + 3; row++)
            {
                for (int col = j; col < j + 3; col++)
                {
                    int k = sol[row][col];
                    a[k - 1] = 0;
                }
            }

            int sum = 0;
            for (int i = 0; i < 9; i++)
            {
                sum = sum + a[i];
            }
            if (sum != 0)
            {
                return 0;
                break;
            }
            else
            {
                return 1;
            }
        }
    }
}

void sudoku()
{
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solvesudoku(grid) == 1)
    { // if solution of sudoku puzzle exists then print the grid
        printmesh(grid);
    }
    else
    {
        printf("No solution exists"); // else print it not solvable
    }

    printf("Enter your solution :\n");
    int sol[9][9];
    for (int i = 0; i < 9; i++)
    { // entry of puzzle solution by user in form of 9 x 9 matrix
        for (int j = 0; j < 9; j++)
        {
            char ch;
            scanf("%c", &ch);
            sol[i][j] = (int)(ch - '0');
            scanf("%c", &ch);
        }
    }

    if (checksol(sol) == 1 && smallgridcheck(sol) == 1)
    { // checking repetetion in row and column as well as 3 x 3 matrixes
        printf("your solution is correct\n");
    }
    else
    {
        printf("your solution is incorrect\n");
    }

    return;
}

//2048 GAME
#define MAXRANDOMVALUE 3 
#define MAXPREV 500 
int arr[4][4] = { 0 }, c[4], temp = 0, len = 0, score = 0, 
    highscore = 0, count = 0, 
    ch = 0; // COUNT WILL COUNT THE NO OF STEPS 
  
int findlen(int n); 
  
// Function to print the game board 
void print() 
{ 
    int i, j, k, len1; 
  
    printf( 
        "\n\t\t\t\t\t===============2048==============\n"); 
    printf("\t\t\t\t\tYOUR SCORE=%d\n\t\t\t\t\t", score); 
    if (score < highscore) { 
        printf("HIGH SCORE=%d\t\t\t\t\t\n", highscore); 
    } 
    else { 
        highscore = score; 
        printf("HIGH SCORE=%d\t\t\t\t\t\n", highscore); 
    } 
    printf("\t\t\t\t\t---------------------------------\n"); 
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            if (j == 0) { 
                printf("\t\t\t\t\t|"); 
            } 
            if (arr[i][j] != 0) { 
                len1 = findlen(arr[i][j]); 
                // printf("%d:",len); 
  
                for (k = 0; k < 4 - len; k++) { 
                    printf(" "); 
                } 
                printf("%d", arr[i][j]); 
  
                for (k = 0; k < 4 - len; k++) { 
                    printf(" "); 
                } 
                for (k = 0; k < len - 1; k++) { 
                    printf(" "); 
                } 
                printf("|"); 
            } 
            else { 
                for (k = 0; k < 8 - 2 * len - 1; k++) { 
                    printf(" "); 
                } 
                printf("|"); 
            } 
            len = 0; 
        } 
        if (i != 3) { 
            printf("\n"); 
            printf("\t\t\t\t\t-----------------------------"
                   "----\n"); 
        } 
    } 
    printf( 
        "\n\t\t\t\t\t---------------------------------\n"); 
    printf("\t\t\t\t\tPREV-> P\t\t\t\t\t\n"); 
    printf("\t\t\t\t\tRESTART-> R\t\t\t\t\t\n"); 
    printf("\t\t\t\t\tEXIT-> U\t\t\t\t\t\n"); 
    printf("\t\t\t\t\tENTER YOUR CHOISE -> "
           "W,S,A,D\n\t\t\t\t\t"); 
} 
  
// Function to move values in the array 
void movevalue(int k) 
{ 
    int i; 
    if (k == 3) { 
        return; 
    } 
    for (i = k; i < 4; i++) { 
        if (c[i] != 0) { 
            movevalue(i + 1); 
            for (; i < 4; i++) { 
                if (c[i + 1] != 0) { 
                    break; 
                } 
                c[i + 1] = c[i]; 
                c[i] = 0; 
            } 
        } 
    } 
} 
  
// Function to find the length of a number (count of digits) 
int findlen(int n) 
{ 
  
    if (n == 0) { 
  
        return len; 
    } 
    else { 
        len++; 
        findlen(n / 10); 
    } 
} 
  
// Function to add a random number to the game board 
void addrandomno() 
{ 
    int no; 
    srand(time(NULL)); 
    int i, j; // RANDOM INDEX 
    do { 
        i = (rand()) % (MAXRANDOMVALUE + 1); 
        j = (rand()) % (MAXRANDOMVALUE + 1); 
    } while (arr[i][j] != 0); 
    // printf("%d %d",i,j); 
    no = 2 * ((rand() % 10) + 1); 
    if (no == 3 || no == 2) { 
        arr[i][j] = 4; 
    } 
    else { 
        arr[i][j] = 2; 
    } 
} 
  
// Function to update the array after moving values 
void rupdate() 
{ 
    int i, j; 
    for (i = 3; i > 0; i--) { 
        if (c[i] == c[i - 1]) { 
            c[i] += c[i - 1]; 
            score = score + c[i]; 
            if (score > highscore) { 
            } 
            temp = 1; 
            c[i - 1] = 0; 
        } 
        else if (c[i - 1] == 0 && c[i] != 0) { 
            c[i - 1] = c[i]; 
            c[i] = 0; 
            temp = 1; 
        } 
        else if (c[i] == 0) { 
            temp = 1; 
        } 
    } 
    movevalue(0); 
} 
  
// Function to create a previous state in the history 
void createprev(int*** p) 
{ 
    int i, j, k; 
    FILE* ptr; 
    ptr = fopen("hstr.txt", "a"); 
    fprintf(ptr, "%d ", score); 
    fclose(ptr); 
  
    if (count == MAXPREV + 1) { 
        for (i = MAXPREV; i > 0; i--) { 
            for (j = 0; j < 4; j++) { 
                for (k = 0; k < 4; k++) { 
                    p[i][j][k] = p[i - 1][j][k]; 
                } 
            } 
        } 
        count = MAXPREV; 
    } 
  
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            p[MAXPREV - count][i][j] = arr[i][j]; 
        } 
    } 
} 
  
// Function to update the array to a previous state 
void updatearrtoprev(int*** p) 
{ 
    int data, i, j; 
    if (count == 0) { 
        printf("\n******FURTHER MORE PREV NOT "
               "POSSIBLE********"); 
        return; 
    } 
    FILE* ptr = fopen("hstr.txt", "r+"); 
    for (i = 0; i < count; i++) { 
        fscanf(ptr, "%d ", &data); 
    } 
    score = data; 
  
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            arr[i][j] = p[MAXPREV - count][i][j]; 
        } 
    } 
    count--; 
} 
  
// Function to reset the game 
void resetgame() 
{ 
    int i, j; 
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            arr[i][j] = 0; 
        } 
    } 
    system("cls || cls"); 
    score = 0; 
    addrandomno(); 
} 

void two048() 
{ 
    struct timespec ts;
    ts.tv_sec=0;
    ts.tv_nsec=1000000;
    int i, j, k, m, n, same = 0; 
    char choise, s = -33, reschk; 
    printf("===============2048==============\n"); 
    printf("WELCOME TO PUZZLE 2048\n"); 
    printf("> CONTROLS\n"); 
    printf("  FOR MOVES:- 'W','S','A','D'\n"); 
    printf("  GO BACKWARD:- 'P'\n"); 
    printf("  RESTAT THE GAME:- 'R'\n"); 
    printf("  EXIT:-'U'\n"); 
  
    printf("\nPRESS ANY KEY TO START THE GAME...."); 
  
    getchar(); 
    system("cls || cls"); 
    printf("\n===============2048==============\n"); 
    printf("\nLOADING...\n"); 
    for (int i = 0, j; i < 35; i++) { 
        printf("%c", s); 
        j = i; 
        if (i % 2 != 0 && i < 20) { 
            nanosleep(&ts, NULL);
        } 
    } 
    nanosleep(&ts, NULL);
    system("cls || cls"); 
    int*** p; 
    p = (int***)malloc(sizeof(int*) * (MAXPREV + 1)); 
    for (int i = 0; i < MAXPREV + 1; i++) { 
        *(p + i) = (int**)malloc(sizeof(int*) * 4); 
    } 
    for (int i = 0; i < MAXPREV + 1; i++) { 
        for (int j = 0; j < 4; j++) { 
            p[i][j] = (int*)malloc(sizeof(int) * 4); 
        } 
    } 
    createprev(p); 
  
    FILE* ptr; 
    ptr = fopen("highscore.txt", "r"); 
    fscanf(ptr, "%d", &highscore); 
    fclose(ptr); 
    ptr = fopen("hstr.txt", "w"); 
    fclose(ptr); 
    addrandomno(); 
    print(); 
    while (1) { 
        if (score > highscore) { 
  
            ptr = fopen("highscore.txt", "w"); 
            fprintf(ptr, "%d", score); 
            fclose(ptr); 
        } 
        choise = getchar(); 
        // cls the input buffer 
        while (getchar() != '\n') 
            ; 
        if (choise == 'D' || choise == 'd') { 
            count++; 
            ch++; 
            createprev(p); 
            for (i = 0; i < 4; i++) { 
                for (j = 0; j < 4; j++) { 
                    c[j] = arr[i][j]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[i][k] = c[k]; 
                } 
            } 
        } 
        else if (choise == 'a' || choise == 'A') { 
            count++; 
            ch++; 
            createprev(p); 
            for (i = 0; i < 4; i++) { 
                for (j = 3; j >= 0; j--) { 
                    c[3 - j] = arr[i][j]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[i][3 - k] = c[k]; 
                } 
            } 
        } 
        else if (choise == 's' || choise == 'S') { 
            count++; 
            ch++; 
  
            createprev(p); 
            for (i = 0; i < 4; i++) { 
                for (j = 0; j < 4; j++) { 
                    c[j] = arr[j][i]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[k][i] = c[k]; 
                } 
            } 
        } 
        else if (choise == 'w' || choise == 'W') { 
            count++; 
            ch++; 
  
            createprev(p); 
            for (i = 0; i < 4; i++) { 
                for (j = 3; j >= 0; j--) { 
                    c[3 - j] = arr[j][i]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[3 - k][i] = c[k]; 
                } 
            } 
        } 
        else if (choise == 'p' || choise == 'p') { 
  
            updatearrtoprev(p); 
  
            temp = 8; 
        } 
        else if (choise == 'R' || choise == 'r') { 
            count = 0; 
            resetgame(); 
            print(); 
            continue; 
        } 
        else if (choise == 'u' || choise == 'U') { 
            return; 
        } 
  
        if (temp == 1) { 
            temp = 0; 
            system("cls || cls"); 
            printf("\n%c\n", choise); 
            addrandomno(); 
            print(); 
        } 
        else if (temp == 8) { 
            temp = 0; 
            print(); 
        } 
        else { 
            for (m = 0; m < 4; m++) { 
                for (n = 3; n > 0; n--) { 
                    if (arr[m][n] == arr[m][n - 1] 
                        || arr[m][n] == 0 
                        || arr[m][n - 1] == 0) { 
                        same = 1; 
                        break; 
                    } 
                    if (arr[n][m] == arr[n - 1][m] 
                        || arr[m][n] == 0 
                        || arr[m][n - 1] == 0) { 
                        same = 1; 
                        break; 
                    } 
                } 
                if (same == 1) 
                    break; 
            } 
            if (same == 1) { 
                printf("\n============INVALID "
                       "KEY==========\n"); 
                same = 0; 
            } 
            else { 
                printf( 
                    "\n=============GAME OVER============"); 
                printf("\nWANT TO PLAY MORE?? Y/N??\n"); 
                reschk = getchar(); 
                while (getchar() != '\n') 
                    ; // cls the input buffer 
                switch (reschk) { 
                case 'Y': 
                case 'y': 
                    resetgame(); 
                    print(); 
                    break; 
                case 'n': 
                case 'N': 
                    return; 
                } 
                continue; 
            } 
        } 
    } 
    return; 
}

//MINESWEEPER
void generator(void);
void difficulty(void);
void guess(void);
void printfield(void);
void playagain(void);
void printfinal(void);
void revealAdjacentBlanks(int, int);
void minesweeper(void);

int level, M, N, no_of_mines, mines, match=0, x, y;
int initial[30][30], answer[30][30], current[30][30];
char again;

//prints information about difficulty levels.
void minesweeper()
{
    printf("\n\tWELCOME  TO  MINESWEEPER.\n");
    printf("Difficulty level 1 has 9x9 grid with 10 mines.\nDifficulty level 2 has 14x14 grid with 25 mines.\nDifficulty level 3 has 16x16 grid with 40 mines.\n");
    printf("Choose difficulty 4 for custom size and mines.\n\n");
    difficulty(); //choosing difficulty
}


//Function to choose difficulty level. 
void difficulty(void)
{
    printf("Select difficulty level between 1-3 and 4 for custom: ");
    scanf("%d",&level);

    if((level != 1) && (level != 2) && (level != 3) && (level != 4))
    {
        while(1){
            printf("Please enter either 1, 2, 3 or 4\n");
            scanf("%d",&level);
            if((level == 1) || (level == 2) || (level == 3) || (level == 4)) break;
        }
    }

    if(level==1)
    {
        M=9;
        N=9;
        no_of_mines=10;

        generator();
        guess();
    }

    if(level==2)
    {
        M=14;
        N=14;
        no_of_mines=25;

        generator();
        guess();
    }

    if(level==3)
    {
        M=16;
        N=16;
        no_of_mines=40;

        generator();
        guess();
    }

    if(level==4)
    {
        printf("Please enter the size of the dimensions and number of mines you want\n");

        printf("First value:");
        scanf("%d", &M);

        printf("Second value:");
        scanf("%d", &N);

        printf("Number of mines:");
        scanf("%d", &no_of_mines);
        //generate minefield and start guessing game
        generator();
        guess();

    }
}


//Function that generates the minesweeper grid with chosen difficulty level.
void generator(void)
{
    //seed random numbers
    srand(time(NULL));
    //initializes grid with '-'.
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            initial[i][j] = current[i][j]= answer[i][j] = '-';
        }
    }
    //places mines on randomly genetated positions
    for(mines=0;mines<no_of_mines;mines++)
    {
        int i=rand()%M;
        int j=rand()%N;
        if(answer[i][j]!='*')
        {
            current[i][j]=answer[i][j]='*';
        }
        else mines--; //retry placing the mine if selected is already occupied
    }

    //calculates and assign numbers around mines
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(answer[i][j]!='*')
            {
                answer[i][j]=0;
            }
            for(int dx=-1; dx<=1; dx++)
            {
                for(int dy=-1; dy<=1; dy++)
                {
                    if(dx==0 && dy==0) continue;
                    if(i+dx>=0 && i+dx<M && j+dy>=0 && j+dy<N && answer[i+dx][j+dy]=='*' && answer[i][j] != '*')
                    {
                        //counts the number of mines around each cell
                        answer[i][j]++;
                    }
                }
            }
        }
    }

}


//function that prints the initial and updated minesweeper grid 
void printfield(void)
{
    //print column numbers
    for(int i=0;i<M;i++)
    {
        if(i==0)
        {
            printf("\t");
        }
        printf("|%d|  ", i);
    }
    printf("\n\n");

    //print row numbers and grid contents
    for(int i=0;i<M;i++ )                       
    {   
        printf("|%d|\t", i);
        for(int j=0;j<N;j++)
        {
            // Display appropriate character for each cell
            if(initial[i][j]=='-')
            {
                printf("|%c|  ",initial[i][j]);

            }
            else if(answer[i][j] == 0 )
            {
                initial[i][j] = 0   ;                
                printf("|%d|  ",initial[i][j]);
            }
            else if(answer[x][y] == '*' || initial[x][y] == '*')
            {
                continue;
            }
            else
            {
                printf("|%d|  ",initial[i][j]);

            }
        }
        printf("\n");
    }
}

//function that takes input of user guess of row and column number, and also checks if the user win or lose by revealing the cell choosen by user in each step. 
void guess(void)
{
    printfield();    //prints the current minefield grid
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(answer[i][j]==initial[i][j]) match++;    
        }
    }

    //check if the player has won
    if(match==((M*N)-no_of_mines))
    {
        printf("\n\nYOU WIN!!!\n");
        playagain();
    }

    // Prompt the user for a guess (row and column)
    printf("enter x and y values: ");
    scanf("%d %d", &x, &y);

    // Validate the guess coordinates
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("Please enter a value inside the grid\n");
        guess();
    }

    // Check if the guessed cell contains a mine
    if( answer[x][y] == '*' )
    {
        printfinal();
        printf("You hit a mine at %d,%d\nYOU LOSE!!!!\n", x, y);
        playagain();
    }
    
    // Check if the cell has already been guessed
    if( initial[x][y] != '-' )
    {
        printf("Please enter a value that has not already been entered\n");
        guess();
    }

    // Reveal the cell and check for adjacent cells if '0'
    else                                               
    {
      initial[x][y]=answer[x][y];
      if(answer[x][y]==0)
      {
        revealAdjacentBlanks(x, y);
      }
      match=0;
      guess();
    }
}


//reveals adjacent 8 cells (except when an adjacent cell is a mine) when user selected cell contains '0'. It also recursively checks if the adjacent cell is '0' to reveal further adjacent cells of the later cell.
void revealAdjacentBlanks(int x, int y)
{
    // Reveal the current cell
    if(answer[x][y] != '*')
    initial[x][y] = answer[x][y];
    // Recursively reveal adjacent blanks
    if (answer[x][y] == 0)
    {
        for (int dx = -1; dx <= 1; dx++) 
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if (dx == 0 && dy == 0) continue;
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < M && newY >= 0 && newY < N && initial[newX][newY] == '-' && answer[newX][newY] != '*')
                {
                    revealAdjacentBlanks(newX, newY);
                }
            }
        }
    }
}


//prints minesweeper grid only containing mines. This function is called when user lose to show the positions of mines.
void printfinal()
{
    for(int i=0;i<M;i++)
    {
        if(i==0)
        {
            printf("\t");
        }
        printf("|%d|\t", i);
    }
    printf("\n\n");

    for(int i=0;i<M;i++)
    {   
        printf("|%d|\t", i);
        for(int j=0;j<N;j++)
        {
            printf("|%c|\t", current[i][j]);
        }
        printf("\n");
    }
}


//takes input from user whether to play the game again after a win or lose.
void playagain(void)
{
    printf("Would you like to play again(Y/N)?:");
    scanf(" %c", &again);
    //validate user input.
    if(again!='Y' && again!='y' && again!='N' && again!='n')
    { 
        while(1)
        {
            printf("please enter y/n.\n");
            printf("do you want to enter more values?(y/n): ");
            scanf(" %c",&again);
            if(again=='Y'  || again=='y' || again=='N' || again=='n') break;
        }
    }

    if(again=='Y' || again=='y')
    {
        difficulty();
    }
    
    else if(again=='N' || again=='n')
    {
         printf("\nGAME OVER\n");
         exit(1);
    }
    
    else
    {
        printf("Please enter either Y or N");
        playagain();
    }
}

//TIC-TAC-TOE GAME
char Board[3][3];
// 3x3 board
// Function to initialize the board
void initialize() 
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            Board[i][j]=' ';
            // Initialising each element of the matrix with a blank space
        }
    }
}

// Function to print the board
void printboard() {
    printf(" %c ", Board[0][0]);
    printf(" | ");
    printf( "%c ",Board[0][1]);
    printf(" | ");
    printf(" %c ",Board[0][2]);
    printf("\n");
    printf("---------------\n");
    printf(" %c ",Board[1][0]);
    printf(" | ");
    printf(" %c ",Board[1][1]);
    printf(" | ");
    printf(" %c ",Board[1][2]);
    printf("\n");
    printf("---------------\n");
    printf(" %c ",Board[2][0]);
    printf(" | ");
    printf(" %c ",Board[2][1]);
    printf(" | ");
    printf(" %c ",Board[2][2]);
    printf("\n");
}

// Function to check if there is a winner
char checkwinner() 
{
    // Checking the row elements are same
    for (int i=0;i<3;i++)
    {
        if(Board[i][0]==Board[i][1]&&Board[i][1]==Board[i][2]&&Board[i][0]!=' ') 
        {
            return Board[i][0];
        }
    }
    // Checking the column elements are same
    for(int j=0;j<3;j++) 
    {
        if(Board[0][j]==Board[1][j]&&Board[1][j]==Board[2][j]&&Board[0][j]!=' ') 
        {
            return Board[0][j];
        }
    }
    // Checking the diagonal elements are same
    if((Board[0][0]==Board[1][1]&&Board[1][1]==Board[2][2]) || 
        (Board[0][2]==Board[1][1]&&Board[1][1]==Board[2][0])&&(Board[0][0]!=' ')) 
    {
        return Board[1][1];
    }
    // Check if the board is full (tie)
    for (int i=0;i<3; i++) 
    {
        for (int j=0;j<3;j++) 
        {
            if(Board[i][j]==' ')
            {
                return ' ';
            }
        }
    }
    return 'T'; //When the game is Tie
}

void TTT() 
{
    int row,col;
    char player='X';
    char winner=' ';

    initialize();
    
    printf("Welcome to Tic Tac Toe!\n");

    while (winner==' ') 
    {
        printf("\nPlayer %c's turn. Enter row and column (0-2): ", player);
        scanf("%d%d",&row,&col);
        
        if (row< 0||row > 2||col<0||col>2||Board[row][col]!=' ') 
        {
            printf("Invalid move. Try again.\n");
            // when the given row or column number does not exist or chosen the same spot as earlier
            continue;
            // to skip the rest of the lines in the loop since the above input is invalid
        }
        
        Board[row][col]=player;
        //printing the board after every choice made by the user
        printboard();
        //checking if the game is over
        winner=checkwinner();
        
        // Switching the player after every turn
        if (player=='X') 
        {
            player='O';
        }
        else 
        {
            player='X';
        }
    }
    
    if (winner=='T') 
    {
        printf("\nThe game is a tie!\n"); 
        // printing statement when the game is a tie
    } 
    else 
    {
        printf("\nPlayer %c wins!\n", winner);
        // printing the winner of the game if any
    }
   return;
}

//CONNECT 4 GAME
#define ROWS 6
#define COLS 7

char board[ROWS][COLS];
// Initialize the game board
void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the game board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n\n");
}

// Drop a token into a column
int dropToken(int col, char token) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = token;
            return 1;
        }
    }
    return 0; // Column is full
}

// Check for a win
int checkWin(char token) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == token && board[i][j + 1] == token && board[i][j + 2] == token && board[i][j + 3] == token) {
                return 1; // Win
            }
        }
    }
    // Check vertical
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == token && board[i + 1][j] == token && board[i + 2][j] == token && board[i + 3][j] == token) {
                return 1; // Win
            }
        }
    }
    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == token && board[i + 1][j + 1] == token && board[i + 2][j + 2] == token && board[i + 3][j + 3] == token) {
                return 1; // Win
            }
        }
    }
    // Check diagonal (bottom-left to top-right)
    for (int i = ROWS - 1; i >= 3; i--) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == token && board[i - 1][j + 1] == token && board[i - 2][j + 2] == token && board[i - 3][j + 3] == token) {
                return 1; // Win
            }
        }
    }
    return 0; // No win
}

// Check if the board is full
int isBoardFull() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Main function
void c4() {
    int col, turn = 1, gameEnd = 0;
    char token = 'X';

    // Initialize the game board
    initializeBoard();

    // Main game loop
    while (!gameEnd) {
        // Display the game board
        displayBoard();

        // Get player input
        printf("Player %d's turn. Enter column number (1-7): ", turn);
        scanf("%d", &col);

        // Validate input
        if (col < 1 || col > 7) {
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            continue;
        }

        // Drop token into column
        if (!dropToken(col - 1, token)) {
            printf("Column is full. Please choose another column.\n");
            continue;
        }

        // Check for win or draw
        if (checkWin(token)) {
            displayBoard();
            printf("Player %d wins!\n", turn);
            gameEnd = 1;
        } else if (isBoardFull()) {
            displayBoard();
            printf("It's a draw!\n");
            gameEnd = 1;
        }

        // Switch player
        turn = (turn == 1) ? 2 : 1;
        token = (token == 'X') ? 'O' : 'X';
    }

    return;
}

//FINAL MAIN FUNCTION
int main(){

    int ch;
    while(true){
        system("cls");
        printf("**************************Welcome to Project of CS LAB GROUP-33**************************\n\n");
        printf("WHICH GAME DO YOU WANT TO PLAY? \n");
        printf("1. Snake and Ladder \n");
        printf("2. Minesweeper\n");    
        printf("3. Tic Tac Toe\n");
        printf("4. Connect 4\n");
        printf("5. 2048\n");    
        printf("6. Sudoku\n");
        printf("7. Exit\n\n");

        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                snl();
            break;

            case 2:
                minesweeper();
            break;
            
            case 3:
                TTT();
            break;

            case 4:
                 c4();
            break;

            case 5:
                two048();
            break;

            case 6:
                sudoku();
            break;

            case 7:
                scanf("%*c");
                exit(0);
            break;

            scanf("%*c");
            default:
                printf("Invalid choice");
            break;  
        }
    }
}