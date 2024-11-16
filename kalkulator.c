#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>	

#define PI 3.14

void clear_screen() {
    #ifdef _WIN32
        system("cls || powershell -command Clear-Host");
    #else
        system("clear");
    #endif
}

struct mata_uang {
	char kode[9];
	int nilai_tukar;
	const char* nama;
};

int input_integer() {
    int input;
    char temp;
    while (1) {
        if (scanf("%d", &input) != 1) {
            while ((temp = getchar()) != '\n' && temp != EOF);
            printf("Input tidak valid. Mohon masukkan bilangan bulat: ");
        } else if (getchar() != '\n') {
            while ((temp = getchar()) != '\n' && temp != EOF);
            printf("Input tidak valid. Mohon masukkan bilangan bulat: ");
        } else {
            return input;
        }
    }
}

// Fungsi operasi dasar (aritmatika)
long long int tambah(int a, int b) { return a + b; }
long long int kurang(int a, int b) { return a - b; }
long long int kali(int a, int b) { return a * b; }
long long int bagi(int a, int b) { return b != 0 ? a / b : 0; }
int modulus(int a, int b) { return b != 0 ? a % b : 0; }
int logaritma(int a, int b) { return b != 0 ? log(a) / log(b) : 0; }
long long int fibonacci(int n) { return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2); }
long long int faktorial(int n) { return n == 0 ? 1 : n * faktorial(n - 1); }
long long int pangkat(int a, int b) { return pow(a, b); }
int akar(int a, int b) { return b != 0 ? pow(a, 1.0 / b) : 0; }

//fungsi trigonometri
int sinus(int a) { return sin(a); }
int cosinus(int a) { return cos(a); }
int tangen(int a) { return tan(a); }
int cosecan(int a) { return 1 / sin(a); }
int secan(int a) { return 1 / cos(a); }
int cotangen(int a) { return 1 / tan(a); }

void konversi_suhu() {
    int skala_awal, skala_akhir, suhu_awal, suhu_akhir;
    int pilihan;

    while (1) {
        printf("+=====================================+\n");
        printf("|            Konversi Suhu            |\n");
        printf("+=====================================+\n");
        printf("| %-35s |\n", "1. Celcius");
        printf("| %-35s |\n", "2. Reamur");
        printf("| %-35s |\n", "3. Fahrenheit");
        printf("| %-35s |\n", "4. Kelvin");
        printf("| %-35s |\n", "5. Kembali ke Menu Utama");
        printf("+=====================================+\n");
        
        printf("Pilih satuan suhu awal: ");
        pilihan = input_integer();
        
        if (pilihan == 5) {
            // Exit to main menu
            return;
        }

        skala_awal = pilihan;

        printf("Masukkan suhu: ");
        suhu_awal = input_integer();
        
        printf("Pilih satuan suhu akhir: ");
        skala_akhir = input_integer();
        
        // Konversi suhu
        switch (skala_awal) {
            case 1: // Celcius
                switch (skala_akhir) {
                    case 1: suhu_akhir = suhu_awal; break;
                    case 2: suhu_akhir = suhu_awal * 4 / 5; break;
                    case 3: suhu_akhir = (suhu_awal * 9 / 5) + 32; break;
                    case 4: suhu_akhir = suhu_awal + 273; break;
                    default: printf("Skala akhir tidak valid.\n"); return;
                }
                break;
            case 2: // Reamur
                switch (skala_akhir) {
                    case 1: suhu_akhir = suhu_awal * 5 / 4; break;
                    case 2: suhu_akhir = suhu_awal; break;
                    case 3: suhu_akhir = (suhu_awal * 9 / 4) + 32; break;
                    case 4: suhu_akhir = (suhu_awal * 5 / 4) + 273; break;
                    default: printf("Skala akhir tidak valid.\n"); return;
                }
                break;
            case 3: // Fahrenheit
                switch (skala_akhir) {
                    case 1: suhu_akhir = (suhu_awal - 32) * 5 / 9; break;
                    case 2: suhu_akhir = (suhu_awal - 32) * 4 / 9; break;
                    case 3: suhu_akhir = suhu_awal; break;
                    case 4: suhu_akhir = (suhu_awal - 32) * 5 / 9 + 273; break;
                    default: printf("Skala akhir tidak valid.\n"); return;
                }
                break;
            case 4: // Kelvin
                switch (skala_akhir) {
                    case 1: suhu_akhir = suhu_awal - 273; break;
                    case 2: suhu_akhir = (suhu_awal - 273) * 4 / 5; break;
                    case 3: suhu_akhir = (suhu_awal - 273) * 9 / 5 + 32; break;
                    case 4: suhu_akhir = suhu_awal; break;
                    default: printf("Skala akhir tidak valid.\n"); return;
                }
                break;
            default:
                printf("Skala awal tidak valid.\n");
                return;
        }
        
        printf("Hasil konversi: %d\n", suhu_akhir);
    }
}


