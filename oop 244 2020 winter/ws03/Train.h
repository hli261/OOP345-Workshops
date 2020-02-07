//==============================================
// Name:           Xiaozhuan Li
// Student Number: 162683189
// Email:          xli403@myseneca.ca
// Date:           Jan-28-2020
// Section:        OOP244NAA
// Workshop:       3 (diy)
//==============================================
// Train.h

#ifndef SDDS_TRAIN_H 
#define SDDS_TRAIN_H 

namespace sdds {
	const int MAX_NAME = 30;
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;

	class Cargo {
		char* m_description{};
		char m_descriptionArray[MAX_DESC]{};
	//	char(*a)[10]    = new (char(*)[10]);
	////	char **a= new char[10];

		double m_weight{};
	public:
		void setDescription(const char* s_description);
		void setDescriptionPtr(char* s_description);
		void setWeight(const double s_double);
		char* getDescription() const;
		char* getDescriptionArray() ;
		double getWeight() const;
		void deleteCargo();
		void init(const char*, double);
		void initPtr( char*, double);
	};

	class Train {
		char m_name[MAX_NAME + 1]{};
		int m_id{};
		Cargo* m_cargo{};
	public:
		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo);
		void unloadCargo();
		
		bool swapCargo(Train&);
		bool increaseCargo(double);
		bool decreaseCargo(double);
	};
}
#endif