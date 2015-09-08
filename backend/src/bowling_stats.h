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
#define NOT_EVALUATED 0
/**
	Bacanje nije izvrseno.
*/
#define NOT_THROWN -1

#include <stdint.h>
#include "users.h"


/**
*	@brief	Funkcija za odredjenog igraca upisuje broj srusenih cunjeva nakon bacanja i racuna ukupan rezultat.
*	@param	p		Igrac koji baca.
*	@param	x		Broj srusenih cunjeva.
*	@retval void
*/
void knockDown(player* p, uint8_t x);


#endif
