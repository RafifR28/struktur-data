#include <iostream>

using namespace std;

struct peta
{
    int jarak; // pp
};

struct peta sales[7][7] = {0, 7, 0, 5, 0, 0, 0,
                           7, 0, 8, 9, 7, 0, 0,
                           0, 8, 0, 0, 5, 0, 0,
                           35, 34, 12, 0};
string kota[7] = {"Semarang", "Demak", "Pati", "Kudus", "Salatiga", "Kendal", "Ambarawa"};

int main()
{
    /*for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            cout << "Inputkan Jarak dari " << x << " Ke " << y << " : ";
            if (x == y)
            {
                sales[x][y].jarak = 0;
                cout << sales[x][y].jarak << endl;
            }
            else if (x > y)
            {
                sales[x][y].jarak = sales[y][x].jarak;
                cout << sales[x][y].jarak << endl;
            }
            else
                cin >> sales[x][y].jarak;
        }
    }*/
    // menampilkan data
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            cout << "Jarak dari kota " << kota[x] << " " << kota[y] << " adalah " << sales[x][y].jarak << endl;
        }
        cout << endl;
    }
    return 0;
}