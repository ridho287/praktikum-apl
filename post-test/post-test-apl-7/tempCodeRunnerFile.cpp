#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include "ui.h"
using namespace std;

struct GuestStar{
    string guestStar;
    int hargaTiket;
};

struct Event{
    string namaEvent;
    string lokasi;
    string tanggal;
    GuestStar artis;
};

struct User{
    string username;
    string password;
    string role;
};

User users[10] = {
    {"ridho","105","admin"}
};

Event dataEvent[100] = {
    {"Anfe ID","Kadrie Oening","03-05-2026",{"The Adams",150000}}
};

int jumlahUser = 1;
int jumlahEvent = 1;

bool validTanggal(string t){
    return (t.length()==10 && t[2]=='-' && t[5]=='-');
}

string loginUser(string username,string password){
    for(int i=0;i<jumlahUser;i++){
        if(users[i].username==username && users[i].password==password){
            return users[i].role;
        }
    }
    return "gagal";
}

int hitungEvent(int n){
    if(n==0)
        return 0;
    return 1 + hitungEvent(n-1);
}

void bubbleSortNamaAsc(Event *dataEvent, int jumlahEvent){
    for(int i=0; i<jumlahEvent-1; i++){
        for(int j=0; j<jumlahEvent-i-1; j++){
            if((dataEvent+j)->namaEvent > (dataEvent+j+1)->namaEvent){
                Event temp = *(dataEvent+j);
                *(dataEvent+j) = *(dataEvent+j+1);
                *(dataEvent+j+1) = temp;
            }
        }
    }
    cout<<"Data berhasil diurutkan sesuai Nama Event (A-Z)!\n";
}

void selectionSortHargaDesc(Event *dataEvent, int jumlahEvent){
    for(int i=0; i<jumlahEvent-1; i++){
        int maxIdx = i;
        for(int j=i+1; j<jumlahEvent; j++){
            if((dataEvent+j)->artis.hargaTiket > (dataEvent+maxIdx)->artis.hargaTiket){
                maxIdx = j;
            }
        }
        Event temp = *(dataEvent+i);
        *(dataEvent+i) = *(dataEvent+maxIdx);
        *(dataEvent+maxIdx) = temp;
    }
    cout<<"Data berhasil diurutkan sesuai Harga Tiket (Termahal-Termurah)!\n";
}

void insertionSortLokasiAsc(Event *dataEvent, int jumlahEvent){
    for(int i=1; i<jumlahEvent; i++){
        Event key = *(dataEvent+i);
        int j = i-1;
        while(j>=0 && (dataEvent+j)->lokasi > key.lokasi){
            *(dataEvent+j+1) = *(dataEvent+j);
            j--;
        }
        *(dataEvent+j+1) = key;
    }
    cout<<"Data berhasil diurutkan sesuai Lokasi (A-Z)!\n";
}

void linearSearchHarga(Event *dataEvent, int jumlahEvent, int target){
    bool ditemukan = false;

    for(int i=0; i<jumlahEvent; i++){
        if((dataEvent+i)->artis.hargaTiket == target){

            if(!ditemukan){
                cout<<"\nData ditemukan:\n";
                cout<<left<<setw(5)<<"No"
                    <<setw(20)<<"Event"
                    <<setw(20)<<"Lokasi"
                    <<setw(15)<<"Tanggal"
                    <<setw(20)<<"Guest Star"
                    <<setw(12)<<"Harga"<<endl;
            }

            cout<<setw(5)<<i+1
                <<setw(20)<<(dataEvent+i)->namaEvent
                <<setw(20)<<(dataEvent+i)->lokasi
                <<setw(15)<<(dataEvent+i)->tanggal
                <<setw(20)<<(dataEvent+i)->artis.guestStar
                <<setw(12)<<(dataEvent+i)->artis.hargaTiket
                <<endl;

            ditemukan = true;
        }
    }

    if(!ditemukan){
        cout<<"Data tidak ditemukan!\n";
    }
}