//fungsi kalkulator bmi
void kalkulator_bmi() {
	char pilih;
	do {
		int berat, tinggi, umur;
    char gender;
    
		printf("Program Kalkulator BMI \n\n");
    printf("Masukkan berat badan Anda (kg): ");
    berat = input_integer();
    
    printf("Masukkan tinggi badan Anda (cm): ");
    tinggi = input_integer();

    printf("Pria = p, Wanita = w \n");
    printf("Masukkan jenis kelamin : ");
    scanf(" %c", &gender);
    
    printf("Masukkan umur Anda: ");
    umur = input_integer();
    
    int bmi = (berat * 10000) / (tinggi * tinggi);
        
    printf("\nHasil Perhitungan BMI:\n");
    printf("BMI Anda: %d\n", bmi);
    
    if (bmi < 16) {
        printf("Kategori: Berat badan anda sangat amat kurang\n ======(Severe Thinness)======\n");
    } else if (bmi >= 16 && bmi <=17) {
        printf("Kategori: Berat badan anda sangat kurang\n ======(Moderate Thinness)======\n");
    } else if (bmi >=17 && bmi <=19) {
        printf("Kategori: Berat badan anda kurang\n ======(Mild Thinness)====== \n");
    } else if (bmi >=20 && bmi <=25) {
         printf("Kategori: Berat badan anda Normal\n ======(Normal)====== \n");
    } else if (bmi >=26 && bmi <=30) {
         printf("Kategori: Berat badan anda berlebih\n ======(Overweight)====== \n");
    } else if (bmi >=31 && bmi <=35) {
         printf("Kategori: Berat badan anda tergolong obesitas \n ======(Obese Class 1)====== \n");
    } else if (bmi >=36 && bmi <=40) {
         printf("Kategori: Berat badan anda tergolong obesitas\n ======(Obese Class 2)====== \n");
    } else if (bmi >=41) {
         printf("Kategori: Berat badan anda tergolong obesitas\n ======(Obese Class 3)====== \n");
    } else {
        printf("Kategori: Obesitas\n");
    }

    if (gender == 'P' || gender == 'p') {
        printf("Jenis Kelamin: Pria\n");
    } else if (gender == 'W' || gender == 'w') {
        printf("Jenis Kelamin: Wanita\n");
    } else {
        printf("Jenis Kelamin: Tidak Valid\n");
    }
    
    printf("Umur: %d tahun\n", umur);
    
    printf("\nCatatan: BMI tidak selalu menjadi indikator kesehatan yang akurat.\n");
    printf("Konsultasikan dengan dokter atau ahli gizi untuk evaluasi lebih lanjut.\n");
		printf("\nIngin kembali ke menu utama? (y/n): ");
    scanf(" %c", &pilih);

	} while ( pilih == 'y' || pilih == 'Y');
   
}

//fungsi kalkulator umur
void kalkulator_umur() {
    int tahun_lahir, bulan_lahir, tanggal_lahir;
    int tahun_sekarang, bulan_sekarang, tanggal_sekarang;
    int umur_tahun, umur_bulan, umur_hari;

    printf("Masukkan tanggal lahir Anda:\n");
    printf("Tahun: ");
    tahun_lahir = input_integer();
    printf("Bulan (1-12): ");
    bulan_lahir = input_integer();
    printf("Tanggal: ");
    tanggal_lahir = input_integer();

    printf("\nMasukkan tanggal hari ini:\n");
    printf("Tahun: ");
    tahun_sekarang = input_integer();
    printf("Bulan (1-12): ");
    bulan_sekarang = input_integer();
    printf("Tanggal: ");
    tanggal_sekarang = input_integer();

    umur_tahun = tahun_sekarang - tahun_lahir;
    umur_bulan = bulan_sekarang - bulan_lahir;
    umur_hari = tanggal_sekarang - tanggal_lahir;

    if (umur_hari < 0) {
        umur_bulan--;
        umur_hari += 30; // Asumsi setiap bulan memiliki 30 hari
    }
    if (umur_bulan < 0) {
        umur_tahun--;
        umur_bulan += 12;
    }

    printf("\nUmur Anda adalah %d tahun, %d bulan, dan %d hari.\n", umur_tahun, umur_bulan, umur_hari);
}

