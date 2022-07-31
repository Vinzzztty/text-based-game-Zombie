#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define max 4
using namespace std;

// Struct MC
struct base_stats_mc
{
    string nama;
    int hp = 100;
    int attack_pistol = 20;
    int attack_machine_gun = 50;
} mc;

// Struct Regular Zombie
struct regular_zombi
{
    int hp = 60;
    int damage = 10;
} regularZombi;

struct segerombol_zombi {
    int hp = 100;
    int damage = 15;
}segerombolZombi1, segerombolZombi2, segerombolZombi3, segerombolZombi4;

// Struct Special Zombie
struct special_zombi
{
    int hp = 150;
    int damage = 40;
} specialZombi;

// struct Monster Zombie
struct monster_zombi
{
    int hp = 200;
    int damage = 20;

} MonsterZombi;

// Struct Array Anggota Kelompok
struct namaAnggota
{
    string namaMhs[4]; //{"Hisam Saputra ", "Kevin Arnandes", "Dika Isnaida  ", "Arya Sakti N. "};
    string nimMhs[4];  //{"21.11.4321", "21.11.4306", "21.11.4292", "21.11.4278"};
} team;

string cari;
string antrianZombie[max];

//Function Declare
void displayStats_mc();
void displayStats_regularZombi();
void displayStats_specialZombi();
void battleMenu();
void cerita1();
void cerita2_1();
void cerita3();

//----------------- QUEUE ------------------
//array queue
int head = 0, tail = 0;

//isFull
bool isFull() {
    if(tail == max) {
        return true;
    } else {
        return false;
    }
}

//isEmpty
bool isEmpty() {
    if(tail == 0) {
        return true;
    } else {
        return false;
    }
}

// enqueue
void enqueue(string data) {
    if(isFull() ) {
        cout<<"Ada " << max << " zombie menyerang!" <<endl;
    } else {
        //cek apakah antrian kosong atau tidak
        if(isEmpty() ) {
            antrianZombie[0] = data;
            head++;
            tail++;
        } else {
            //Data ada tapi tidak kosong
            antrianZombie[tail] = data;
            tail++;
        }
    }
}

void isClear() {
    antrianZombie[0] = "";
    antrianZombie[1] = "";
    antrianZombie[2] = "";
    antrianZombie[3] = "";
    cout<< "\t" << mc.nama <<" Telah Menghabisi Para Zombie!" <<endl;
    cout<<"Dia Melihat sekitar...... " <<endl;
    system("pause");
    cout<<endl;
}

//display
void viewDisplay() {
    cout<<"Segerombolan ZOMBIE: " <<endl;
    if(isEmpty() ) {
        cout<<"Semua Zombie telah dihabisi" <<endl;
        system("pause");
        
    } else if(antrianZombie[0] == "" ) {
        cout<<"Telah Berhasil Dihabisi" <<endl;
    } 
    else {
        for(int i=0; i<max; i++) {
            //cek apakah ruang kosong atau tidak
            if(antrianZombie[i] != "") {
                //kalau tidak kosong
                cout<<">>" <<" " <<antrianZombie[i] <<endl;
            }
        }
    }
    cout<<endl;
}
// ------------- END QUEUE -------------

// Function Deklrasi
void BattleDisplayA();
void BattleDisplayB();
void BattleDisplayC();
void BattleDisplayD();
void BattleDisplay2();
void BattleA();
void BattleB();
void BattleC();
void BattleD();
void Battle2();
void itemDrop(string data);
void start();
void credit();

int main()
{
    int temp = 0;
    int pil;

    enqueue("Zombie 1"); enqueue("Zombie 2"); enqueue("Zombie 3"); enqueue("Zombie 4");

    menu:
    system("cls");
    cout << "\t\t+++++++++++   MENU GAME   +++++++++++\n";
    cout << "\t\t|    1. START                       |\n";
    cout << "\t\t|    2. CREDIT                      |\n";
    cout << "\t\t|    3. EXIT                        |\n";
    cout << "\t\t+++++++++++++++++++++++++++++++++++++\n";
    cout << "\t\t|    Masukkan Pilihan: ";
    cin >> pil;

    switch (pil)
    {
    case 1:
        start();
        break;
    case 2:
        credit();
        goto menu;
        break;
    case 3:
        system("cls");
        cout << "\n\t\t>> SAMPAI JUMPA!!\n";
        break;
    default:
        cout << "Pilihan Yang Anda Masukkan Tidak Ada!\n";
        system("pause");
        goto menu;
        break;
    }
}

