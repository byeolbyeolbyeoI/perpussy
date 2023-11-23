#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <locale>
#include <cctype>

using namespace std;

struct Menu {
    int menu;
    int count;
    int count2;
    int count3;
    int count4;
    int count5;
    int count6;
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
    string nama;
    string prodi;
    string status;
};

bool login(string username,string password){
    string u,p;
    ifstream login("admin.txt");
    while(getline(login, u) &&
         getline(login, p))
    {   
        if(username == u && password == p){
            return true;
        }
    }
    return false;
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
    
    I1.count = 0;
    I1.count2 = 0;
    I1.count3 = 0;
    I1.count4 = 0;
    I1.count5 = 0;
    I1.count6 = 0;

    cout << "input buku\n";

    cout << "masukkan data buku\n";
    
    do{
        I1.count = 0;
        I1.count2 = 0;
        I1.count3 = 0;
        I1.count4 = 0;
        I1.count5 = 0;
        I1.count6 = 0;

        cout << "id\t\t: ";
        cin >> I.id; 

        if(I.id.length() == 4){
            I1.count = 1;
        }
        else{
            cout << "id harus 4 digit tanpa spasi\n";
            I1.count = 0;   
        }

        if(I1.count == 1){
            for(int i = 0; i < 2; i++){
                if(isupper(I.id[i])){
                    I1.count5 = 1;
                }
                else{
                    cout << "format id haruslah KAPITAL KAPITAL ANGKA ANGKA\n";
                    I1.count = 0;
                    break;
                }
            }
        }
        if(I1.count5 == 1){
            for(int j = 2; j < 4; j++){
                if(isdigit(I.id[j])){
                    I1.count5 = 1;
                }
                else{
                    cout << "format id haruslah KAPITAL KAPITAL ANGKA ANGKA\n";
                    I1.count = 0;
                    break;
                }
            }
        }

        if(I1.count == 1){

            ifstream cek("buku.txt");
            if(cek.is_open()){

                while(  
                    getline(cek, Input.id)         &&
                    getline(cek, Input.judul)      &&
                    getline(cek, Input.genre)      &&
                    getline(cek, Input.penulis)    &&
                    getline(cek, Input.penerbit)   &&
                    getline(cek, Input.tahun)      &&
                    getline(cek, Input.status)
                ){
                    if(Input.id == I.id){
                        cout << "id sudah ada, isi dengan id yang lain!\n";
                        I1.count2 = 0;
                        break;

                    }
                    else{
                        cout << "id tersedia, silahkan lengkapi data yang lain\n";
                        I1.count2 = 1;
                        break;
                    }
                }
                
            }
            else{
                I1.count3 = 1;
                cin.ignore();
                cout << "judul\t\t: ";
                getline(cin, I.judul);

                cout << "genre\t\t: ";
                getline(cin, I.genre);

                cout << "penulis\t\t: ";
                getline(cin, I.penulis);

                cout << "penerbit\t: ";
                getline(cin, I.penerbit);

                I1.count4 = 0;

                do{
                    cout << "tahun terbit\t: ";
                    getline(cin, I.tahun);

                    if(I.tahun.length() == 4){
                        I1.count5 = 1;
                    }
                    else{
                        cout << "tahun terbit harus 4 digit tanpa spasi\n";
                        I1.count5 = 0;   
                    }

                    if(I1.count5 == 1){
                        for(char ch : I.tahun){
                            if(!isdigit(ch)){
                                cout << "tahun terbit haruslah angka\n";
                                I1.count4 = 0;
                                break;
                            }
                            else{
                                I1.count4 = 1;
                            }
                        }

                        if(I1.count4 == 1){
                            break;
                        }
                    }
                }while(true);

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
                break;
            }
        }
        else{
            continue;
        }

        if(I1.count2 == 1){
            break;
        }
        else if(I1.count2 = 0){
            continue;
        }

    }while(true);
    
    if(I1.count3 != 1){
        cin.ignore();
        cout << "judul\t\t: ";
        getline(cin, I.judul);

        cout << "genre\t\t: ";
        getline(cin, I.genre);

        cout << "penulis\t\t: ";
        getline(cin, I.penulis);

        cout << "penerbit\t: ";
        getline(cin, I.penerbit);

        I1.count4 = 0;

        do{
            cout << "tahun terbit\t: ";
            getline(cin, I.tahun);

            if(I.tahun.length() == 4){
                I1.count5 = 1;
            }
            else{
                cout << "tahun terbit harus 4 digit tanpa spasi\n";
                I1.count5 = 0;   
            }

            if(I1.count5 == 1){
                for(char ch : I.tahun){
                    if(!isdigit(ch)){
                        cout << "tahun terbit haruslah angka\n";
                        I1.count4 = 0;
                        break;
                    }
                    else{
                        I1.count4 = 1;
                    }
                }

                if(I1.count4 == 1){
                    break;
                }
            }

        }while(true);

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
    ofstream baru("buku2.txt", ios::app);

    //if file good
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
            do{
                /* cout << "[1]. ID" << endl;
                cout << "[2]. Judul" << endl;
                cout << "[3]. Genre" << endl;
                cout << "[4]. Penulis" << endl;
                cout << "[5]. Penerbit" << endl;
                cout << "[6]. Tahun Terbit" << endl;
                cout << "[7]. Status" << endl << endl;
                */

                cout << "ID\t\t: " << Edit.id << endl;
                cout << "Judul\t\t: " << Edit.judul << endl;
                cout << "Genre\t\t: " << Edit.genre << endl;
                cout << "Penulis\t\t: " << Edit.penulis << endl;
                cout << "Penerbit\t: " << Edit.penerbit << endl;
                cout << "Tahun Terbit\t: " << Edit.tahun << endl;
                cout << "Status\t\t: " << Edit.status << endl;

                cout << "pilih yang ingin anda edit (id dan status buku tidak dapat diedit) : \n";
                cin >> E1.menu;
                cin.ignore();
                switch(E1.menu){
                    case 1 :
                        cout << "id buku tidak dapat diedit, pilih opsi yang lain\n";
                        getch();
                        break;
                    case 2 :
                        cout << "masukkan judul yang baru : ";
                        getline(cin, E.judul);
                        Edit.judul = E.judul;
                        E1.count = 1;
                        break;
                    case 3 :
                        cout << "masukkan genre yang baru : ";
                        getline(cin, E.genre);
                        Edit.genre = E.genre;
                        E1.count = 1;
                        break;
                    case 4 :
                        cout << "masukkan penulis yang baru : ";
                        getline(cin, E.penulis);
                        Edit.penulis = E.penulis;
                        E1.count = 1;
                        break;
                    case 5 :
                        cout << "masukkan penerbit yang baru : ";
                        getline(cin, E.penerbit);
                        Edit.penerbit = E.penerbit;
                        E1.count = 1;
                        break;
                    case 6 :
                        cout << "masukkan tahun terbit yang baru : ";
                        getline(cin, E.tahun);
                        Edit.tahun = E.tahun;
                        E1.count = 1;
                        break;
                    case 7 :
                        cout << "status buku tidak dapat diedit, pilih opsi lain\n";
                        getch();
                        break;
                    default :
                        cout << "input tidak valid, pilih opsi lain\n";
                        break;   
                }
                if(E1.count == 1){
                    break;
                }
            }while(true);
        }
        
            baru << Edit.id << endl << Edit.judul << endl << Edit.genre << endl << Edit.penulis << endl << Edit.penerbit << endl << Edit.tahun << endl << "Siap" << endl;
    }

    edit.close();
    baru.close();

    remove("buku.txt");
    rename("buku2.txt", "buku.txt");
}

