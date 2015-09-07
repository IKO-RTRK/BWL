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

/**
 * @brief	Funkcija vrsi alokaciju memorije za staze, od korisnika se zahtjeva da unese broj staza.
 * @retval void
 */
void initialise();

/**
 * @brief	Funkcija vrsi unos podataka vezanih za stazu.
 * @param laneId	Vrijednost koja ce biti jedinstvena za svaku stazu
 * @retval void
 */
void createLane(int8_t laneId);

/**
 * @brief	Funkcija vrsi unos podataka vezanih za jednog igraca.
 * @param laneId	Id staze za koju se vrsi unos.
 * @retval void
 */
void createPlayer(int8_t laneId);
player* getPlayerByNameAndId(char* playerName,int laneId);  // vraca igraca na osnovu ta dva podatka

/**
 * @brief	Funkcija provjerava da li je broj traka koji unese korisnik validan(maksimano 3 trake).
 * @param numberOfLanes	Broj staza.
 * @retval int	Ako je broj staza validan funkcija vraca 0, inace 1.
 */
int numberOfLanesValidation(int numberOfLanes);

/**
 * @brief Funkcija provjerava da li je broj igraca na traci valida(maksimalno 6 igraca).
 * @param numberOfPlayers Broj igraca.
 * @retval int Ako je broj igraca validan funkcija vraca 0, inace 1.
 */ 
int numberOfPlayersValidation(int numberOfPlayers);
int deletePLayer(player* p);  // uz pomoc prethodne funkcije, moze se obrisati igrac iz niza 


#endif

