#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bir öğeyi temsil etmek için yapıyı tanımlama
struct Calisan
{
    int kod;
    char ad[50];
    char telefon[15];
    char email[50];
    float ucret;
    int yas;
};

// Yeni bir kayıt oluşturmak için işlev
void CalisanKaydiOlustur(struct Calisan *kayitlar, int *sayac)
{
    printf("Kodu girin: ");
    scanf("%d", &kayitlar[*sayac].kod);

    printf("Adı girin: ");
    scanf("%s", kayitlar[*sayac].ad);

    printf("Email adresini girin: ");
    scanf("%s", kayitlar[*sayac].email);

    printf("Telefon numarasını girin: ");
    scanf("%s", kayitlar[*sayac].telefon);

    printf("Yaşı girin: ");
    scanf("%d", &kayitlar[*sayac].yas);

    printf("Yeni kayıt oluşturmak için giriş ücretini girin:");
    scanf("%f", &kayitlar[*sayac].ucret);

    printf("\n");

    printf("Harika! Kaydınız başarıyla oluşturuldu =) \n");

    (*sayac)++;
}

// Bir dosyaya kayıtları içeren bir dosya oluşturmak için işlev
void DosyaOlustur()
{
    struct Calisan olusturCalisan;
    printf("Kaydedilen verileri içeren bir dosya oluşturmak istiyorsanız, aşağıdaki alanlara yeniden girin");

    printf("\nKodunuzu girin: ");
    scanf("%d", &olusturCalisan.kod);

    printf("Dosyaya kaydedilecek adı girin: ");
    scanf("%s", olusturCalisan.ad);

    printf("Dosyaya kaydedilecek email adresini girin: ");
    scanf("%s", olusturCalisan.email);

    printf("Dosyaya kaydedilecek telefon numarasını girin: ");
    scanf("%s", olusturCalisan.telefon);

    printf("Dosyaya kaydedilecek yaşını girin: ");
    scanf("%d", &olusturCalisan.yas);

    printf("Dosyaya kaydedilecek giriş ücretini girin:");
    scanf("%f", &olusturCalisan.ucret);

    printf("\nHarika! Bilgileriniz içeren bir dosya oluşturuldu =) \n");

    FILE *dosya = fopen("kullanici_verileri.txt", "a");
    if (dosya == NULL)
    {
        printf("Dosya açılırken hata oluştu.");
        return;
    }

    fprintf(dosya, "kod: %d\n", olusturCalisan.kod);
    fprintf(dosya, "ad: %s\n", olusturCalisan.ad);
    fprintf(dosya, "email: %s \n", olusturCalisan.email);
    fprintf(dosya, "telefon: %s \n", olusturCalisan.telefon);
    fprintf(dosya, "yas: %d yaş\n", olusturCalisan.yas);
    fprintf(dosya, "ucret: %.2f TL\n", olusturCalisan.ucret);

    fclose(dosya);
}

// Tüm kayıtları listelemek için işlev
void CalisanlariListele(const struct Calisan *kayitlar, int sayici)
{
    printf("\nKayıtların Listesi:\n");
    for (int i = 0; i < sayici; i++)
    {
        printf("Kod: %d\n", kayitlar[i].kod);
        printf("Ad: %s\n", kayitlar[i].ad);
        printf("E-mail: %s\n", kayitlar[i].email);
        printf("Telefon: %s\n", kayitlar[i].telefon);
        printf("Yaş: %d\n", kayitlar[i].yas);
        printf("Giriş Ücreti: %.2f\n", kayitlar[i].ucret);
    }
}

// Bir kaydı kod ile aramak için işlev
void CalisanKaydiniAra(const struct Calisan *kayitlar, int sayici)
{
    int arananKod;
    printf("Aranacak kodu girin: ");
    scanf("%d", &arananKod);

    int bulundu = 0;
    for (int i = 0; i < sayici; i++)
    {
        if (kayitlar[i].kod == arananKod)
        {
            printf("Kayıt Bulundu:\n");
            printf("Kod: %d\n", kayitlar[i].kod);
            printf("Ad: %s\n", kayitlar[i].ad);
            printf("E-mail: %s\n", kayitlar[i].email);
            printf("Telefon: %s\n", kayitlar[i].telefon);
            printf("Yaş: %d\n", kayitlar[i].yas);
            printf("Giriş Ücreti: %.2f\n", kayitlar[i].ucret);
            bulundu = 1;
            break;
        }
    }

    if (!bulundu)
    {
        printf("Aranan kayıt bulunamadı =( \n");
        printf("Lütfen girdiğiniz kodu kontrol edin. \n");
    }
}

