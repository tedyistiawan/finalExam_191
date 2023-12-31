#include <iostream>
using namespace std;

struct Node {
	int noData;
	string name;
	Node* next;
};

Node* START = NULL;

void addNode() {
	int produk;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukkan Produk: ";
	cin >> produk;
	cout << "Masukkan Nama: ";
	cin >> nama;
	nodeBaru->noData = produk;
	nodeBaru->name = nama;

	if (START == NULL || produk <= START->noData) {
		if (START != NULL && produk == START->noData)
		{
			cout << "Produk sudah ada" << endl;
			return;
		}

		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (produk >= current->noData))
	{
		if (produk == current->noData)
		{
			cout << "Produk sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool searchNode(int Produk, Node* current, Node* previous) {
	previous = START;
	current = START;
	while (current != NULL && Produk > current->noData)
	{
		previous = current;
		current = current->next;
	}


	if (current == NULL)
	{
		return false;
	}
	else if (current->noData == Produk)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool listEmpty() {
	if (START == NULL)
		return true;
	else
		return false;

}

void traverse() {
	if (listEmpty()) {
		cout << "urutkan sesuai jumlah" << endl;
		system("cls");
		return;
	}

	else {
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << "Produk: " << currentNode->noData << ", Nama: " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void searchData() {
	if (listEmpty()) {
		cout << "Urutkan sesuai jumlah " << endl;
		system("cls");
		return;
	}

	else {
		int Produk;
		cout << "Masukkan Produk: ";
		cin >> Produk;
		Node* currentNode = START;
		while (currentNode != NULL) {
			if (currentNode->noData == Produk) {
				cout << "Produk: " << currentNode->noData << ", Nama: " << currentNode->name << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Urutkan sesuai jumlah" << endl;
	}
}

int main() {
	int pilihan;
	do
	{
		try
		{

			cout << "1. Nama Produk" << endl;
			cout << "2. jumlah Produk" << endl;
			cout << "3. Tampilkan Produk" << endl;
			cout << "4. Tipe Produk" << endl;
			cout << "Pilihan: ";
			cin >> pilihan;
			switch (pilihan)
			{
			case 1:
				addNode();
				cout << "Produk Berhasil Ditambahkan" << endl;
				system("cls");
				break;
			case 2:
				if (listEmpty())
				{
					cout << "Urutkan jumlah produk" << endl;
					system("cls");
					break;
				}
				int Nama;
				cout << "Tambahkan Produk : ";
				cin >> Nama;
				if ((Nama)) {
					cout << "Produk : " << Nama << "tampilkan semua produk " << endl;
					system("cls");
				}
				else
					cout << " Urutkan produk " << endl;
				break;
			case 3:
				traverse();
				break;
			case 4:
				searchData();
				break;	
			default:
				cout << "Manajemen Data produk" << endl;
				break;
			}
		}
		catch (exception e)
		{
			cout << "Urutkan berdasarkan Jumlah" << endl;
		}

	} while (pilihan != 4);
}

// 2. single linklist, ada beberapa yang di delete 
// 3. pencarian sebuah data dari yang terkecil hingga terbesar
		// di pindahkan dari ukuran yang terbesar sebelah kanan dan yang terkecil di urutkan dari sebelah kiri
// 4. alogaritma stack adalah situasi dimana programnya terjebak dalam kesalahan yang membuat tidak bisa di tampilkan hasilnya
      //misalnya variabelnya yang salah
// 5. a. 4 kedalaman 
      // b. inorder karena sturktur dan bentuknya seperti akar pohon 