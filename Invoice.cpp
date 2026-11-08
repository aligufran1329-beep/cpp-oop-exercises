#include <iostream>
#include "Invoice.h"
using namespace std;

int main()
{
	Invoice I1("Pen","Stationary Items",2,50);
	cout<<"Purchased Item: "<<I1.getName()<<endl;
	cout<<"Description: "<<I1.getDescription()<<endl;
	cout<<"Price: "<<I1.getPperItems()<<endl;
	cout<<"Quantity: "<<I1.getQofItems()<<endl;
	cout<<"Grand Total: "<<I1.getInvoiceAmount()<<endl;
	return 0;
}
