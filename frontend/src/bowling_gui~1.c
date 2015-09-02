#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
#include "bowling_gui~1.h"

static int lastPosition;// Potrebna mi je informacija o poslednjoj poziciji

//Ovo podrzava samo gcc kompajler
char matrixLane[ROW][COLUMN] = {[0 ... ROW-1][0 ... COLUMN-1] = ' '};
char matrixTable[ROW_TABLE][COLUMN_TABLE] = {[0 ... ROW_TABLE-1][0 ... COLUMN_TABLE-1] = ' '};
char bowling_pins[NUM_OF_PINS] = {[0 ... NUM_OF_PINS-1] = '!'};

char bowling_ball = 'o';


void initialisationLane(void)
{
    int curr_row;
    int curr_column;
    
    //unos staze
    for (curr_row = 0; curr_row < ROW; curr_row++)
    {
	matrixLane[curr_row][0] = '|';
	matrixLane[curr_row][2] = '|';
	matrixLane[curr_row][10] = '|';
	matrixLane[curr_row][12] = '|';
    }
    
    matrixLane[BALL_POS_ROW][BALL_POS_COL] = bowling_ball;  //pocetna pozicija na kojoj ce se nalaziti kugla
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
	tmp1 = n;
	for (curr_column = curr_row; curr_column > 0; curr_column--)
	{
	    matrixLane[tmp][tmp1] = bowling_pins[counter--];
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
	    matrixTable[0][tmp1 + curr_column] = '-';
	    matrixTable[3][tmp1 + curr_column] = '-';
	}

	tmp1+=4;
    }
    
    
    int tmp = START_LANE_COLON;				//prva kolona od koje pocinju da se upisuju |

    for (curr_row = 0; curr_row < 11; curr_row++)
    {
	for (curr_column = 0; curr_column < 2; curr_column++) 
	{
	    matrixTable[1][tmp] = '|';
	    matrixTable[2][tmp] = '|';
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
	offset = (random7() % 3) - 1;
   
      }
      
      prev_pos_row = curr_pos_row;
      prev_pos_col = curr_pos_col;
      
      curr_pos_row -= 1;
      curr_pos_col = curr_pos_col + offset;
	
      matrixLane[prev_pos_row][prev_pos_col] = '.';		//na prethodnoj poziciji na kojoj se nalazila kugla upisi .
      matrixLane[curr_pos_row][curr_pos_col] = bowling_ball;//na trenutnu poziciju na kojoj se nalazi kugla ucrtaj kuglu 
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
	 	 	matrixLane[3][6]='x'; break;
	 	 case 2:
	 	 	matrixLane[2][5]='x'; break;
	 	 case 3:
	 	 	matrixLane[2][7]='x'; break;
	 	 case 4:
	 	 	matrixLane[1][4]='x'; break;
	 	 case 5:
	 	 	matrixLane[1][6]='x'; break;
	 	 case 6:
	 	 	matrixLane[1][8]='x'; break;
	 	 case 7:
	 	 	matrixLane[0][3]='x'; break;
	 	 case 8:
	 	 	matrixLane[0][5]='x'; break;
	 	 case 9:
	 	 	matrixLane[0][9]='x'; break;
	 	 case 10:
	 	 	matrixLane[0][9]='x'; break;

	 	 }
	 	}
	 }
	 matrixLane[4][lastPosition]='.';
	  system("clear");
      print();
      usleep(700000);
}

//funkcija koje postavlja rezultate rusenja cunjeva
//i ukupan broj bodova po frejmovima
void populateMatrixTable(int* score,int* total)
{
  int i = 0;	//trenutna kolona u matrici
  int j = 0;	//citanje iz score niza
  int k = 0;	//citanje iz total niza
  int l = 0;	//upisa ucinka za frame, pomjeranje kroz polja na kojima se upisuje rezultat
  
  int tmpScore[21] = {1,2,4,6,8,6}; 	// nizovi koristeni za testiranje
  int tmpTotal[10] = {6,15,21,35};	// umjesto njih ce se koristiti rezultati iz statistike
  score = tmpScore;
  total = tmpTotal;
  
  for (i = 1; i < COLUMN_TABLE; i+= 2)
  {
    if (*(score+j) != 0)
      matrixTable[1][i] = *(score+j++) + 0x30;		//postavljen rezultat bacanja, matrica je char, a rezultat int
    if ((i+1)%4 == 0)
    {
      if (*(total+k) != 0)
      {
	int tmpResult = *(total+k++);
	int tmpMod = 0;
	l = 0;
	while (tmpResult)
	{
	  tmpMod = tmpResult % 10;
	  tmpResult /= 10;
	  matrixTable[2][i-l] = tmpMod + 0x30;		//upisujemo broj po ciframa
	  l++;
	}
      }						 //postavljen ukupan ucinak za frame
    }
  }
  return;
}

//Ispis matrice
void print(void)
{
    int curr_row;
    int curr_column;
    int j = 0;
    
    for (curr_row = 0; curr_row < 4; curr_row++) 
    {
        //ispis 4 reda trake
	for (curr_column = 0; curr_column < COLUMN; curr_column++)
	{
	    printf("%c", matrixLane[curr_row][curr_column]);		
	}
	
	//ispis 4 reda tabele
	for (curr_column = COLUMN; curr_column < COLUMN + COLUMN_TABLE; curr_column++, j++)
	{
	  printf("%c", matrixTable[curr_row][j]);		
	}
	j = 0;
	printf("\n");
	
    }
    
    //ispis ostatka trake
    for (curr_row = ROW_TABLE ; curr_row < ROW; curr_row++) 
    {
      
	for (curr_column = 0; curr_column < COLUMN; curr_column++)	
	{
	    printf("%c", matrixLane[curr_row][curr_column]);		
	}
	
	printf("\n");
	
    }
    return;
}

void printTable(void)
{
    int curr_row;
    int curr_column;
    
    for (curr_row = 0; curr_row < ROW_TABLE; curr_row++) 
    {
	for (curr_column = 0; curr_column < COLUMN_TABLE; curr_column++)
	{
	    printf("%c", matrixTable[curr_row][curr_column]);
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
  system("clear");
  print();
 // printTable();
  usleep(700000);
  move();
  int KolikoZaOboriti;
  KolikoZaOboriti=knockDown(lastPosition);    
  pinsDown(KolikoZaOboriti);
  int tmpPopulate1,tmpPolulate2;
  populateMatrixTable(&tmpPopulate1,&tmpPolulate2);
  system("clear");
  
  print();

  return 0;
}
