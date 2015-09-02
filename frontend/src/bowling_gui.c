#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
#include "bowling_gui.h"

static int lastPosition;// Potrebna mi je informacija o poslednjoj poziciji

//Ovo podrzava samo gcc kompajler
char matrix[ROW][COLUMN] = {[0 ... ROW-1][0 ... COLUMN-1] = ' '};
char bowling_pins[NUM_OF_PINS] = {[0 ... NUM_OF_PINS-1] = '!'};

char bowling_ball = 'o';


void initialisationLane(void)
{
    int curr_row;
    int curr_column;
    int j;
    //unos staze
    for (curr_row = 4; curr_row < ROW; curr_row++)
    {
	/*matrix[curr_row][2] = '|';
	matrix[curr_row][4] = '|';
	matrix[curr_row][12] = '|';
	matrix[curr_row][14] = '|';*/

	for(j=5;j<12;j++)
	{
		matrix[curr_row][j] = ' ';
	}
	matrix[curr_row][3] = ' ';
	matrix[curr_row][13] = ' ';
	matrix[curr_row][2] = '|';
	matrix[curr_row][4] = '|';
	matrix[curr_row][12] = '|';
	matrix[curr_row][14] = '|';
    }
    
    matrix[BALL_POS_ROW][BALL_POS_COL] = bowling_ball;  //pocetna pozicija na kojoj ce se nalaziti kugla
    return;
}


void initialisationPins(void)
{
    int curr_row;
    int curr_column;
    int counter = NUM_OF_PINS - 1;
    int tmp = 0, tmp1;
    int n = START_PINS;

    //unosenje cunjeva u matricu
    for (curr_row = 4; curr_row > 0; curr_row--)
    {
	matrix[tmp][2] = '|';
	matrix[tmp][4] = '|';
	matrix[tmp][12] = '|';
	matrix[tmp][14] = '|';

	tmp1 = n;
	for (curr_column = curr_row; curr_column > 0; curr_column--)
	{
	    matrix[tmp][tmp1] = bowling_pins[counter--];
	    tmp1+=2;
	}
	tmp++;
	n++;
	
    }
    return;
}
    

 
void initialisationTable(void)
{   
    int curr_row;
    int curr_column;
    
    int tmp1 = START_LANE_ROW;				//prvi red od koga pocinju da se upisuju -
    for (curr_row = 0; curr_row < 10; curr_row++)
    {
	for (curr_column = 0; curr_column < 3; curr_column++) 
	{
	    matrix[0][tmp1 + curr_column] = '-';
	    matrix[3][tmp1 + curr_column] = '-';
	}

	tmp1+=4;
    }
    
    
    int tmp = START_LANE_COLON;				//prva kolona od koje pocinju da se upisuju |

    for (curr_row = 0; curr_row < 11; curr_row++)
    {
	for (curr_column = 0; curr_column < 2; curr_column++) 
	{
	    matrix[1][tmp] = '|';
	    matrix[2][tmp] = '|';
	}
	tmp+=4;
    }
    
    
}
    

    
void move(void)
{ 
    int offset; 					//rezultat random-a, ukoliko kugla nije otisla van staze
    int curr_pos_row = BALL_POS_ROW;			//trentuni red u kome se nalazi kugla u toku kretanja
    int curr_pos_col = BALL_POS_COL;			//trentuna kolona u kojoj se nalazi kugla u toku kretanja
    int prev_pos_row;					//prethodni red u kome se nalazila kugla
    int prev_pos_col;					//prethodna kolona
    double a, b;		// koriste se samo za funkciju foo1
    while (curr_pos_row >= 5)				//sve dok ne dodje kugla do cunjeva
    {

      if(curr_pos_col==4)		// ako je kugla dosla do kanala, natjeramo ga da udje u njega
	offset = -1;
      else if(curr_pos_col==12)		// isto to samo u drugu stranu
	offset = 1;
      else if (curr_pos_col < 4  || curr_pos_col > 12) 	//ako je kugla dosla do kraja staze, da se nastavi kretati pravo kroz kanal
	offset = 0;					//ne koristi se vise radnom jer je njeno kretanje fiksno 
      else
      {
	offset = (random() % 3) - 1;
      }
      
      prev_pos_row = curr_pos_row;
      prev_pos_col = curr_pos_col;
      
      curr_pos_row -= 1;
      curr_pos_col = curr_pos_col + offset;
	
      matrix[prev_pos_row][prev_pos_col] = '.';		//na prethodnoj poziciji na kojoj se nalazila kugla upisi .
      matrix[curr_pos_row][curr_pos_col] = bowling_ball;//na trenutnu poziciju na kojoj se nalazi kugla ucrtaj kuglu 
      lastPosition=curr_pos_col;//ovo sam dodao jer mi je bila potrebna zadnja pozicija
      system("clear");
      print();
      usleep(700000);
      
    }
}

