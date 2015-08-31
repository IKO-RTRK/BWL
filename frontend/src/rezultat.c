# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main(void){

char b[10][2];// 10 je zbog broja serija a 2 zbog bacanja i postavim na ' ' sve
int i, j;
for(i=0;i<10;i++)
{
	for(j=0;j<2;j++)
	{
	b[i][j]=' ';
	}
}	
int ukupno[10]={0};

void prikazRezultata(int serija, int bacanje, int sruseno, int ukupanRez)
// moja ideja je da nam oni salju koja je serija, bacanje, koliko je sruseno i da oni vode racuna o ukupnom rezultatu
{
// ovdje je ona logika kad se ispisuje X,- i /
if(sruseno==10) b[serija][bacanje]='X';
else if(sruseno==0) b[serija][bacanje]='-';
else if(bacanje==2 && b[serija][bacanje-1]+sruseno==0x40) b[serija][bacanje]='/';
else b[serija][bacanje]=0x30+sruseno;

ukupno[serija]=ukupanRez;

// znam da se ovo moglo uraditi elegantnije ali nisam imao ideja a i bilo je kasno a ja umoran...
printf("\n1.serija 2.serija 3.serija 4.serija 5.serija 6.serija 7.serija 8.serija 9.serija 10.serija\n\n");
printf("| %c | %c || %c | %c || %c | %c || %c | %c || %c | %c || %c | %c || %c | %c || %c | %c || %c | %c || %c | %c ||\n",
b[0][0],b[0][1],b[1][0],b[1][1],b[2][0],b[2][1],b[3][0],b[3][1],b[4][0],b[4][1],b[5][0],b[5][1],b[6][0],b[6][1],b[7][0],b[7][1],b[8][0],
b[8][1],b[9][0],b[9][1]);
printf("|    ---||    ---||    ---||    ---||    ---||    ---||    ---||    ---||    ---||    ---||\n");
printf("|   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||   %d   ||\n\n",
ukupno[0],ukupno[1],ukupno[2],ukupno[3],ukupno[4],ukupno[5],ukupno[6],ukupno[7],ukupno[8],ukupno[9]);

}
// ovdje sam pozvao ovu funkciju samo jednom
prikazRezultata(0,0,3,3);
return 0;
}
