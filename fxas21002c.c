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
    ui8Register[0] |= 0B00000011;
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
