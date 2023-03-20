#pragma once
#include "Attributes.h"
#include "Selectors.h"

class Sekcja {
	Sekcja* next;
	Sekcja* prior;
	Selectors  selectors;
	Attributes attributes;
};