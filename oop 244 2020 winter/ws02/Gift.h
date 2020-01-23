//==============================================
// Name:           Xiaozhuan Li
// Student Number: 162683189
// Email:          xli403@myseneca.ca
// Date:           Jan-20-2020
// Section:        OOP244NAA
// Workshop:       2 (in-lab)
//==============================================
// Gift.h

#ifndef SDDS_GIFT_H 
#define SDDS_GIFT_H 

namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;

	struct Gift {
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};
	
	void gifting(char* g_description);
	void gifting(double& g_price);
	void gifting(int& g_units);
	void display(const Gift& gift, int numberOfGifts);


}
#endif
