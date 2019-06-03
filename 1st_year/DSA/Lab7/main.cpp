#include <iostream>
#include "SortedIteratedList.h"
using namespace std;
bool Relation123(TComp a, TComp b){
    return a > b;
}
int main() {
    cout << "Hello, World!\n\n";
    auto sl = SortedIteratedList(Relation123);
    sl.add(11);
    sl.add(7);
    sl.add(20);
    sl.add(2);
    sl.add(9);
    sl.add(4);
    sl.add(19);
    sl.add(15);
    sl.add(13);
    sl.add(17);
    sl.add(25);
    sl.print();
    auto it = sl.iterator();
    while (it.valid()) {
        cout << it.getCurrent() << "\n";
        it.next();
    }
    return 0;
}
// 2 - 4 - 7 - 9 - 11 - 13 - 15 - 17 - 19 - 20 - 25
/*
 *                  11
 *            7             22
 *         2     9     19      25
 *           4       15   20
 *                 13  17
 */