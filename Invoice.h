#include <string>
using namespace std;

class Invoice
{
	private:	
	
	string Name = "";						 		 // N   <---- Name	
	string Description = "";					    // D   <---- Description
	int Quantity_of_Purchased_Items = 0;           // QPI <---- Quantity of Purchased Items
	int Price_Per_items = 0;			          // PPI <---- Price Per items
	double Value_Added_Tax_Rate = 0.20;        	 // VAT <---- Value Added Tax Rate
	double Discount_Rate = 0.0;				    // DR  <---- Discount Rate
	
	public:
	// Constructor
	Invoice(string N, string D, int QPI, int PPI)
	{
		Name = N;
		Description = D;
		if( QPI > 1)
		{
		Quantity_of_Purchased_Items = QPI;
		}
		if(PPI > 1)
		{
		Price_Per_items = PPI;	
		}
		Value_Added_Tax_Rate = 0.20;
		Discount_Rate = 0.0;
	}
	// Setter and Getters
	void setName (string N) { Name = N;}
	void setDescription (string D) { Description = D;}
	void setQofItems (int QPI){
	if( QPI > 1)
	{ Quantity_of_Purchased_Items = QPI;}
	} 
	void setPperItems (int PPI){
	if( PPI > 1)
	{ Price_Per_items = PPI;}
	} 
	string getName () { return Name;}
	string getDescription () { return Description;}
	int getQofItems () { return Quantity_of_Purchased_Items;}
	int getPperItems () { return Price_Per_items;}
	// Member Functions

	double getInvoiceAmount() 
	{
		double subtotal =Quantity_of_Purchased_Items*Price_Per_items; 
		double InvoiceAmount = subtotal+(subtotal*Value_Added_Tax_Rate)-(subtotal*Discount_Rate);
		return InvoiceAmount;
	} 
};	
