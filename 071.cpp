#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long ccn,mods,divs,check1,check2,check3;
    int count,num1,num2,totalcount,count1,totalcount1,totallycount,valid;
    string ctype;

    cout<<"REKENING YANG TERSEDIA: \n";
    cout<<"============\n1.MASTERCARD\n2.VISA\n============\n";
    cout<<"Selamat datang di pengecekan rekening! \nMasukkan rekening anda: ";
    cin>>ccn;

    mods = 100; // set nilai dari modulus yang akan dipakai untuk Algoritma Luhn
    divs = 10; // set nilai dari pembagian yang akan dipakai untuk Algoritma Luhn
    totalcount = 0; // harus ngeset nilai ke 0 jika tidak maka akan terjadi error 
    totalcount1 = 0; 
    totallycount = 0; 

    do 
    {
        count = (((ccn % mods) / divs)*2); // Nilai kartu kredit akan dicek dan dikalkulasikan
        if (count >= 10)   // Jika dari count nilainya lebih dari 10 yang membuat dua digit akan dipisah dua digit angka tersebut
        {
            num1 = count / 10; // Digit yang di kiri akan diambil
            num2 = count % 10; // DIgit kanan yang diammbil
            count = num1 + num2; // Digit kiri dan kanan dijumlahkan
        }
        else
        {
            count = count; // jika tidak ada dua digit akan tetap sama
        }
    totalcount= totalcount + count; // Akumulasi nilai dari semua yang dijumlahkan
    mods *= 100; // dikali 100 untuk melanjutkan algoritma luhn
    divs *= 100; 
    } while (mods <= 10000000000000000 || divs <= 1000000000000000) ; // akan berhenti jika sudah sampai nilai tersebut

    mods = 10;
    divs = 1;

    do
    {
        count1 = ((ccn % mods) / divs); // lanjutan dari algoritma luhn
        totalcount1= totalcount1 + count1; // AKumulasi nilai
        mods *= 100;
        divs *= 100;
    } while(mods <= 1000000000000000 || divs <= 100000000000000);  // akan berhenti jika sudah sampai nilai tersebut

    totallycount = totalcount + totalcount1; // Total dari semua
    valid = totallycount % 10; // Penentuan Nilai valid
    check1 = (ccn % 10000000000000000) / 100000000000000; // check1 utk mengecek 2 digit awal untuk 16 digit (MASTERCARD/VISA)
    check2 = (ccn % 10000000000000000) / 1000000000000000; // check2 utk mengecek 1 digit awal untuk 16 digit (MASTERCARD/VISA))
    check3 = (ccn % 10000000000000) / 1000000000000; //  check3 utk mengecek 1 digit awal untuk 13 digit (VISA)

    if (valid == 0) // JIKA VALID SUDAH TEPAT YAITU 0
    {
        if (check2 == 4) // 4 adalah digit awal untuk visa sesuai dari check2 (16digit) maka card type = VISA
        {
            ctype = "VISA";
        }
        else if (check3 == 4)  // 4 adalah digit awal untuk visa sesuai dari check2 (13digit) maka card type = VISA
        {
            ctype = "VISA";
        }
        else
        {
            switch (check1) // Jika digit 2 awal adalah 51 - 55 maka kartu MASTERCARD, jika TIDAK SESUAI UNTUK SEMUA DIATAS MAKA TIDAK DIKETAHUI
            {
                case 51:
                    ctype = "MASTERCARD";
                    break;
                case 52:
                    ctype = "MASTERCARD";
                    break;
                case 53:
                    ctype = "MASTERCARD";
                    break;
                case 54:
                    ctype = "MASTERCARD";
                    break;
                case 55:
                    ctype = "MASTERCARD";
                    break;
                default:
                    ctype = "TIDAK DIKETAHUI";
            }
        }
    }
    else // JIKA VALID TIDAK TEPAT MAKA TIDAK VALID 
    {
        ctype = "TIDAK VALID";
    }

    cout<<"Nomor Rekening Kartu anda: "<<ccn<<endl; //Kartu rekening yang sudah diinput
    cout<<"Tipe Kartu anda: "<<ctype<<endl; //card type fungsi diatas
    cout<<"Checksum: "<<totallycount; //checksum itu nilai dari algoritma luhn diatas
    return 0;
}