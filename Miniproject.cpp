#include <iostream>
using namespace std;

int jumlahPercobaan = 0;

int cekTebakan(int tebakan, int angkaRahasia)
{
    if (tebakan == angkaRahasia)
        return 1;
    else if (tebakan < angkaRahasia)
        return 0;
    else
        return -1;
}

int cekTebakan(int tebakan, int angkaRahasia, int batas)
{
    if (tebakan < 1 || tebakan > batas)
        return 2;

    return cekTebakan(tebakan, angkaRahasia);
}

void pilihLevel(int &angka, int &batas)
{
    int angkaRahasia[] = {7, 15, 219};
    int batasLevel[] = {20, 50, 500};
    int pilihan;

    while (true)
    {
        cout << "\n=== PILIH LEVEL ===\n";

        for (int i = 1; i <= 3; i++)
        {
            cout << i << ". Level " << i << endl;
        }

        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
            case 2:
            case 3:
                angka = angkaRahasia[pilihan - 1];
                batas = batasLevel[pilihan - 1];
                return;

            default:
                cout << "Pilihan tidak valid!\n";
                continue;
        }
    }
}

void permainan(int angka, int batas)
{
    int tebakan;
    int hasil;

    cout << "\nTebak angka dari 1 sampai "
         << batas << "!\n";

    while (true)
    {
        cout << "Masukkan tebakan: ";
        cin >> tebakan;

        jumlahPercobaan++;

        hasil = cekTebakan(tebakan, angka, batas);

        if (hasil == 2)
        {
            cout << "Angka harus berada dalam batas!\n";
            continue;
        }
        else if (hasil == 1)
        {
            break;
        }
        else if (hasil == 0)
        {
            cout << "Terlalu kecil!\n";
        }
        else
        {
            cout << "Terlalu besar!\n";
        }
    }
}

int main()
{
    int angka;
    int batas;

    cout << "========================\n";
    cout << "     GAME TEBAK ANGKA\n";
    cout << "========================\n";

    pilihLevel(angka, batas);

    permainan(angka, batas);

    cout << "\nTebakan benar! Kamu menang!\n";
    cout << "Jumlah percobaan: "
         << jumlahPercobaan << endl;

    cout << "Terima kasih sudah bermain!\n";

    return 0;
}
