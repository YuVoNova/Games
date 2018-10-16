#include "Item.h"

using namespace std;

class Inventory
{
	public:
		const int capacity = 10;
		
		Sword sword;
		Dagger dag;
		Longbow bow;
		
		Helmet helm;
		Chestplate chest;
		Shield shield;
		
		HealthPotion hp;
		MagicPotion mp;
		
		Inventory();
		int SumItems();
};

class Player
{
	public:
		Materials myMat;
		Inventory myInv;
		int myGold;
		
		Player(int);
		void RecycleItem(Item&);
		void CraftItem(Item&);
		void SellItem(Item&);
		void BuyItem(Item&);
		void DisplayPlayerInfo();
		void DisplayShopInfo();
};