//fungsi konversi satuan
void konversi_satuan() {
    int pilihan_awal, pilihan_akhir, nilai;
		double hasil;
    const char* satuan[] = {
        "Kilometer", "Hektometer", "Dekameter", "Meter", 
        "Desimeter", "Sentimeter", "Milimeter", "Mikrometer",
        "Nanometer", "Inci", "Kaki", "Yard", "Mil"
    };
    int jumlah_satuan = sizeof(satuan) / sizeof(satuan[0]);

    printf("+=================================+\n");
    printf("|     Konversi Satuan Panjang     |\n");
    printf("+=================================+\n");
    printf("| No |           Satuan           |\n");
    printf("+----+----------------------------+\n");
    for (int i = 0; i < jumlah_satuan; i++) {
        printf("| %-2d | %-26s |\n", i + 1, satuan[i]);
    }
    printf("+=================================+\n");

    printf("Pilih nomor satuan awal: ");
    pilihan_awal = input_integer() - 1;
    printf("Pilih nomor satuan akhir: ");
    pilihan_akhir = input_integer() - 1;

    if (pilihan_awal < 0 || pilihan_awal >= jumlah_satuan || 
        pilihan_akhir < 0 || pilihan_akhir >= jumlah_satuan) {
        printf("Pilihan satuan tidak valid.\n");
        return;
    }

    printf("Masukkan nilai yang akan dikonversi: ");
    nilai = input_integer();

    double nilai_meter;
    double faktor_konversi[] = {
        1000.0, 100.0, 10.0, 1.0, 0.1, 0.01, 0.001, 0.000001, 0.000000001,
        0.0254, 0.3048, 0.9144, 1609.344
    };
    
    // Konversi ke meter
    nilai_meter = nilai * faktor_konversi[pilihan_awal];
    
    // Konversi dari meter ke satuan akhir
    hasil = nilai_meter / faktor_konversi[pilihan_akhir];

    printf("+=====================================================+\n");
    printf("|                   Hasil Konversi                    |\n");
    printf("+=====================================================+\n");
    printf("| %-10d %-12s = %-10.6g %-12s |\n", 
           nilai, satuan[pilihan_awal], hasil, satuan[pilihan_akhir]);
    printf("+=====================================================+\n");
}


void konversi_mata_uang() {
    struct mata_uang daftar_mata_uang[] = {
        {"1", 15500, "USD (US Dollar)"},
        {"2", 17000, "EUR (Euro)"},
        {"3", 20000, "GBP (Poundsterling)"},
        {"4", 12000, "SGD (Singapore Dollar)"},
        {"5", 2000, "CNY (Yuan)"},
        {"6", 100, "KRW (Won)"},
        {"7", 10000, "AUD (Australian Dollar)"},
        {"8", 16000, "CHF (Swiss Franc)"},
        {"9", 3500, "MYR (US Dollar)"},
        {"10", 3500, "MYR (Malaysian Ringgit)"},
        {"11", 400, "THB (Thai Baht)"},
        {"12", 300, "PHP (Philippine Peso)"},
        {"13", 200, "INR (Indian Rupee)"},
        {"14", 1, "IDR (Indonesian Rupiah)"}
    };

    int jumlah_mata_uang = sizeof(daftar_mata_uang) / sizeof(daftar_mata_uang[0]);

    // Menampilkan daftar mata uang
    printf("+------+---------------------------+\n");
    printf("| Kode | Mata uang                 |\n");
    printf("+------+---------------------------+\n");
    for (int i = 0; i < jumlah_mata_uang; i++) {
        printf("| %-4s | %-25s |\n", daftar_mata_uang[i].kode, daftar_mata_uang[i].nama);
    }
    printf("+------+---------------------------+\n");

    // Input mata uang asal
    char kode_asal[3];
    printf("Silahkan masukkan mata uang asal : ");
    scanf("%2s", kode_asal);

    // Input mata uang tujuan
    char kode_tujuan[3];
    printf("Silahkan masukkan mata uang tujuan : ");
    scanf("%2s", kode_tujuan);

    // Input jumlah uang
    int jumlah;
    printf("Silahkan masukkan jumlah uang : ");
    jumlah = input_integer();

    // Mencari nilai tukar mata uang asal dan tujuan
    int nilai_tukar_asal = 0, nilai_tukar_tujuan = 0;
    const char *nama_asal = "", *nama_tujuan = "";
    for (int i = 0; i < jumlah_mata_uang; i++) {
        if (strcmp(daftar_mata_uang[i].kode, kode_asal) == 0) {
            nilai_tukar_asal = daftar_mata_uang[i].nilai_tukar;
            nama_asal = daftar_mata_uang[i].nama;
        }
        if (strcmp(daftar_mata_uang[i].kode, kode_tujuan) == 0) {
            nilai_tukar_tujuan = daftar_mata_uang[i].nilai_tukar;
            nama_tujuan = daftar_mata_uang[i].nama;
        }
    }

    if (nilai_tukar_asal == 0 || nilai_tukar_tujuan == 0) {
        printf("Kode mata uang tidak valid.\n");
        return;
    }

    
    long long hasil = (long long)jumlah * nilai_tukar_asal / nilai_tukar_tujuan;

    // Menampilkan hasil konversi
    printf("\nHasil Konversi:\n");
    printf("+---------------------------+---------------------------+\n");
    printf("| %-25s | %-25s |\n", nama_asal, nama_tujuan);
    printf("+---------------------------+---------------------------+\n");
    printf("| %-25d | %-25lld |\n", jumlah, hasil);
    printf("+---------------------------+---------------------------+\n");
}

