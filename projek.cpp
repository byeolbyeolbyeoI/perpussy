#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct Menu {
    int menu;
    int count;
    int count2;
    int count3;
};

struct Pengelola {
    string username;
    string password;
};

struct Buku {
    string id; // format AA01
    string judul;
    string genre;
    string penulis;
    string penerbit;
    string tahun;
    string status;
};

struct Mahasiswa {
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

    struct Buku Daftar;

    while(
        getline(daftar, Daftar.id)         &&
        getline(daftar, Daftar.judul)      &&
        getline(daftar, Daftar.genre)      &&
        getline(daftar, Daftar.penulis)    &&
        getline(daftar, Daftar.penerbit)   &&
        getline(daftar, Daftar.tahun)      &&
        getline(daftar, Daftar.status)
    ){
        cout << "ID\t\t: " << Daftar.id << endl;
        cout << "Judul\t\t: " << Daftar.judul << endl;
        cout << "Genre\t\t: " << Daftar.genre << endl;
        cout << "Penulis\t\t: " << Daftar.penulis << endl;
        cout << "Penerbit\t: " << Daftar.penerbit << endl;
        cout << "Tahun Terbit\t: " << Daftar.tahun << endl;
        cout << "Status\t\t: " << Daftar.status << endl;
        cout << "=====================" << endl;
    }
    cout << "\ntekan tombol apapun untuk melanjutkan";
    getch();
    cin.ignore();
}


void input(){
    struct Buku Input;
    struct Buku I;
    struct Menu I1;
    cin.ignore();
    cout << "input buku\n";

    cout << "masukkan data buku\n";
    
    do{
        cout << "id\t\t: ";
        cin >> I.id; 
        
        if(I.id.length() > 4){
            cout << "id harus 4 digit tanpa spasi\n";
            I1.count = 0;
        }
        else{
            cout << "masuk sini";
            I1.count = 1;
        }

        if(I1.count == 1){
            ifstream cek("buku.txt");

            while(
                getline(cek, Input.id)         &&
                getline(cek, Input.judul)      &&
                getline(cek, Input.genre)      &&
                getline(cek, Input.penulis)    &&
                getline(cek, Input.penerbit)   &&
                getline(cek, Input.tahun)      &&
                getline(cek, Input.status)
            ){
                cout << "masuk sini ga";
                if(Input.id == I.id){
                    cout << "id sudah ada, isi dengan id yang lain!\n";
                    I1.count2 = 0;
                    break;
                }
                else{
                    cout << "masuk sini ga";
                    I1.count2 = 1;
                }
            }
        }
        else{
            continue;
        }

        if(I1.count2 == 1){
                break;
        }
        else{
            continue;
        }

    }while(true);
    
    cin.ignore();
    cout << "judul\t\t: ";
    getline(cin, I.judul);

    cout << "genre\t\t: ";
    getline(cin, I.genre);

    cout << "penulis\t\t: ";
    getline(cin, I.penulis);

    cout << "penerbit\t: ";
    getline(cin, I.penerbit);

    cout << "tahun\t\t: ";
    getline(cin, I.tahun);

    ofstream input("buku.txt", ios::app);
    
    if(input.is_open()){
        input << I.id << endl << I.judul << endl << I.genre << endl << I.penulis << endl << I.penerbit << endl << I.tahun << endl << "Siap" << endl;
        cout << "data buku berhasil di unggah\n";
        cout << "tekan tombol apapun untuk melanjutkan...\n";
        getch();
    }
    else{
        cout << "file tidak dapat dibuka\n";
    }

}

void edit(){
    struct Menu E1;
    struct Buku Edit;
    struct Buku E;
    string id;

    E1.count = 0;

    cout << "id buku yang ingin diedit : ";
    cin >> id;
    ifstream edit("buku.txt");

    while(
        getline(edit, Edit.id)         &&
        getline(edit, Edit.judul)      &&
        getline(edit, Edit.genre)      &&
        getline(edit, Edit.penulis)    &&
        getline(edit, Edit.penerbit)   &&
        getline(edit, Edit.tahun)      &&
        getline(edit, Edit.status)
    ){
        if(id == Edit.id){
            cout << "pilih yang ingin anda edit (id dan status buku tidak dapat diedit) : \n";
            cin >> E1.menu;
            cin.ignore();
            switch(E1.menu){
                case 1 :
                    cout << "id buku tidak dapat diedit, pilih opsi yang lain\n";
                    E1.count = 1;
                    break;
                case 2 :
                    cout << "masukkan judul yang baru : ";
                    getline(cin, E.judul);
                    Edit.judul = E.judul;
                    break;
                case 3 :
                    cout << "masukkan genre yang baru : ";
                    getline(cin, E.genre);
                    Edit.genre = E.genre;
                    break;
                case 4 :
                    cout << "masukkan penulis yang baru : ";
                    getline(cin, E.penulis);
                    Edit.penulis = E.penulis;
                    break;
                case 5 :
                    cout << "masukkan penerbit yang baru : ";
                    getline(cin, E.penerbit);
                    Edit.penerbit = E.penerbit;
                    break;
                case 6 :
                    cout << "masukkan tahun terbit yang baru : ";
                    getline(cin, E.tahun);
                    Edit.tahun = E.tahun;
                    break;
                case 7 :
                    cout << "status buku tidak dapat diedit, pilih opsi lain\n";
                    E1.count = 1;
                    break;
                default :
                    cout << "input tidak valid, pilih opsi lain\n";
                    E1.count = 1;
                    break;
            }
            ofstream baru("buku2.txt", ios::app);
            baru << Edit.id << endl << Edit.judul << endl << Edit.genre << endl << Edit.penulis << endl << Edit.penerbit << endl << Edit.tahun << endl << "Siap" << endl;
        }
    }
}

void pinjam(){

}
int main(){
    struct Pengelola A; 
    
    do{
        cout << "username : ";
        cin >> A.username;

        cout << "password : ";
        cin >> A.password;
        if (login(A.username, A.password) == true){
            cout << "selamat datang " << A.username << " di program perpus merdeka";
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