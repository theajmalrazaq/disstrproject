//#include <iostream>
//using namespace std;
//class set {
//	 char* setA;
//	 char* setB;
//	 int sizeA;
//	 int sizeB;
//
//	//initialize seta
//	void initsetA() {
//		 int x;
//		cout << "Enter size of set A: ";
//		cin >> x;
//		//validate input
//		while (x < 3 || cin.fail()) {
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Invalid Size It should be >= 3 and Int" << endl;
//			cout << "Enter size of set A: ";
//			cin >> x;
//		}
//		sizeA = x;
//		setA = new  char[sizeA];
//	}
//	//initialize setb
//	void initsetB() {
//		 int y;
//		cout << "Enter size of set B: ";
//		cin >> y;
//		//validate input
//		while (y < 3 || cin.fail()) {
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Invalid Size It should be >= 3 and Int" << endl;
//			cout << "Enter size of set B: ";
//			cin >> y;
//		}
//		sizeB = y;
//		setB = new char[sizeB];
//	}
//public:
//	//constructor to initialize variables
//	set() {
//		sizeA = 0;
//		sizeB = 0;
//		setA = NULL;
//		setB = NULL;
//	};
//	//destructor to delete dynamic memory
//	~set() {
//		delete[] setA;
//		delete[] setB;
//		setA = NULL;
//		setB = NULL;
//	}
//
//	// initialize sets and thier elements
//	void input() {
//		initsetA();
//		cout << "Enter elements of set A: " << endl;
//		for ( int i = 0; i < sizeA; i++) {
//			cout << "Enter element " << i + 1 << ": ";
//			cin >> setA[i];
//		}
//
//
//		initsetB();
//		cout << "Enter elements of set B: " << endl;
//		for ( int i = 0; i < sizeB; i++) {
//			cout << "Enter element " << i + 1 << ": ";
//			cin >> setB[i];
//		}
//	}
//
//
//	// print sets
//	void print() {
//		if (setA == NULL || setB == NULL) {
//			cout << "Sets are not created Yet!!" << endl;
//			return;
//		}
//		cout << "Set A: ";
//			cout << "{";
//		for ( int i = 0; i < sizeA; i++) {
//			cout << setA[i] << ",";
//		}
//			cout << "}";
//		cout << endl;
//		cout << "Set B: ";
//		cout << "{";
//		for ( int i = 0; i < sizeB; i++) {
//			cout << setB[i] << ",";
//		}
//		cout << "}";
//		cout << endl;
//	}
//
//
//	//union of sets
//	void Union() {
//		if (setA == NULL || setB == NULL) {
//			cout << "Sets are not created Yet!!" << endl;
//			return;
//		}
//		char* setunion = new  char[sizeA + sizeB]; // create temp array to store union
//		 int i = 0;
//		for ( int j = 0; j < sizeA; j++) {
//			setunion[i++] = setA[j];
//		}
//		for ( int j = 0; j < sizeB; j++) {
//			for ( int k = 0;k < sizeA;k++) {
//				if (setB[j] == setA[k]) { //condition to ignore duplicates
//					break;
//				}
//				else if (k == sizeA - 1) {
//					setunion[i++] = setB[j];
//				}
//			}
//		}
//		cout << "Union of set A and set B is: ";
//		for ( int j = 0; j < i; j++) {
//			cout << setunion[j] << " ";
//		}
//		cout << endl;
//
//		delete[] setunion;
//		setunion = NULL;
//	}
//
//
//
//	//intersection of sets
//	void intersection() {
//		if (setA == NULL || setB == NULL) {
//			cout << "Sets are not created Yet!!" << endl;
//			return;
//		}
//		char* setinter = new  char[sizeA + sizeB]; // create temp array to store intersection
//		 int i = 0;
//		for ( int j = 0; j < sizeA; j++) {
//			for ( int k = 0; k < sizeB; k++) {
//				if (setA[j] == setB[k]) {
//					setinter[i++] = setA[j];
//				}
//			}
//		}
//		cout << "Intersection of set A and set B is: ";
//		if (i == 0)
//			cout << "Empty Set!! { }" << endl;
//		else
//			for (int j = 0; j < i; j++) {
//				cout << setinter[j] << " ";
//			}
//			cout << endl;
//		delete[] setinter;
//		setinter = NULL;
//
//	}
//
//
//
//	//sub setA from setB
//	void subAB() {
//		if (setA == NULL || setB == NULL) {
//			cout << "Sets are not created Yet!!" << endl;
//			return;
//		}
//		 char* setsub = new  char[sizeA]; 
//		 int i = 0;
//
//		for ( int j = 0; j < sizeA; j++) {
//			bool found = false;
//			for ( int k = 0; k < sizeB; k++) {
//				if (setA[j] == setB[k]) {
//					found = true;
//					break;
//				}
//			}
//			if (!found) {
//				setsub[i++] = setA[j];
//			}
//		}
//
//		
//		cout << "Subtraction of set B from set A is: ";
//		if (i == 0) 
//			cout << "Empty Set!! { }" << endl;
//		else
//		for ( int j = 0; j < i; j++) {
//			cout << setsub[j] << " ";
//		}
//		cout << endl;
//		delete[] setsub; 
//		setsub = NULL;
//	}
//
//
//	// sub setB from setA
//	void subBA() {
//		if (setA == NULL || setB == NULL) {
//			cout << "Sets are not created Yet!!" << endl;
//			return;
//		}
//		 char* setsub = new  char[sizeB]; 
//		 int i = 0;
//
//		for ( int j = 0; j < sizeB; j++) {
//			bool found = false;
//			for ( int k = 0; k < sizeA; k++) {
//				if (setB[j] == setA[k]) {
//					found = true;
//					break;
//				}
//			}
//			if (!found) {
//				setsub[i++] = setB[j];
//			}
//		}
//		cout << "Subtraction of set B from set A is: ";
//		if (i == 0)
//			cout << "Empty Set!! { }" << endl;
//		else
//		for ( int j = 0; j < i; j++) {
//			cout << setsub[j] << " ";
//		}
//		cout << endl;
//
//		delete[] setsub; 
//		setsub = NULL;
//	}
//
//
//
//	// calculate num of relations
//	void  numofrelations() const {
//		if (setA == NULL || setB == NULL) {
//			cout << "Sets are not created Yet!!" << endl;
//			return;
//		}
//		 int num = sizeA * sizeB;
//		 size_t rel = pow(2, num); // used size_t to store large values
//		cout << "Number of relations between set A and set B is: " << rel << endl;
//	}
//
//
//	// check if the relation is reflexive
//	void checkreflexive() {
//		 int size_rel;
//		cout << "Enter the number of Pairs: ";
//		cin >> size_rel;
//		//validate input
//		while (cin.fail() || size_rel < 2) {
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Invalid Input size must be > 2 and Int!!" << endl;
//			cout << "Enter the number of Pairs: ";
//			cin >> size_rel;
//		}
//
//		char** setrelation = new  char* [size_rel]; //used 2D array to store pairs
//		for ( int i = 0; i < size_rel; i++) {
//			setrelation[i] = new char[2];
//		}
//
//		// Take input of pairs
//		cout << "Enter the pairs:" << endl;
//		for ( int i = 0; i < size_rel; i++) {
//			cout << "Enter 1st element of Pair " << i + 1 << ": ";
//			cin >> setrelation[i][0]; 
//
//			cout << "Enter 2nd element of Pair " << i + 1 << ": ";
//			cin >> setrelation[i][1]; 
//
//		}
//
//		
//		bool isReflexive = true;
//		for ( int i = 0; i < size_rel; i++) {
//			 int element = setrelation[i][0];
//			bool found = false;
//
//			// Check if (element, element) exists in the relation
//			for ( int j = 0; j < size_rel; j++) {
//				if (setrelation[j][0] == element && setrelation[j][1] == element) {
//					found = true;
//					break;
//				}
//			}
//			if (!found) {
//				isReflexive = false;
//				break;
//			}
//		}
//
//		if (isReflexive) {
//			cout << "The relation is reflexive." << endl;
//		}
//		else {
//			cout << "The relation is not reflexive." << endl;
//		}
//
//		// deallocate memory
//		for ( int i = 0; i < size_rel; i++) {
//			delete[] setrelation[i];
//		}
//		delete[] setrelation;
//		setrelation = NULL;
//	}
//
//
//
//
//
//	// check if the relation is symmetric
//	void checksymmetric() {
//		 int size_rel;
//		cout << "Enter the number of Pairs: ";
//		cin >> size_rel;
//		//validate input
//		while (cin.fail() || size_rel < 2) {
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Invalid Input size must be > 2 and Int!!" << endl;
//			cout << "Enter the number of Pairs: ";
//			cin >> size_rel;
//		}
//		
//		 char** setrelation = new char* [size_rel];
//		for ( int i = 0; i < size_rel; i++) {
//			setrelation[i] = new  char[2];
//		}
//
//		// Take input of pairs
//		cout << "Enter the pairs:" << endl;
//		for ( int i = 0; i < size_rel; i++) {
//			cout << "Enter 1st element of Pair " << i + 1 << ": ";
//			cin >> setrelation[i][0]; 
//
//
//			cout << "Enter 2nd element of Pair " << i + 1 << ": ";
//			cin >> setrelation[i][1]; 
//		}
//
//
//
//	
//		bool isSymmetric = true;
//		for ( int i = 0; i < size_rel; i++) {
//			bool foundSymmetric = false;
//			for ( int j = 0; j < size_rel; j++) {
//				// Check if the reverse pair (b, a) exists for each pair (a, b)
//				if (setrelation[i][0] == setrelation[j][1] && setrelation[i][1] == setrelation[j][0]) {
//					foundSymmetric = true;
//					break;
//				}
//			}
//			if (!foundSymmetric) {
//				isSymmetric = false;
//				break;
//			}
//		}
//
//		if (isSymmetric) {
//			cout << "The relation is symmetric." << endl;
//		}
//		else {
//			cout << "The relation is not symmetric." << endl;
//		}
//
//	
//		for ( int i = 0; i < size_rel; i++) {
//			delete[] setrelation[i];
//		}
//		delete[] setrelation;
//		setrelation = NULL;
//	}
//
//
//
//	// check if the relation is antisymmetric
//	void checkantisymmetric() {
//		 int size_rel;
//		cout << "Enter the number of Pairs: ";
//		cin >> size_rel;
//		//validate input
//		while (cin.fail() || size_rel < 2) {
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Invalid Input size must be > 2 and Int!!" << endl;
//			cout << "Enter the number of Pairs: ";
//			cin >> size_rel;
//		}
//		
//		char** setrelation = new  char* [size_rel];
//		for ( int i = 0; i < size_rel; i++) {
//			setrelation[i] = new char[2];
//		}
//
//		// Take input of pairs
//		cout << "Enter the pairs:" << endl;
//		for ( int i = 0; i < size_rel; i++) {
//			cout << "Enter 1st element of Pair " << i + 1 << ": ";
//			cin >> setrelation[i][0]; 
//
//
//			cout << "Enter 2nd element of Pair " << i + 1 << ": ";
//			cin >> setrelation[i][1]; 
//		}
//
//		
//		bool isAntisymmetric = true;
//		for ( int i = 0; i < size_rel; i++) {
//			for ( int j = 0; j < size_rel; j++) {
//				if (i != j && setrelation[i][0] == setrelation[j][1] && setrelation[i][1] == setrelation[j][0]) { // Ensures the pairs are distinct (i != j) and if (a, b) and (b, a) exists
//					if (setrelation[i][0] != setrelation[i][1]) { // If a == b, then the relation is antisymmetric
//						isAntisymmetric = false; // If a != b, then the relation is not antisymmetric
//						break;
//					}
//				}
//			}
//			if (!isAntisymmetric) {
//				break;
//			}
//		}
//
//		
//		if (isAntisymmetric) {
//			cout << "The relation is antisymmetric." << endl;
//		}
//		else {
//			cout << "The relation is not antisymmetric." << endl;
//		}
//
//		
//		for ( int i = 0; i < size_rel; i++) {
//			delete[] setrelation[i];
//		}
//		delete[] setrelation;
//		setrelation = NULL;
//	}
//
//
//
//
//
//
//	 void showmenu() {
//		  int flag = 1;
//		 while (flag) {
//			 system("cls");
//			 int opt;
//			 cout << "----- Menu ------" << endl;
//			 cout << "1. Create Sets" << endl;
//			 cout << "2. Take Union Of Sets" << endl;
//			 cout << "3. Take Intersection Of Sets" << endl;
//			 cout << "4. Sub Set B from A (A-B)" << endl;
//			 cout << "5. Sub Set A from B (B-A)" << endl;
//			 cout << "6. Total Num of Relations" << endl;
//			 cout << "7. Check Reflexive" << endl;
//			 cout << "8. Check Symmetric" << endl;
//			 cout << "9. Check Antisymmetric" << endl;
//			 cout << "10. Print Sets" << endl;
//			 cout << "0. Exit" << endl;
//			 cout << "----------------" << endl;
//			 cout << "Enter Your Choice: ";
//			 cin >> opt;
//			 while (cin.fail()) { 
//				 cin.clear();
//				 cin.ignore(1000, '\n');
//				 cout << "Invalid Choice!!" << endl;
//				 cout << "Enter Your Choice: ";
//				 cin >> opt;
//			 }
//			 switch (opt) {
//			 case 0:
//				 flag = 0;
//				 break;
//			 case 1:
//				 input();
//				 break;
//			 case 2:
//				 Union(); 
//				 break;
//			 case 3:
//				 intersection(); 
//				 break;
//			 case 4:
//				 subAB(); 
//				 break;
//			 case 5:
//				 subBA(); 
//				 break;
//			 case 6:
//				 numofrelations(); 
//				 break;
//			 case 7:
//				 checkreflexive();
//				 break;
//			 case 8:
//				 checksymmetric();
//				 break;
//			 case 9:
//				 checkantisymmetric();
//				 break;
//			 case 10:
//				 print();
//				 break;
//			 default:
//				 cout << "Invalid input" << endl;
//				 break;
//			 }
//
//			 if (flag) {
//				 cout << "\nPress any key to return to the menu...";
//				 cin.ignore();
//				 cin.get();
//			 }
//		 }
//	 }
//
//};
// int main() {
//	set s;
//	s.showmenu();
//	return 0;
//}