//*****************************************************************************
// fxas21002c.c - Prototypes for the FXAS21002C Peripheral
//
//  Created on: Jul 9, 2018
//      Author: Brandon Dixon
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "fxas21002c.h"

void GyroStandby(uint32_t ui32SlaveAddress)
{
    uint8_t ui8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
    ui8Register[0] &= ~(0B00000011);
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
}

void GyroReady(uint32_t ui32SlaveAddress)
{
    uint8_t ui8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
    ui8Register[0] &= ~(0B00000010);
    ui8Register[0] |= 0B00000001;
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
}

void GyroActive(uint32_t ui32SlaveAddress)
{
    uint8_t ui8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
    ui8Register[0] |= 0B00000011;
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
}

void GyroReset(uint32_t ui32SlaveAddress)
{
    uint8_t RESET = 0x40;
    printf("\r\nResetting device");
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, &RESET, 1);

    uint8_t ui8Register[1];

    ui8Register[0] = 0x00;    
    do
    {
        I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
	ui8Register[0] &= RESET;
    } while (ui8Register[0]);
    printf(" ... Done");
    printf("\r\nCalibrating");


    uint8_t CALIBRATED = 0x80;
    ui8Register[0] = 0x00;    
    do
    {
        I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
	ui8Register[0] &= CALIBRATED;
    } while (ui8Register[0]);
    printf(" ... Done");

    uint8_t RATE = 0x1E;
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, &RATE, 1);
}


void GyroSelfTest(uint32_t ui32SlaveAddress, _Bool bState)
{
    uint8_t ui8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));    
    ui8Register[0] &= ~(0B00100000);
    ui8Register[0] |= (bState << 5);
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
}

void GyroTemp(uint32_t ui32SlaveAddress)
{
    int8_t i8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, i8Register, sizeof(i8Register));
    printf("\r\nTemperature: %d degC",i8Register[0]);
}

void GyroGetData(uint32_t ui32SlaveAddress, tRawData *tRD )
{
    uint8_t ui8Register[6];
    I2CGyroReceive(ui32SlaveAddress, GYRO_OUT_X_MSB, ui8Register, sizeof(ui8Register));

    printf("\r\nX:%02X X:%02X Y:%02X Y:%02X Z:%02X Z:%02X",
                ui8Register[0],ui8Register[1],ui8Register[2],ui8Register[3],ui8Register[4],ui8Register[5]);

    // copy the 16 bit gyroscope byte data into 16 bit words
    tRD->x = (int16_t)((ui8Register[0] << 8) | (ui8Register[1] >> 2));
    tRD->y = (int16_t)((ui8Register[2] << 8) | (ui8Register[3] >> 2));
    tRD->z = (int16_t)((ui8Register[4] << 8) | (ui8Register[5] >> 2));
}
