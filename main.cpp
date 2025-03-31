#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ile;
clock_t start,stop;
double czas;

void sortowanie_babelkowe(int* tab, int n) {
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= 1; j--)
		{
			if (tab[j] > tab[j - 1])
			{
				swap(tab[j], tab[j - 1]);
			}
		}
	}
}

void quicksort(int* tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];
	int i, j;
	i = lewy;
	j = prawy;
	do {
		while (tablica[i] < v)i++;
		while (tablica[j] > v)j--;
		if (i <= j){
			swap(tablica[i], tablica[j]);
			i++; j--;
		}
	} while (i <= j);

	if (j > lewy)quicksort(tablica, lewy, j);
	if (i < prawy)quicksort(tablica, i, prawy);
}

int main() {

	cout << "Porownanie czasu sortowania v.1" << endl;
	
	cout << "Ile liczb w tablicy: ";
	cin >> ile;

	//dynamiczna alokacja [pamiêci
	int *tablica = new int[ile];
	int *tablica2 = new int[ile];
	

	srand(time(NULL));

	for (int i = 0; i < ile; i++) {
		tablica[i] = rand() % 1000000 + 1;
		//cout << tablica[i]<<" ";
	}
	
	for (int i = 0; i < ile; i++) {
		tablica2[i] = tablica[i];
		//cout << tablica[i]<<" ";
	}
	cout << "Sortowanie babelkowe. Prosze czekac!!!" << endl;

	start = clock();

	sortowanie_babelkowe(tablica, ile);
	
	stop = clock();

	czas = (double)(stop - start) / CLOCKS_PER_SEC;  
	
	cout << "Czas sortowania babelkowego: " << czas << " s" << endl;
	
	/*for (int i = 0; i < ile; i++) {
		cout << tablica2[i] << " ";
	}*/
	
	cout << endl << "Sortowanie quick. Prosze czekac!!!" << endl;
	start = clock();
	quicksort(tablica2, 0, ile-1);
	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "Czas sortowania quicksort: " << czas << " s" << endl;
	/*for (int i = 0; i < ile; i++) {
		cout << tablica2[i] << " ";
	}*/

	delete[]tablica;
	delete[]tablica2;
	
	return 0;
}