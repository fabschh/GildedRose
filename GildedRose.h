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
    void update_item(int index);
    void decrement_worth_item(Item *item_pointer);
    void increment_worth_item(Item *item_pointer);
    bool worth_greater_0(Item *item_pointer);
    bool worth_lower_50(Item *item_pointer);
    bool is_standard_item(Item *item_pointer);
    virtual ~GildedRose();
};

