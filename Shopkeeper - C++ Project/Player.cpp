#include "Player.h"

using namespace std;

Inventory::Inventory()
{
	
}

Player::Player(int g)
{
	myMat.glass = 50;
	myMat.wood = 50;
	myMat.organic = 50;
	myMat.metal = 50;
	
	myGold = g;
}

int Inventory::SumItems()
{
	int sum = 0;
	
	sum += sword.inInventory;
	sum += dag.inInventory;
	sum += bow.inInventory;
	sum += helm.inInventory;
	sum += chest.inInventory;
	sum += shield.inInventory;
	sum += hp.inInventory;
	sum += mp.inInventory;
	
	return sum;
}

void Player::RecycleItem(Item &item)
{
	if (item.inInventory > 0)
	{
		Materials m;
		
		m = item.CalculateRecycle();
		
		myMat.wood += m.wood;
		myMat.glass += m.glass;
		myMat.organic += m.organic;
		myMat.metal += m.metal;
		
		item.inInventory -= 1;
		
		cout << endl << "Item successfully recycled.\n-Gained Materials-\nGlass: " << m.glass << "\nMetal: "
		<< m.metal << "\nOrganic: " << m.organic << "\nWood: " << m.wood << endl;
	}
	else
	{
		cout << endl << "You do not own any of this item." << endl;
	}
}

void Player::CraftItem(Item &item)
{
	if (myInv.SumItems() < myInv.capacity)
	{
		Materials m;
		
		m = item.CalculateCraft();
		
		if (myMat.wood < m.wood || myMat.glass < m.glass || myMat.organic < m.organic || myMat.metal < m.metal)
		{
			cout << endl << "Insufficient materials." << endl;
		}
		else
		{
			myMat.wood -= m.wood;
			myMat.glass -= m.glass;
			myMat.organic -= m.organic;
			myMat.metal -= m.metal;
			
			item.inInventory += 1;
			
			cout << endl << "Item " << item.getItemType() << " successfully crafted." << endl;
		}
	}
	else
	{
		cout << endl << "Your inventory is at full capacity." << endl;
	}
}

void Player::SellItem(Item &item)
{
	if (item.inInventory > 0)
	{
		myGold += item.SellValue();
		item.inInventory -= 1;
		item.inStock += 1;
		
		cout << endl << "Item " << item.getItemType() << " successfully bought." << endl;
	}
	else
	{
		cout << endl << "You do not own any of this item." << endl;
	}
}

void Player::BuyItem(Item &item)
{
	if (item.inStock > 0)
	{
		if (myGold > item.getCost())
		{
			if (myInv.SumItems() < myInv.capacity)
			{
				myGold -= item.getCost();
				item.inInventory += 1;
				item.inStock -= 1;
				
				cout << endl << "Item " << item.getItemType() << " successfully bought." << endl;
			}
			else
			{
				cout << endl << "Your inventory is at full capacity." << endl;
			}
		}
		else
		{
			cout << endl << "Insufficient gold." << endl;
		}
	}
	else
	{
		cout << endl << "Item out of stock." << endl;
	}
}

void Player::DisplayPlayerInfo()
{
	cout << endl << "-Player Info-\n\nInventory Items (" << myInv.SumItems() << "/" << myInv.capacity << "):\n";
	
	if (myInv.sword.inInventory > 0)
	{
		cout << myInv.sword.inInventory << " " << myInv.sword.getItemType() << endl;
	}
	if (myInv.dag.inInventory > 0)
	{
		cout << myInv.dag.inInventory << " " << myInv.dag.getItemType() << endl;
	}
	if (myInv.bow.inInventory > 0)
	{
		cout << myInv.bow.inInventory << " " << myInv.bow.getItemType() << endl;
	}
	if (myInv.helm.inInventory > 0)
	{
		cout << myInv.helm.inInventory << " " << myInv.helm.getItemType() << endl;
	}
	if (myInv.chest.inInventory > 0)
	{
		cout << myInv.chest.inInventory << " " << myInv.chest.getItemType() << endl;
	}
	if (myInv.shield.inInventory > 0)
	{
		cout << myInv.shield.inInventory << " " << myInv.shield.getItemType() << endl;
	}
	if (myInv.hp.inInventory > 0)
	{
		cout << myInv.hp.inInventory << " " << myInv.hp.getItemType() << endl;
	}
	if (myInv.mp.inInventory > 0)
	{
		cout << myInv.mp.inInventory << " " << myInv.mp.getItemType() << endl;
	}
	
	cout << "\nMaterials\nGlass: " << myMat.glass << "\nMetal: " << myMat.metal << "\nOrganic: " << myMat.organic << "\nWood: " << myMat.wood << endl;
	cout << "\nPurse: " << myGold << "Gold\n";
}

void Player::DisplayShopInfo()
{
	Materials m;
	
	cout << endl << "-Shop Info-\n\n";;
	
	m = myInv.sword.getMaterials();
	cout << myInv.sword.getItemType() << "\nItem Type: " << myInv.sword.getBaseType() << "  Damage: " << myInv.sword.damage << "  Range: " 
	<< myInv.sword.range << "  In Stock: " << myInv.sword.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.sword.getCost() << "\n\n";
	
	m = myInv.dag.getMaterials();
	cout << myInv.dag.getItemType() << "\nItem Type: " << myInv.dag.getBaseType() << "  Damage: " << myInv.dag.damage << "  Range: " 
	<< myInv.dag.range << "  In Stock: " << myInv.dag.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.dag.getCost() << "\n\n";
	
	m = myInv.bow.getMaterials();
	cout << myInv.bow.getItemType() << "\nItem Type: " << myInv.bow.getBaseType() << "  Damage: " << myInv.bow.damage << "  Range: " 
	<< myInv.bow.range << "  In Stock: " << myInv.bow.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.bow.getCost() << "\n\n";
	
	m = myInv.helm.getMaterials();
	cout << myInv.helm.getItemType() << "\nItem Type: " << myInv.helm.getBaseType() << "  Defense: " << myInv.helm.defense << "  Flexibility: " 
	<< myInv.helm.flex << "  In Stock: " << myInv.helm.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.helm.getCost() << "\n\n";
	
	m = myInv.chest.getMaterials();
	cout << myInv.chest.getItemType() << "\nItem Type: " << myInv.chest.getBaseType() << "  Defense: " << myInv.chest.defense << "  Flexibility: " 
	<< myInv.chest.flex << "  In Stock: " << myInv.chest.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.chest.getCost() << "\n\n";
	
	m = myInv.shield.getMaterials();
	cout << myInv.shield.getItemType() << "\nItem Type: " << myInv.shield.getBaseType() << "  Defense: " << myInv.shield.defense << "  Flexibility: " 
	<< myInv.shield.flex << "  In Stock: " << myInv.shield.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.shield.getCost() << "\n\n";
	
	m = myInv.hp.getMaterials();
	cout << myInv.hp.getItemType() << "\nItem Type: " << myInv.hp.getBaseType() << "  Duration: " << myInv.hp.duration << 
	"  In Stock: " << myInv.hp.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.hp.getCost() << "\n\n";
	
	m = myInv.mp.getMaterials();
	cout << myInv.mp.getItemType() << "\nItem Type: " << myInv.mp.getBaseType() << "  Duration: " << myInv.mp.duration << 
	"  In Stock: " << myInv.mp.inStock << "\nMade Of ->  Glass: " << m.glass << "  Metal: " << m.metal << "  Organic: " 
	<< m.organic << "  Wood: " << m.wood << "\nCost: " << myInv.mp.getCost() << "\n\n";
}