void itemDrop(string data)
{
    string item[max] = {"zombieHearts", "healItem", "antiBodi", "Boom"};

    int ketemu;

    ketemu = 0;
    for (int i = 0; i < max; i++)
    {
        if (item[i] == data)
        {
            ketemu = 1;
            i = max;
        }
    }
    if (ketemu == 0)
    {
        cout << "Drop item yang dicari tidak ditemukan!!\n";
    }
    else
    {
        cout << "Item " << data << " berhasil ditemukan!\n";
    }
}

//------------ BATTLE DISPLAY 2---------------
void BattleDisplayA()
{

    system("cls");
    cout << "# " << mc.nama;
    cout << "\t\t# "
         << "REGULAR ZOMBIE 1" << endl;
    cout << "| "
         << "Nyawa  : " << mc.hp;
    cout << "\t| "
         << "Nyawa  : " << segerombolZombi1.hp << endl;
    cout << "| "
         << "Damage : " << mc.attack_machine_gun;
    cout << "\t| "
         << "Damage : " << segerombolZombi1.damage << endl;
    cout << "============================================================================" << endl;
}
void BattleDisplayB()
{

    system("cls");
    cout << "# " << mc.nama;
    cout << "\t\t# "
         << "REGULAR ZOMBIE 2" << endl;
    cout << "| "
         << "Nyawa  : " << mc.hp;
    cout << "\t| "
         << "Nyawa  : " << segerombolZombi2.hp << endl;
    cout << "| "
         << "Damage : " << mc.attack_machine_gun;
    cout << "\t| "
         << "Damage : " << segerombolZombi2.damage << endl;
    cout << "============================================================================" << endl;
}
void BattleDisplayC()
{

    system("cls");
    cout << "# " << mc.nama;
    cout << "\t\t# "
         << "REGULAR ZOMBIE 3" << endl;
    cout << "| "
         << "Nyawa  : " << mc.hp;
    cout << "\t| "
         << "Nyawa  : " << segerombolZombi3.hp << endl;
    cout << "| "
         << "Damage : " << mc.attack_machine_gun;
    cout << "\t| "
         << "Damage : " << segerombolZombi3.damage << endl;
    cout << "============================================================================" << endl;
}
void BattleDisplayD()
{

    system("cls");
    cout << "# " << mc.nama;
    cout << "\t\t# "
         << "REGULAR ZOMBIE 4" << endl;
    cout << "| "
         << "Nyawa  : " << mc.hp;
    cout << "\t| "
         << "Nyawa  : " << segerombolZombi4.hp << endl;
    cout << "| "
         << "Damage : " << mc.attack_machine_gun;
    cout << "\t| "
         << "Damage : " << segerombolZombi4.damage << endl;
    cout << "============================================================================" << endl;
}

//--------- BATTLE DISPLAY 3 ------------
void BattleDisplay2()
{

    system("cls");
    cout << "# " << mc.nama;
    cout << "\t\t# "
         << "MONSTER ZOMBIE" << endl;
    cout << "| "
         << "Nyawa  : " << mc.hp;
    cout << "\t| "
         << "Nyawa  : " << MonsterZombi.hp << endl;
    cout << "| "
         << "Damage : " << mc.attack_machine_gun;
    cout << "\t| "
         << "Damage : " << MonsterZombi.damage << endl;
    cout << "============================================================================" << endl;
}

