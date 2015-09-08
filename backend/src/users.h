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
} player;

/**
	@brief Strukura predstavlja apstrakciju jedne staze sa igracima koji ucestvuju u igri
*/
typedef struct Lane
{
	int8_t laneId;			///< Identifikator staze
	player* playersOnLane;  	///< Niz igraca koji igraju na datoj stazi
	int8_t numberOfPlayers;	  	///< Broj igraca koji igraju na datoj stazi
} lane;

lane* allLanes;
int8_t numberOfLanes;

/**
 * @brief	Funkcija vrsi alokaciju memorije za staze, od korisnika se zahtjeva da unese broj staza.
 * @retval 	void
 */
void initialise();

/**
 * @brief		Funkcija vrsi unos podataka vezanih za stazu.
 * @param laneId	Vrijednost koja ce biti jedinstvena za svaku stazu
 * @retval void
 */
void createLane(int8_t laneId);

/**
 * @brief		Funkcija vrsi unos podataka vezanih za jednog igraca.
 * @param laneId	Id staze za koju se vrsi unos.
 * @param position	Pozicija u nizu igraca na koju se vrsi unos
 * @retval void
 */
void createPlayer(int8_t laneId, int8_t position);


player* getPlayerByNameAndId(char* playerName,int8_t laneId);  


int8_t deletePLayer(player* p);  


#endif

