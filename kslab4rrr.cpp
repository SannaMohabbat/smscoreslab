#include <iostream>
#include <fstream>
std::ifstream infile;
double average (int a[], int SIZE, std::string file);//calling avg fxn
double highestavg (double a[], int SIZE, int counter, std::string file);//calling highest avg fxn
double lowestavg (double a[], int SIZE, int count, std::string file);//calling lowest avg fxn
int main()
{
	int avg;
	int x = 0;
	//std::fstream infile;
	int counter = 0;
	int count = 0;
	const int SIZE=10;
	std::string file;
	double a[SIZE];//array to store average
	int rows;
	int arr[rows][SIZE];//array to store numbers in file
	std::string exit ="k";
	std::string f;
	while (exit != "n"){//setting a while loop for exiting program
	std::cout << "What is the file name? ";
	std::cin >> file;
	infile.open(file, std::fstream::in);//opening file that user inputs
	//std::ofstream outfile (file, std::fstream::app);
	for (int i = 0; i < SIZE; i++){//this for loop stores the number in the files into an array
	infile >> f;//this string stores all the numbers before the act scores
		for(int j = 0; j < SIZE; j++){
			infile >> arr[i][j];}}//storing numbers into array
			infile.close ();//closing file
	for (int i = 0; i < SIZE; i++){//this for loop outputs array
		for(int j = 0; j < SIZE; j++){
			std::cout << arr[i][j] << " ";}
			std::cout << std::endl;}
	for (int i = 0; i < SIZE; i++){
	a[i]=average(arr[i], SIZE, file);}//calling functions needed
	highestavg(a,SIZE,counter, file);
	lowestavg(a,SIZE,count, file);
	std::cout << "\n Do you want to repeat(y/n):  ";//asking user if they want to repeat
	std::cin >> exit;// exit if user enters 'n'
		//return 0;		
	}
}
double average (int a[], int SIZE, std::string file)
{
	std::ofstream outfile (file, std::ofstream::app);//appends whatever the output is into file
	double avg;
	double sum = 0;
	for ( int x= 0; x<SIZE; x++){
		sum+=a[x];//calculates sum of numbers
	avg=sum/10;//calculates avg of numers
	}
	std::cout << "average is " << avg <<"\n";
	outfile << "average is " << avg <<"\n";//puts the avg into the file
	 return avg;
}
double highestavg (double a[], int SIZE, int counter, std::string file)
{
	std::ofstream outfile (file, std::ofstream::app);
	double havg = a[0];
	for (int i = 0; i < SIZE; i++){//computes the highest score out of the averages
		if (havg < a[i]){
			havg = a[i];}}
			std::cout << "highest average is " << havg << std::endl;
			outfile << "highest average is " << havg << std::endl; //stores highest avg into file
			return havg;
}
double lowestavg (double a[], int SIZE, int count, std::string file)
{
	std::ofstream outfile (file, std::ofstream::app);
	double lavg = a[0];
	for (int i = 0; i < SIZE; i++){//computes lowest score out of all averages
		if (lavg > a[i]){
			lavg = a[i];}}
			std::cout << "the lowest average is " << lavg << std::endl;
			outfile << "the lowest average is " << lavg << std::endl;//puts lowest average into file
			return lavg;
}