//-------- Battle 2 ------------
void BattleA()
{
    BattleDisplayA();
    int PilBa;

    if (mc.hp >= 1 && segerombolZombi1.hp >= 1)
    {
        cout << "1. Attack" << endl;
        cout << "2. Block" << endl;
        cout << "3. Heal" << endl;
        cout << "Pilih aksi anda ";
        cin >> PilBa;
        if (PilBa == 1)
        {
            cout << "ATTACKING!!!";
            segerombolZombi1.hp = segerombolZombi1.hp - mc.attack_machine_gun;
            cout << "Berhasil menyerang zombi" << endl;
            system("pause");
            BattleDisplayA();
            if (segerombolZombi1.hp >= 10)
            {
                cout << "ZOMBI ATTACK!!!" << endl;
                mc.hp = mc.hp - segerombolZombi1.damage;
                if (mc.hp <= 0)
                {
                    mc.hp = 0;
                }
            }
            else if (segerombolZombi1.hp <= 0)
            {
                segerombolZombi1.hp = 0;
            }
            system("pause");
            BattleA();
        }
        else if (PilBa == 2)
        {
            cout << "BLOCKING!!!" << endl;
            int Block = rand() % 40 + 1;
            if (Block >= 20)
            {
                cout << "Kamu berhasil Block" << endl;
                system("pause");
                BattleA();
            }
            else
            {
                cout << "Kamu Gagal Block" << endl;
                mc.hp = mc.hp - segerombolZombi1.damage;
                system("pause");
                BattleA();
            }
        }
        else if (PilBa == 3)
        {
            cout << "HEALING !!!" << endl;
            if (mc.hp <= 30)
            {
                mc.hp = mc.hp + 5;
                cout << "Berhasil Heal 5 HP" << endl;
                system("pause");
                BattleA();
            }
            else
            {
                cout << "Kamu tidak bisa healing karena nyawa mu masih banyak" << endl;
                system("pause");
                BattleA();
            }
        }
        else
        {
            cout << "\n";
            cout << "Pilihan tidak ada silahkan pilih lagi" << endl;
            system("pause");
            BattleA();
        }
    }
    else if (mc.hp <= 1)
    {
        cout << "KAMU KEHILANGAN BANYAK DARAH AKIBAT SERANGAN DARI ZOMBIE!!!" << endl;
        cout << "KAMU MULAI KEHILANGAN KESADARAN" << endl;
        cout << "PARA ZOMBIE PUN MULAI BERKUMPUL\nDan MEREKA MULAI MEMAKAN BAGIAN TUBUHMU" << endl;
        cout << "SELESAI MEREKA MEMAKANMU\nMEREKA MULAI BERKUMPUL UNTUK MERAYAKAN KEMATIANMU" << endl;
        cout << "PARA ZOMBIE MULAI MELAKUKAN INVANSI KE PENJURU DUNIA!!" << endl;
        cout << mc.nama << "Telah Mati,\n\t\tZOMBIE BERHASIL MENGUASAI DUNIA!!\n";
        system("pause");
        credit();
    }
    else if (segerombolZombi1.hp <= 1)
    {
        cout<<"Zombie 1 Berhasil diKalahkan!" <<endl;
        system("pause");
        BattleB();
    }
}
void BattleB()
{
    BattleDisplayB();
    int PilBa;

    if (mc.hp >= 1 && segerombolZombi2.hp >= 1)
    {
        cout << "1. Attack" << endl;
        cout << "2. Block" << endl;
        cout << "3. Heal" << endl;
        cout << "Pilih aksi anda ";
        cin >> PilBa;
        if (PilBa == 1)
        {
            cout << "ATTACKING!!!";
            segerombolZombi2.hp = segerombolZombi2.hp - mc.attack_machine_gun;
            cout << "Berhasil menyerang zombi" << endl;
            system("pause");
            BattleDisplayB();
            if (segerombolZombi2.hp >= 10)
            {
                cout << "ZOMBI ATTACK!!!" << endl;
                mc.hp = mc.hp - segerombolZombi2.damage;
                if (mc.hp <= 0)
                {
                    mc.hp = 0;
                }
            }
            else if (segerombolZombi2.hp <= 0)
            {
                segerombolZombi2.hp = 0;
            }
            system("pause");
            BattleB();
        }
        else if (PilBa == 2)
        {
            cout << "BLOCKING!!!" << endl;
            int Block = rand() % 40 + 1;
            if (Block >= 20)
            {
                cout << "Kamu berhasil Block" << endl;
                system("pause");
                BattleB();
            }
            else
            {
                cout << "Kamu Gagal Block" << endl;
                mc.hp = mc.hp - segerombolZombi2.damage;
                system("pause");
                BattleB();
            }
        }
        else if (PilBa == 3)
        {
            cout << "HEALING !!!" << endl;
            if (mc.hp <= 30)
            {
                mc.hp = mc.hp + 5;
                cout << "Berhasil Heal 5 HP" << endl;
                system("pause");
                BattleB();
            }
            else
            {
                cout << "Kamu tidak bisa healing karena nyawa mu masih banyak" << endl;
                system("pause");
                BattleB();
            }
        }
        else
        {
            cout << "\n";
            cout << "Pilihan tidak ada silahkan pilih lagi" << endl;
            system("pause");
            BattleB();
        }
    }
    else if (mc.hp <= 1)
    {
        cout << "KAMU KEHILANGAN BANYAK DARAH AKIBAT SERANGAN DARI ZOMBIE!!!" << endl;
        cout << "KAMU MULAI KEHILANGAN KESADARAN" << endl;
        cout << "PARA ZOMBIE PUN MULAI BERKUMPUL\nDan MEREKA MULAI MEMAKAN BAGIAN TUBUHMU" << endl;
        cout << "SELESAI MEREKA MEMAKANMU\nMEREKA MULAI BERKUMPUL UNTUK MERAYAKAN KEMATIANMU" << endl;
        cout << "PARA ZOMBIE MULAI MELAKUKAN INVANSI KE PENJURU DUNIA!!" << endl;
        cout << mc.nama << "Telah Mati,\n\t\tZOMBIE BERHASIL MENGUASAI DUNIA!!\n";
        system("pause");
        credit();
    }
    else if (segerombolZombi2.hp <= 1)
    {
        cout<<"Zombie 2 Berhasil diKalahkan!" <<endl;
        system("pause");
        BattleC();
    }
}
void BattleC()
{
    BattleDisplayC();
    int PilBa;

    if (mc.hp >= 1 && segerombolZombi3.hp >= 1)
    {
        cout << "1. Attack" << endl;
        cout << "2. Block" << endl;
        cout << "3. Heal" << endl;
        cout << "Pilih aksi anda ";
        cin >> PilBa;
        if (PilBa == 1)
        {
            cout << "ATTACKING!!!";
            segerombolZombi3.hp = segerombolZombi3.hp - mc.attack_machine_gun;
            cout << "Berhasil menyerang zombi" << endl;
            system("pause");
            BattleDisplayC();
            if (segerombolZombi3.hp >= 10)
            {
                cout << "ZOMBI ATTACK!!!" << endl;
                mc.hp = mc.hp - segerombolZombi3.damage;
                if (mc.hp <= 0)
                {
                    mc.hp = 0;
                }
            }
            else if (segerombolZombi3.hp <= 0)
            {
                segerombolZombi3.hp = 0;
            }
            system("pause");
            BattleC();
        }
        else if (PilBa == 2)
        {
            cout << "BLOCKING!!!" << endl;
            int Block = rand() % 40 + 1;
            if (Block >= 20)
            {
                cout << "Kamu berhasil Block" << endl;
                system("pause");
                BattleC();
            }
            else
            {
                cout << "Kamu Gagal Block" << endl;
                mc.hp = mc.hp - segerombolZombi3.damage;
                system("pause");
                BattleC();
            }
        }
        else if (PilBa == 3)
        {
            cout << "HEALING !!!" << endl;
            if (mc.hp <= 30)
            {
                mc.hp = mc.hp + 5;
                cout << "Berhasil Heal 5 HP" << endl;
                system("pause");
                BattleC();
            }
            else
            {
                cout << "Kamu tidak bisa healing karena nyawa mu masih banyak" << endl;
                system("pause");
                BattleC();
            }
        }
        else
        {
            cout << "\n";
            cout << "Pilihan tidak ada silahkan pilih lagi" << endl;
            system("pause");
            BattleC();
        }
    }
    else if (mc.hp <= 1)
    {
        cout << "KAMU KEHILANGAN BANYAK DARAH AKIBAT SERANGAN DARI ZOMBIE!!!" << endl;
        cout << "KAMU MULAI KEHILANGAN KESADARAN" << endl;
        cout << "PARA ZOMBIE PUN MULAI BERKUMPUL\nDan MEREKA MULAI MEMAKAN BAGIAN TUBUHMU" << endl;
        cout << "SELESAI MEREKA MEMAKANMU\nMEREKA MULAI BERKUMPUL UNTUK MERAYAKAN KEMATIANMU" << endl;
        cout << "PARA ZOMBIE MULAI MELAKUKAN INVANSI KE PENJURU DUNIA!!" << endl;
        cout << mc.nama << "Telah Mati,\n\t\tZOMBIE BERHASIL MENGUASAI DUNIA!!\n";
        system("pause");
        credit();
    }
    else if (segerombolZombi3.hp <= 1)
    {
        cout<<"Zombie 3 Berhasil diKalahkan!" <<endl;
        system("pause");
        BattleD();
    }
}
void BattleD()
{
    BattleDisplayD();
    int PilBa;

    if (mc.hp >= 1 && segerombolZombi4.hp >= 1)
    {
        cout << "1. Attack" << endl;
        cout << "2. Block" << endl;
        cout << "3. Heal" << endl;
        cout << "Pilih aksi anda ";
        cin >> PilBa;
        if (PilBa == 1)
        {
            cout << "ATTACKING!!!";
            segerombolZombi4.hp = segerombolZombi4.hp - mc.attack_machine_gun;
            cout << "Berhasil menyerang zombi" << endl;
            system("pause");
            BattleDisplayD();
            if (segerombolZombi4.hp >= 10)
            {
                cout << "ZOMBI ATTACK!!!" << endl;
                mc.hp = mc.hp - segerombolZombi4.damage;
                if (mc.hp <= 0)
                {
                    mc.hp = 0;
                }
            }
            else if (segerombolZombi4.hp <= 0)
            {
                segerombolZombi4.hp = 0;
            }
            system("pause");
            BattleD();
        }
        else if (PilBa == 2)
        {
            cout << "BLOCKING!!!" << endl;
            int Block = rand() % 40 + 1;
            if (Block >= 20)
            {
                cout << "Kamu berhasil Block" << endl;
                system("pause");
                BattleD();
            }
            else
            {
                cout << "Kamu Gagal Block" << endl;
                mc.hp = mc.hp - segerombolZombi4.damage;
                system("pause");
                BattleD();
            }
        }
        else if (PilBa == 3)
        {
            cout << "HEALING !!!" << endl;
            if (mc.hp <= 30)
            {
                mc.hp = mc.hp + 5;
                cout << "Berhasil Heal 5 HP" << endl;
                system("pause");
                BattleD();
            }
            else
            {
                cout << "Kamu tidak bisa healing karena nyawa mu masih banyak" << endl;
                system("pause");
                BattleD();
            }
        }
        else
        {
            cout << "\n";
            cout << "Pilihan tidak ada silahkan pilih lagi" << endl;
            system("pause");
            BattleD();
        }
    }
    else if (mc.hp <= 1)
    {
        cout << "KAMU KEHILANGAN BANYAK DARAH AKIBAT SERANGAN DARI ZOMBIE!!!" << endl;
        cout << "KAMU MULAI KEHILANGAN KESADARAN" << endl;
        cout << "PARA ZOMBIE PUN MULAI BERKUMPUL\nDan MEREKA MULAI MEMAKAN BAGIAN TUBUHMU" << endl;
        cout << "SELESAI MEREKA MEMAKANMU\nMEREKA MULAI BERKUMPUL UNTUK MERAYAKAN KEMATIANMU" << endl;
        cout << "PARA ZOMBIE MULAI MELAKUKAN INVANSI KE PENJURU DUNIA!!" << endl;
        cout << mc.nama << "Telah Mati,\n\t\tZOMBIE BERHASIL MENGUASAI DUNIA!!\n";
        system("pause");
        credit();
    }
    else if (segerombolZombi4.hp <= 1)
    {
        cout<<"Zombie 4 Berhasil diKalahkan!" <<endl;
        system("pause");
        cerita3();
    }
}

