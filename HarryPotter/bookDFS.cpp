#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "testCases.h"

using namespace std;

const double MaxVal = std::numeric_limits<double>::max(); // define a maximum value, the value is ignored when this position corresponds to a minimum value
#define disc2 2 * 15 * 0.93
#define disc3 3 * 15 * 0.87
#define disc4 4 * 15 * 0.82
#define disc5 5 * 15 * 0.75
#define disc6  6 * 15 * 0.72
#define disc7  7 * 15 * 0.70

double Min (double b1, double b2, double b3, double b4, double b5, double b6, double b7) // returns the minimum
{
    double books[7] = {b1, b2, b3, b4, b5, b6, b7};
    sort(begin(books), end(books));
    return books[0];
}

double find_BestSol (int book1, int book2, int book3, int book4, int book5 , int book6 , int book7)
{
    int allBooks[7] = { book1, book2, book3, book4, book5 , book6 , book7 };

    sort(begin(allBooks), end(allBooks));

    book1 = allBooks[0];
    book2 = allBooks[1];
    book3 = allBooks[2];
    book4 = allBooks[3];
    book5 = allBooks[4];
    book6 = allBooks[5];
    book7 = allBooks[6];


    if (allBooks[0] > 0){ 
        return                      Min(15.0 + find_BestSol(book1, book2, book3, book4, book5 , book6 , book7 - 1),
                                        disc2 + find_BestSol(book1, book2, book3, book4, book5 , book6 - 1, book7 - 1),
                                        disc3 + find_BestSol(book1, book2, book3, book4, book5 - 1, book6 - 1, book7 - 1),
                                        disc4 + find_BestSol(book1, book2, book3, book4 - 1, book5 - 1, book6 - 1, book7 - 1),
                                        disc5 + find_BestSol(book1, book2, book3 - 1, book4 - 1, book5 - 1 , book6 - 1, book7 - 1),
                                        disc6 + find_BestSol(book1, book2 - 1, book3 - 1, book4 - 1, book5 - 1 , book6 - 1, book7 - 1),
                                        disc7 + find_BestSol(book1 - 1, book2 - 1, book3 - 1, book4 - 1, book5 - 1 , book6 - 1, book7 - 1));

    }
    else if ((allBooks[0] == 0) && (allBooks[1] > 0))
    {
        return                      Min(15.0 + find_BestSol(book1, book2, book3, book4, book5 , book6 , book7 - 1),
                                        disc2 + find_BestSol(book1, book2, book3, book4, book5 , book6 - 1, book7 - 1),
                                        disc3 + find_BestSol(book1, book2, book3, book4, book5 - 1, book6 - 1, book7 - 1),
                                        disc4 + find_BestSol(book1, book2, book3, book4 - 1, book5 - 1, book6 - 1, book7 - 1),
                                        disc5 + find_BestSol(book1, book2, book3 - 1, book4 - 1, book5 - 1 , book6 - 1, book7 - 1),
                                        disc6 + find_BestSol(book1, book2 - 1, book3 - 1, book4 - 1, book5 - 1 , book6 - 1, book7 - 1), MaxVal);

    }
    else if ((allBooks[0] == 0) && (allBooks[1] == 0) && (allBooks[2] > 0))
    {
        return                        Min(15.0 + find_BestSol(book1, book2, book3, book4, book5 , book6 , book7 - 1),
                                          disc2 + find_BestSol(book1, book2, book3, book4, book5 , book6 - 1, book7 - 1),
                                          disc3 + find_BestSol(book1, book2, book3, book4, book5 - 1, book6 - 1, book7 - 1),
                                          disc4 + find_BestSol(book1, book2, book3, book4 - 1, book5 - 1, book6 - 1, book7 - 1),
                                          disc5 + find_BestSol(book1, book2, book3 - 1, book4 - 1, book5 - 1 , book6 - 1, book7 - 1),
                                          MaxVal, MaxVal);
    }
    else if ((allBooks[0] == 0) && (allBooks[1] == 0) && (allBooks[2] == 0) && (allBooks[3] > 0))
    {
        return                        Min(15.0 + find_BestSol(book1, book2, book3, book4, book5 , book6 , book7 - 1),
                                          disc2 + find_BestSol(book1, book2, book3, book4, book5 , book6 - 1, book7 - 1),
                                          disc3 + find_BestSol(book1, book2, book3, book4, book5 - 1, book6 - 1, book7 - 1),
                                          disc4 + find_BestSol(book1, book2, book3, book4 - 1, book5 - 1, book6 - 1, book7 - 1),
                                          MaxVal, MaxVal, MaxVal);
    }
    else if ((allBooks[0] == 0) && (allBooks[1] == 0) && (allBooks[2] == 0) && (allBooks[3] == 0) && (allBooks[4] > 0))
    {
        return                        Min(15.0 + find_BestSol(book1, book2, book3, book4, book5 , book6 , book7 - 1),
                                          disc2 + find_BestSol(book1, book2, book3, book4, book5 , book6 - 1, book7 - 1),
                                          disc3 + find_BestSol(book1, book2, book3, book4, book5 - 1, book6 - 1, book7 - 1),
                                          MaxVal, MaxVal, MaxVal, MaxVal);
    }

    else if ((allBooks[0] == 0) && (allBooks[1] == 0) && (allBooks[2] == 0) && (allBooks[3] == 0) && (allBooks[4] == 0) && (allBooks[5] > 0))
    {
        return                        Min(15.0 + find_BestSol(book1, book2, book3, book4, book5 , book6 , book7 - 1),
                                          disc2 + find_BestSol(book1, book2, book3, book4, book5 , book6 - 1, book7 - 1),
                                          MaxVal, MaxVal, MaxVal, MaxVal, MaxVal);
    }

    else if ((allBooks[0] == 0) && (allBooks[1] == 0) && (allBooks[2] == 0) && (allBooks[3] == 0) && (allBooks[4] == 0) && (allBooks[5] == 0), (allBooks[6] > 0))
    {
        return                        15.0 + find_BestSol(book1, book2, book3, book4, book5 , book6 , book7 - 1);



    }
    else // both 0
    {
        return 0;
    }

} 

