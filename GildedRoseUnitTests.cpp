#include <gtest/gtest.h>

#include "GildedRose.h"
#include "Item.h"

#define TEST_CONJURED_ITEMS

TEST(GildedRoseTest, Day01) {
  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("+5 Dexterity Vest", 10, 20));
  items.push_back(G.createItem("Aged Brie", 2, 0));
  items.push_back(G.createItem("Elixir of the Mongoose", 5, 7));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", 0, 80));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", -1, 80));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 15, 20));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 10, 49));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 5, 49));

    G.update_all_items();
  EXPECT_EQ("+5 Dexterity Vest", G.item_list[0]->name);
  EXPECT_EQ(9, G.item_list[0]->expires_in_days);
  EXPECT_EQ(19, G.item_list[0]->worth_item);

  EXPECT_EQ("Aged Brie", G.item_list[1]->name);
  EXPECT_EQ(1, G.item_list[1]->expires_in_days);
  EXPECT_EQ(1, G.item_list[1]->worth_item);

  EXPECT_EQ("Elixir of the Mongoose", G.item_list[2]->name);
  EXPECT_EQ(4, G.item_list[2]->expires_in_days);
  EXPECT_EQ(6, G.item_list[2]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[3]->name);
  EXPECT_EQ(0, G.item_list[3]->expires_in_days);
  EXPECT_EQ(80, G.item_list[3]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[4]->name);
  EXPECT_EQ(-1, G.item_list[4]->expires_in_days);
  EXPECT_EQ(80, G.item_list[4]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[5]->name);
  EXPECT_EQ(14, G.item_list[5]->expires_in_days);
  EXPECT_EQ(21, G.item_list[5]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[6]->name);
  EXPECT_EQ(9, G.item_list[6]->expires_in_days);
  EXPECT_EQ(50, G.item_list[6]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[7]->name);
  EXPECT_EQ(4, G.item_list[7]->expires_in_days);
  EXPECT_EQ(50, G.item_list[7]->worth_item);
}

TEST(GildedRoseTest, Day02) {
  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("+5 Dexterity Vest", 10, 20));
  items.push_back(G.createItem("Aged Brie", 2, 0));
  items.push_back(G.createItem("Elixir of the Mongoose", 5, 7));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", 0, 80));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", -1, 80));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 15, 20));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 10, 49));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 5, 49));

    G.update_all_items();
    G.update_all_items();

  EXPECT_EQ("+5 Dexterity Vest", G.item_list[0]->name);
  EXPECT_EQ(8, G.item_list[0]->expires_in_days);
  EXPECT_EQ(18, G.item_list[0]->worth_item);

  EXPECT_EQ("Aged Brie", G.item_list[1]->name);
  EXPECT_EQ(0, G.item_list[1]->expires_in_days);
  EXPECT_EQ(2, G.item_list[1]->worth_item);

  EXPECT_EQ("Elixir of the Mongoose", G.item_list[2]->name);
  EXPECT_EQ(3, G.item_list[2]->expires_in_days);
  EXPECT_EQ(5, G.item_list[2]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[3]->name);
  EXPECT_EQ(0, G.item_list[3]->expires_in_days);
  EXPECT_EQ(80, G.item_list[3]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[4]->name);
  EXPECT_EQ(-1, G.item_list[4]->expires_in_days);
  EXPECT_EQ(80, G.item_list[4]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[5]->name);
  EXPECT_EQ(13, G.item_list[5]->expires_in_days);
  EXPECT_EQ(22, G.item_list[5]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[6]->name);
  EXPECT_EQ(8, G.item_list[6]->expires_in_days);
  EXPECT_EQ(50, G.item_list[6]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[7]->name);
  EXPECT_EQ(3, G.item_list[7]->expires_in_days);
  EXPECT_EQ(50, G.item_list[7]->worth_item);
}

