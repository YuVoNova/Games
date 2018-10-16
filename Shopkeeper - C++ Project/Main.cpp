#include "Player.h"

using namespace std;

inline void DisplayMenu();
inline void DisplayItems();

int main(int argc, char** argv)
{
	int g, select;
	bool hasQuit = false;
	
	cout << "===WELCOME TO THE SHOPKEEEPER!===\nYou able to buy and sell stuff, also craft or recycle items you wish.\nFor the right price of course!\n\n" 
	<< "Enter the gold you have in your purse: ";		cin >> g;
	
	Player player(g);
	
	while (!hasQuit)
	{
		DisplayMenu();
		cin >> select;
		
		if (select == 1)
		{
			player.DisplayPlayerInfo();
		}
		else if (select == 2)
		{
			player.DisplayShopInfo();
		}
		else if (select == 3)
		{
			DisplayItems();
			cin >> select;
			
			if (select == 1)			player.BuyItem(player.myInv.sword);
			else if (select == 2)		player.BuyItem(player.myInv.dag);
			else if (select == 3)		player.BuyItem(player.myInv.bow);
			else if (select == 4)		player.BuyItem(player.myInv.helm);
			else if (select == 5)		player.BuyItem(player.myInv.chest);
			else if (select == 6)		player.BuyItem(player.myInv.shield);
			else if (select == 7)		player.BuyItem(player.myInv.hp);
			else if (select == 8)		player.BuyItem(player.myInv.mp);
			else 						cout << endl << "Wrong selection." << endl;
		}
		else if (select == 4)
		{
			DisplayItems();
			cin >> select;
			
			if (select == 1)			player.SellItem(player.myInv.sword);
			else if (select == 2)		player.SellItem(player.myInv.dag);
			else if (select == 3)		player.SellItem(player.myInv.bow);
			else if (select == 4)		player.SellItem(player.myInv.helm);
			else if (select == 5)		player.SellItem(player.myInv.chest);
			else if (select == 6)		player.SellItem(player.myInv.shield);
			else if (select == 7)		player.SellItem(player.myInv.hp);
			else if (select == 8)		player.SellItem(player.myInv.mp);
			else 						cout << endl << "Wrong selection." << endl;
		}
		else if (select == 5)
		{
			DisplayItems();
			cin >> select;
			
			if (select == 1)			player.CraftItem(player.myInv.sword);
			else if (select == 2)		player.CraftItem(player.myInv.dag);
			else if (select == 3)		player.CraftItem(player.myInv.bow);
			else if (select == 4)		player.CraftItem(player.myInv.helm);
			else if (select == 5)		player.CraftItem(player.myInv.chest);
			else if (select == 6)		player.CraftItem(player.myInv.shield);
			else if (select == 7)		player.CraftItem(player.myInv.hp);
			else if (select == 8)		player.CraftItem(player.myInv.mp);
			else 						cout << endl << "Wrong selection." << endl;
		}
		else if (select == 6)
		{
			DisplayItems();
			cin >> select;
			
			if (select == 1)			player.RecycleItem(player.myInv.sword);
			else if (select == 2)		player.RecycleItem(player.myInv.dag);
			else if (select == 3)		player.RecycleItem(player.myInv.bow);
			else if (select == 4)		player.RecycleItem(player.myInv.helm);
			else if (select == 5)		player.RecycleItem(player.myInv.chest);
			else if (select == 6)		player.RecycleItem(player.myInv.shield);
			else if (select == 7)		player.RecycleItem(player.myInv.hp);
			else if (select == 8)		player.RecycleItem(player.myInv.mp);
			else 						cout << endl << "Wrong selection." << endl;
		}
		else if (select == 0)
		{
			hasQuit = true;
		}
		else
		{
			cout << endl << "Wrong selection, please select again." << endl;
		}
	}
	
	cout << endl << "Thanks for stopping by!";
	
	return 0;
}

inline void DisplayMenu()
{
	cout << endl << "1- Player Info\n2- Shop Info\n3- Buy Item\n4- Sell Item\n5- Craft Item\n6- Recycle Item\n0- Exit\n\nSelect: ";
}

inline void DisplayItems()
{
	cout << endl << "\nItem List:\n1- Sword\n2- Dagger\n3- Longbow\n4- Helmet\n5- Chestplate\n6- Shield\n7- Health Potion\n8- Magic Potion\nSelect: ";
}
