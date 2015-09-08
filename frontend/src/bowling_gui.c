#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  <stdint.h>
#include "bowling_gui.h"

static int lastPosition[3];// Potrebna mi je informacija o poslednjoj poziciji

//Ovo podrzava samo gcc kompajler
char matrix_track[ROW_TRACK][COLUMN_TRACK] = {[0 ... ROW_TRACK-1][0 ... COLUMN_TRACK-1] = ' '};
char matrix_table[ROW_TABLE][COLUMN_TABLE] = {[0 ... ROW_TABLE-1][0 ... COLUMN_TABLE-1] = ' '};
char bowling_pins[NUM_OF_PINS] = {[0 ... NUM_OF_PINS-1] = '!'};
char bowling_ball = 'o';

typedef struct node{ // lista koja sluzi za izvlacenje rednog broja dostupnih pinova koji se mogu srusiti
	int position;
	struct node *next;
} node;

node * head=NULL;
node * tail=NULL;
char listSize=0;

void SetCursorPos(int XPos, int YPos)
{
 printf("\033[%d;%dH", YPos+1, XPos+1);
}

void listAppend(int broj)
{
	if ( head == NULL ) 
	{
		head=tail=(node*)malloc(sizeof(node));
		head->position=tail->position=broj;
		head->next=tail->next=NULL;
		return;
	}
	node *temp=tail;
	tail=(node*)malloc(sizeof(node));
	tail->next=NULL;
	temp->next=tail;
	tail->position=broj;
}
void listDestroy()
{
	node *temp;
	while(head!=NULL)
	{
		temp=head->next;
		free(head);
		head=temp;
	}
	head=tail=NULL;
	listSize=0;
}
int listGetAvailablePin(int atPosition) // vraca pin koji se moze srusiti, a nalazi se na poziciji "atPosition" u listi
{
	if ( atPosition > listSize || atPosition < 1 ) atPosition=1; // u slucaju da dodje nedozvoljena vrijednost izbacuje se onaj na poziciji 1
	int i=1;
	node *temp=head;
	node *prev=NULL;
	for(; i<atPosition; i++)
	{
		prev=temp;
		temp=temp->next;
	}
	i=temp->position;
	if ( temp==head ) { head=head->next; free(temp); listSize--; return i; }
	if ( temp==tail ) { free(tail); tail=prev; tail->next=NULL; listSize--; return i; }
	prev->next=temp->next;
	free(temp);
	listSize--;
	return i;
	
}
void listInitialisation()
{
	int i;
	listDestroy();
	for(i=1;i<=10;i++)
	listAppend(i);
	listSize=10;
}


void initialisationLane()
{
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t j;
    //unos staze
    for (curr_row = END_OF_PINS_ROW ; curr_row < ROW_TRACK; curr_row++)
      {
	for(j=5;j<12;j++)
	  {
		matrix_track[curr_row][j] = ' ';
	  }
	matrix_track[curr_row][3] = ' ';
	matrix_track[curr_row][13] = ' ';
	matrix_track[curr_row][2] = '|';
	matrix_track[curr_row][4] = '|';
	matrix_track[curr_row][12] = '|';
	matrix_track[curr_row][14] = '|';
      }
    
    matrix_track[BALL_POS_ROW][FIRST_BALL_POS_COL] = bowling_ball;  //pocetna pozicija na kojoj ce se nalaziti kugla
    return;
}


void initialisationPins()
{
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t counter = NUM_OF_PINS - 1;
    uint8_t tmp = START_OF_FIRST_TRACK_ROW, tmp1;
    uint8_t n = START_PINS;

    //unosenje cunjeva u matricu
    for (curr_row =END_OF_PINS_ROW; curr_row > START_OF_FIRST_TRACK_ROW; curr_row--)
    {
	matrix_track[tmp][2] = '|';
	matrix_track[tmp][4] = '|';
	matrix_track[tmp][12] = '|';
	matrix_track[tmp][14] = '|';

	tmp1 = n;
	for (curr_column = curr_row; curr_column >START_OF_FIRST_TRACK_ROW; curr_column--)
	{
	    matrix_track[tmp][tmp1] = bowling_pins[counter--];
	    tmp1+=2;
	}
	tmp++;
	n++;
	
    }
    return;
}
    
void initialisationTrack()
{
	initialisationPins();
	initialisationLane();
}

