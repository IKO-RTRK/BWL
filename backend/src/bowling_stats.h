/** 
	@file	bowling_stats.h
	@brief	Dokument sadrzi kratak opis funkcija (funkcionalnost, parametri, povratne vrijednosti),
		kao i kratak opis makroa, konstanti i globalnih varijabli koje su koristene.	
	@author RT-RK - Backend 
	@date   Septembar, 2015
*/
#ifndef BOWLING_STATS_H
#define BOWLING_STATS_H
/**
	Broj okvira u jednoj igri. Svaki okvir se sastoji od maksimalno dva bacanja, osim zadnjeg okvira, 
	koji može imati maksimalno tri bacanja.
*/
#define NUM_OF_FRAMES 10
/**
	Broj maksimalnih bacanja u jednoj igri.
*/
#define MAX_NUM_OF_THROWS (NUM_OF_FRAMES*2 + 1)
/**
	Prvo bacanje u okviru posljednjeg okvira.
*/
#define LAST_FRAME_FIRST_THROW 18
/**
	Maksimalan broj srusenih cunjeva u jednom bacanju.
*/
#define ALL_PINS_DOWN 10
/**
	Vrijednost okvira još nije izracunata.
*/
#define NOT_EVALUATED -1
/**
	Bacanje nije izvrseno.
*/
#define NOT_THROWN -1
#include <stdint.h>

/**
	@brief Struktura predstavlja apstrakciju jednog igraca sa svim potrebnim podacima za igru. 
*/
typedef struct Player 
{
    char* name;				///< Ime igraca
    int16_t frames[NUM_OF_FRAMES];	///< Niz u koji se upisuju bodovi po okvirima 
    int8_t points[MAX_NUM_OF_THROWS]; 	///< Niz u koji se upisuju bodovi po bacanjima
    uint16_t totalScore; 		///< Ukupan rezultat
    uint8_t numOfThrow;			///< Broj bacanja
    int lane_id;			///< Broj staze koja je dodjeljena igracu
} player;

/**
*	@brief	Funkcija vrsi pocetnu inicijalizaciju igre. Parametri funkcije su argumenti komandne linije. 
*	@param	argc	Ukupan broj argumenata komandne linije.
*	@param	argv[]	Niz stringova (argumenata). Prvi stvarni argument predstavlja ukupan broj staza. Drugi argument oznacava 
			broja igraca na prvoj stazi, a zatim dolaze imena svih igraca sa prve staze. Nakon toga dolazi broj igraca 
			na drugoj stazi, pa njihova imena. Postupak se ponavlja za sve staze.
*	@retval void
*/
void initialise(int argc, char* argv[]);
/**
*	@brief	Funkcija na osnovu imena igraca i broja staze vraca broj bodova koje je ostvario taj igrac.
*	@param	playerName	Ime igraca.
*	@param	laneId		Broj staze.
*	@retval int16_t		Ukupan broj bodova za odredjenog igraca na odredjenoj stazi.
*/
int16_t score(char* playerName,int laneId);
/**
*	@brief	Funkcija za odredjenog igraca na odredjenoj stazi upisuje broj srusenih cunjeva nakon bacanja.
*	@param	playerName	Ime igraca.
*	@param	laneId		Broj staze.
*	@param	x		Broj srusenih cunjeva.
*	@retval void
*/
void knockDown(char* playerName,int laneId,uint8_t x);
//int validate(int argc ,char* argv[]);

/**
*	@brief	Funkcija za odredjenog igraca na odredjenoj stazi vraca adresu pocetka niza koji sadrzi bodove po bacanjima.
*	@param	playerName	Ime igraca.
*	@param	laneId		Broj staze.
*	@retval int8_t*		Referenca na niz bodova po bacanjima.
*/
int8_t* get_points_array(char* playerName,int laneId); 
/**
*	@brief	Funkcija za odredjenog igraca na odredjenoj stazi vraca adresu pocetka niza koji sadrzi bodove po okvirima.
*	@param	playerName	Ime igraca.
*	@param	laneId		Broj staze.
*	@retval int16_t*	Referenca na niz okvira (frejmova).
*/
int16_t* get_frames_array(char* playerName, int laneId); 
/**
*	@brief	Funkcija za odredjeni broj staze vraca niz imena svih igraca na toj stazi.
*	@param	laneId		Broj staze.
*	@retval char**		Referenca na niz.
*/
char** getAllPlayersOnLane(int laneId);
/**
*	@brief	Funkcija vraca adresu niza koji sadrzi identifikatore svih staza.
*	@param	void
*	@retval int*	Referenca na niz.
*/
int* getAllLaneIds();
#endif