//hitung luas bangun datar
void hitung_luas_bangun_datar() {
    int pilihan;
    double panjang, lebar, alas, tinggi, jari_jari, sisi, sisi1, sisi2, sisi3, sisi4, tinggi_trapesium;

    printf("+===========================================+\n");
    printf("|          Hitung Luas Bangun Datar         |\n");
    printf("+===========================================+\n");
    printf("| 1. Segitiga                               |\n");
    printf("| 2. Persegi                                |\n");
    printf("| 3. Persegi Panjang                        |\n");
    printf("| 4. Jajaran Genjang                        |\n");
    printf("| 5. Trapesium                              |\n");
    printf("| 6. Lingkaran                              |\n");
    printf("+===========================================+\n");

    printf("Pilih bangun datar yang ingin dihitung luasnya: ");
    pilihan = input_integer();

    switch (pilihan) {
        case 1: // Segitiga
            printf("Masukkan alas segitiga: ");
            alas = input_integer();
            printf("Masukkan tinggi segitiga: ");
            tinggi = input_integer();
            printf("Luas segitiga: %.2f\n", (alas * tinggi) / 2);
            break;

        case 2: // Persegi
            printf("Masukkan sisi persegi: ");
            sisi = input_integer();
            printf("Luas persegi: %.2f\n", sisi * sisi);
            break;

        case 3: // Persegi Panjang
            printf("Masukkan panjang persegi panjang: ");
            panjang = input_integer();
            printf("Masukkan lebar persegi panjang: ");
            lebar = input_integer();
            printf("Luas persegi panjang: %.2f\n", panjang * lebar);
            break;

        case 4: // Jajaran Genjang
            printf("Masukkan alas jajaran genjang: ");
            alas = input_integer();
            printf("Masukkan tinggi jajaran genjang: ");
            tinggi = input_integer();
            printf("Luas jajaran genjang: %.2f\n", alas * tinggi);
            break;

        case 5: // Trapesium
            printf("Masukkan alas besar trapesium: ");
            sisi1 = input_integer();
            printf("Masukkan alas kecil trapesium: ");
            sisi2 = input_integer();
            printf("Masukkan tinggi trapesium: ");
            tinggi_trapesium = input_integer();
            printf("Luas trapesium: %.2f\n", ((sisi1 + sisi2) / 2) * tinggi_trapesium);
            break;

        case 6: // Lingkaran
            printf("Masukkan jari-jari lingkaran: ");
            jari_jari = input_integer();
            printf("Luas lingkaran: %.2f\n", PI * jari_jari * jari_jari);
            break;

        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}

// Fungsi untuk menghitung keliling bangun datar
void hitung_keliling_bangun_datar() {
    int pilihan;
    printf("+=======================================+\n");
    printf("|      Hitung Keliling Bangun Datar     |\n");
    printf("+=======================================+\n");
    printf("| %-2d | %-30s |\n", 1, "Segitiga");
    printf("| %-2d | %-30s |\n", 2, "Persegi");
    printf("| %-2d | %-30s |\n", 3, "Persegi Panjang");
    printf("| %-2d | %-30s |\n", 4, "Jajargenjang");
    printf("| %-2d | %-30s |\n", 5, "Trapesium");
    printf("| %-2d | %-30s |\n", 6, "Lingkaran");
    printf("+===========================================+\n");
    printf("Pilih bangun datar: ");
    pilihan = input_integer();
    
    switch (pilihan) {
        case 1: { // Segitiga
            int a, b, c;
            printf("Masukkan panjang sisi pertama: ");
            a = input_integer();
            printf("Masukkan panjang sisi kedua: ");
            b = input_integer();
            printf("Masukkan panjang sisi ketiga: ");
            c = input_integer();
            int keliling = a + b + c;
            printf("Keliling segitiga adalah: %d\n", keliling);
            break;
        }
        case 2: { // Persegi
            int s;
            printf("Masukkan panjang sisi: ");
            s = input_integer();
            int keliling = 4 * s;
            printf("Keliling persegi adalah: %d\n", keliling);
            break;
        }
        case 3: { // Persegi Panjang
            int p, l;
            printf("Masukkan panjang: ");
            p = input_integer();
            printf("Masukkan lebar: ");
            l = input_integer();
            int keliling = 2 * (p + l);
            printf("Keliling persegi panjang adalah: %d\n", keliling);
            break;
        }
        case 4: { // Jajargenjang
            int a, b;
            printf("Masukkan panjang sisi alas: ");
            a = input_integer();
            printf("Masukkan panjang sisi miring: ");
            b = input_integer();
            int keliling = 2 * (a + b);
            printf("Keliling jajargenjang adalah: %d\n", keliling);
            break;
        }
        case 5: { // Trapesium
            int a, b, c, d;
            printf("Masukkan panjang sisi sejajar pertama: ");
            a = input_integer();
            printf("Masukkan panjang sisi sejajar kedua: ");
            b = input_integer();
            printf("Masukkan panjang sisi miring pertama: ");
            c = input_integer();
            printf("Masukkan panjang sisi miring kedua: ");
            d = input_integer();
            int keliling = a + b + c + d;
            printf("Keliling trapesium adalah: %d\n", keliling);
            break;
        }
        case 6: { // Lingkaran
            double r;
            printf("Masukkan jari-jari: ");
            r = input_integer();
            double keliling = 2 * PI * r;
            printf("Keliling lingkaran adalah: %.2g\n", keliling);
            break;
        }
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}

//fungsi hitung volume bangun ruang
void hitung_volume_bangun_ruang() {
    int pilihan;
    double panjang, lebar, tinggi, jari_jari, sisi, alas, tinggi_piramida;

    printf("+======================================+\n");
    printf("|      Kalkulator Volume Bangun Ruang  |\n");
    printf("+======================================+\n");
    printf("| 1. Kubus                             |\n");
    printf("| 2. Balok                             |\n");
    printf("| 3. Prisma                            |\n");
    printf("| 4. Piramida                          |\n");
    printf("| 5. Tabung                            |\n");
    printf("| 6. Kerucut                           |\n");
    printf("| 7. Bola                              |\n");
    printf("+======================================+\n");
    printf("Pilih jenis bangun ruang: ");
    pilihan = input_integer();

    switch (pilihan) {
    case 1: // Kubus
        printf("Masukkan panjang sisi kubus: ");
        sisi = input_integer();
        printf("Volume kubus adalah: %.2f\n", pow(sisi, 3));
        break;

    case 2: // Balok
        printf("Masukkan panjang balok: ");
        panjang = input_integer();
        printf("Masukkan lebar balok: ");
        lebar = input_integer();
        printf("Masukkan tinggi balok: ");
        tinggi = input_integer();
        printf("Volume balok adalah: %.2f\n", panjang * lebar * tinggi);
        break;

    case 3: // Prisma
        printf("Masukkan luas alas prisma: ");
        alas = input_integer();
        printf("Masukkan tinggi prisma: ");
        tinggi = input_integer();
        printf("Volume prisma adalah: %.2f\n", alas * tinggi);
        break;

    case 4: // Piramida
        printf("Masukkan luas alas piramida: ");
        alas = input_integer();
        printf("Masukkan tinggi piramida: ");
        tinggi_piramida = input_integer();
        printf("Volume piramida adalah: %.2f\n", (alas * tinggi_piramida) / 3);
        break;

    case 5: // Tabung
        printf("Masukkan jari-jari tabung: ");
        jari_jari = input_integer();
        printf("Masukkan tinggi tabung: ");
        tinggi = input_integer();
        printf("Volume tabung adalah: %.2f\n", PI * pow(jari_jari, 2) * tinggi);
        break;

    case 6: // Kerucut
        printf("Masukkan jari-jari kerucut: ");
        jari_jari = input_integer();
        printf("Masukkan tinggi kerucut: ");
        tinggi = input_integer();
        printf("Volume kerucut adalah: %.2f\n", (PI * pow(jari_jari, 2) * tinggi) / 3);
        break;

    case 7: // Bola
        printf("Masukkan jari-jari bola: ");
        jari_jari = input_integer();
        printf("Volume bola adalah: %.2f\n", (4.0 / 3.0) * PI * pow(jari_jari, 3));
        break;

    default:
        printf("Pilihan tidak valid.\n");
        break;
    }
}

void hitung_luas_alas_bangun_ruang() {
    int pilihan;
    double panjang, lebar, tinggi, jari_jari, alas, luas;

    printf("+======================================+\n");
    printf("|  Kalkulator Luas Alas Bangun Ruang   |\n");
    printf("+======================================+\n");
    printf("| 1. Kubus                             |\n");
    printf("| 2. Balok                             |\n");
    printf("| 3. Prisma                            |\n");
    printf("| 4. Piramida                          |\n");
    printf("| 5. Tabung                            |\n");
    printf("| 6. Kerucut                           |\n");
    printf("+======================================+\n");
    printf("Pilih jenis bangun ruang (1-7): ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1: // Kubus
            printf("Masukkan panjang sisi kubus: ");
            panjang = input_integer();
            luas = panjang * panjang;
            printf("Luas alas kubus adalah: %.2lf\n", luas);
            break;
        case 2: // Balok
            printf("Masukkan panjang balok: ");
						panjang = input_integer();
            printf("Masukkan lebar balok: ");
            lebar = input_integer();
            luas = panjang * lebar;
            printf("Luas alas balok adalah: %.2lf\n", luas);
            break;
        case 3: // Prisma
            printf("Masukkan panjang sisi alas prisma: ");
            panjang = input_integer();
            printf("Masukkan lebar sisi alas prisma: ");
            lebar = input_integer();
            luas = panjang * lebar;
            printf("Luas alas prisma adalah: %.2lf\n", luas);
            break;
        case 4: // Piramida
            printf("Masukkan panjang alas piramida: ");
            panjang = input_integer();
            printf("Masukkan lebar alas piramida: ");
            lebar = input_integer();
            luas = panjang * lebar;
            printf("Luas alas piramida adalah: %.2lf\n", luas);
            break;
        case 5: // Tabung
            printf("Masukkan jari-jari alas tabung: ");
            jari_jari = input_integer();
            luas = PI * jari_jari * jari_jari;
            printf("Luas alas tabung adalah: %.2lf\n", luas);
            break;
        case 6: // Kerucut
            printf("Masukkan jari-jari alas kerucut: ");
            jari_jari = input_integer();
            luas = PI * jari_jari * jari_jari;
            printf("Luas alas kerucut adalah: %.2lf\n", luas);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}

// Fungsi untuk memvalidasi dan membaca input integer dari pengguna
int read_integer_input() {
    char buffer[100];
    int value;
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        } else {
            printf("Input tidak valid, masukkan angka: ");
        }
    }
}

// Fungsi untuk membaca input string dari pengguna
void input_string(char *str, size_t size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';  // Menghapus karakter newline
}

// Fungsi untuk menukar dua integer
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk menghitung rata-rata
double calculate_mean(int arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Fungsi untuk menghitung median
double calculate_median(int arr[], int size) {
    // Mengurutkan array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

// Fungsi untuk menghitung modus
int calculate_mode(int arr[], int size) {
    int max_count = 0;
    int mode = arr[0];
    int count;
    
    // Menghitung frekuensi setiap elemen
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        // Memperbarui modus jika frekuensi saat ini lebih tinggi
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }

    // Mengecek apakah ada lebih dari satu modus
    int is_multiple_modes = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == mode) {
            continue;
        }
        count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count == max_count) {
            is_multiple_modes = 1;
            break;
        }
    }
    
    if (is_multiple_modes) {
        printf("Ada lebih dari satu modus.\n");
    }
    
    return mode;
}


