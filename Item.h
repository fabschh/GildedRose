//
// Created by Ralf on 06.10.2022.
//

// Probably Item should have some methods, too.
// But be aware! Did you read the requirements?
// So do not touch this!

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
using namespace std;

enum ItemType { LEGENDARY, CONJURED, MATURING, EXPIRING, NORMAL };

class Item {
public:
    string name;
    int expires_in_days;
  int worth_item;
  Item(std::string name, int sellIn, int quality) : name(name), expires_in_days(sellIn), worth_item(quality)
  {};
  ItemType typeOf() const;
};

#endif // ITEM_H
