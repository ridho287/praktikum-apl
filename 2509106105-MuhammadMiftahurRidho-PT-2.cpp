#include <iostream>
#include <iomanip>
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

User users[10]={
    {"ridho","105","admin"}
};

Event dataEvent[100]={
    {"Anfe ID","Kadrie Oening","03-05-2026",{"The Adams",150000}}
};

int jumlahUser=1;
int jumlahEvent=1;

bool validTanggal(string t){
    return (t.length()==10 && t[2]=='-' && t[5]=='-');
}

void registerUser(){

    cout<<"\n=== REGISTER USER ===\n";

    cout<<"Username : ";
    cin>>users[jumlahUser].username;

    cout<<"Password : ";
    cin>>users[jumlahUser].password;

    cout<<"Role (admin/pengguna) : ";
    cin>>users[jumlahUser].role;

    jumlahUser++;

    cout<<"Register berhasil!\n";
}

string loginUser(){

    string username,password;

    cout<<"Username : ";
    cin>>username;

    cout<<"Password : ";
    cin>>password;

    for(int i=0;i<jumlahUser;i++){
        if(users[i].username==username && users[i].password==password){
            return users[i].role;
        }
    }

    return "gagal";
}

void tambahEvent(){

    cout<<"\n=== Tambah Event ===\n";

    cin.ignore();

    cout<<"Nama Event : ";
    getline(cin,dataEvent[jumlahEvent].namaEvent);

    cout<<"Lokasi : ";
    getline(cin,dataEvent[jumlahEvent].lokasi);

    string tanggal;

    do{
        cout<<"Tanggal (dd-mm-yyyy) : ";
        cin>>tanggal;

        if(!validTanggal(tanggal))
            cout<<"Format salah!\n";

    }while(!validTanggal(tanggal));

    dataEvent[jumlahEvent].tanggal=tanggal;

    cin.ignore();

    cout<<"Guest Star : ";
    getline(cin,dataEvent[jumlahEvent].artis.guestStar);

    cout<<"Harga Tiket : ";
    cin>>dataEvent[jumlahEvent].artis.hargaTiket;

    jumlahEvent++;

    cout<<"Event berhasil ditambahkan!\n";
}

void lihatEvent(){

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
        <<setw(12)<<"Harga Tiket"<<endl;

    for(int i=0;i<jumlahEvent;i++){

        cout<<setw(5)<<i+1
            <<setw(20)<<dataEvent[i].namaEvent
            <<setw(20)<<dataEvent[i].lokasi
            <<setw(15)<<dataEvent[i].tanggal
            <<setw(20)<<dataEvent[i].artis.guestStar
            <<setw(12)<<dataEvent[i].artis.hargaTiket
            <<endl;
    }
}

void ubahEvent(){

    if(jumlahEvent==0){
        cout<<"Data kosong!\n";
        return;
    }

    int nomor;

    lihatEvent();

    cout<<"Pilih nomor data : ";
    cin>>nomor;

    if(nomor<1 || nomor>jumlahEvent){
        cout<<"Nomor tidak valid!\n";
        return;
    }

    nomor--;

    cin.ignore();

    cout<<"Nama Event baru : ";
    getline(cin,dataEvent[nomor].namaEvent);

    cout<<"Lokasi baru : ";
    getline(cin,dataEvent[nomor].lokasi);

    string tanggal;

    do{
        cout<<"Tanggal baru (dd-mm-yyyy) : ";
        cin>>tanggal;

        if(!validTanggal(tanggal))
            cout<<"Format salah!\n";

    }while(!validTanggal(tanggal));

    dataEvent[nomor].tanggal=tanggal;

    cin.ignore();

    cout<<"Guest Star baru : ";
    getline(cin,dataEvent[nomor].artis.guestStar);

    cout<<"Harga Tiket baru : ";
    cin>>dataEvent[nomor].artis.hargaTiket;

    cout<<"Data berhasil diubah!\n";
}

void hapusEvent(){

    if(jumlahEvent==0){
        cout<<"Data kosong!\n";
        return;
    }

    int nomor;

    lihatEvent();

    cout<<"Pilih nomor data : ";
    cin>>nomor;

    if(nomor<1 || nomor>jumlahEvent){
        cout<<"Nomor tidak valid!\n";
        return;
    }

    nomor--;

    for(int i=nomor;i<jumlahEvent-1;i++){
        dataEvent[i]=dataEvent[i+1];
    }

    jumlahEvent--;

    cout<<"Data berhasil dihapus!\n";
}

int main(){

    int pilihan;
    string role;
    int percobaan = 0;

    do{

        cout<<"\n=== MENU UTAMA ===\n";
        cout<<"1. Login\n";
        cout<<"2. Register\n";
        cout<<"3. Keluar\n";
        cout<<"Pilih : ";
        cin>>pilihan;

        if(pilihan==1){

            role = loginUser();

            if(role=="admin"){

                cout<<"Login Admin berhasil!\n";
                percobaan = 0;

                do{

                    cout<<"\n=== MENU ADMIN ===\n";
                    cout<<"1. Tambah Event\n";
                    cout<<"2. Lihat Event\n";
                    cout<<"3. Ubah Event\n";
                    cout<<"4. Hapus Event\n";
                    cout<<"5. Logout\n";
                    cout<<"Pilih : ";
                    cin>>pilihan;

                    switch(pilihan){
                        case 1: tambahEvent(); break;
                        case 2: lihatEvent(); break;
                        case 3: ubahEvent(); break;
                        case 4: hapusEvent(); break;
                    }

                }while(pilihan!=5);

            }

            else if(role=="pengguna"){

                cout<<"Login Pengguna berhasil!\n";
                percobaan = 0;

                do{

                    cout<<"\n=== MENU PENGGUNA ===\n";
                    cout<<"1. Lihat Event\n";
                    cout<<"2. Logout\n";
                    cout<<"Pilih : ";
                    cin>>pilihan;

                    if(pilihan==1)
                        lihatEvent();

                }while(pilihan!=2);

            }

            else{

                percobaan++;
                cout<<"Login gagal! Percobaan ke "<<percobaan<<" \n";

                if(percobaan==3){
                    cout<<"Anda gagal login 3 kali. Program berhenti.\n";
                    return 0;
                }

            }

        }

        else if(pilihan==2){
            registerUser();
        }

    }while(pilihan!=3);

    cout<<"Program selesai.\n";
}