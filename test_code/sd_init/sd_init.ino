#include "SdFat.h"
#include <SPI.h>

#define SPI_SPEED SD_SCK_MHZ(4)
#define CS_PIN 10
#define SCK_PIN 12
#define MISO_PIN 13
#define MOSI_PIN 11

SdFat sd;

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("\n[TAISO] Initializing SPI and SD Card...");

    // bound spi to my pins
    SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

    if (!sd.begin(CS_PIN, SPI_SPEED)) {
        if (sd.card()->errorCode()) {
            Serial.println("SD initialization failed.");
        } else if (sd.vol()->fatType() == 0) {
            Serial.println("Can't find a valid FAT16/FAT32 partition.");
        } else {
            Serial.println("Can't determine error type");
        }
        return;
    }

    Serial.println("[SUCCESS] SD card initialized.");
    Serial.println("Files on card:");
    Serial.println("      Size    Name");

    sd.ls(LS_R | LS_SIZE);
}

void loop() {
    // Nothing here for now
}