TEST(GildedRoseTest, Day05) {
  const int NO_OF_DAYS =5;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("+5 Dexterity Vest", 10, 20));
  items.push_back(G.createItem("Aged Brie", 2, 0));
  items.push_back(G.createItem("Elixir of the Mongoose", 5, 7));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", 0, 80));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", -1, 80));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 15, 20));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 10, 49));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 5, 49));

  for (int i=1; i<=NO_OF_DAYS;i++) {
      G.update_all_items();
  }

  EXPECT_EQ("+5 Dexterity Vest", G.item_list[0]->name);
  EXPECT_EQ(5, G.item_list[0]->expires_in_days);
  EXPECT_EQ(15, G.item_list[0]->worth_item);

  EXPECT_EQ("Aged Brie", G.item_list[1]->name);
  EXPECT_EQ(-3, G.item_list[1]->expires_in_days);
  EXPECT_EQ(8, G.item_list[1]->worth_item);

  EXPECT_EQ("Elixir of the Mongoose", G.item_list[2]->name);
  EXPECT_EQ(0, G.item_list[2]->expires_in_days);
  EXPECT_EQ(2, G.item_list[2]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[3]->name);
  EXPECT_EQ(0, G.item_list[3]->expires_in_days);
  EXPECT_EQ(80, G.item_list[3]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[4]->name);
  EXPECT_EQ(-1, G.item_list[4]->expires_in_days);
  EXPECT_EQ(80, G.item_list[4]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[5]->name);
  EXPECT_EQ(10, G.item_list[5]->expires_in_days);
  EXPECT_EQ(25, G.item_list[5]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[6]->name);
  EXPECT_EQ(5, G.item_list[6]->expires_in_days);
  EXPECT_EQ(50, G.item_list[6]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[7]->name);
  EXPECT_EQ(0, G.item_list[7]->expires_in_days);
  EXPECT_EQ(50, G.item_list[7]->worth_item);
}

TEST(GildedRoseTest, Day20) {
  const int NO_OF_DAYS =20;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("+5 Dexterity Vest", 10, 20));
  items.push_back(G.createItem("Aged Brie", 2, 0));
  items.push_back(G.createItem("Elixir of the Mongoose", 5, 7));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", 0, 80));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", -1, 80));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 15, 20));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 10, 49));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 5, 49));

  for (int i=1; i<=NO_OF_DAYS;i++) {
      G.update_all_items();
  }

  EXPECT_EQ("+5 Dexterity Vest", G.item_list[0]->name);
  EXPECT_EQ(-10, G.item_list[0]->expires_in_days);
  EXPECT_EQ(0, G.item_list[0]->worth_item);

  EXPECT_EQ("Aged Brie", G.item_list[1]->name);
  EXPECT_EQ(-18, G.item_list[1]->expires_in_days);
  EXPECT_EQ(38, G.item_list[1]->worth_item);

  EXPECT_EQ("Elixir of the Mongoose", G.item_list[2]->name);
  EXPECT_EQ(-15, G.item_list[2]->expires_in_days);
  EXPECT_EQ(0, G.item_list[2]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[3]->name);
  EXPECT_EQ(0, G.item_list[3]->expires_in_days);
  EXPECT_EQ(80, G.item_list[3]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[4]->name);
  EXPECT_EQ(-1, G.item_list[4]->expires_in_days);
  EXPECT_EQ(80, G.item_list[4]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[5]->name);
  EXPECT_EQ(-5, G.item_list[5]->expires_in_days);
  EXPECT_EQ(0, G.item_list[5]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[6]->name);
  EXPECT_EQ(-10, G.item_list[6]->expires_in_days);
  EXPECT_EQ(0, G.item_list[6]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[7]->name);
  EXPECT_EQ(-15, G.item_list[7]->expires_in_days);
  EXPECT_EQ(0, G.item_list[7]->worth_item);
}

