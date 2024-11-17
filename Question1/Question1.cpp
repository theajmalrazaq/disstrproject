#include <iostream>
using namespace std;
class set {
	int* setA;
	int* setB;
	int sizeA;
	int sizeB;
public:
	set() {
		sizeA = 0;
		sizeB = 0;
		setA = NULL;
		setB = NULL;
	};
	//setter to initialize setA
	void initsetA() {
		int x;
		cout << "Enter size of set A: ";
		cin >> x;
		while (x <= 3) {
			cout << "Invalid Size It should be > than 3" << endl;
			cout << "Enter size of set A: ";
			cin >> x;
		}
		sizeA = x;
		setA = new int[sizeA];
	}
	//setter to initialize setB
	void initsetB() {
		int y;
		cout << "Enter size of set B: ";
		cin >> y;
		while (y <= 3) {
			cout << "Invalid Size It should be > than 3" << endl;
			cout << "Enter size of set B: ";
			cin >> y;
		}
		sizeB = y;
		setB = new int[sizeB];
	}
	//function to initialize sets and thier elements
	void input() {
		initsetA();
		cout << "Enter elements of set A: " << endl;
		for (int i = 0; i < sizeA; i++) {
			cout << "Enter element " << i + 1 << ": ";
			cin >> setA[i];
		}
		initsetB();
		cout << "Enter elements of set B: " << endl;
		for (int i = 0; i < sizeB; i++) {
			cout << "Enter element " << i + 1 << ": ";
			cin >> setB[i];
		}
	}
	//function to union 
	void Union() {
		int* setU = new int[sizeA + sizeB];
		int i = 0;
		for (int j = 0; j < sizeA; j++) {
			setU[i++] = setA[j];
		}
		for (int j = 0; j < sizeB; j++) {
			for (int k = 0;k < sizeA;k++) {
				if (setB[j] == setA[k]) {
					break;
				}
				else if (k == sizeA - 1) {
					setU[i++] = setB[j];
				}
			}
		}


		cout << "Union of set A and set B is: ";
		for (int j = 0; j < i; j++) {
			cout << setU[j] << " ";
		}
		cout << endl;
	}
	//function to find intersection
	void intersection() {
		int* setI = new int[sizeA + sizeB];
		int i = 0;
		for (int j = 0; j < sizeA; j++) {
			for (int k = 0; k < sizeB; k++) {
				if (setA[j] == setB[k]) {
					setI[i++] = setA[j];
				}
			}
		}
		cout << "Intersection of set A and set B is: ";
		for (int j = 0; j < i; j++) {
			cout << setI[j] << " ";
		}
		cout << endl;
	}

	//function to sub setA from setB
	void subAB() {
		int* setS = new int[sizeA]; 
		int i = 0;

		for (int j = 0; j < sizeA; j++) {
			bool found = false;
			for (int k = 0; k < sizeB; k++) {
				if (setA[j] == setB[k]) {
					found = true;
					break;
				}
			}
			if (!found) {
				setS[i++] = setA[j];
			}
		}

		
		cout << "Subtraction of set B from set A is: ";
		for (int j = 0; j < i; j++) {
			cout << setS[j] << " ";
		}
		cout << endl;

		delete[] setS; 
	}


	//function to sub setB from setA
	void subBA() {
		int* setS = new int[sizeB]; 
		int i = 0;

		for (int j = 0; j < sizeB; j++) {
			bool found = false;
			for (int k = 0; k < sizeA; k++) {
				if (setB[j] == setA[k]) {
					found = true;
					break;
				}
			}
			if (!found) {
				setS[i++] = setB[j];
			}
		}
		cout << "Subtraction of set B from set A is: ";
		for (int j = 0; j < i; j++) {
			cout << setS[j] << " ";
		}
		cout << endl;

		delete[] setS; 
	}

	//function to calculate num of relations
	 void  numofrelations() {
		int num = sizeA * sizeB;
		int rel = pow(2, num);
		cout << "Number of relations between set A and set B is: " << rel << endl;
	}
	 void showmenu() {
		 int flag = 1;
		 while (flag) {
			 system("cls");
			 int opt;
			 cout << "----- Menu ------" << endl;
			 cout << "1. Create Sets" << endl;
			 cout << "2. Take Union Of Sets" << endl;
			 cout << "3. Take Intersection Of Sets" << endl;
			 cout << "4. Sub Set B from A (A-B)" << endl;
			 cout << "5. Sub Set A from B (B-A)" << endl;
			 cout << "6. Total Num of Relations" << endl;
			 cout << "0. Exit" << endl;
			 cout << "Enter Your Choice: ";
			 cin >> opt;

			 switch (opt) {
			 case 0:
				 flag = 0;
				 break;
			 case 1:
				 input();
				 break;
			 case 2:
				 Union(); 
				 break;
			 case 3:
				 intersection(); 
				 break;
			 case 4:
				 subAB(); 
				 break;
			 case 5:
				 subBA(); 
				 break;
			 case 6:
				 numofrelations(); 
				 break;
			 default:
				 cout << "Invalid Choice!!" << endl;
				 break;
			 }

			 if (flag) {
				 cout << "\nPress any key to return to the menu...";
				 cin.ignore();
				 cin.get();
			 }
		 }
	 }




};
int main() {
	set s;
	s.showmenu();
	return 0;
}