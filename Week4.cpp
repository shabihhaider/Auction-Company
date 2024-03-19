#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MIN_ITEMS = 10;

class Auction 
{
public:
    vector<int> itemNo;
    vector<string> description;
    vector<float> reservePrice;
    vector<int> numBids;
    vector<float> highestBid;
    vector<int> buyerNumbers;
    
    int totalItems;
    float totalAuctionFee;
    Auction() : itemNo(), description(), reservePrice(), numBids(), highestBid(), buyerNumbers(), totalItems(0), totalAuctionFee(0.0f) {
	numBids.resize(totalItems, 0);
	}
    
    void task1() 
	{
        cout << " | Enter following details:\n";
        cout << " | How many Items? ";
        cin >> totalItems;

        while (totalItems < MIN_ITEMS) 
		{
            cout << " | Items should be at least 10.\n";
            cin >> totalItems;
        }
        cin.ignore();
        for (int i = 0; i < totalItems; i++) 
		{
			
            itemNo.push_back(i + 1);

            cout << "\n** Item " << itemNo[i] << " **\n";
    		cout << "Enter Description: ";
    		string desc;
    		getline(cin, desc);
    		description.push_back(desc);
    		
            cout << " | Item " << itemNo[i] << " Reserve Price: &";
            float price;
            cin>>price;
            reservePrice.push_back(price);
            
            cin.ignore();
        }
    }
    
    void task2() 
	{
		top:
		int input;
		while (true)
{        // Display all items
        for (int i = 0; i < totalItems; i++) 
		{
            cout << " | Item " << itemNo[i] << " Description: " << description[i] << " Reserve Price: &" << reservePrice[i] << endl;
            if (i< numBids.size() && i < highestBid.size() && numBids[i] > 0) 
			{
                cout << " | Current Highest Bid: &" << highestBid[i] << endl;
            }
        }

        int buyerNumber;
        cout << "Enter your Buyer number: ";
        cin >> buyerNumber;

        bool buyerFound = false;
    for (int i = 0; i < buyerNumbers.size(); i++) 
	{
        if (buyerNumbers[i] == buyerNumber) 
		{
            cout << "This Buyer already exists!" << endl;
            buyerFound = true;
            break;
        }
    }

    if (buyerFound) 
	{
        goto top;
    }
    	top1:
        int itemToBid;
        cout << "Enter the Item number you want to bid on: ";
        cin >> itemToBid;

        if (itemToBid < 1 || itemToBid > totalItems) 
		{
            cout << "Invalid item number." << endl;
            goto top1;
        }
        
        top2:
        float bidAmount;
        cout << "Enter your Bid amount: ";
cin >> bidAmount;

if (itemToBid < 1 || itemToBid > totalItems) 
{ 
    cout << "Invalid item number." << endl;
    return;
}

if (bidAmount <= reservePrice[itemToBid - 1]) 
{ 
    cout << "Bid amount must be higher than the reserve price." << endl;
    goto top2;
}

int itemIndex = itemToBid - 1; // Convert item number to index

if (itemIndex < 0 || itemIndex >= totalItems) 
{
    cout << "Invalid item index." << endl;
    return;
}

buyerNumbers.push_back(buyerNumber);

if (itemIndex >= numBids.size()) 
{
    numBids.resize(itemIndex + 1, 0);
}
numBids[itemIndex]++;

if (itemIndex >= highestBid.size()) 
{
    highestBid.resize(itemIndex + 1, 0.0f);
}
if (bidAmount > highestBid[itemIndex]) 
{
    highestBid[itemIndex] = bidAmount;
}

cout << "Your bid has been placed." << endl;
 
 cout << "\n ** For Exit (0) Otherwise press any key **\n";
 cin >> input;
 if(input == 0)
 {
 	break;
 }
 }
    }
    
    void task3() 
	{
    int numSold = 0;
    int numNotMetReserve = 0;
    int numNoBids = 0;

    cout << "\n<<<<< Auction Results >>>>>\n" << endl;

    if (totalItems > 0) {
        for (int i = 0; i < totalItems; i++) 
		{
            if (i < highestBid.size() && i < reservePrice.size() && i < numBids.size()) 
			{
                if (highestBid[i] >= reservePrice[i]) 
				{
                    cout << "Item " << itemNo[i] << " (<< Sold! >>)" << endl;
                    cout << "  - Final Bid: &" << highestBid[i] << endl;

                    totalAuctionFee += highestBid[i] * 0.1f;
                    numSold++;
                } 
				else if (numBids[i] == 0) 
				{
                    cout << "Item " << itemNo[i] << " (<< No Bids >>)" << endl;
                    numNoBids++;
                } 
				else 
				{
                    cout << "Item " << itemNo[i] << " (<< Did not meet reserve price >>)" << endl;
                    cout << "  - Highest Bid: &" << highestBid[i] << endl;
                    numNotMetReserve++;
                }
            } 
			else 
			{
                cout << "Invalid access to vectors. Please check vector sizes." << endl;
            }
        }
    } 
	else 
	{
        cout << "No items in the auction." << endl;
    }

    cout << "\n<<<<< Auction Summary >>>>>\n" << endl;
    cout << "  - Items Sold: " << numSold << endl;
    cout << "  - Items Not Meeting Reserve: " << numNotMetReserve << endl;
    cout << "  - Items with No Bids: " << numNoBids << endl;
    cout << "  - Total Auction Fee: &" << totalAuctionFee << endl;
}
};

int main() {
    Auction auction;
    // Task1
    auction.task1();
    system("pause");
    // Task2
	auction.task2();
	system("pause");
	// Task3
	auction.task3();
    cout << endl;
    
    return 0;
}

