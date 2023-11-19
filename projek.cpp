#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct pengelola {
    string username;
    string password;
};

struct buku {
    string id; // format AA01
    string judul;
    string genre;
    string penulis;
    string penerbit;
    string tahun;
    string status;
};

struct mahasiswa {
    string nim;
    string prodi;
    string status;
};

bool login(string username,string password){
    string u,p;
    ifstream login("admin.txt");
    while(login >> u >> p){
        if(username == u && password == p){
            return true;
        }
        else{
            return false;
        }
    }
};

void daftar(){
    cout << "daftar buku\n";
    ifstream daftar("buku.txt");

    struct buku i;

    while(
        getline(daftar, i.id)         &&
        getline(daftar, i.judul)      &&
        getline(daftar, i.genre)      &&
        getline(daftar, i.penulis)    &&
        getline(daftar, i.penerbit)   &&
        getline(daftar, i.tahun)      &&
        getline(daftar, i.status)
    ){
        cout << "ID\t\t: " << i.id << endl;
        cout << "Judul\t\t: " << i.judul << endl;
        cout << "Genre\t\t: " << i.genre << endl;
        cout << "Penulis\t\t: " << i.penulis << endl;
        cout << "Penerbit\t: " << i.penerbit << endl;
        cout << "Tahun Terbit\t\t: " << i.tahun << endl;
        cout << "Status\t\t: " << i.status << endl;
        cout << "=====================" << endl;
    }
}


void input(){
    struct buku c;
    struct buku b;
    cin.ignore();
    int count = 0;
    int count2 = 0;
    cout << "input buku\n";

    cout << "masukkan data buku\n";

    do{
        cout << "id\t\t: ";
        cin >> b.id;  
        
        if(b.id.length() > 4){
            count = 0;
        }
        else if(b.id.length() == 0){
            count = 0;
        }
        else{
            count = 1;
        }

        if(count == 1){
            ifstream cek("buku.txt");
            
            while(
                getline(cek, c.id)         &&
                getline(cek, c.judul)      &&
                getline(cek, c.genre)      &&
                getline(cek, c.penulis)    &&
                getline(cek, c.penerbit)   &&
                getline(cek, c.tahun)      &&
                getline(cek, c.status)
            ){
                if(c.id == b.id){
                    cout << "id sudah ada, isi dengan id yang lain!\n";
                    count2 = 0;
                    break;
                }
                else{
                    count2 = 1;
                    break;
                }
            }

            if(count2 == 1){
                break;
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }
    }while(true);
    
    cin.ignore();
    cout << "judul\t\t: ";
    getline(cin, b.judul);

    cout << "genre\t\t: ";
    getline(cin, b.genre);

    cout << "penulis\t\t: ";
    getline(cin, b.penulis);

    cout << "penerbit\t: ";
    getline(cin, b.penerbit);

    cout << "tahun\t\t: ";
    getline(cin, b.tahun);

    ofstream input("buku.txt", ios::app);
    
    if(input.is_open()){
        input << b.id << endl << b.judul << endl << b.genre << endl << b.penulis << endl << b.penerbit << endl << b.tahun << endl << "Siap" << endl;
        cout << "data buku berhasil di unggah\n";
        cout << "tekan tombol apapun untuk melanjutkan...\n";
        getch();
    }
    else{
        cout << "file tidak dapat dibuka\n";
    }

}

void edit(){

}

void pinjam(){

}
int main(){
    struct pengelola a; 
    
    do{
        cout << "username : ";
        cin >> a.username;

        cout << "password : ";
        cin >> a.password;
        if (login(a.username, a.password) == true){
            cout << "selamat datang " << a.username << " di program perpus merdeka";
            break;
        }
        else{
            cout << "username atau password yang anda masukkan salah, silahkan coba lagi";
            system("cls");
        }
    }while(true);

    int menu;
    do{
        system("cls");
        cout << "Menu\n[1]. Lihat Daftar Buku\n[2]. Input Buku\n[3]. Edit Buku\n[4]. Peminjaman\nPilih : ";
        cin >> menu;
        switch(menu){
            case 1 :
                daftar();
                break;
            case 2 :
                input();
                break;
            case 3 :
                edit();
                break;
            case 4 :
                pinjam();
                break;
            default :
                cout << "input tidak valid, silahkan memilih kembali";
                break;
        }
    }while(true);

    return 0;
}