// Fungsi untuk mendapatkan input data dari pengguna
void get_user_input(int arr[], int *size) {
    *size = 0;
    char input[100];
    
    printf("Masukkan data (ketik 'stop' untuk berhenti):\n");
    while (1) {
        printf("Data ke-%d: ", *size + 1);
        input_string(input, sizeof(input));
        if (strcmp(input, "stop") == 0) {
            break;
        }
        if (isdigit(input[0]) || (input[0] == '-' && isdigit(input[1]))) {
            arr[*size] = atoi(input);
            (*size)++;
        } else {
            printf("Input tidak valid, masukkan angka atau 'stop': ");
        }
    }
}

// Fungsi untuk menampilkan hasil statistik
void kalkulator_statistik() {
    clear_screen();
    
    int size;
    int data[100];
    
    get_user_input(data, &size);
    
    printf("+======================================+\n");
    printf("|      Statistik Data                  |\n");
    printf("+======================================+\n");
    printf("| 21. Mean                             |\n");
    printf("| 22. Median                           |\n");
    printf("| 23. Modus                            |\n");
    printf("+======================================+\n");
    
    printf("Pilih jenis statistik yang ingin dihitung: ");
    int pilihan = read_integer_input();
    
    switch (pilihan) {
        case 21:
            printf("Mean dari data yang dimasukkan adalah: %.2g\n", calculate_mean(data, size));
            break;
        case 22:
            printf("Median dari data yang dimasukkan adalah: %.2g\n", calculate_median(data, size));
            break;
        case 23:
            printf("Modus dari data yang dimasukkan adalah: %d\n", calculate_mode(data, size));
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }
}