//---------- BAG. 3 ------------
void Battle2()
{
    BattleDisplay2();
    int PilBa;

    if (mc.hp >= 1 && MonsterZombi.hp >= 1)
    {
        cout << "1. Attack" << endl;
        cout << "2. Block" << endl;
        cout << "3. Heal" << endl;
        cout << "Pilih aksi anda ";
        cin >> PilBa;
        if (PilBa == 1)
        {
            cout << "ATTACKING!!!";
            MonsterZombi.hp = MonsterZombi.hp - mc.attack_machine_gun;
            cout << "Berhasil menyerang zombi" << endl;
            system("pause");
            BattleDisplay2();
            if (MonsterZombi.hp >= 100)
            {
                cout << "Zombie memberikan serangan kejutan..." << endl;
                mc.hp = mc.hp - MonsterZombi.damage;
                system("pause");
                if(mc.hp <= 0) {
                    mc.hp = 0;
                }
            }
            else if (MonsterZombi.hp <= 0)
            {
                MonsterZombi.hp = 0;
            }
            system("pause");
            Battle2();
        }
        else if (PilBa == 2)
        {
            cout << "BLOCKING!!!" << endl;
            int Block = rand() % 40 + 1;
            if (Block >= 20)
            {
                cout << "Kamu berhasil Block" << endl;
                system("pause");
                Battle2();
            }
            else
            {
                cout << "Kamu Gagal Block" << endl;
                mc.hp = mc.hp - MonsterZombi.damage;
                system("pause");
                Battle2();
            }
        }
        else if (PilBa == 3)
        {
            cout << "HEALING !!!" << endl;
            if (mc.hp <= 50)
            {
                mc.hp = mc.hp + 10;
                cout << "Berhasil Heal 10 HP" << endl;
                system("pause");
                Battle2();
            }
            else
            {
                cout << "Kamu tidak bisa healing karena nyawa mu masih banyak" << endl;
                system("pause");
                Battle2();
            }
        }
        else
        {
            cout << "\n";
            cout << "Pilihan tidak ada silahkan pilih lagi" << endl;
            system("pause");
            Battle2();
        }
    }
    else if (mc.hp <= 1)
    {
        cout << "KAMU KEHILANGAN BANYAK DARAH AKIBAT SERANGAN DARI ZOMBIE!!!" << endl;
        cout << "KAMU MULAI KEHILANGAN KESADARAN" << endl;
        cout << "PARA ZOMBIE PUN MULAI BERKUMPUL\nDan MEREKA MULAI MEMAKAN BAGIAN TUBUHMU" << endl;
        cout << "SELESAI MEREKA MEMAKANMU\nMEREKA MULAI BERKUMPUL UNTUK MERAYAKAN KEMATIANMU" << endl;
        cout << "PARA ZOMBIE MULAI MELAKUKAN INVANSI KE PENJURU DUNIA!!" << endl;
        cout << mc.nama << "Telah Mati,\n\t\tZOMBIE BERHASIL MENGUASAI DUNIA!!\n";
        system("pause");
        credit();
        exit(0);
    }
    else if (MonsterZombi.hp <= 1)
    {
        system("cls");
        cout << "BERHASIL MENGALAHKAN MONSTER ZOMBI" << endl;
        cout << "SEKARANNG ANDA SUDAH DI DEPAN LABORATORIUM, DAN ANDA MENGAMBIL\n";
        cout << "ANTI BODY, KEMUDIAN ANDA MENYEBARKAN ANTI BODI TERSEBUT KE PENJURU\n";
        cout << "AKHIRNAY VIRUS ANEH TERSEBUT SUDAH HILANG, DAN KEMUDIA KEHIDUPAN\n";
        cout << "BERJALAN NORAMAL............\n";
        cout << "\n\t=============> GAME TAMATTTT <=============\n";
        system("pause");
        credit();
        exit(0);
    }
}

