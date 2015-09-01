#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
#include "bowling_gui.h"

static int lastPosition;// Potrebna mi je informacija o poslednjoj poziciji

void initialisation(void) 
{
    int curr_row;
    int curr_column;
    int counter = NUM_OF_PINS - 1;
    
    //unos staze
    for (curr_row = 0; curr_row < ROW; curr_row++)
    {
	matrix[curr_row][0] = '|';
	matrix[curr_row][2] = '|';
	matrix[curr_row][14] = '|';
	matrix[curr_row][16] = '|';
    }

    
    int tmp = 0, tmp1;
    int n = START_PINS;

    //unosenje cunjeva u matricu
    for (curr_row = 4; curr_row > 0; curr_row--)
    {
	tmp1 = n;
	for (curr_column = curr_row; curr_column > 0; curr_column--)
	{
	    matrix[tmp][tmp1] = bowling_pins[counter--];
	    tmp1+=2;
	}
	tmp++;
	n++;
    }

    
    matrix[BALL_POS_ROW][BALL_POS_COL] = bowling_ball;  //pocetna pozicija na kojoj ce se nalaziti kugla

    //prikaz rezultata
    
    tmp1 = START_LANE_ROW;				//prvi red od koga pocinju da se upisuju -
    for (curr_row = 0; curr_row < 10; curr_row++)
    {
	for (curr_column = 0; curr_column < 3; curr_column++) 
	{
	    matrix[0][tmp1 + curr_column] = '-';
	    matrix[3][tmp1 + curr_column] = '-';
	}

	tmp1+=4;
    }
    
    
    tmp = START_LANE_COLON;				//prva kolona od koje pocinju da se upisuju |

    for (curr_row = 0; curr_row < 11; curr_row++)
    {
	for (curr_column = 0; curr_column < 2; curr_column++) 
	{
	    matrix[1][tmp] = '|';
	    matrix[2][tmp] = '|';
	}
	tmp+=4;
    }
    
    //primjer kako ce izgledati rezultati
    
    matrix[1][23] = '_';
    matrix[1][25] = '1';
    matrix[2][25] = '1';
    
    system("clear");
    print();
    usleep(700000);
    return;
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
      if (curr_pos_col < 2 || curr_pos_col > 14) 	//ako je kugla dosla do kraja staze, da se nastavi kretati pravo kroz kanal
	offset = 0;					//ne koristi se vise radnom jer je njeno kretanje fiksno 
      else
      {
	//foo1(a,b); //napisao sam je samo da bih mogao dobiti bolje vrijednosti za random
		    //ako se ko sjeti neceg pametnijeg neka optimizuje
		  //bez neceg ovakvog random vraca uvijek istu vrijednost
		// ni u kojem slucaju ovo ovako ostaviti
	a += 2.435;
	b += 4.353;
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


// Ovo je neki moj random
unsigned int random7()
{
	unsigned int x;
	char* a;
	x=(unsigned int)a;
	return x;
}
// Funkcija koja u odnosu na poziciju vraca slucajan broj cunjeva koje treba srusiti
// Mislim da bi ovu funkciju trebali koristiti i ovi iz backenda prilikom pozivanja svoje f_je srusi
int knockDown(int position)
{
	int maxMod,x;
	if(position<5 || position>11)
		return 0;
	else if(position==5 || position==11)
		maxMod=3;
	else if(position==6 || position==10)
		maxMod=5;
	else if(position==7 || position==9)
		maxMod=7;
	else if(position==8)
		maxMod=10;
		
	x=(random7()%maxMod)+1;
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

	 	 switch(pale[i])
	 	 {

	 	 case 1:
	 	 	matrix[3][8]='x'; break;
	 	 case 2:
	 	 	matrix[2][7]='x'; break;
	 	 case 3:
	 	 	matrix[2][9]='x'; break;
	 	 case 4:
	 	 	matrix[1][6]='x'; break;
	 	 case 5:
	 	 	matrix[1][8]='x'; break;
	 	 case 6:
	 	 	matrix[1][10]='x'; break;
	 	 case 7:
	 	 	matrix[0][5]='x'; break;
	 	 case 8:
	 	 	matrix[0][7]='x'; break;
	 	 case 9:
	 	 	matrix[0][9]='x'; break;
	 	 case 10:
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
  initialisation();
  move();
  int KolikoZaOboriti;
  KolikoZaOboriti=knockDown(lastPosition);    
  pinsDown(KolikoZaOboriti);

  return 0;
}
