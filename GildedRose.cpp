#include "GildedRose.h"

#define LIMIT_INCREASE_WORTH_DOUBLE 10
#define LIMIT_INCREASE_WORTH_TRIPLE 5
#define MAX_WORTH 50
#define MIN_WORTH 0
#define MIN_DAYS 0

GildedRose::GildedRose(vector<Item*> &items) : item_list(items) {

}

GildedRose::~GildedRose() {
    for (auto &item: item_list) {
        delete item;
    }
}

const ItemType is_backstage_pass = EXPIRING;
const ItemType is_sulfuras = LEGENDARY;
const ItemType is_aged_brie = MATURING;
const ItemType is_normal = NORMAL;

void GildedRose::decrement_worth_item(Item *item_pointer) {
    if(item_pointer->worth_item > MIN_WORTH){
        item_pointer->worth_item--;
    }
}

void GildedRose::increment_worth_item(Item *item_pointer) {
    if(item_pointer->worth_item < MAX_WORTH){
        item_pointer->worth_item++;
    }
}

bool GildedRose::is_expired(Item *item_pointer) {
    if (item_pointer->expires_in_days < MIN_DAYS) {
        return true;
    }
    else {
        return false;
    }
}

void GildedRose::decrement_expires_in_days(Item *item_pointer) {
    item_pointer->expires_in_days--;
}

void GildedRose::adapt_worth_backstage_pass(Item* item_pointer){
    increment_worth_item(item_pointer);

    if (item_pointer->expires_in_days <= LIMIT_INCREASE_WORTH_DOUBLE) {
                increment_worth_item(item_pointer);
    }

    if (item_pointer->expires_in_days <= LIMIT_INCREASE_WORTH_TRIPLE) {
                increment_worth_item(item_pointer);
    }
}

void GildedRose::update_normal_item(Item* item_pointer){
    decrement_worth_item(item_pointer);

    decrement_expires_in_days(item_pointer);

    if(is_expired(item_pointer)){
        decrement_worth_item(item_pointer);
    }
}

void GildedRose::update_backstage_pass(Item* item_pointer){
    adapt_worth_backstage_pass(item_pointer);
    decrement_expires_in_days(item_pointer);

    if(is_expired(item_pointer)){
        item_pointer->worth_item = MIN_WORTH;
    }
}

void GildedRose::update_aged_brie(Item* item_pointer){
    increment_worth_item(item_pointer);

    decrement_expires_in_days(item_pointer);
    if(is_expired(item_pointer)){
        increment_worth_item(item_pointer);
    }
}

void GildedRose::update_sulfuras(Item* item_pointer){

}

void GildedRose::update_conjured(Item* item_pointer){
    decrement_worth_item(item_pointer);

    decrement_expires_in_days(item_pointer);

    if(is_expired(item_pointer)){
        decrement_worth_item(item_pointer);
    }
    /*decrement_worth_item(item_pointer);    10/10 passed
    decrement_worth_item(item_pointer);

     decrement_expires_in_days(item_pointer);

    if(is_expired(item_pointer)){
        decrement_worth_item(item_pointer);
    }*/
}

void GildedRose::update_item(Item *this_item) {
    if(this_item->typeOf() == is_normal){
        update_normal_item(this_item);
    }
    if(this_item->typeOf() == is_backstage_pass){
        update_backstage_pass(this_item);
    }
    if(this_item->typeOf() == is_aged_brie){
        update_aged_brie(this_item);
    }
    if(this_item->typeOf() == is_sulfuras){
        update_sulfuras(this_item);
    }
    if(this_item->typeOf() == CONJURED){
        update_conjured(this_item);
    }
}

void GildedRose::update_all_items() {
    for (Item *this_item : item_list) {
        update_item(this_item);
    }
}

Item *GildedRose::createItem(string name, int expires_in_days, int quality) const {
    return new Item(name, expires_in_days, quality);
}
