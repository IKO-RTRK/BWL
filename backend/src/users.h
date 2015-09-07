#ifndef USERS_H
#define USERS_H

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

extern player** allPlayers;   // Niz svih igraca koji trenutno igraju

void createPlayer();   // Kreira se igrac, tj. unose se ime i broj staze sa tastature i ubacuje se u niz

player* getPlayerByNameAndId(char* playerName,int laneId);  // vraca igraca na osnovu ta dva podatka

int deletePLayer(player* p);  // uz pomoc prethodne funkcije, moze se obrisati igrac iz niza 


#endif

