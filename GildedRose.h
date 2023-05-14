#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class GildedRose
{
public:
    vector<Item*> &item_list;
    GildedRose(vector<Item*> &items);
    Item* createItem(string,int,int) const;
    void update_all_items();
    void update_item(Item* this_item);
    void decrement_worth_item(Item *item_pointer);
    void increment_worth_item(Item *item_pointer);
    bool is_expired(Item *item_pointer);
    void decrement_expires_in_days(Item* item_pointer);

    void update_normal_item(Item* item_pointer);
    void update_backstage_pass(Item* item_pointer);
    void adapt_worth_backstage_pass(Item* item_pointer);
    void update_aged_brie(Item* item_pointer);
    void update_sulfuras(Item* item_pointer);
    void update_conjured(Item* item_pointer);
    virtual ~GildedRose();
};