TEST(GildedRoseTest, Day30) {
  const int NO_OF_DAYS =30;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("+5 Dexterity Vest", 10, 20));
  items.push_back(G.createItem("Aged Brie", 2, 0));
  items.push_back(G.createItem("Elixir of the Mongoose", 5, 7));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", 0, 80));
  items.push_back(G.createItem("Sulfuras, Hand of Ragnaros", -1, 80));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 15, 20));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 10, 49));
  items.push_back(G.createItem("Backstage passes to a TAFKAL80ETC concert", 5, 49));

  for (int i=1; i<=NO_OF_DAYS;i++) {
      G.update_all_items();
  }

  EXPECT_EQ("+5 Dexterity Vest", G.item_list[0]->name);
  EXPECT_EQ(-20, G.item_list[0]->expires_in_days);
  EXPECT_EQ(0, G.item_list[0]->worth_item);

  EXPECT_EQ("Aged Brie", G.item_list[1]->name);
  EXPECT_EQ(-28, G.item_list[1]->expires_in_days);
  EXPECT_EQ(50, G.item_list[1]->worth_item);

  EXPECT_EQ("Elixir of the Mongoose", G.item_list[2]->name);
  EXPECT_EQ(-25, G.item_list[2]->expires_in_days);
  EXPECT_EQ(0, G.item_list[2]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[3]->name);
  EXPECT_EQ(0, G.item_list[3]->expires_in_days);
  EXPECT_EQ(80, G.item_list[3]->worth_item);

  EXPECT_EQ("Sulfuras, Hand of Ragnaros", G.item_list[4]->name);
  EXPECT_EQ(-1, G.item_list[4]->expires_in_days);
  EXPECT_EQ(80, G.item_list[4]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[5]->name);
  EXPECT_EQ(-15, G.item_list[5]->expires_in_days);
  EXPECT_EQ(0, G.item_list[5]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[6]->name);
  EXPECT_EQ(-20, G.item_list[6]->expires_in_days);
  EXPECT_EQ(0, G.item_list[6]->worth_item);

  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", G.item_list[7]->name);
  EXPECT_EQ(-25, G.item_list[7]->expires_in_days);
  EXPECT_EQ(0, G.item_list[7]->worth_item);
}

#ifdef TEST_CONJURED_ITEMS

TEST(NewConjuredItemsTest, Day01) {
  const int NO_OF_DAYS = 1;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("Conjured Mana Cake", 3, 6));

  for (int i = 1; i <= NO_OF_DAYS; i++) {
      G.update_all_items();
  }
  cout << "\"Conjured\" item_list degrade in Quality twice as fast as normal item_list";

  EXPECT_EQ("Conjured Mana Cake", G.item_list[0]->name);
  EXPECT_EQ(4, G.item_list[0]->worth_item);
}

TEST(NewConjuredItemsTest, Day02) {
  const int NO_OF_DAYS = 2;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("Conjured Mana Cake", 3, 6));

  for (int i = 1; i <= NO_OF_DAYS; i++) {
      G.update_all_items();
  }

  EXPECT_EQ("Conjured Mana Cake", G.item_list[0]->name);
  EXPECT_EQ(2, G.item_list[0]->worth_item);
}

TEST(NewConjuredItemsTest, Day05) {
  const int NO_OF_DAYS = 5;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("Conjured Mana Cake", 3, 6));

  for (int i = 1; i <= NO_OF_DAYS; i++) {
      G.update_all_items();
  }

  EXPECT_EQ("Conjured Mana Cake", G.item_list[0]->name);
  EXPECT_EQ(0, G.item_list[0]->worth_item);
}

TEST(NewConjuredItemsTest, Day20) {
  const int NO_OF_DAYS = 20;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("Conjured Mana Cake", 3, 6));

  for (int i = 1; i <= NO_OF_DAYS; i++) {
      G.update_all_items();
  }

  EXPECT_EQ("Conjured Mana Cake", G.item_list[0]->name);
  EXPECT_EQ(0, G.item_list[0]->worth_item);
}

TEST(NewConjuredItemsTest, Day30) {
  const int NO_OF_DAYS = 30;

  vector<Item*> items;
  GildedRose G(items);

  items.push_back(G.createItem("Conjured Mana Cake", 3, 6));

  for (int i = 1; i <= NO_OF_DAYS; i++) {
      G.update_all_items();
  }

  EXPECT_EQ("Conjured Mana Cake", G.item_list[0]->name);
  EXPECT_EQ(0, G.item_list[0]->worth_item);
}
#endif
