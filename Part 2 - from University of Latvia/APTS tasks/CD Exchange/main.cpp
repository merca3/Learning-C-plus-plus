#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class Order {
	public:
		int time;
		char action;
		string person_code;
		string cd;
		Order(int time, char action, string person_code, string cd);
};

Order::Order(int time, char action, string person_code, string cd) {
	this->time = time;
	this->action = action;
	this->person_code = person_code;
	this->cd = cd;
}

bool checkMatchingOrders(list<Order>& orders, Order newOrder) {
	list<Order>::iterator order_iterator = orders.begin();
	while (order_iterator != orders.end()) {
	    
		if ((*order_iterator).cd == newOrder.cd && (*order_iterator).action != newOrder.action) {
		    
			if ((*order_iterator).action == 'A' && newOrder.action == 'B') {
				cout << newOrder.time << " " << (*order_iterator).person_code << " " << newOrder.person_code << endl;
			} 
			else if (newOrder.action == 'A' && (*order_iterator).action == 'B') {
				cout << newOrder.time << " " << newOrder.person_code << " " << (*order_iterator).person_code << endl;
			}

			orders.erase(order_iterator);

			return true;
		}

		++order_iterator;
	}

	orders.push_back(newOrder);
	return false;
}


int main()
{
    FILE* submittedOrders = freopen("exchange.in", "r", stdin);
	FILE* orderMatches = freopen("exchange.out", "w", stdout);

	list<Order> orders;
	int matchedOrdersCount = 0;

	int time;
	char action;
	string person_code, cd;
	
	while (cin >> time >> action >> person_code >> cd) {
    	Order newOrder(time, action, person_code, cd);
		if (checkMatchingOrders(orders, newOrder)) matchedOrdersCount++;
    }

	if (matchedOrdersCount == 0) cout << "No matched orders" << endl;

	orders.clear();
}