void initialisationTable()
{   
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t tmp1 = START_LANE_ROW;				//prvi red od koga pocinju da se upisuju -
    for (curr_row = 0; curr_row < 10; curr_row++)
    {
	for (curr_column = 1; curr_column < 4; curr_column++) 
	{
	    matrix_table[0][tmp1 + curr_column] = '-';
	    matrix_table[3][tmp1 + curr_column] = '-';
	}

	tmp1+=4;
    }
        
    uint8_t tmp = START_LANE_COLON;				//prva kolona od koje pocinju da se upisuju |

    for (curr_row = 0; curr_row < 11; curr_row++)
    {
	for (curr_column = 0; curr_column < 2; curr_column++) 
	{
	    matrix_table[1][tmp] = '|';
	    matrix_table[2][tmp] = '|';
	}
	tmp+=4;
    }
    
    
}

    /*
void move(int TrackNumber)
{ 
    uint8_t offset; 					//rezultat random-a, ukoliko kugla nije otisla van staze
    uint8_t curr_pos_row = BALL_POS_ROW;			//trentuni red u kome se nalazi kugla u toku kretanja
    uint8_t curr_pos_col = FIRST_BALL_POS_COL+(TrackNumber*DIFF);			//trentuna kolona u kojoj se nalazi kugla u toku kretanja
    uint8_t prev_pos_row;					//prethodni red u kome se nalazila kugla
    uint8_t prev_pos_col;					//prethodna kolona
    while (curr_pos_row >= 10)				//sve dok ne dodje kugla do cunjeva
    {

      if(curr_pos_col==4+(TrackNumber*DIFF))		// ako je kugla dosla do kanala, natjeramo ga da udje u njega
	offset = -1;
      else if(curr_pos_col==12+(TrackNumber*DIFF))		// isto to samo u drugu stranu
	offset = 1;
      else if (curr_pos_col < 4+(TrackNumber*DIFF)  || curr_pos_col > 12+(TrackNumber*DIFF)) 	//ako je kugla izasla sa staze, da se nastavi kretati pravo kroz kanal
	offset = 0;					//ne koristi se vise radnom jer je njeno kretanje fiksno 
      else
      {
	offset = (random1() % 3) - 1;
      }
      
      prev_pos_row = curr_pos_row;
      prev_pos_col = curr_pos_col;
      
      curr_pos_row -= 1;
      curr_pos_col = curr_pos_col + offset;
      matrix[prev_pos_row][prev_pos_col] = '.';		//na prethodnoj poziciji na kojoj se nalazila kugla upisi .
      matrix[curr_pos_row][curr_pos_col] = bowling_ball;//na trenutnu poziciju na kojoj se nalazi kugla ucrtaj kuglu 
      lastPosition[TrackNumber]=curr_pos_col;   			//ovo sam dodao jer mi je bila potrebna zadnja pozicija
      system("clear");
      print();
      usleep(100000);
      
    }
}*//*
// Funkcija koja u odnosu na poziciju vraca slucajan broj cunjeva koje treba srusiti
// Mislim da bi ovu funkciju trebali koristiti i ovi iz backenda prilikom pozivanja svoje f_je srusi
int knockDownPins(int position, int remain,int TrackNumber) 	// dodan int TrackNumber, int remain se koristi da se pamti broj nesrusenih
{  // da se ne desi u slucaju da je u prvom bacanju pogodjen centar i sruseno 7 cunjeva i da se u narednom bacanju pogodi centar ponovo
   // i tad srusi npr 5 a ostala su samo 3... min ogranicava maxMod 
	uint8_t maxMod,x;		
	if(position<5+(TrackNumber*DIFF) || position>11+(TrackNumber*DIFF))
		return 0;
	else if(position==5+(TrackNumber*DIFF) || position==11+(TrackNumber*DIFF))
		maxMod=min(remain,3);
	else if(position==6+(TrackNumber*DIFF) || position==10+(TrackNumber*DIFF))
		maxMod=min(remain,5);
	else if(position==7+(TrackNumber*DIFF) || position==9+(TrackNumber*DIFF))
		maxMod=min(remain,7);
	else if(position==8+(TrackNumber*DIFF))
		maxMod=min(remain,10);
	x=(random1()%maxMod)+1;
	return x;
}

// Funkcija koja stavlja 'x' na mjesto srusenog cunja, s tim da ona  na slucajan nacin
//  bira poziciju na kojoj ce srusiti cunj
void pinsDown(int k, int TrackNumber,int roll) //roll je redni broj bacanja u frejmu ( za prvo bacanje argument je 0, za drugo je 1 )
{
	if ( !roll ) listInitialisation();
	if( k!=0 )
	{
	uint8_t pale[k], i, j;
	for(i=0;i<k;i++)
	{
		pale[i]=listGetAvailablePin((random1()%listSize)+1);
	}
	   for(i=0;i<k;i++)
	     {

	       switch(pale[i]) 
	 	{

	 	 case 1:
	 	 	  matrix[8][8+(TrackNumber*DIFF)]='x'; break;
	 	 case 2:
	 	 	  matrix[7][7+(TrackNumber*DIFF)]='x'; break;
	 	 case 3:
	 	 	  matrix[7][9+(TrackNumber*DIFF)]='x'; break;
	 	 case 4: 
	 	 	  matrix[6][6+(TrackNumber*DIFF)]='x'; break;
	 	 case 5:
	 	 	  matrix[6][8+(TrackNumber*DIFF)]='x'; break;
	 	 case 6:
	 	 	  matrix[6][10+(TrackNumber*DIFF)]='x'; break;
	 	 case 7:
	 	 	  matrix[5][5+(TrackNumber*DIFF)]='x'; break;
	 	 case 8:
	 	 	  matrix[5][7+(TrackNumber*DIFF)]='x'; break;
	 	 case 9:
	 	 	  matrix[5][9+(TrackNumber*DIFF)]='x'; break;
	 	 case 10:
	 	 	  matrix[5][11+(TrackNumber*DIFF)]='x'; break;
	 	}
	     }
	}
	matrix[10][lastPosition[TrackNumber]]='.';
	system("clear");
        print();
        usleep(100000);
}
*/
//funkcija koje postavlja rezultate rusenja cunjeva
//i ukupan broj bodova po frejmovima
/*void populateMatrixTable(int* score,int* total)
{
  uint8_t i = 0;	//trenutna kolona u matrici
  uint8_t j = 0;	//citanje iz score niza
  uint8_t k = 0;	//citanje iz total niza
  uint8_t l = 0;	//upisa ucinka za frame, pomjeranje kroz polja na kojima se upisuje rezultat
  
  int tmpScore[21] = {1,2,4,6,8,6}; 	// nizovi koristeni za testiranje
  int tmpTotal[10] = {6,15,21,35};	// umjesto njih ce se koristiti rezultati iz statistike
  score = tmpScore;
  total = tmpTotal;
  
  for (i = START_LANE_ROW; i < COLUMN; i+= 2)
  {
    if (*(score+j) != 0)
      matrix[1][i] = *(score+j++) + 0x30;		//postavljen rezultat bacanja, matrica je char, a rezultat int
    if ((i+1)%4 == 2)			//uslov je ovakav jer tabela pocinje da se ispisuje od pozicije START_LANE_ROW, 
    {					//na poziciji odredjenoj uslovom se nalazi posljednja cifra rezultata za frame
      if (*(total+k) != 0)
      {
	int tmpResult = *(total+k++);
	int tmpMod = 0;
	l = 0;
	while (tmpResult)
	{
	  tmpMod = tmpResult % 10;
	  tmpResult /= 10;
	  matrix[2][i-l] = tmpMod + 0x30;		//upisujemo broj po ciframa
	  l++;
	}
      }						 //postavljen ukupan ucinak za frame
    }
  }
  return;
}*/

