#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int MAX_DATA = 100;
const double PHI = 3.141592653589793;


struct Data {
    char kode;
    int tahun;
    double harga;
    double iklan;
    int penjualan;
    int stok;
};

double rataRata(double arr[], int n) {
	double hasil = 0.0;
	for (int i = 0; i < n; i++) {
		hasil+=arr[i];
	}
	return hasil / n;
}

double maks(double arr[], int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

double min(double arr[], int n) {
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if(arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

double exp1(double x) {
	double suku = 1.0;
	double hasil = 1.0;
	for (int i = 1; i <= 100; i++) {
		suku*= x / i;
		hasil+= suku;
	}
	return hasil;
}


int main () {
	
	Data data[MAX_DATA];
	ifstream infile("dataset.csv");
	string header;
	char sep;
	int i = 0;
	//soal 1
	getline(infile, header);
	while(infile >> data[i].kode >> sep >> data[i].tahun >> sep >> data[i].harga >> sep >> data[i].iklan >> sep >> data[i].penjualan >> sep
	            >> data[i].stok) {
		i++;
	}
	infile.close();
	cout << "===================================\n";
	cout << "DATA PENJUALAN GUDANG" << endl;
	cout << "===================================\n";
	cout << "Jumlah data = " << i << endl;
	cout << "\n5 Data Pertama = " << endl;
	for (int j = 0; j < 5; j++) {
		cout << data[j].kode << " " << data[j].tahun << " " << data[j].harga << " " << data[j].iklan << " " << data[j].penjualan << " "
		     << data[j].stok << endl;
	}
	//soal 2
	double savePrice[i], saveIklan[i], savePenjualan[i], saveStok[i];
	for (int j = 0; j < i; j++) {
		savePrice[j] = data[j].harga;
		saveIklan[j] = data[j].iklan;
		savePenjualan[j] = data[j].penjualan;
		saveStok[j] = data[j].stok;
	}
	cout << "===================================\n";
	cout << "STATISTIK GLOBAL" << endl;
	cout << "===================================\n";
	cout << "Rata - rata Harga     = " << rataRata(savePrice, i) << endl;
	cout << "Rata - rata Iklan     = " << rataRata(saveIklan, i) << endl;
	cout << "Rata - rata Penjualan = " << rataRata(savePenjualan, i) << endl;
	cout << "Rata - rata Stok      = " << rataRata(saveStok, i) << endl;
	cout << endl << "Penjualan Minimum = " << min(savePenjualan,i) << endl;
	cout << "Penjualan Maksimum = " << maks(savePenjualan,i);
	//soal 3
	cout << "\n===================================\n";
	cout << "STATISTIK PER KODE GUDANG" << endl;
	cout << "===================================\n";
	int count = 0, countB = 0, countC = 0, countD = 0;
	double savePriceA[i], savePriceB[i], savePriceC[i], savePriceD[i];
	double saveIklanA[i], saveIklanB[i], saveIklanC[i], saveIklanD[i];
	double savePenjualanA[i], savePenjualanB[i], savePenjualanC[i], savePenjualanD[i];
	double saveStokA[i], saveStokB[i], saveStokC[i], saveStokD[i];
	for (int j = 0; j < i; j++) {
		if(data[j].kode == 'A') {
			savePriceA[count] = data[j].harga;
			saveIklanA[count] = data[j].iklan;
			savePenjualanA[count] = data[j].penjualan;
			saveStokA[count] = data[j].stok;
			count++;
		}
		if(data[j].kode == 'B') {
			countB++;
			savePriceB[countB] = data[j].harga;
			saveIklanB[countB] = data[j].iklan;
			savePenjualanB[countB] = data[j].penjualan;
			saveStokB[countB] = data[j].stok;
		}
		if(data[j].kode == 'C') {
			countC++;
			savePriceC[countC] = data[j].harga;
			saveIklanC[countC] = data[j].iklan;
			savePenjualanC[countC] = data[j].penjualan;
			saveStokC[countC] = data[j].stok;
		}
		if(data[j].kode == 'D') {
			countD++;
			savePriceD[countD] = data[j].harga;
			saveIklanD[countD] = data[j].iklan;
			savePenjualanD[countD] = data[j].penjualan;
			saveStokD[countD] = data[j].stok;
		}
	}
	cout << "Kode A" << endl;
	cout << "Jumlah Data           = " << count << endl;
	cout << "Rata - rata Harga     = " << rataRata(savePriceA,count) << endl;
	cout << "Rata - rata Penjualan = " << rataRata(savePenjualanA,count) << endl;
	cout << "Rata - rata Stok      = " << rataRata(saveStokA,count) << endl;
	cout << "Rata - rata Iklan     = " << rataRata(saveIklanA, count) << endl;
	cout << "---------------------------\n";
	cout << "Kode B" << endl;
	cout << "Jumlah Data           = " << countB << endl;
	cout << "Rata - rata Harga     = " << rataRata(savePriceB,countB) << endl;
	cout << "Rata - rata Penjualan = " << rataRata(savePenjualanB,countB) << endl;
	cout << "Rata - rata Stok      = " << rataRata(saveStokB,countB) << endl;
	cout << "Rata - rata Iklan     = " << rataRata(saveIklanB, countB) << endl;
	cout << "---------------------------\n";
	cout << "Kode C" << endl;
	cout << "Jumlah Data           = " << countC << endl;
	cout << "Rata - rata Harga     = " << rataRata(savePriceC,countC) << endl;
	cout << "Rata - rata Penjualan = " << rataRata(savePenjualanC,countC) << endl;
	cout << "Rata - rata Stok      = " << rataRata(saveStokC,countC) << endl;
	cout << "Rata - rata Iklan     = " << rataRata(saveIklanC, countC) << endl;
	cout << "---------------------------\n";
	cout << "Kode D" << endl;
	cout << "Jumlah Data           = " << countD << endl;
	cout << "Rata - rata Harga     = " << rataRata(savePriceD,countD) << endl;
	cout << "Rata - rata Penjualan = " << rataRata(savePenjualanD,countD) << endl;
	cout << "Rata - rata Stok      = " << rataRata(saveStokD,countD) << endl;
	cout << "Rata - rata Iklan     = " << rataRata(saveIklanD, countD) << endl;
	//Soal 4
	cout << "===================================\n";
	cout << "KATEGORI STOK" << endl;
	cout << "===================================\n";
	int jumlahA = 0, jumlahB = 0, jumlahC = 0;
	for (int j = 0; j < i; j++) {
		if(data[j].stok < 230) {
			jumlahA++;
		} else if(data[j].stok >= 230 && data[j].stok < 260) {
			jumlahB++;
		} else if(data[j].stok >= 260) {
			jumlahC++;
		}
	}
	cout << "Stok Rendah  = " << jumlahA << endl;
	cout << "Stok Sedang  = " << jumlahB << endl;
	cout << "Stok Tinggi  = " << jumlahC << endl;
	//soal 5	
	double mean = rataRata(savePenjualan,i);
	double std, atas = 0.0;
	for (int j = 0; j < i; j++) {
		atas+=(data[j].penjualan - mean) * (data[j].penjualan - mean);
	}
	std = sqrt(atas / i);
	double x1 = mean - std;
	double x2 = mean;
	double x3 = mean + std;
	//x1
	double pdf1, k;
	double awal = 1.0 / (std * sqrt(2*PHI));
	k = (pow(x1 - mean, 2)) / (2 * pow(std,2));
	pdf1 = awal * exp1(-k);
	//x2
	double pdf2, k1;
	k1 = (pow(x2 - mean, 2)) / (2 * pow(std,2));
	pdf2 = awal * exp1(-k1);
	//x3
	double pdf3, k2;
	k2 = (pow(x3 - mean, 2)) / (2 * pow(std,2));
	pdf3 = awal * exp1(-k2);
	cout << "===================================\n";
	cout << "DISTRIBUSI NORMAL PENJUALAN" << endl;
	cout << "===================================\n";
	cout << "Mean = " << mean << endl;
	cout << "Standart Deviasi = " << std << endl;
	cout << "PDF Normal" << endl;
	cout << "\nf(x1) = " << "f(" << x1 << ") = " << pdf1;
	cout << "\nf(x2) = " << "f(" << x2 << ") = " << pdf2;
	cout << "\nf(x3) = " << "f(" << x3 << ") = " << pdf3;
	
	
	
}
