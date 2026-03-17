// // // // #include <iostream>
// // // // using namespace std;

// // // // / Fungsi ditaruh sebelum main
// // // // int kuadrat(int x) {
// // // // return x * x;
// // // // }

// // // // / Prosedur ditulis sebelum main
// // // // void sapa(string nama) {
// // // // cout < "Halo, " < nama < "!" < endl;
// // // // }

// // // // int main() {
// // // // sapa("Budi");
// // // // cout < "Hasil 5 kuadrat: " < kuadrat(5) < endl;
// // // // return 0;
// // // // }

// // // #include <iostream>
// // // using namespace std;

// // // / Definisikan prosedur atau fungsi sebelum fungsi main
// // // int kuadrat(int x);
// // // void sapa(string nama);

// // // int main() {
// // // sapa("Andi");
// // // cout < "Hasil 3 kuadrat: " < kuadrat(3) < endl;
// // // return 0;
// // // }
// // // / Penulisan fungsi setelah main
// // // int kuadrat(int x) {
// // // return x * x;
// // // }

// // // / Penulisan prosedur setelah main
// // // void sapa(string nama) {
// // // cout < "Halo, " < nama < "!" < endl;
// // // }

// // #include <iostream>
// // using namespace std;

// // / prosedur ini menerima nilai dari variable gajiSaya
// // void cobaUbahGaji(int gajiSaya) {
// // gajiSaya = 1000000000; / gaji di dalam prosedur
// // cout < "Gaji pas di dalam fungsi: " < gajiSaya < endl;
// // }

// // int main() {
// // int gajiSaya = 5000000; / gaji di dalam main

// // cout < "Gaji awal: " < gajiSaya < endl;

// // cobaUbahGaji(gajiSaya); / kirim ke fungsi

// // cout < "Gaji setelah fungsi dipanggil: " < gajiSaya < endl;

// // return 0;
// // }

// #include <iostream>
// using namespace std;

// / variabel global
// int skorTertinggi = 100;

// void cetakSkor() {
// / Fungsi ini akan membaca variabel global skorTertinggi
// cout < "Skor Fungsi: " < skorTertinggi < endl;
// }

// int main() {
// cout < "Skor : " < skorTertinggi < endl;

// / Panggil fungsi
// cetakSkor();

// return 0;
// }

// #include <iostream>
// using namespace std;
// void calonJuara() {
// // variabel lokal, cuma bisa dipakai di dalam fungsi ini
// string Team = "RRQ";
// cout << "Tim: " << Team << endl;
// }
// int main() {
// calonJuara(); // fungsi berjalan normal
// // namun jika kita coba akses Team di sini
// // cout << "Tim: " << Team << endl;
// // maka akan error karena Team tidak dikenal di sini
// return 0;
// }

// #include <iostream>
// using namespace std;

// / Variabel global bernilai 10
// int angka = 10;

// void cobaShadow() {
//     int angka = 500;

// cout < "Nilai angka dalam fungsi: " < angka < " (Ini yang
// lokal)" < endl;
// }

// int main() {
// cout < "Nilai angka di global: " < angka < " (Ini yang
// global)" < endl;

// cobaShadow(); / Panggil fungsi yang melakukan shadowing

// / setelah fungsi angka akan kembali menggunakan variabel global
// cout < "Nilai angka akhir: " < angka < " (Balik ke global)" <
// endl;

// return 0;
// }

#include <iostream>
using namespace std;
/ Fungsi menjumlahkan bilangan bulat
int tambah(int a, int b) {
return a + b;
}
/ Fungsi 2 menjumlahkan bilangan desimal
double tambah(double a, double b) {
return a + b;
}
int main() {
cout < "Hasil Int : " < tambah(5, 6) < endl;
cout < "Hasil Double : " < tambah(5.5, 6.6) < endl;
return 0;
}