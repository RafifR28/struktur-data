#include <iostream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;
struct dll
{
    string judul;
    dll *next;
    dll *prev;
};

dll *head = NULL;
dll *tail = NULL;

void addBelakang()
{ /// addBlkg()
    dll *baru;
    baru = new dll;
    cout << "Tambahkan tab browser: ";
    getline(cin, baru->judul);
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL)
    {
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data Masuk\n";
}

void insertTengah()
{ /// insertTgh()
    dll *baru, *bantu;
    int posisi, i;
    baru = new dll;
    cout << "Tambahkan tab browser: ";
    getline(cin, baru->judul);
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL)
    {
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        cout << "Masukkan posisi: ";
        cin >> posisi;
        if (posisi == 1)
        {
            baru->next = head;
            head->prev = baru;
            head = baru;
            tail->next = head;
            head->prev = tail;
        }
        else
        {
            bantu = head;
            for (i = 1; i < posisi - 1; i++)
            {
                bantu = bantu->next;
            }
            baru->next = bantu->next;
            baru->prev = bantu;
            bantu->next->prev = baru;
            bantu->next = baru;
        }
    }
    cout << "Data Masuk\n";
}


/*void insertTengah()
{
    dll *baru, *bantu;
    int dataCari;
    baru = new dll;
    cout << "Tambahkan tab browser: ";
    getline(cin, baru->judul);
    if (head == NULL)
    {
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        cout << "Masukkan tab browser setelah tab apa : ";
        getline(cin, dataCari);
        bantu = head;
        do
        {
            if (dataCari == bantu->judul)
            {
                baru->next = bantu->next;
                baru->prev = bantu;
                bantu->next->prev = baru;
                bantu->next = baru;
                break;
            } else
            {
                bantu->next = baru;
                baru->next = bantu->next->next;
                baru->prev = bantu;
                bantu = bantu->next;
            }
        } while (bantu != head);
    }
}*/

void hapusData(dll **head_ref, dll *del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
    {
        return;
    }
    /* If node to be deleted is head node */
    if (*head_ref == del)
    {
        *head_ref = del->next;
    }
    /* Change next only if node to be deleted is NOT
       the last node */
    if (del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    /* Change prev only if node to be deleted is NOT
       the first node */
    if (del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    /* Finally, free the memory occupied by del*/
    free(del);
}

/* Function to delete the node at the given position
   in the doubly linked list */
void hapusPosisi(dll **head_ref, int n)
{
    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || n <= 0)
        return;

    dll *current = *head_ref;
    int i;

    /* traverse up to the node at position 'n' from
       the beginning */
    for (i = 1; current != NULL && i < n; i++)
    {
        current = current->next;
    }
    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
    {
        return;
    }
    /* delete the node pointed to by 'current' */
    hapusData(head_ref, current);
    cout << "Data terhapus\n";
}

int cariData(dll **head_ref, string x)
{

    // Stores head Node
    dll *temp = *head_ref;

    // Stores position of the integer
    // in the doubly linked list
    int pos = 0;

    // Traverse the doubly linked list
    while (temp->judul != x && temp->next != NULL)
    {

        // Update pos
        pos++;

        // Update temp
        temp = temp->next;
    }

    // If the integer not present
    // in the doubly linked list
    if (temp->judul != x)
    {
        return -1;
    }
    // If the integer present in
    // the doubly linked list

    return (pos + 1);
}

void tampildepan()
{
    dll *bantu;
    bantu = head;
    /**
    do{
        cout << "| " << bantu -> judul << " [x]| ";
        bantu = bantu -> next;
    }while(bantu != head);
    */

    while (bantu != NULL)
    {
        cout << "| " << bantu->judul << " [x]| ";
        bantu = bantu->next;
        if (bantu == head)
        {
            break;
        }
    }
}

int main()
{
    /// krg tambah tengah after, sorting, hapus masi ngebug, dll yg tidak saya ketahui (bagus lg tambah swap si:v)
    int pilih;
    string dataCari;
    do
    {
        system("cls");
        cout << " +=======================================+" << endl;
        cout << " |          PROGRAM Tab Browser          |" << endl;
        cout << " |          Create by Kelompok 7         |" << endl;
        cout << " |=======================================|" << endl;
        cout << " | 1. Tambah Tab                         |" << endl;
        cout << " | 2. Tambah Tengah Tab                  |" << endl;
        cout << " | 3. Hapus Tab                          |" << endl;
        cout << " | 4. Tampil Data                        |" << endl;
        cout << " | 5. Keluar Program                     |" << endl;
        cout << " +=======================================+" << endl;
        cout << " Pilihan Anda [1-10]: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1)
        {
            system("cls");
            addBelakang();
        }
        if (pilih == 2)
        {
            system("cls");
            insertTengah();
        }
        if (pilih == 3)
        {
            system("cls");
            cout << "Mau hapus tab yang mana? ";
            getline(cin, dataCari);
            hapusPosisi(&head, cariData(&head, dataCari));
        }
        if (pilih == 4)
        {
            system("cls");
            tampildepan();
        }
        if (pilih == 5)
        {
            system("cls");
            return 0;
        }
        if (pilih == 10)
        {
            return 0;
        }
        _getch();
    } while (pilih != 11);
    return 0;
}

/** Web: https://www.geeksforgeeks.org/search-an-element-in-a-doubly-linked-list/
         https://www.geeksforgeeks.org/delete-doubly-linked-list-node-given-position/
*/
