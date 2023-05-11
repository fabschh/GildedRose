//
// Created by Ralf on 06.10.2022.
//

// I think Items could have a inheritance hierarchy.
// But I did not have the time to do it!

#ifndef GILDEDROSE_ITEMTYPES_H
#define GILDEDROSE_ITEMTYPES_H

#include <string>
#include <vector>
using namespace std;

#include "Item.h"

/* We should use inheritance but the goblin will not let me do it! 
// Do not delete this code. You will need it!
class LegendaryItem : public Item {
public:
  LegendaryItem(string name, int expires_in_days, int worth_item) : Item(name, expires_in_days, worth_item){};
};

class ConjuredItem : public Item {
public:
  ConjuredItem(string name, int expires_in_days, int worth_item) : Item(name, expires_in_days, worth_item){};
};

class MaturingItem : public Item {
public:
  MaturingItem(string name, int expires_in_days, int worth_item) : Item(name, expires_in_days, worth_item){};
};

class ExpiringItem : public Item {
public:
  ExpiringItem(string name, int expires_in_days, int worth_item) : Item(name, expires_in_days, worth_item){};
};
*/

#endif // GILDEDROSE_ITEMTYPES_H
