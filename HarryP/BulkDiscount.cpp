#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <fstream>
#include "testCases.h"
using namespace std;


static std::vector<int> books
{
	2,2,2,2,1,1
};

static  vector<float> discounts
{
	0, 0, 0.07f, .13f, .18f, .25f, .28f, .30f
};


static   vector<float> prices
{
	-1.0
};



class BookGroup
{

public:

	std::unordered_set<int> Books;
	float cost;


	BookGroup();

	BookGroup(const BookGroup& other)
	{
		for (auto& book : other.Books) // foreach in algorithm
		{
			Books.insert(book);
		}
	}


	BookGroup(int book)
	{
		Books.insert(book);
	}

	float getCost()
	{
		cost = (Books.size() == 0) ? std::numeric_limits<float>::max() : prices[Books.size()];
		return cost;

	}

	void printTheBooksAndTheCost()
	{

		for (auto& iter : Books) {

			cout << iter << " ";

		}

		cout << "Cost " << getCost() << endl;
	}
};


class BookGroups
{


public:

	vector<BookGroup> Groups;
	float Cost;
	int TotalBooks;

	BookGroups()
	{
		TotalBooks = 0;
		Cost = std::numeric_limits<float>::max(); // set cost to max float for compare
	}

	vector<BookGroup> getGroups() {

		return Groups;
	}

	vector<BookGroup> clearGroups() {

		return Groups;
	}


	BookGroups(const BookGroups& other)  // copy contructor

	{
		Cost = other.Cost; TotalBooks = other.TotalBooks;

		for (auto& iter : other.Groups) {

			Groups.push_back(iter);
		}
	}

	int getTotalBooks() { return TotalBooks; }
	float getCost() { return Cost; }

	void setTotalBooks(int tb) { TotalBooks = tb; }
	void setCost(float cst) { Cost = cst; }


	void printBookGroupsAndCost()  {

		for (auto& iter : Groups) {

			iter.printTheBooksAndTheCost();
		}

		cout << "Total Cost " << getCost() << endl;
	}

	void AddBook(const int group,const int bookId)
	{

		if (Groups[group].Books.count(bookId) == 0)
		{
			Groups[group].Books.insert(bookId);
			Calculate();
		}

	}

	void Calculate()
	{
		Cost = 0;
		TotalBooks = 0;

		for (auto& i : Groups) {
			Cost += i.getCost();
			TotalBooks += i.Books.size();

		}
	}

};



static void printMatrix(const vector<vector<BookGroups>>& groups)
{
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		for (unsigned int j = 0; j < groups[i].size(); j++)
		{
			if (groups[i][j].Cost == std::numeric_limits<double>::max())
			{
				cout << "-1 ";
			}
			else
			{
				cout << groups[i][j].Cost << " ";
			}
		}
		cout << endl;
	}
}

static BookGroups PickMeAWinner(const BookGroups& left, const BookGroups& right) 
{


	if (left.TotalBooks > right.TotalBooks)
	{
		return left;
	}

	if (right.TotalBooks > left.TotalBooks)
	{
		return right;
	}

	if (left.Cost < right.Cost)
	{
		return left;
	}

	if (right.Cost < left.Cost)
	{
		return right;
	}

	return left;
}

class BookDiscount {


private:
	BookGroups baseGroups = BookGroups();
	vector<int> unplacedBooks = vector<int>();

public :BookDiscount() {
	}

	void checkOut() {
		books.clear();
		int bookNum;
		for (int b = 0; b < 7; b++) {
			cout << "Type the number of books for book ";
			cout << (b + 1);
			cout << endl; // Type a number and press enter
			do {
				cin >> bookNum; // Get user input from the keyboard
				if (bookNum > 255) { cout << "that is way to many books ending... try smaller number " << endl; }
			} while (bookNum > 255);
			books.push_back(bookNum);
		}

		for (unsigned int i = 1; i < discounts.size(); i++)
		{
			prices.push_back((15 * i) * (1 - discounts[i]));
		}




		// Split into initial groups by taking the books with the max number of books ordered
		// and making that into distinct groups of 1.  Also do the same for any other book that
		// has the same number ordered.  The rest of the books are unplaced and become the matrix columns.


		int neededGroups = *(max_element(std::begin(books), std::end(books)));

		for (unsigned int book = 0; book < books.size(); book++)
		{
			unsigned int count = books[book];

			if (count > 1)
			{
				for (unsigned int i = 0; i < baseGroups.Groups.size() && i < count; i++)
				{
					baseGroups.AddBook(i, book);
				}

				int add = count - baseGroups.Groups.size();
				//paul sucks he really really sucks

				for (unsigned int i = add; i > 0; i--)
				{
					baseGroups.Groups.push_back(BookGroup(book));
				}
			}
			else
			{
				unplacedBooks.push_back(book);
			}
		}

		baseGroups.Calculate();

		vector<vector<BookGroups>> m(baseGroups.Groups.size(), vector<BookGroups>(unplacedBooks.size(), baseGroups)); /// matrix containing the book groups

		for (unsigned int i = 0; i < m.size(); i++)
		{
			for (unsigned int j = 0; j < m[i].size(); j++)
			{
				auto bestCandidate = BookGroups(baseGroups);
				bestCandidate.AddBook(i, unplacedBooks[j]);

				if (j - 1 > -1)  // check matrix boundries
				{
					auto contender = BookGroups((m[i][j - 1])); // this is a possible canidate

					contender.AddBook(i, unplacedBooks[j]); // place the book for contention
					bestCandidate = PickMeAWinner(contender, bestCandidate); // compare and pick best

					if (i - 1 > -1)
					{
						contender = BookGroups((m[i - 1][j - 1]));  // this is a possible canidate

						contender.AddBook(i, unplacedBooks[j]);// place the book for contention
						bestCandidate = PickMeAWinner(contender, bestCandidate); // compare and pick best
					}
				}

				if (i - 1 > -1)  //check matrix boundries
				{
					auto contender = BookGroups((m[i - 1][j])); // this is a possible canidate

					bestCandidate = PickMeAWinner(bestCandidate, contender); //compareand pick best
				}

				m[i][j] = bestCandidate;

				printMatrix(m);
				cout << endl;
			}
		}

		BookGroups best = unplacedBooks.size() == 0 ? baseGroups : m[m.size() - 1][m[0].size() - 1];

		cout << endl;
		cout << "Best Groups :" << endl;
		best.printBookGroupsAndCost();
	}

	

};


int main() {

	BookDiscount HarryPotterDiscount = BookDiscount();
	HarryPotterDiscount.checkOut();


	return 0;

}