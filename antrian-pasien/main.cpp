#include <iostream>
#include <conio.h>

using namespace std;

struct antrian
{
    char nama[30];
    char sex[20];
    int umur;
};
struct antrian pasien[100];
int datake=1;

void inqueue()
{
    cout << "Inputkan Nama Pasien       : ";
    cin >> pasien[datake].nama;
    cout << "Inputkan Jenis Kelamin     : ";
    cin >> pasien[datake].sex;
    cout << "Inputkan Umur Pasien       : ";
    cin >> pasien[datake].umur;
    datake++;
}

void tampildata()
{
    for(int x=1; x<datake; x++)
    {
        cout << x << " " << pasien[x].nama;
        cout << " " << pasien[x].sex;
        cout << " " << pasien[x].umur << endl;
    }
}


void maju(int zz)
{
    for(int x=zz; x<datake; x++)
    {
        pasien[x-1]=pasien[x];
    }
}
void dequeue()
{
    int ke;
    cout << "Anda Akan Dequeue Antrian Nomor : ";
    cin >> ke;
    cout << "Hasil Dequeue adalah : ";
    cout << pasien[ke].nama<< " " << pasien[ke].sex << " " << pasien[ke].umur << endl;
    cout << "Press Any Key to continue...";
    getch();
    maju(ke+1);
    cout << endl;
    datake--;
}

int main()
{
    int pilih;
    do
    {
        tampildata();
        cout << "1. Inqueque" << endl;
        cout << "2. Dequeue" << endl;
        cout << "9. Exit" << endl;
        cout << "Pilih Angka [1-9] : ";
        cin >> pilih;

        if(pilih=1){
            inqueue();
        }
        if(pilih=2){
            dequeue();
        }
    }while(pilih!=9);
    return 0;
}
