#include "crc_calculation.h" // crc_calculation fonksiyonunun prototipini içeren başlık dosyası
#include <stdio.h>           // Standart girdi/çıktı işlemleri için standart kütüphane

// CRC hesaplama fonksiyonu
uint16_t crc_calculation(const unsigned char* data, size_t length) {
    uint16_t CRC_poly = 0xA001;       // CRC algoritmasında kullanılan polinom degeri
    uint16_t crc_value = 0xFFFF;      // CRC'nin baslangic degeri, tum bitleri 1 olan bir 16-bit sayar

    // Verinin her baytı için döngü
    for (size_t i = 0; i < length; i++) {
        crc_value ^= data[i];         // CRC degerini verinin bu bayti ile XOR'la

        // Bu baytin her biti icin dongu
        for (int bit = 0; bit < 8; bit++) {
            if (crc_value & 0x0001) {       // CRC'nin en dusuk biti 1 mi?
                crc_value = (crc_value >> 1) ^ CRC_poly; // Eger oyleyse, saga kaydir ve polinom ile XOR yap
            } else {
                crc_value >>= 1;           // EDe�lse, sadece sola kaydir
            }
        }
    }
    return crc_value & 0xFFFF; // CRC'yi 16 bit sinirinda tut ve dondur
}

// CRC kontrol fonksiyonu
void crc_control(uint16_t crc_modbus, uint16_t crc_cal)
{
    if (crc_cal == crc_modbus) {       // Hesaplanan CRC ile verilen CRC eslesiyor mu?
        HAL_Delay(200);                // Eslesiyorsa 200 ms bekle
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); // LED'i ac (GPIOD uzerindeki 12. pin)
        HAL_Delay(100);                // LED yanik durumda 100 ms bekle
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); // LED'i kapat
    } else {
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); // Eslesmiyorsa LED'i kapali tut
    }
}
