#include <iostream>
using namespace std;

int main() {
    string nama, password;
    int kesempatan = 0;

    while (kesempatan < 3) {
        cout << "=============================\n";
        cout << "        LOGIN SISTEM         \n";
        cout << "=============================\n";
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if (nama == "ridho" && password == "105") {
            cout << "\nLogin Berhasil!\n";
            break;
        } else {
            kesempatan++;
            cout << "Login Gagal!" << kesempatan << "\n\n";
        }
    }

    if (kesempatan == 3) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    double jam;
    double menit;
    double detik;

    while (pilihan != 4) { 
        cout << "\n=================================\n";
        cout << "        MENU KONVERSI WAKTU      \n";
        cout << "=================================\n";
        cout << "1. Jam -> Menit dan Detik\n";
        cout << "2. Menit -> Jam dan Detik\n";
        cout << "3. Detik -> Jam dan Menit\n";
        cout << "4. Keluar\n";
        cout << "=================================\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        
    switch (pilihan) {

        case 1: 
            cout << "Masukkan jumlah Jam: ";
            cin >> jam;

            menit = jam * 60;
            detik = jam * 3600;

            cout << "Hasil: " << menit << " menit dan "
                 << detik << " detik\n";
            break;

        case 2:
            cout << "Masukkan jumlah Menit: ";
            cin >> menit;

            jam = menit / 60;
            detik = menit * 60;

            cout << "Hasil: " << jam << " jam dan "
                 << detik << " detik\n";
            break;

        case 3:
            cout << "Masukkan jumlah Detik: ";
            cin >> detik;

            jam = detik / 3600;
            menit = detik / 60;

            cout << "Hasil: " << jam << " jam dan "
                 << menit << " menit\n";
            break;

        case 4:
            cout << "Terima kasih. Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
    }
} 
    return 0;
}