int binarySearchNama(Event *dataEvent, int jumlahEvent, string target){
    int kiri = 0, kanan = jumlahEvent - 1;

    while(kiri <= kanan){
        int tengah = (kiri + kanan) / 2;

        if((dataEvent+tengah)->namaEvent == target){
            return tengah;
        }
        else if((dataEvent+tengah)->namaEvent < target){
            kiri = tengah + 1;
        }
        else{
            kanan = tengah - 1;
        }
    }
    return -1;
}

void registerUser(User *users, int *jumlahUser){
    cout<<"\n=== REGISTER USER ===\n";
    cout<<"Username : ";
    cin>> (users + *jumlahUser)->username;

    cout<<"Password : ";
    cin>> (users + *jumlahUser)->password;

    cout<<"Role (admin/pengguna) : ";
    cin>> (users + *jumlahUser)->role;

    (*jumlahUser)++;
    cout<<"Register berhasil!\n";
}

void tambahEvent(Event *dataEvent, int *jumlahEvent){
    cout<<"\n=== Tambah Event ===\n";

    cin.ignore();

    cout<<"Nama Event : ";
    getline(cin,(dataEvent + *jumlahEvent)->namaEvent);

    cout<<"Lokasi : ";
    getline(cin,(dataEvent + *jumlahEvent)->lokasi);

    string tanggal;
    while(true){
        try{
            cout<<"Tanggal (dd-mm-yyyy) : ";
            cin>>tanggal;

            if(!validTanggal(tanggal)){
                throw invalid_argument("Format tanggal salah!");
            }
            break;
        }catch(exception &e){
            cout<<"Error: "<<e.what()<<endl;
        }
    }

    (dataEvent + *jumlahEvent)->tanggal = tanggal;

    cin.ignore();

    cout<<"Guest Star : ";
    getline(cin,(dataEvent + *jumlahEvent)->artis.guestStar);

    while(true){
        try{
            cout<<"Harga Tiket : ";
            cin>>(dataEvent + *jumlahEvent)->artis.hargaTiket;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                throw invalid_argument("Input harus angka!");
            }

            if((dataEvent + *jumlahEvent)->artis.hargaTiket < 0){
                throw invalid_argument("Harga tidak boleh negatif!");
            }

            break;
        }catch(exception &e){
            cout<<"Error: "<<e.what()<<endl;
        }
    }

    (*jumlahEvent)++;
    cout<<"Event berhasil ditambahkan!\n";
}

void lihatEvent(Event *dataEvent, int jumlahEvent){
    if(jumlahEvent==0){
        cout<<"Data event kosong!\n";
        return;
    }

    cout<<"\n=== DATA EVENT KONSER ===\n";

    cout<<left<<setw(5)<<"No"
        <<setw(20)<<"Event"
        <<setw(20)<<"Lokasi"
        <<setw(15)<<"Tanggal"
        <<setw(20)<<"Guest Star"
        <<setw(12)<<"Harga"<<endl;

    for(int i=0;i<jumlahEvent;i++){
        cout<<setw(5)<<i+1
            <<setw(20)<<(dataEvent+i)->namaEvent
            <<setw(20)<<(dataEvent+i)->lokasi
            <<setw(15)<<(dataEvent+i)->tanggal
            <<setw(20)<<(dataEvent+i)->artis.guestStar
            <<setw(12)<<(dataEvent+i)->artis.hargaTiket
            <<endl;
    }
}

