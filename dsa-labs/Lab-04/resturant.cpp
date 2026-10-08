# include <iostream>
# include <string>
# include "ordermanager.h"
using namespace std;
int main()
	{
		Order arr[] = {
		Order(101, "Ali", 20),
		Order(102, "Sara", 5),
		Order(103, "Ahmed", 30),
		Order(104, "Usman", 2),
	};

OrderManager manager(arr, 4, 5); // time quantum = 5
manager.processOrders();
return 0;
}