int  main()
{

    std::ofstream FileName;
    FileName.open("answers.txt");

    for (int i = 0; i < test_cases.size();i++) {
        cout << i << endl;
        FileName << endl;
        FileName << "Test Case " << test_cases[i][0] << test_cases[i][1] << test_cases[i][2] << test_cases[i][3] << test_cases[i][4] << test_cases[i][5] << test_cases[i][6]<< " ";
        FileName  << find_BestSol(test_cases[i][0], test_cases[i][1], test_cases[i][2], test_cases[i][3], test_cases[i][4], test_cases[i][5], test_cases[i][6]);

    }

    FileName.close();

}



/*

The seventh and final book in the extremely popular Harry Potter series has just been released, and
Crazy Jake’s Online Bookstore is offering discounts on purchases. The list price on each of the seven
books is $15. However, if you purchase multiple books in the series, you will receive a discount based on
how many unique books you bought. If you buy two different books from the series, you will get 7% off
each of the books. If you buy three different books, you will get 13% off each of the books. With 4
different books, you will get 18% off each book. Purchasing 5 different books, will get you 25% off each
book. If you buy 6 different books, you will get a whopping 28% off each book. Finally, if you buy all 7
books from the series, you will get 30% off each book.
The discount offered is only applicable to the set of books used to qualify for the discount. For example,
if you purchased 5 books, 4 of which are different, you would receive a 18% discount on the price of the
four books, but the fifth book would still cost $15.
Design a piece of software that can calculate the total cost of any conceivable selection of books given
the available discounts. The software should be designed to maximize the possible savings by
intelligently determining how many books in the “cart” to group together to get the MaxValest overall
discount.
Example:
2 copies of the first book
2 copies of the second book
2 copies of the third book
2 copies of the fourth book
1 copy of the fifth book
1 copy of the sixth book
The correct answer is not (6*$15*0.72)+(4*$15*0.82)=$114. There is a cheaper solution. Creating two
groups of 5 results in (5*$15*0.75)+(5*$15*0.75)=$112.5.

What is the max number of groups?
1 of each books

10 groups of 1
5 groups of 2

*/


