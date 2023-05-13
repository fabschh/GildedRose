#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class GildedRose
{
public:
    vector<Item*> & item_list;
    GildedRose(vector<Item*> & items);
    Item* createItem(string,int,int) const;
    void update_all_items();
    void update_item(Item* this_item);
    void decrement_worth_item(Item *item_pointer);
    void increment_worth_item(Item *item_pointer);
    bool worth_higher_min(Item *item_pointer);
    bool worth_lower_max(Item *item_pointer);
    bool is_worthy_sulfuras(Item *item_pointer);
    bool is_expired(Item *item_pointer);
    void decrement_expires_in_days(Item* item_pointer);
    void handle_expired_item(Item* item_pointer);
    virtual ~GildedRose();
};

