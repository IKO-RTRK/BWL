#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
#include "bowling_gui.h"

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
	foo1(a,b); //napisao sam je samo da bih mogao dobiti bolje vrijednosti za random
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
      system("clear");
      print();
      usleep(700000);
      
    }
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
  return 0;
}