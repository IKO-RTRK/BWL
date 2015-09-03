#include <stdio.h>
//#include <stdlib.h>
# include <unistd.h>
#include  <stdint.h>
#include "bowling_gui.h"

static int lastPosition;// Potrebna mi je informacija o poslednjoj poziciji

//Ovo podrzava samo gcc kompajler
char matrix[ROW][COLUMN] = {[0 ... ROW-1][0 ... COLUMN-1] = ' '};
char bowling_pins[NUM_OF_PINS] = {[0 ... NUM_OF_PINS-1] = '!'};
char bowling_ball = 'o';

void initialisationLane(void)
{
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t j;
    //unos staze
    for (curr_row = 4; curr_row < ROW; curr_row++)
      {
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
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t counter = NUM_OF_PINS - 1;
    uint8_t tmp = 0, tmp1;
    uint8_t n = START_PINS;

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
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t tmp1 = START_LANE_ROW;				//prvi red od koga pocinju da se upisuju -
    for (curr_row = 0; curr_row < 10; curr_row++)
    {
	for (curr_column = 0; curr_column < 3; curr_column++) 
	{
	    matrix[0][tmp1 + curr_column] = '-';
	    matrix[3][tmp1 + curr_column] = '-';
	}

	tmp1+=4;
    }
        
    uint8_t tmp = START_LANE_COLON;				//prva kolona od koje pocinju da se upisuju |

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
    uint8_t offset; 					//rezultat random-a, ukoliko kugla nije otisla van staze
    uint8_t curr_pos_row = BALL_POS_ROW;			//trentuni red u kome se nalazi kugla u toku kretanja
    uint8_t curr_pos_col = BALL_POS_COL;			//trentuna kolona u kojoj se nalazi kugla u toku kretanja
    uint8_t prev_pos_row;					//prethodni red u kome se nalazila kugla
    uint8_t prev_pos_col;					//prethodna kolona
    double a, b;		// koriste se samo za funkciju foo1
    while (curr_pos_row >= 5)				//sve dok ne dodje kugla do cunjeva
    {

      if(curr_pos_col==4)		// ako je kugla dosla do kanala, natjeramo ga da udje u njega
	offset = -1;
      else if(curr_pos_col==12)		// isto to samo u drugu stranu
	offset = 1;
      else if (curr_pos_col < 4  || curr_pos_col > 12) 	//ako je kugla izasla sa staze, da se nastavi kretati pravo kroz kanal
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
      lastPosition=curr_pos_col;   			//ovo sam dodao jer mi je bila potrebna zadnja pozicija
      system("clear");
      print();
      usleep(700000);
      
    }
}

// Funkcija koja u odnosu na poziciju vraca slucajan broj cunjeva koje treba srusiti
// Mislim da bi ovu funkciju trebali koristiti i ovi iz backenda prilikom pozivanja svoje f_je srusi
int knockDownPins(int position, int remain) 	// remain se koristi da zapamtim broj nesrusenih
{  // da se ne desi u slucaju da je u prvom bacanju pogodjen centar i sruseno 7 cunjeva i da se u narednom bacanju pogodi centar ponovo
   // i tad srusi npr 5 a ostala su samo 3... min ogranicava maxMod 
	uint8_t maxMod,x;				
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
void pinsDown(int k,int fallen[],int position)	//fallen dodano da bi se znalo koji cunjevi su sruseni, sluzi za tesiranje
{
      if(k!=0)
      {
	int pale[k], i, j;
	for(i=0;i<k;i++)
	{
	  fallen[i] = pale[i]=random()%10+1;
	  if (position == 5)
	  {
	    if (pale[i] != 4 && pale[i] != 7 && pale[i] != 8)
	    {
	      i--;
	      continue;
	    }
	  }
	  else if (position == 11)
	  {
	    if (pale[i] != 6 && pale[i] != 9 && pale[i] != 10)
	    {
	      i--;
	      continue;
	    }
	  }
	  else if (position == 6)
	  {
	    if (pale[i] != 2 && pale[i] != 4 && pale[i] != 5 && pale[i] != 7 && pale[i] != 8)
	    {
	      i--;
	      continue;
	    }
	  }
	  else if (position == 10)
	  {
	    if (pale[i] != 3 && pale[i] != 5 && pale[i] != 6 && pale[i] != 9 && pale[i] != 10)
	    {
	      i--;
	      continue;
	    }
	  }
	  else if (position == 7)
	  {
	    if (pale[i] != 1 && pale[i] != 2 && pale[i] != 3 && pale[i] != 4 && pale[i] != 5 && pale[i] != 7 && pale[i] != 8)
	    {
	      i--;
	      continue;
	    }
	  }
	  else if (position == 9)
	  {
	    if (pale[i] != 1 && pale[i] != 2 && pale[i] != 3 && pale[i] != 5 && pale[i] != 6 && pale[i] != 9 && pale[i] != 10)
	    {
	      i--;
	      continue;
	    }
	  }
	  for(j=0;j<i;j++)		// Da ne izgleda da su npr srusena samo 2 cunja a trebalo je 5
					// tj da se ne postavlja 'x' na isto mjesto
	  {
	    if(pale[i]==pale[j]) 
	      i--;
	  }
	 }
	   for(i=0;i<=k;i++)
	     {

	       switch(pale[i])	// Ovi if-ovi dodani u svakom case-u da ne bi u drugom bacanju ponovo stavljalo 'x'
				// tamo gdje je on vec postavljen... Treba biti zapamcen polozaj nesrusenih cunjeva iz prvog bacanja 
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
	 
	/* matrix[4][lastPosition]='.';
	 system("clear");			Zakomentarisano zbog testova, nakon testiranja otkomentarisati
         print();
         usleep(700000);     */
}

//funkcija koje postavlja rezultate rusenja cunjeva
//i ukupan broj bodova po frejmovima
void populateMatrixTable(int* score,int* total)
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
}

//Ispis matrice
void print(void)
{
    uint8_t curr_row;
    uint8_t curr_column;
    
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

unsigned int random(void)
{
     static unsigned int zi,zii = 1;
     
     zi=(1103515245* zii + 12345) % 2147483648 ;
     zii=zi;
             return zi ;
}

int main(void)		// otkomentarisati samo ako se bude nesto provjeravalo
{
  initialisationLane();
  initialisationPins();
  initialisationTable();
  
  uint8_t KolikoZaOboriti[21];  // Zbog 21-og bacanja
  uint8_t i;
  for(i=0;i<10;i++)	// Simulacija vise bacanja... Trebalo bi 21 ali predugo traje dok provjeravamo ispis
  {
    move();

    if(i%2==1)
      KolikoZaOboriti[i]=knockDownPins(lastPosition, 10-KolikoZaOboriti[i-1]);    
    else
      KolikoZaOboriti[i]=knockDownPins(lastPosition, 10);
    int tmpNiz[3];
    pinsDown(KolikoZaOboriti[i],tmpNiz,lastPosition);
    sleep(2);
    int tmpPopulation1,tmpPopulation2;
    populateMatrixTable(&tmpPopulation1,&tmpPopulation2);
    initialisationLane();		// Ova initialisationLane refresh-uje donji dio staze ispod cunjeva
    initialisationTable();		// i tabela se treba refresh-ovati nakon svakog bacanja

    if(i<9&&i>0&&(i%2==1||KolikoZaOboriti[i]==10)) 
      initialisationPins();	// Cunjevi se nakon svaka dva bacanja trebaju refresh-ovati
// Ovako sam uradio jer treba da nakon prvog bacanja u seriji ostanu neporuseni cunjevi

    }

    return 0;
}  
