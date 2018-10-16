#include "Materials.h"

using namespace std; 

class Item
{
	private:
		int cost;
		string baseType;
		string itemType;
		Materials madeOf;
	
	public:
		int inStock;
		int inInventory;
		
		Item(int = 0, string = " ", string = " ");
		~Item();
		Materials CalculateCraft();
		Materials CalculateRecycle();
		int SellValue()							{return (int)(cost * 70 / 100);}
		
		inline void setMadeOf(Materials m)		{madeOf = m;}
		
		inline int getCost() const				{return cost;}
		inline string getItemType() const		{return itemType;}
		inline string getBaseType() const		{return baseType;}
		inline Materials getMaterials() const	{return madeOf;}
};





class Weapon : public Item
{
	public:
		int damage;
		float range;
		
	public:
		Weapon(int = 0, string = " ", string = " ", int = 0, float = 0);
};

class Sword : public Weapon
{
	public:
		Sword();
};

class Dagger : public Weapon
{
	public:
		Dagger();
};

class Longbow : public Weapon
{
	public:
		Longbow();
};





class Armor : public Item
{
	public:
		int defense;
		float flex;
		
	public:
		Armor(int = 0, string = " ", string = " ", int = 0, float = 0);
};

class Helmet : public Armor
{
	public:
		Helmet();
};

class Chestplate : public Armor
{
	public:
		Chestplate();
};

class Shield : public Armor
{
	public:
		Shield();
};





class Potion : public Item
{
	public:
		int duration;
		
	public:
		Potion(int = 0, string = " ", string = " ", int = 0);
};

class HealthPotion : public Potion
{
	public:
		HealthPotion();
};

class MagicPotion : public Potion
{
	public:
		MagicPotion();
};
