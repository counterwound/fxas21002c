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

void GyroActive(uint32_t ui32SlaveAddress)
{
    uint8_t ui8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
    ui8Register[0] |= 0B00000010;
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
}

void GyroRange(uint32_t ui32SlaveAddress, tGyroRange tGFSR)
{
    uint8_t ui8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG0, ui8Register, sizeof(ui8Register));
    ui8Register[0] &= ~(0B00000011);
    ui8Register[0] |= tGFSR;
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG0, ui8Register, sizeof(ui8Register));
}

void GyroOutputDataRate(uint32_t ui32SlaveAddress,  tOutputDataRate tODR)
{
    uint8_t ui8Register[1];
    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
    ui8Register[0] &= ~(0B00011100);
    ui8Register[0] |= (tODR << 2 );
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
}

void GyroReset(uint32_t ui32SlaveAddress)
{
    uint8_t ui8Register[1];

    ui8Register[0] = GYRO_RESET;
    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
}

void GyroGetData(uint32_t ui32SlaveAddress, tRawData *tRD )
{
    uint8_t ui8Register[7];
    I2CGyroReceive(ui32SlaveAddress, GYRO_STATUS, ui8Register, sizeof(ui8Register));

    // copy the 16 bit gyroscope byte data into 16 bit words
    tRD->x = (int16_t)((ui8Register[1] << 8) | (ui8Register[2] >> 0));
    tRD->y = (int16_t)((ui8Register[3] << 8) | (ui8Register[4] >> 0));
    tRD->z = (int16_t)((ui8Register[5] << 8) | (ui8Register[6] >> 0));
}

//void GyroReady(uint32_t ui32SlaveAddress)
//{
//    uint8_t ui8Register[1];
//    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
//    ui8Register[0] &= ~(0B00000010);
//    ui8Register[0] |= 0B00000001;
//    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
//}

//void GyroSelfTest(uint32_t ui32SlaveAddress, _Bool bState)
//{
//    uint8_t ui8Register[1];
//    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));    
//    ui8Register[0] &= ~(0B00100000);
//    ui8Register[0] |= (bState << 5);
//    I2CGyroSend(ui32SlaveAddress, GYRO_CTRL_REG1, ui8Register, sizeof(ui8Register));
//}

//void GyroTemp(uint32_t ui32SlaveAddress)
//{
//    int8_t i8Register[1];
//    I2CGyroReceive(ui32SlaveAddress, GYRO_CTRL_REG1, i8Register, sizeof(i8Register));
//    printf("\r\nTemperature: %d degC",i8Register[0]);
//}
