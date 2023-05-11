#include "GildedRose.h"

GildedRose::GildedRose(vector<Item*> & items) : item_list(items)
{}

GildedRose::~GildedRose() {
  for (auto & item : item_list) {
    delete item;
  }
}

const string is_backstage_pass = "Backstage passes to a TAFKAL80ETC concert";
const string is_sulfuras = "Sulfuras, Hand of Ragnaros";

void GildedRose::decrement_worth_item(Item *item_pointer) {
    item_pointer->worth_item--;
}

void GildedRose::increment_worth_item(Item *item_pointer) {
    item_pointer->worth_item++;
}

bool GildedRose::worth_greater_0(Item *item_pointer){
    return item_pointer->worth_item > 0;
}

bool GildedRose::worth_lower_50(Item *item_pointer){
    return item_pointer->worth_item < 50;
}

bool GildedRose::is_standard_item(Item *item_pointer){
    if(item_pointer->name != "Aged Brie" && item_pointer->name != is_backstage_pass && item_pointer->name != is_sulfuras){
        return true;
    }
}

void GildedRose::update_item(int index){
    if (item_list[index]->name != "Aged Brie" && item_list[index]->name != is_backstage_pass)
    {
        if (worth_greater_0(item_list[index]))
        {
            if (item_list[index]->name != is_sulfuras)
            {
                decrement_worth_item(item_list[index]);
            }
        }
    }
    else
    {
        if (worth_lower_50(item_list[index]))
        {
            increment_worth_item(item_list[index]);

            if (item_list[index]->name == is_backstage_pass)
            {
                if (item_list[index]->expires_in_days <= 10)
                {
                    if (worth_lower_50(item_list[index]))
                    {
                        increment_worth_item(item_list[index]);;
                    }
                }

                if (item_list[index]->expires_in_days <= 5)
                {
                    if (worth_lower_50(item_list[index]))
                    {
                        increment_worth_item(item_list[index]);;
                    }
                }
            }
        }
    }

    if (item_list[index]->name != is_sulfuras)
    {
        item_list[index]->expires_in_days = item_list[index]->expires_in_days - 1;
    }

    if (item_list[index]->expires_in_days < 0)
    {
        if (item_list[index]->name != "Aged Brie")
        {
            if (item_list[index]->name != is_backstage_pass)
            {
                if (worth_greater_0(item_list[index]))
                {
                    if (item_list[index]->name != is_sulfuras)
                    {
                        decrement_worth_item(item_list[index]);
                    }
                }
            }
            else
            {
                item_list[index]->worth_item = item_list[index]->worth_item - item_list[index]->worth_item;
            }
        }
        else
        {
            if (worth_lower_50(item_list[index]))
            {
                increment_worth_item(item_list[index]);;
            }
        }
    }
}

void GildedRose::update_all_items()
{
    for (int i = 0; i < item_list.size(); i++)
    {
        update_item(i);
    }
}

Item* GildedRose::createItem(string name, int expires_in_days, int quality) const {
  return new Item(name, expires_in_days, quality);
}
