#ifndef USERS_H
#define USERS_H

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
#include <inttypes.h>

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
   // int lane_id;			///< Broj staze koja je dodjeljena igracu
} player;

/**
 * 	@brief Strukura predstavlja apstrakciju jedne staze sa igracima koji ucestvuju u igri
 */
typedef struct Lane
{
	int8_t laneId;			///<Identifikator staze
	player* playersOnLane;  ///<Niz igraca koji igraju na datoj stazi
	int8_t numberOfPlayers;	  ///<Broj igraca koji igraju na datoj stazi
} lane;

lane* allLanes;

void initialise();		//kreira odredjen broj staza na kojima ce se igrati
void createPlayer();   // Kreira se igrac, tj. unose se ime i broj staze sa tastature i ubacuje se u niz
player* getPlayerByNameAndId(char* playerName,int laneId);  // vraca igraca na osnovu ta dva podatka

int deletePLayer(player* p);  // uz pomoc prethodne funkcije, moze se obrisati igrac iz niza 


#endif