// Funkcija koja u odnosu na poziciju vraca slucajan broj cunjeva koje treba srusiti
// Mislim da bi ovu funkciju trebali koristiti i ovi iz backenda prilikom pozivanja svoje f_je srusi
int knockDownPins(int position, int remain)
{
	int maxMod,x;
	if(position<5 || position>11)
		return 0;
	else if(position==5 || position==11)
		maxMod=min(remain,3);
	else if(position==6 || position==10)
		maxMod=min(remain,5);
	else if(position==7 || position==9)
		maxMod=min(remain,7);
	else if(position==8)
		maxMod=min(remain,10);
		
	x=(random()%maxMod)+1;
	return x;
}

// Funkcija koja stavlja 'x' na mjesto srusenog cunja, s tim da ona  na slucajan nacin
//  bira poziciju na kojoj ce srusiti cunj
void pinsDown(int k)
{
	 if(k!=0)
	 {
	 int pale[k], i, j;
	 for(i=0;i<=k;i++)
		{
		pale[i]=random()%11;
		for(j=0;j<i;j++)
			{
			if(pale[i]==pale[j]) 
			i--;
			}
	 	}
	 for(i=0;i<=k;i++)
	 	{

	 	 switch(pale[i])	// Ovi if-ovi dodani u svakom case-u da ne bi u drugom bacanju ponovo stavljalo 'x'
					// tamo gdje je on vec postavljen

	 	 {

	 	 case 1:
			if(matrix[3][8]=='x')
			  i--;
			else
	 	 	  matrix[3][8]='x'; break;
	 	 case 2:
			if(matrix[2][7]=='x')
			  i--;
			else
	 	 	  matrix[2][7]='x'; break;
	 	 case 3:
			if(matrix[2][9]=='x')
			  i--;
			else
	 	 	  matrix[2][9]='x'; break;
	 	 case 4: 
			if(matrix[1][6]=='x')
			  i--;
			else
	 	 	  matrix[1][6]='x'; break;
	 	 case 5:
			if(matrix[1][8]=='x')
			  i--;
			else
	 	 	  matrix[1][8]='x'; break;
	 	 case 6:
	 	 	if(matrix[1][10]=='x')
			  i--;
			else
	 	 	  matrix[1][10]='x'; break;
	 	 case 7:
	 	 	if(matrix[0][5]=='x')
			  i--;
			else
	 	 	  matrix[0][5]='x'; break;
	 	 case 8:
	 	 	if(matrix[0][7]=='x')
			  i--;
			else
	 	 	  matrix[0][7]='x'; break;
	 	 case 9:
	 	 	if(matrix[0][9]=='x')
			  i--;
			else
	 	 	  matrix[0][9]='x'; break;
	 	 case 10:
	 	 	if(matrix[0][11]=='x')
			  i--;
			else
	 	 	  matrix[0][11]='x'; break;

	 	 }
	 	}
	 }
	 matrix[4][lastPosition]='.';
	  system("clear");
      print();
      usleep(700000);
}



//Ispis matrice
void print(void)
{
    int curr_row;
    int curr_column;
    
    for (curr_row = 0; curr_row < ROW; curr_row++) 
    {
	for (curr_column = 0; curr_column < COLUMN; curr_column++)
	{
	    printf("%c", matrix[curr_row][curr_column]);
	}
	printf("\n");
    }
    return;
}

int main(void)
{
  initialisationLane();
  initialisationPins();
  initialisationTable();
  //system("clear");
 // print();
  //usleep(700000);

int KolikoZaOboriti[21];  
  int i;
for(i=0;i<4;i++)// Simulacija vise bacanja
{
  move();
  if(i%2==1)
    KolikoZaOboriti[i]=knockDownPins(lastPosition, 10-KolikoZaOboriti[i-1]);    
  else
    KolikoZaOboriti[i]=knockDownPins(lastPosition, 10);
  pinsDown(KolikoZaOboriti[i]);
  sleep(2);
  initialisationLane();// Ova initialisation1 mi je za donji dio staze ispod cunjeva
  if(i<9&&i>0&&(i%2==1||KolikoZaOboriti[i]==10)) 
  {
	 //initialisationLane();
  	 initialisationPins();
 	 initialisationTable();
  };
  //system("clear");
// A ova da se nakon svaka dva bacanja sve "refresuje"
// Ovako sam uradio jer treba da nakon prvog bacanja u seriji ostanu neporuseni cunjevi... Zbog toga sam sve ovo pisao

}

  return 0;
}