void ubahEvent(Event *dataEvent, int jumlahEvent){
    if(jumlahEvent==0){
        cout<<"Data kosong!\n";
        return;
    }

    int nomor;
    lihatEvent(dataEvent,jumlahEvent);

    try{
        cout<<"Pilih nomor data : ";
        cin>>nomor;

        if(nomor<1 || nomor>jumlahEvent){
            throw out_of_range("Nomor tidak valid!");
        }
    }catch(exception &e){
        cout<<"Error: "<<e.what()<<endl;
        return;
    }

    nomor--;

    cin.ignore();

    cout<<"Nama Event baru : ";
    getline(cin,(dataEvent+nomor)->namaEvent);

    cout<<"Lokasi baru : ";
    getline(cin,(dataEvent+nomor)->lokasi);

    string tanggal;
    while(true){
        try{
            cout<<"Tanggal baru (dd-mm-yyyy) : ";
            cin>>tanggal;

            if(!validTanggal(tanggal)){
                throw invalid_argument("Format tanggal salah!");
            }
            break;
        }catch(exception &e){
            cout<<"Error: "<<e.what()<<endl;
        }
    }

    (dataEvent+nomor)->tanggal = tanggal;

    cin.ignore();

    cout<<"Guest Star baru : ";
    getline(cin,(dataEvent+nomor)->artis.guestStar);

    while(true){
        try{
            cout<<"Harga baru : ";
            cin>>(dataEvent+nomor)->artis.hargaTiket;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                throw invalid_argument("Input harus angka!");
            }

            break;
        }catch(exception &e){
            cout<<"Error: "<<e.what()<<endl;
        }
    }

    cout<<"Data berhasil diubah!\n";
}

void hapusEvent(Event *dataEvent, int *jumlahEvent){
    if(*jumlahEvent==0){
        cout<<"Data kosong!\n";
        return;
    }

    int nomor;
    lihatEvent(dataEvent,*jumlahEvent);

    try{
        cout<<"Pilih nomor : ";
        cin>>nomor;

        if(nomor<1 || nomor>*jumlahEvent){
            throw out_of_range("Nomor tidak valid!");
        }
    }catch(exception &e){
        cout<<"Error: "<<e.what()<<endl;
        return;
    }

    nomor--;

    for(int i=nomor;i<(*jumlahEvent)-1;i++){
        *(dataEvent+i) = *(dataEvent+i+1);
    }

    (*jumlahEvent)--;
    cout<<"Data berhasil dihapus!\n";
}

void pause(){
    cout<<"\nTekan ENTER untuk lanjut...";
    cin.ignore(1000, '\n');
    cin.get();
}

