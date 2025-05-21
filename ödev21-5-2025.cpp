#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Fonksiyon bildirimi
int dosyaKontrol();
void dosyaOlustur();
void dosyayaYaz();
void dosyaOku();
void dosyaSil();

char dosyaAdi[20] = "veri.txt";

int main() {
    int secim;

    printf("Bir dosya adi girin: ");
    scanf("%s", dosyaAdi);

    while (1) {
        printf("\n=== DOSYA ISLEMLERI ===\n");
        printf("1 - Dosya Var Mi?\n");
        printf("2 - Dosya Olustur\n");
        printf("3 - Dosyaya Sayi Yaz\n");
        printf("4 - Dosyayi Oku\n");
        printf("5 - Dosyayi Sil\n");
        printf("6 - Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
        case 1:
            dosyaKontrol();
            break;
        case 2:
            dosyaOlustur();
            break;
        case 3:
            dosyayaYaz();
            break;
        case 4:
            dosyaOku();
            break;
        case 5:
            dosyaSil();
            break;
        case 6:
            printf("Programdan cikiliyor...\n");
            exit(0);
        default:
            printf("Gecersiz secim yaptiniz!\n");
        }
    }

    return 0;
}

int dosyaKontrol() {
    FILE* dosya = fopen(dosyaAdi, "r");

    if (dosya != NULL) {
        fclose(dosya);
        printf("Dosya bulundu: %s\n", dosyaAdi);
        return 1;
    }
    else {
        printf("Dosya yok: %s\n", dosyaAdi);
        return 0;
    }
}

void dosyaOlustur() {
    FILE* dosya = fopen(dosyaAdi, "w");

    if (dosya == NULL) {
        printf("Dosya olusturulamadi!\n");
        return;
    }

    fprintf(dosya, "Yeni bir dosya oluşturuldu.\n");
    fclose(dosya);
    printf("Dosya olusturuldu ve yazi yazildi!\n");
}

void dosyayaYaz() {
    if (!dosyaKontrol()) {
        printf("Dosya yok, once dosya olusturun.\n");
        return;
    }

    FILE* dosya = fopen(dosyaAdi, "a");

    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    int sayi;
    for (int i = 0; i < 5; i++) {
        printf("%d. sayiyi girin: ", i + 1);
        scanf("%d", &sayi);
        fprintf(dosya, "%d\n", sayi);
    }

    fclose(dosya);
    printf("Sayilar dosyaya eklendi!\n");
}

void dosyaOku() {
    if (!dosyaKontrol()) {
        printf("Dosya okunamiyor, cunku yok.\n");
        return;
    }

    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    char satir[100];
    printf("\n--- Dosya Icerigi ---\n");
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        printf("%s", satir);
    }

    fclose(dosya);
    printf("\nDosya okundu!\n");
}

void dosyaSil() {
    if (!dosyaKontrol()) {
        printf("Dosya zaten yok, silinecek bir sey yok.\n");
        return;
    }

    if (remove(dosyaAdi) == 0) {
        printf("Dosya silindi!\n");
    }
    else {
        printf("Dosya silinemedi!\n");
    }
}
