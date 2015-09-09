#ifndef USERS_H
#define USERS_H
/**
	Broj frejmova u jednoj igri.
*/
#define NUM_OF_FRAMES 10
/**
	Broj maksimalnih bacanja u jednoj igri.
*/
#define MAX_NUM_OF_THROWS (NUM_OF_FRAMES*2 + 1)
/**
	Vrijednost okvira još nije izracunata.
*/
#define NOT_EVALUATED 0

#include <stdint.h>
#include <inttypes.h>
#include "player.h"

#define MAX_NUM_OF_LANES 3
#define MAX_NUM_OF_PLAYERS 6
#define MIN_NUM_OF_LANES 1
#define MIN_NUM_OF_PLAYERS 1


/**
	@brief Strukura predstavlja apstrakciju jedne staze sa igracima koji ucestvuju u igri
*/
typedef struct Lane
{
	int8_t laneId;			///< Identifikator staze
	player* playersOnLane;  	///< Niz igraca koji igraju na datoj stazi
	int8_t numberOfPlayers;
	int8_t currentPlayer;	  	///< Broj igraca koji igraju na datoj stazi
} lane;

lane* allLanes;
int8_t numberOfLanes;

/**
 * @brief	Funkcija vrsi alokaciju memorije za staze, od korisnika se zahtjeva da unese broj staza. Mora biti pozvana prije createLane i createPlayer
 * @param	numberOfLanes	Broj staza koji treba da bude kreiran.
 * @retval 	int8_t
 */
int8_t initialise(int8_t numOfLanes);

/**
 * @brief		Funkcija vrsi unos podataka vezanih za stazu. Mora biti pozvana prije createPlayer.
 * @param laneId	Vrijednost koja ce biti jedinstvena za svaku stazu.
 * @param numberOfPlayers	Broj igraca koji ce biti na stazi.
 * @retval int8_t
 */
int8_t createLane(int8_t laneId, int8_t numberOfPlayers);

/**
 * @brief		Funkcija vrsi unos podataka vezanih za jednog igraca.
 * @param laneId	Id staze za koju se vrsi unos.
 * @param playerName	Ime igraca koji treba biti dodan.
 * @retval int8_t
 */
int8_t createPlayer(int8_t laneId, char* playerName);

  

/**
 * @brief		Funkcija vrsi brisanje igraca sa odredjene staze.
 * @param player	Pokazivac na strukturu player predstavlja igraca koji ce biti obrisan.
 * @param laneId	Id staze sa koje se brise igrac.
 * @retval int8_t 	Funkcija vraca vrijednost -1 ako igrac nije pronadjen na stazi, inace 0
 */
int8_t deletePLayer(player* p, int8_t laneId);

player* getPlayerByNameAndId(char* playerName, int8_t laneId);


#endif

