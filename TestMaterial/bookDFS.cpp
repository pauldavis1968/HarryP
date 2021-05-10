#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "testCases.h"

using namespace std;

const double larg = std::numeric_limits<double>::max(); // define a maximum value, the value is ignored when this position corresponds to a minimum value



double Min (double a, double b, double c, double d, double e, double f, double g) // returns the minimum
{
    double nn[7] = {a, b, c, d, e, f, g};
    sort(begin(nn), end(nn));
    return nn[0];
}

double find_BestSol (int x1, int x2, int x3, int x4, int x5 , int x6 , int x7)
{
    int n[7] = { x1, x2, x3, x4, x5 , x6 , x7 };

    sort(begin(n), end(n));

    x1 = n[0];
    x2 = n[1];
    x3 = n[2];
    x4 = n[3];
    x5 = n[4];
    x6 = n[5];
    x7 = n[6];
    /* x1 < x2 < x3 < x4  < x5 <x6 <x7*/


    if (n [0] > 0) // 0 greater than the minimum; all winding number greater than 0; then all possible discounts set out, returns the minimum value
    {
        return                      Min(15.0 + find_BestSol(x1, x2, x3, x4, x5 , x6 , x7 - 1),
                                        2 * 15 * 0.93 + find_BestSol(x1, x2, x3, x4, x5 , x6 - 1, x7 - 1),
                                        3 * 15 * 0.87 + find_BestSol(x1, x2, x3, x4, x5 - 1, x6 - 1, x7 - 1),
                                        4 * 15 * 0.82 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1, x6 - 1, x7 - 1),
                                        5 * 15 * 0.75 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1 , x6 - 1, x7 - 1),
                                        6 * 15 * 0.72 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1 , x6 - 1, x7 - 1),
                                        7 * 15 * 0.70 + find_BestSol(x1 - 1, x2 - 1, x3 - 1, x4 - 1, x5 - 1 , x6 - 1, x7 - 1));

    }
    else if ((n[0] == 0) && (n[1] > 0))
    {
        return                      Min(15.0 + find_BestSol(x1, x2, x3, x4, x5 , x6 , x7 - 1),
                                        2 * 15 * 0.93 + find_BestSol(x1, x2, x3, x4, x5 , x6 - 1, x7 - 1),
                                        3 * 15 * 0.87 + find_BestSol(x1, x2, x3, x4, x5 - 1, x6 - 1, x7 - 1),
                                        4 * 15 * 0.82 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1, x6 - 1, x7 - 1),
                                        5 * 15 * 0.75 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1 , x6 - 1, x7 - 1),
                                        6 * 15 * 0.72 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1 , x6 - 1, x7 - 1), larg);

    }
    else if ((n[0] == 0) && (n[1] == 0) && (n[2] > 0))
    {
        return                        Min(15.0 + find_BestSol(x1, x2, x3, x4, x5 , x6 , x7 - 1),
                                          2 * 15 * 0.93 + find_BestSol(x1, x2, x3, x4, x5 , x6 - 1, x7 - 1),
                                          3 * 15 * 0.87 + find_BestSol(x1, x2, x3, x4, x5 - 1, x6 - 1, x7 - 1),
                                          4 * 15 * 0.82 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1, x6 - 1, x7 - 1),
                                          5 * 15 * 0.75 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1 , x6 - 1, x7 - 1),
                                          larg, larg);
    }
    else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] > 0))
    {
        return                        Min(15.0 + find_BestSol(x1, x2, x3, x4, x5 , x6 , x7 - 1),
                                          2 * 15 * 0.93 + find_BestSol(x1, x2, x3, x4, x5 , x6 - 1, x7 - 1),
                                          3 * 15 * 0.87 + find_BestSol(x1, x2, x3, x4, x5 - 1, x6 - 1, x7 - 1),
                                          4 * 15 * 0.82 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1, x6 - 1, x7 - 1),
                                          larg, larg, larg);
    }
    else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] == 0) && (n[4] > 0))
    {
        return                        Min(15.0 + find_BestSol(x1, x2, x3, x4, x5 , x6 , x7 - 1),
                                          2 * 15 * 0.93 + find_BestSol(x1, x2, x3, x4, x5 , x6 - 1, x7 - 1),
                                          3 * 15 * 0.87 + find_BestSol(x1, x2, x3, x4, x5 - 1, x6 - 1, x7 - 1),
                                          larg, larg, larg, larg);
    }

    else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] == 0) && (n[4] == 0) && (n[5] > 0))
    {
        return                        Min(15.0 + find_BestSol(x1, x2, x3, x4, x5 , x6 , x7 - 1),
                                          2 * 15 * 0.93 + find_BestSol(x1, x2, x3, x4, x5 , x6 - 1, x7 - 1),
                                          larg, larg, larg, larg, larg);
    }

    else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] == 0) && (n[4] == 0) && (n[5] == 0), (n[6] > 0))
    {
        return                        15.0 + find_BestSol(x1, x2, x3, x4, x5 , x6 , x7 - 1);



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

        FileName << endl;
        FileName  << find_BestSol(test_cases[i][0], test_cases[i][1], test_cases[i][2], test_cases[i][3], test_cases[i][4], test_cases[i][5], test_cases[i][6]);

    }

    FileName.close();

}




//   double solution = find_BestSol(n1[0],n1[1],n1[2],n1[3],n1[4],n1[5], n1[6]);
//cout << "the least money spent is:" << solution << endl;

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
intelligently determining how many books in the “cart” to group together to get the largest overall
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