// ------- CERITA 2
void cerita2_1()
{
    cout << "Masuk ke Cerita 2\n";
    system("cls");
    cout << mc.nama << " berhasil mengalahkan zombi, lalu dia mengatopsi zombi" << endl;
    cout << "dan menemukan sesuatu yang janggal." << endl;
    cout << "Dia merasa tahu sumber gejala dan mengambil sampel untuk dibawa ke Lab. " << endl;
    cout << "Pada saat perjalanan ke Lab menggunakan mobil militer, dia dihadang oleh 4 zombi" << endl;
    cout << "Kamu lalu menggunakan machine gun yang ada di atas mobil untuk melawan zombie itu" << endl;
    cout<<"\n\t";
    viewDisplay();
    system("pause");
    BattleDisplayA();
    BattleA();
}

//--------- CERITA 3 ----------
void cerita3()
{
    system("cls");
    isClear();
    viewDisplay();
    cout << "BERHASIL MENGALAHKAN SEKUMPULAN ZOMBIE" << endl;
    cout << "Namun,......." <<endl;
    cout << "KAMU MULAI KEHILANGAN KESADARAN KARENA EFEK MELAWAN 4 ZOMBIE" << endl;
    cout << mc.nama <<" merasa kelelahan dan beristirahat." <<endl;
    system("pause");
    system("cls");
    cout<<"\t*Bermimpi berhasil membuat antibodi!" <<endl;
    system("pause");
    system("cls");
    cout << mc.nama <<" TERBANGUN DARI TIDURNYA DAN LANGSUNG BERGEGAS MENUJU LAB " << endl;
    cout << "TIBA TIBA BENSIN MOBIL MILTER YANG KAMU KENDARAI KEHABISAN BENSIN " << endl;
    cout << "SEHINGGA KAMU HARUS MELANJUTKAN PERJALANAN DENGAN BERJALAN KAKI " << endl;
    cout << "DITENGAH PERJALANAN KAMU MELIHAT MOBIL TUA DI BAHU JALAN" << endl;
    cout << "KAMU MENCOBA MEMPERBAIKI MOBIL TERSEBUT...." << endl;
    cout << "KEMUDIAN ANDA MENGEMUDI MOBIL TERBSEBUT, TAPI KETIKA MAU MASUK KE LABORATORIUM" << endl;
    cout << "ANDA DIHADANG OLEH SEBUAH MONSTER ZOMBI YANG TERLIHAT LEBIH BESAR DAN MENYERAMKAN.\n";
    cout << "KAMU MENCARI SENJATA YANG KUAT UNTUK MELAWANNYA KEMUDIAN ANDA MENEMUKAN " << endl;
    cout << "MACHINE GUN LALU KAMU MENGGUNAKAN MACHINE GUN UNTUK MELAWANNYA" << endl;
    system("pause");
    Battle2();
}