void tampilkan_menu_utama() {
    clear_screen();
    printf("+=======================================================+\n");
    printf("|       Selamat datang di Kalkulator Multi-Fungsi       |\n");
    printf("+=======================================================+\n");
    printf("| %-25s | %-25s |\n", "1. Penjumlahan", "10. Akar");
    printf("| %-25s | %-25s |\n", "2. Pengurangan", "11. Trigonometri");
    printf("| %-25s | %-25s |\n", "3. Perkalian", "12. Konversi Suhu");
    printf("| %-25s | %-25s |\n", "4. Pembagian", "13. Kalkulator BMI");
    printf("| %-25s | %-25s |\n", "5. Modulus", "14. Kalkulator Umur");
    printf("| %-25s | %-25s |\n", "6. Logaritma", "15. Konversi Satuan");
    printf("| %-25s | %-25s |\n", "7. Fibonacci", "16. Konversi Mata Uang");
    printf("| %-25s | %-25s |\n", "8. Faktorial", "17. hitung luas bangunan");
    printf("| %-25s | %-25s |\n", "9. Pangkat", "18. keliling bangunan");
		printf("| %-25s | %-25s |\n", "19. volume bangun ruang", "20. alas bangun ruang");
		printf("| %-25s | %-25s |\n", "21. statistik data", "22. keluar");
    printf("+=======================================================+\n");
    printf("|      Selamat Menggunakan Kalkulator Multi-Fungsi      |\n");
    printf("+=======================================================+\n");
    printf("Silahkan Masukkan Pilihan Anda: ");
}

