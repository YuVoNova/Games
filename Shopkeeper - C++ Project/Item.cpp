#include "Item.h"

using namespace std;

Materials def;

Item::Item(int c, string bt, string it)
{
	cost = c;
	baseType = bt;
	itemType = it;
	madeOf = def;
	inStock = 5;
	inInventory = 0;
}

Item::~Item()
{
	
}

Materials Item::CalculateCraft()
{
	Materials m;
	
	m.metal = madeOf.metal * 130 / 100;
	m.glass = madeOf.glass * 130 / 100;
	m.wood = madeOf.wood * 130 / 100;
	m.organic = madeOf.organic * 130 / 100;
	
	return m;
}

Materials Item::CalculateRecycle()
{
	Materials m;
	
	m.metal = madeOf.metal * 70 / 100;
	m.glass = madeOf.glass * 70 / 100;
	m.wood = madeOf.wood * 70 / 100;
	m.organic = madeOf.organic * 70 / 100;
	
	return m;
}





Weapon::Weapon(int c, string bt, string it, int d, float r) : Item(c, bt, it)
{
	damage = d;
	range = r;
}

Sword::Sword() : Weapon(175, "Weapon", "Sword", 15, 25)
{
	Materials m;
	
	m.glass = 2.75f;
	m.metal = 35.45f;
	m.wood = 7.2f;
	m.organic = 0;
	
	setMadeOf(m);
}
Dagger::Dagger() : Weapon(45, "Weapon", "Dagger", 4, 12.5f)
{
	Materials m;
	
	m.glass = 0.75f;
	m.metal = 18;
	m.wood = 3.75f;
	m.organic = 0.5f;
	
	setMadeOf(m);
}
Longbow::Longbow() : Weapon(225, "Weapon", "Longbow", 12, 250)
{
	Materials m;
	
	m.glass = 0;
	m.metal = 0.35f;
	m.wood = 22.5f;
	m.organic = 3.55f;
	
	setMadeOf(m);
}





Armor::Armor(int c, string bt, string it, int d, float f) : Item(c, bt, it)
{
	defense = d;
	flex = f;
}

Helmet::Helmet() : Armor(350, "Armor", "Helmet", 3, 1.75f)
{
	Materials m;
	
	m.glass = 3.55f;
	m.metal = 35;
	m.wood = 0;
	m.organic = 0;
	
	setMadeOf(m);
}
Chestplate::Chestplate() : Armor(500, "Armor", "Chestplate", 6, 5)
{
	Materials m;
	
	m.glass = 7.5f;
	m.metal = 85.25f;
	m.wood = 0.25f;
	m.organic = 2.5f;
	
	setMadeOf(m);
}
Shield::Shield() : Armor(265, "Armor", "Shield", 4, 3.25f)
{
	Materials m;
	
	m.glass = 0;
	m.metal = 15;
	m.wood = 35.25f;
	m.organic = 0.25f;
	
	setMadeOf(m);
}





Potion::Potion(int c, string bt, string it, int d) : Item(c, bt, it)
{
	duration = d;
}

HealthPotion::HealthPotion() : Potion(15, "Potion", "Health Potion", 60)
{
	Materials m;
	
	m.glass = 7.55f;
	m.metal = 0;
	m.wood = 0.05f;
	m.organic = 13.5f;
	
	setMadeOf(m);
}
MagicPotion::MagicPotion() : Potion(15, "Potion", "Magic Potion", 120)
{
	Materials m;
	
	m.glass = 7.55f;
	m.metal = 0;
	m.wood = 0.05f;
	m.organic = 21;
	
	setMadeOf(m);
}