int main(){

    int pilihan;
    string role;
    int percobaan=0;

    do{
        cout<<"\n=== MENU UTAMA ===\n";
        cout<<"1. Login\n";
        cout<<"2. Register\n";
        cout<<"3. Keluar\n";
        cout<<"Pilih : ";

        try{
            cin>>pilihan;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                throw invalid_argument("Input harus angka!");
            }
        }catch(exception &e){
            cout<<"Error: "<<e.what()<<endl;
            continue;
        }

        if(pilihan==1){

            string username,password;

            cout<<"Username : ";
            cin>>username;

            cout<<"Password : ";
            cin>>password;

            try{
                role = loginUser(username,password);

                if(role=="gagal"){
                    throw runtime_error("Username atau password salah!");
                }

            }catch(exception &e){
                percobaan++;
                cout<<"Error: "<<e.what()<<endl;
                cout<<"Percobaan ke "<<percobaan<<endl;

                if(percobaan==3){
                    cout<<"Anda gagal login 3 kali. Program berhenti.\n";
                    return 0;
                }
                continue;
            }

            if(role=="admin"){

                cout<<"Login Admin berhasil!\n";
                percobaan=0;

                do{

                    clear();
                    header("MENU ADMIN");

                    cout<<"[1]  Tambah Event\n";
                    cout<<"[2]  Lihat Event\n";
                    cout<<"[3]  Ubah Event\n";
                    cout<<"[4]  Hapus Event\n";
                    cout<<"----------------------------------------\n";
                    cout<<"[5]  Total Event (Rekursif)\n";
                    cout<<"----------------------------------------\n";
                    cout<<"[6]  Urutkan Nama Event (A-Z)\n";
                    cout<<"[7]  Urutkan Harga (Tertinggi)\n";
                    cout<<"[8]  Urutkan Lokasi (A-Z)\n";
                    cout<<"----------------------------------------\n";
                    cout<<"[9]  Cari Berdasarkan Harga\n";
                    cout<<"[10] Cari Berdasarkan Nama\n";
                    cout<<"----------------------------------------\n";
                    cout<<"[11] Logout\n";
                    cout<<"========================================\n";
                    cout<<"Pilih menu : ";

                    try{
                        cin>>pilihan;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000,'\n');
                            throw invalid_argument("Input harus angka!");
                        }
                    }catch(exception &e){
                        cout<<"Error: "<<e.what()<<endl;
                        continue;
                    }

                    switch(pilihan){

                        case 1: 
                            tambahEvent(dataEvent, &jumlahEvent); 
                            pause(); 
                            break;

                        case 2: 
                            lihatEvent(dataEvent, jumlahEvent); 
                            pause();   // <-- INI PENTING
                            break;

                        case 3: 
                            ubahEvent(dataEvent, jumlahEvent); 
                            pause(); 
                            break;

                        case 4: 
                            hapusEvent(dataEvent, &jumlahEvent); 
                            pause(); 
                            break;

                        case 5: 
                            cout<<"Total Event : "<<hitungEvent(jumlahEvent)<<endl; 
                            pause(); 
                            break;

                        case 6: 
                            bubbleSortNamaAsc(dataEvent, jumlahEvent); 
                            lihatEvent(dataEvent, jumlahEvent); 
                            pause(); 
                            break;

                        case 7: 
                            selectionSortHargaDesc(dataEvent, jumlahEvent); 
                            lihatEvent(dataEvent, jumlahEvent); 
                            pause(); 
                            break;

                        case 8: 
                            insertionSortLokasiAsc(dataEvent, jumlahEvent); 
                            lihatEvent(dataEvent, jumlahEvent); 
                            pause(); 
                            break;

                        case 9:{
                            int h;
                            cout<<"Masukkan harga tiket: ";
                            cin>>h;
                            linearSearchHarga(dataEvent, jumlahEvent, h);
                            pause();
                            break;
                        }

                        case 10:{
                            string nama;
                            cin.ignore();
                            cout<<"Masukkan nama event: ";
                            getline(cin, nama);

                            bubbleSortNamaAsc(dataEvent, jumlahEvent);

                            int idx = binarySearchNama(dataEvent, jumlahEvent, nama);

                            if(idx != -1){
                                cout<<"\nData ditemukan:\n";
                                cout<<setw(5)<<idx+1
                                    <<setw(20)<<(dataEvent+idx)->namaEvent
                                    <<setw(20)<<(dataEvent+idx)->lokasi
                                    <<setw(15)<<(dataEvent+idx)->tanggal
                                    <<setw(20)<<(dataEvent+idx)->artis.guestStar
                                    <<setw(12)<<(dataEvent+idx)->artis.hargaTiket
                                    <<endl;
                            } else {
                                cout<<"Data tidak ditemukan!\n";
                            }

                            pause();
                            break;
                        }
                    }

                }while(pilihan!=11);

            }

            else if(role=="pengguna"){

                cout<<"Login Pengguna berhasil!\n";

                do{
                    cout<<"\n=== MENU PENGGUNA ===\n";
                    cout<<"1. Lihat Event\n";
                    cout<<"2. Logout\n";
                    cout<<"Pilih : ";

                    try{
                        cin>>pilihan;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000,'\n');
                            throw invalid_argument("Input harus angka!");
                        }
                    }catch(exception &e){
                        cout<<"Error: "<<e.what()<<endl;
                        continue;
                    }

                    if(pilihan==1)
                        lihatEvent(dataEvent, jumlahEvent);

                }while(pilihan!=2);

            }

        }

        else if(pilihan==2){
            registerUser(users, &jumlahUser);
        }

    }while(pilihan!=3);

    cout<<"Program selesai\n";
}