//---------- BATTLE DISPLAY 1 ----------
void battleMenu()
{
    int pi, temp;
menu:
    system("cls");
    cout << "# " << mc.nama;
    cout << "\t\t# "
         << "Zombie" << endl;
    cout << "| "
         << "Nyawa  : " << mc.hp;
    cout << "\t| "
         << "Nyawa  : " << regularZombi.hp << endl;
    cout << "| "
         << "Damage : " << mc.attack_pistol;
    cout << "\t| "
         << "Damage : " << regularZombi.damage << endl;
    cout << "============================================================================" << endl;
    cout << "1. Attack  2. Finish HIM" << endl;
    cout << "Masukan pilihan anda ";
    cin >> pi;

    if (pi == 1)
    {
        cout << "Attack !" << endl;
        if (regularZombi.hp == 0)
        {
            cout << "ZOMBIE MATI!!" << endl;
            system("pause");
            cerita2_1();
        }
        else if (regularZombi.hp < 0)
        {
            cout << "ZOMBIE MATI!!" << endl;
            system("pause");
            cerita2_1();
        }
        else
        {
            temp = regularZombi.hp - mc.attack_pistol;
            regularZombi.hp = temp;
            cout << mc.nama << " memberikan serangan ke Zombie!\n";
            system("pause");
            goto menu;
        }
    }
    else if (pi == 2)
    {
        if (regularZombi.hp == 0 && regularZombi.hp <= 0)
        {
            cout << "Zombie Berhasil Dikalahkan!\n";
            cout << "\t>> DROP ITEM dari Zombie yang telah dikalahkan! \n";
            cout << "Masukkan item yang jatuh: ";
            cin >> cari;
            itemDrop(cari);
            system("pause");
            cerita2_1();
        }
        else
        {
            cout << "Zombie masih memiliki HP sebesar " << regularZombi.hp << endl;
            system("pause");
            goto menu;
        }
    }
    else
    {
        cout << "maaf pilihan anda tidak ";
        system("pause");
        goto menu;
    }
    system("cls");
    cerita2_1();
}