// Bir kaydı kod ile düzenlemek için işlev
void CalisanKaydiniDuzenle(struct Calisan *kayitlar, int sayici)
{
    int duzenlemeKodu;
    printf("Düzenlemek istediğiniz kodu girin: ");
    scanf("%d", &duzenlemeKodu);

    int bulundu = 0;
    for (int i = 0; i < sayici; i++)
    {
        if (kayitlar[i].kod == duzenlemeKodu)
        {
            printf("Yeni adı girin: ");
            scanf("%s", kayitlar[i].ad);

            printf("Yeni giriş ücretini girin: ");
            scanf("%f", &kayitlar[i].ucret);

            printf("Yeni telefon numarasını girin: ");
            scanf("%s", kayitlar[i].telefon);

            printf("Yeni e-mail adresini girin: ");
            scanf("%s", kayitlar[i].email);

            printf("Yeni yaşını girin: ");
            scanf("%d", &kayitlar[i].yas);

            printf("Kodu düzenlenen kayıt başarıyla düzenlendi.\n");
            bulundu = 1;
            break;
        }
    }

    if (!bulundu)
    {
        printf("Düzenlenecek kayıt bulunamadı =( \n");
        printf("Lütfen girdiğiniz kodu kontrol edin. \n");
    }
}

// Bir kaydı kod ile silmek için işlev
void CalisanKaydiniSil(struct Calisan *kayitlar, int *sayici)
{
    int silmeKodu;
    printf("Silmek istediğiniz kodu girin: ");
    scanf("%d", &silmeKodu);

    int bulundu = 0;
    for (int i = 0; i < *sayici; i++)
    {
        if (kayitlar[i].kod == silmeKodu)
        {
            // Tüm sonraki kayıtları bir pozisyon sola taşı
            for (int j = i; j < *sayici - 1; j++)
            {
                kayitlar[j] = kayitlar[j + 1];
            }
            (*sayici)--;
            printf("Kayıt başarıyla silindi.\n");
            bulundu = 1;
            break;
        }
    }

    if (!bulundu)
    {
        printf("Silmek istediğiniz kayıt bulunamadı =( \n");
        printf("Lütfen girdiğiniz kodu kontrol edin. \n");
    }
}

int main()
{
    struct Calisan kayitlar[10];
    int sayici = 0;
    int kullaniciSecimi;

    do
    {
        printf("\nMerhaba! Banka uygulamamıza hoş geldiniz.\n");

        printf("  ┌──────────────────┐  \n");
        printf("  │  ╭┼┼╮             │  \n");
        printf("  │  ╰┼┼╮             │  \n");
        printf("  │  ╰┼┼╯             │      \n");
        printf("  │                     │  \n");
        printf("  │  M E R K E Z        │  \n");
        printf("  │  B A N K A          │  \n");
        printf("  │                     │  \n");
        printf("  │                     │  \n");
        printf("  │  C E N T R A L      │  \n");
        printf("  │  B A N K            │  \n");
        printf("  │                     │  \n");
        printf("  │                     │  \n");
        printf("  │                     │  \n");
        printf("  └──────────────────┘  \n");

        printf("\nLütfen yapmak istediğiniz işlemi seçin: \n");

        printf("\n------------------------------------------------------- \n");

        printf("1 - Yeni bir çalışan kaydı oluştur\n");
        printf("2 - Kayıtlarımı içeren bir dosya oluştur\n");
        printf("3 - Kayıtları listele\n");
        printf("4 - Bir kaydı ara\n");
        printf("5 - Bir kaydı düzenle\n");
        printf("6 - Bir kaydı sil\n");

        scanf("%d", &kullaniciSecimi);

        switch (kullaniciSecimi)
        {
        case 1:
            CalisanKaydiOlustur(kayitlar, &sayici);
            break;
        case 2:
            DosyaOlustur();
            break;
        case 3:
            CalisanlariListele(kayitlar, sayici);
            break;
        case 4:
            CalisanKaydiniAra(kayitlar, sayici);
            break;
        case 5:
            CalisanKaydiniDuzenle(kayitlar, sayici);
            break;
        case 6:
            CalisanKaydiniSil(kayitlar, &sayici);
            break;
        default:
            printf("Geçersiz seçenek. Lütfen tekrar deneyin.\n");
        }
    } while (kullaniciSecimi != 6);

    return kullaniciSecimi;
}