void pinjam(){
    struct Buku Pinjam;
    struct Buku P;
    struct Menu P1;
    struct Mahasiswa M;
    struct Mahasiswa Mahasiswa;

    P1.count = 0;
    P1.count2 = 0;
    ifstream pinjam("buku.txt");

    pinjam.seekg(0, ios::end);

    if(pinjam.tellg() < 1){
        cout << "kosong";
    }
    else{
        pinjam.clear();
        pinjam.seekg(0,ios::beg);
        string tes;

        do{
            pinjam.seekg(0,ios::beg);
            P.id.clear();
            P1.count = 0;
            P1.count2 = 0;
            remove("buku3.txt");
            cout << "masukkan id yang ingin dipinjam : ";
            cin >> P.id;
            
            while(
                getline(pinjam, Pinjam.id)         &&
                getline(pinjam, Pinjam.judul)      &&
                getline(pinjam, Pinjam.genre)      &&
                getline(pinjam, Pinjam.penulis)    &&
                getline(pinjam, Pinjam.penerbit)   &&
                getline(pinjam, Pinjam.tahun)      &&
                getline(pinjam, Pinjam.status)   
            )
            {
                if(P.id == Pinjam.id){
                    if(Pinjam.status == "Siap"){
                        cout << "Buku tersedia!\n";
                        do{
                            cout << "masukkan nim peminjam : ";
                            cin >> M.nim;

                            ifstream p("mahasiswa.txt");
                            while(
                                getline(p, Mahasiswa.nim)       &&
                                getline(p, Mahasiswa.nama)      &&
                                getline(p, Mahasiswa.prodi)     &&
                                getline(p, Mahasiswa.status)
                            )
                            {
                                if(M.nim == Mahasiswa.nim){
                                    string oleh = "Dipinjam oleh ";
                                    Pinjam.status = oleh.append(Mahasiswa.nama);
                                    cout << Pinjam.status << endl;
                                    P1.count = 1;
                                    break;
                                }
                            }
                            if(P1.count == 1){
                                break;
                            }
                        }while(true);
                    }
                    else{
                        cout << "Buku sudah dipinjam, pilih buku lain\n";
                        P1.count2 = 1;
                    }
                }
                // ga ada di loop pertama
                if(P1.count2 == 1){
                    break;
                }
                ofstream pinjam2("buku3.txt", ios::app);
                pinjam2 << Pinjam.id << endl << Pinjam.judul << endl << Pinjam.genre << endl << Pinjam.penulis << endl << Pinjam.penerbit << endl << Pinjam.tahun << endl << Pinjam.status << endl;
                
            }
            if(P1.count == 1){
                break;
            }
        }while(true);
        pinjam.close();

        remove("buku.txt");
        rename("buku3.txt", "buku.txt");
    }
}
void kembali(){
    struct Buku Kembali;
    struct Buku K;
    struct Menu K1;
    struct Mahasiswa M;
    struct Mahasiswa Mahasiswa;

    K1.count = 0;
    K1.count2 = 0;
    ifstream kembali("buku.txt");

    kembali.seekg(0, ios::end);

    if(kembali.tellg() < 1){
        cout << "kosong";
    }
    else{
        kembali.clear();
        kembali.seekg(0,ios::beg);
        
        do{
            K.id.clear();
            cin.ignore();
            cout << "masukkan id yang ingin dikembalikan : ";
            cin >> K.id;

            while(
                getline(kembali, Kembali.id)         &&
                getline(kembali, Kembali.judul)      &&
                getline(kembali, Kembali.genre)      &&
                getline(kembali, Kembali.penulis)    &&
                getline(kembali, Kembali.penerbit)   &&
                getline(kembali, Kembali.tahun)      &&
                getline(kembali, Kembali.status)   
            )
            {
                if(K.id == Kembali.id){
                    if(Kembali.status[0] == 'D'){
                        Kembali.status = "Siap";
                        
                        cout << "Buku berhasil dikembalikan\n";
                        K1.count = 1;
                    }
                    else if(Kembali.status == "Siap"){
                        cout << "Buku tidak sedang dipinjam\n";
                        K1.count2 = 1;
                    }
                }
                if(K1.count2 == 1){
                    break;
                }
                ofstream kembali2("buku3.txt", ios::app);
                kembali2 << Kembali.id << endl << Kembali.judul << endl << Kembali.genre << endl << Kembali.penulis << endl << Kembali.penerbit << endl << Kembali.tahun << endl << Kembali.status << endl;
                
            }
            if(K1.count2 == 1){
                break;
            }
            if(K1.count == 1){
                break;
            }
        }while(true);
        kembali.close();

        remove("buku.txt");
        rename("buku3.txt", "buku.txt");
    }
}

int main(){
    struct Menu M;
    struct Pengelola A; 
    M.count = 0;
    M.count2 = 0;
    M.count3 = 0;
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

    int menu; //debug
    int menu4;
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
                do{
                    cout << "Menu :\n[1]. Pinjam\n[2]. Kembalikan\n[3]. Menu\n";
                    cout << "Pilih : ";
                    cin >> menu4;
                    M.count3 = 0;
                    switch(menu4){
                        case 1:
                            pinjam();
                            break;
                        case 2:
                            kembali();
                            break;
                        case 3:
                            cout << "mengembalikan ke menu...";
                            M.count3 = 1;
                            getch();
                            break;
                        default:
                            cout << "input tidak valid, silahkan mengisi kembali";
                            break;    
                    }

                    if(M.count3 == 1){
                        break;
                    }
                }while(true);
                break;
            default :
                cout << "input tidak valid, silahkan memilih kembali";
                break;
        }
    }while(true);

    return 0;
}