int main() {
    int pilihan;

    while(1) {
        tampilkan_menu_utama();
        pilihan = input_integer();
        
        switch (pilihan) {
        case 1:
            clear_screen();
            printf("Program Penjumlahan\n");
            printf("Masukkan angka pertama: ");
            int a = input_integer();
            printf("Masukkan angka kedua: ");
            int b = input_integer();
            printf("Hasil penjumlahan dari %d + %d adalah: %d\n", a, b, tambah(a, b));
            break;
        case 2:
            clear_screen();
            printf("Program Pengurangan\n");
            printf("Masukkan angka pertama: ");
            a = input_integer();
            printf("Masukkan angka kedua: ");
            b = input_integer();
            printf("Hasil pengurangan dari %d - %d adalah: %d\n", a, b, kurang(a, b));
            break;
        case 3:
            clear_screen();
            printf("Program Perkalian\n");
            printf("Masukkan angka pertama: ");
            a = input_integer();
            printf("Masukkan angka kedua: ");
            b = input_integer();
            printf("Hasil perkalian dari %d * %d adalah: %d\n", a, b, kali(a, b));
            break;
        case 4:
            clear_screen();
            printf("Program Pembagian\n");
            printf("Masukkan angka pertama: ");
            a = input_integer();
            printf("Masukkan angka kedua: ");
            b = input_integer();
            if (b == 0) {
                printf("Error: Pembagian dengan nol tidak diperbolehkan.\n");
            } else {
                printf("Hasil pembagian dari %d / %d adalah: %d\n", a, b, bagi(a, b));
            }
            break;
        case 5:
            clear_screen();
            printf("Program Modulus\n");
            printf("Masukkan angka pertama: ");
            a = input_integer();
            printf("Masukkan angka kedua: ");
            b = input_integer();
            if (b == 0) {
                printf("Error: Modulus dengan nol tidak diperbolehkan.\n");
            } else {
                printf("Hasil modulus dari %d %% %d adalah: %d\n", a, b, modulus(a, b));
            }
            break;
        case 6:
            clear_screen();
            printf("Program Logaritma\n");
            printf("Masukkan angka pertama: ");
            a = input_integer();
            printf("Masukkan angka kedua: ");
            b = input_integer();
            printf("Hasil logaritma dari %d log %d adalah: %d\n", a, b, logaritma(a, b));
            break;
        case 7 :
            clear_screen();
            printf("Program Fibonacci\n");
            printf("Masukkan bilangan ke-: ");
            a = input_integer();
            printf("Bilangan fibonacci ke-%d adalah : %d\n", a, fibonacci(a));
            break;
        case 8:
            clear_screen();
            printf("Program Faktorial\n");
            printf("Masukkan bilangan: ");
            a = input_integer();
            printf("Faktorial dari %d adalah: %d\n", a, faktorial(a));
            break;
        case 9:
            clear_screen();
            printf("Program Pangkat\n");
            printf("Masukkan bilangan: ");
            a = input_integer();
            printf("Masukkan pangkat: ");
            b = input_integer();
            printf("%d pangkat %d adalah: %d\n", a, b, pangkat(a, b));
            break;
        case 10:
            clear_screen();
            printf("Program Akar\n");
            printf("Masukkan bilangan: ");
            a = input_integer();
            printf("Masukkan akar: ");
            b = input_integer();
            printf("%d akar %d adalah: %d\n", a, b, akar(a, b));
            break;
        case 11:
            clear_screen();
            printf("Program Trigonometri\n");
            printf("Masukkan sudut: ");
            a = input_integer();
            printf("Sinus dari %d adalah: %d\n", a, sinus(a));
            printf("Cosinus dari %d adalah: %d\n", a, cosinus(a));
            printf("Tangen dari %d adalah: %d\n", a, tangen(a));
            printf("Cosecan dari %d adalah: %d\n", a, cosecan(a));
            printf("Secan dari %d adalah: %d\n", a, secan(a));
            printf("Cotangen dari %d adalah: %d\n", a, cotangen(a));
            break;
        case 12:
            konversi_suhu();
            break;
        case 13:
            clear_screen();
            kalkulator_bmi();
            break;
        case 14 :
            clear_screen();
            kalkulator_umur();
            break;
        case 15:
            clear_screen();
            konversi_satuan();
            break;
        case 16:
            clear_screen();
						konversi_mata_uang();
            break;
				case 17 :
						clear_screen();
						hitung_luas_bangun_datar();
						break;
				case 18 :
						clear_screen();
						hitung_keliling_bangun_datar();
						break;
				case 19 :
						clear_screen();
						hitung_volume_bangun_ruang();
						break;
				case 20 :
						clear_screen();
						hitung_luas_alas_bangun_ruang();
						break;
				case 21 :
						clear_screen();
						kalkulator_statistik();
						break;
        case 22:
            printf("Terima kasih telah menggunakan Kalkulator Multi-Fungsi. Sampai jumpa!\n");
            getchar();
            return 0;
        default:
            printf("Pilihan tidak tersedia. Silakan coba lagi.\n");
            getchar();
            break;
        }
        
        printf("\nTekan Enter untuk melanjutkan...");
        while (getchar() != '\n');
    }
}