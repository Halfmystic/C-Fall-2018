#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


class functions {


public:

	/*Get the values from the text file*/
	static void getData(int array[], int secondArray[], const int SIZE) {

		ifstream inFile;
		ofstream outFile;


		inFile.open("./random.txt");

		if (!inFile) {
			cout << "Error Opening File\n";
		}

		else
		{
			for (int i = 0; i < SIZE; i++)
			{

				inFile >> array[i];
				

			}

			for (int i = 0; i < SIZE; i++)
			{

				
				inFile >> secondArray[i];

			}


			inFile.close();
		}

	}

	static void displayValues(int array[], int size, int &exchange1, int &exchange2)
	{


	cout << "Number of exchanges made by each sort algorithm.\n";
	cout << "Bubble sort:    " << functions::bubbleSort(array, size, exchange1) << endl;
	cout << "Selection sort: " << functions::selectionSort(array, size, exchange2) << endl;
	}



private:

	/******************************************************************************
	 *                                 linearSearch                               *
	 ******************************************************************************/
	int linearSearch(int list[], int size, int value, int &LinBMark)
	{
	
		int index = 0;			// Used as a subscript to search array
		int position = -1;		// Used to record the position of search value
		bool found = false;     // Flag to indicate if the value was found

		while (index < size && !found)
		{
			if (list[index] == value)	// If the value is found
			{
				found = true;			// Set the flag
				position = index;		// Record the value's subscript
			}
			index++;

			if (position == -1)
				LinBMark++;
		}
		return position;				// Return the position, or -1
	}

	/******************************************************************************
	 *                                BinarySearch                                *
	 ******************************************************************************/
	int binarySearch(int array[], int size, int value, int &BinBMark)
	{
		int first = 0,							// First array element
			last = size - 1,					// Last array element
			middle,								// Midpoint of search
			position = -1;						// Position of search value
		bool found = false;						// Flag

		while (!found && first <= last)
		{
			middle = (first + last) / 2;		// Calculate midpoint
			if (array[middle] == value)			// If value is found
			{
				found = true;
				position = middle;
			}
			else if (array[middle] > value)		// If value is in the lower half
				last = middle - 1;
			else
				first = middle + 1;				// If value is in the upper half
			if (position == -1)
				BinBMark++;
		}
		return position;
	}

	/*Bubble Sort function*/

	static int bubbleSort(int array[], int size, int &exchange1)
	{
		int temp;
		bool swap;
		exchange1 = 0;

		do
		{
			swap = false;
			for (int count = 0; count < (size - 1); count++)
			{
				if (array[count] > array[count + 1])
				{
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					swap = true;
					exchange1++;
				
				}
			}
		} while (swap);

		return exchange1;
	}

	

/********************************************************************************
 *                               selectionSort                                  *
 ********************************************************************************/
	static int selectionSort(int array[], int size, int &exchange2)
	{
		int startScan, minIndex, minValue;

		for (int startScan = 0; startScan < (size - 1); startScan++)
		{
			minIndex = startScan;
			minValue = array[startScan];
			for (int index = startScan + 1; index < size; index++)
			{
				if (array[index] < minValue)
				{
					minValue = array[index];
					minIndex = index;
					exchange2++;
				}
			}
			array[minIndex] = array[startScan];
			array[startScan] = minValue;
		}
		return exchange2;
	}
};

int main() {
	const int SIZE = 200;
	int array[SIZE];
	int secondArray[SIZE], exchange1, exchange2;



	functions::displayValues(array, SIZE, exchange1, exchange2);

	return 0;
}