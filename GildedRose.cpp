#include "GildedRose.h"

#define LIMIT_INCREASE_WORTH_DOUBLE 10
#define LIMIT_INCREASE_WORTH_TRIPLE 5
#define SET_WORTH_ZERO 0

GildedRose::GildedRose(vector<Item *> &items) : item_list(items) {}

GildedRose::~GildedRose() {
    for (auto &item: item_list) {
        delete item;
    }
}

const ItemType is_backstage_pass = EXPIRING;
const ItemType is_sulfuras = LEGENDARY;
const ItemType is_aged_brie = MATURING;

void GildedRose::decrement_worth_item(Item *item_pointer) {
    item_pointer->worth_item--;
}

void GildedRose::increment_worth_item(Item *item_pointer) {
    item_pointer->worth_item++;
}

bool GildedRose::worth_higher_min(Item *item_pointer) {
    return item_pointer->worth_item > 0;
}

bool GildedRose::worth_lower_max(Item *item_pointer) {
    return item_pointer->worth_item < 50;
}

bool GildedRose::is_worthy_sulfuras(Item *item_pointer) {
    if (worth_higher_min(item_pointer) && item_pointer->typeOf() != is_sulfuras) {
        return true;
    } else {
        return false;
    }
}

bool GildedRose::is_expired(Item *item_pointer){
    if(item_pointer->expires_in_days < 0){
        return true;
    }
    else{
        return false;
    }
}

void GildedRose::decrement_expires_in_days(Item* item_pointer){
    item_pointer->expires_in_days--;
}

void GildedRose::handle_expired_item(Item* item_pointer){

        if (item_pointer->typeOf() != is_aged_brie) {
            if (item_pointer->typeOf() != is_backstage_pass) {
                if (is_worthy_sulfuras(item_pointer)) {
                    decrement_worth_item(item_pointer);
                }
            }
            else{
                item_pointer->worth_item = SET_WORTH_ZERO;
            }
        }
        else if (worth_lower_max(item_pointer)){
            increment_worth_item(item_pointer);
        }
}

void GildedRose::update_item(Item* this_item) {
    if (this_item->typeOf() != is_aged_brie && this_item->typeOf() != is_backstage_pass) {
        if (worth_higher_min(this_item) && this_item->typeOf() != is_sulfuras) {
            decrement_worth_item(this_item);
        }
    }
    else if (worth_lower_max(this_item)){
            increment_worth_item(this_item);

            if (this_item->typeOf() == is_backstage_pass && worth_lower_max(this_item)) {
                if (this_item->expires_in_days <= LIMIT_INCREASE_WORTH_DOUBLE) {
                    increment_worth_item(this_item);
                }

                if (this_item->expires_in_days <= LIMIT_INCREASE_WORTH_TRIPLE){
                    increment_worth_item(this_item);
                }
            }
    }

    if (this_item->typeOf() != is_sulfuras) {
        decrement_expires_in_days(this_item);
    }

    if(is_expired(this_item)){
            handle_expired_item(this_item);
    }
}

void GildedRose::update_all_items() {
    for (Item* this_item : item_list) {
        update_item(this_item);
    }
}

Item *GildedRose::createItem(string name, int expires_in_days, int quality) const {
    return new Item(name, expires_in_days, quality);
}