//Ispis matrice
void print_track(int NumberOfLanes)
{
    uint8_t curr_lane;
    uint8_t curr_row;
    uint8_t curr_column;
    for (curr_lane = 0; curr_lane < NumberOfLanes; curr_lane++)
	{
	    for (curr_row = 0; curr_row < ROW_TRACK; curr_row++) 
	    {
		for (curr_column = 0; curr_column < COLUMN_TRACK; curr_column++)
		{
	 	    SetCursorPos((curr_lane * DIFF_TRACKS)+curr_column, curr_row);
		    printf("%c", matrix_track[curr_row][curr_column]);
		}
		printf("\n");
	    }
	}
    return;
}


void print_table(int NumberOfTables)
{
    uint8_t curr_table;
    uint8_t curr_row;
    uint8_t curr_column;
    for (curr_table = 0; curr_table < NumberOfTables; curr_table++)
	{
	    for (curr_row = 0; curr_row < ROW_TABLE; curr_row++) 
	    {
		for (curr_column = 0; curr_column < COLUMN_TABLE; curr_column++)
		{
	 	    SetCursorPos(curr_column,(curr_table * DIFF_TABLES) + curr_row + 1);
		    printf("%c", matrix_table[curr_row][curr_column]);
		}
		printf("\n");
	    }
	}
    return;
}


unsigned int random1(void)
{
     static unsigned int zi;
     
     zi=(1103515245* zi + 12345) % 2147483648 ;
             return zi ;
}


int main(void)

{
initialisationTable();
//print_track(3);
print_table(3);
	//potrebno pozvati clear prije pokretanja programa
    return 0;
} 
