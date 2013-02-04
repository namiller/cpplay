#include "node.h"
#include <iostream>

using namespace std;
int main(){
    node<int> t1(2);
    node<int> t2(2);

    t1.next(t2);
    t1.val() = 10;
    cout<<t1.val()<<endl;
    cout << t1.next().val()<<endl;
    t2.val() = 100;
    cout << t1.next().val()<<endl;
    cout << t2.prev().val()<<endl;

    
    return 0;
}