//------------ PROLOG ----------
void start()
{
    system("cls");
    cout << "Start Game!\n";
    cout << "Masukkan nama karakter: ";
    cin >> mc.nama;
    cout << endl;

    // Prolog
    cout << "Prolog\n";
    cout << mc.nama << " dia seorang tentara medis dan lulusan Akademi Militer.\n";
    cout << "Pada tahun 2045 di sebuah kota A muncul suatu gejala\nmenular dan berkembang dengan sangat cepat yang bisa\nmengubah orang menjadi zombi.  Negara A membuat\nsituasi Darurat dan Tentara dikumpulkan untuk\nmelindungi warga\n";
    system("pause");
    system("cls");
    displayStats_mc();
    system("pause");
    cerita1();
}

void cerita1()
{
    // Main Story Bagan 1
    system("cls");
    cout << "Stats " << mc.nama << endl;
    displayStats_mc();
    cout << endl;
    cout << mc.nama << " bertemu dengan Zombie.\nDia harus mengalahkan zombie untuk melindungi warga!";

    battleMenu();
}

void credit()
{
    system("cls");
    string temp_nama, temp_nim;
    int jmlanggota = max;

    // Input Data Anggota kelompok
    team.namaMhs[0] = {"Kevin Arnandes"};
    team.nimMhs[0] = {"21.11.4306"};
    team.namaMhs[1] = {"Hisam Saputra "};
    team.nimMhs[1] = {"21.11.4321"};
    team.namaMhs[2] = {"Arya Sakti N. "};
    team.nimMhs[2] = {"21.11.4292"};
    team.namaMhs[3] = {"Dika Isnaida  "};
    team.nimMhs[3] = {"21.11.4278"};

    // Cetak Data Anggota Kelompok
    cout << "\t\t\t>>    KELOMPOK 4 <<\n";
    cout << "\t---------------------------------------------------\n";

    //// SORTING ASCENDING NIM !
    for (int i = 0; i < (jmlanggota - 1); i++)
    {
        for (int j = 0; j < (jmlanggota - 1); j++)
        {
            if (team.nimMhs[j] > team.nimMhs[j + 1])
            {
                // Bubble NIM
                temp_nim = team.nimMhs[j];
                team.nimMhs[j] = team.nimMhs[j + 1];
                team.nimMhs[j + 1] = temp_nim;

                temp_nama = team.namaMhs[j];
                team.namaMhs[j] = team.namaMhs[j + 1];
                team.namaMhs[j + 1] = temp_nama;
            }
        }
    }
    for (int i = 0; i < jmlanggota; i++)
    {
        cout << "\t\t>> " << team.namaMhs[i] << "\t" << team.nimMhs[i] << endl;
    }
    cout << "\t---------------------------------------------------\n";

    system("pause");
}

void displayStats_mc()
{
    cout << "HP\t\t: " << mc.hp << endl;
    cout << "Damage (Pistol)\t: " << mc.attack_pistol << endl;
}
