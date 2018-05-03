//*****************************************************************************
// fxas21002c.h - Prototypes for the FXAS21002C Peripheral
//
//  Created on: May 1, 2018
//      Author: Brandon Dixon
//
//*****************************************************************************

#ifndef FXAS21002C_H_
#define FXAS21002C_H_

//*****************************************************************************
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//*****************************************************************************

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
// Register addreses
//*****************************************************************************
#define GYRO_STATUS         0x00
#define GYRO_OUT_X_MSB      0x01
#define GYRO_OUT_X_LSB      0x02
#define GYRO_OUT_Y          0x03
#define GYRO_OUT_Y_LSB      0x04
#define GYRO_OUT_Z_MSB      0x05
#define GYRO_OUT_Z_LSB      0x06
#define GYRO_DR_STATUS      0x07
#define GYRO_F_STATUS       0x08
#define GYRO_F_SETUP        0x09
#define GYRO_F_EVENT        0x0A
#define GYRO_INT_SRC_FLAG   0x0B
#define GYRO_WHO_AM_I       0x0C
#define GYRO_CTRL_REG0      0x0D
#define GYRO_RT_CFG         0x0E
#define GYRO_RT_SRC         0x0F
#define GYRO_RT_THS         0x10
#define GYRO_RT_COUNT       0x11
#define GYRO_TEMP           0x12
#define GYRO_CTRL_REG1      0x13
#define GYRO_CTRL_REG2      0x14
#define GYRO_CTRL_REG3      0x15

//*****************************************************************************
// Functions
//*****************************************************************************

// Set initial input parameters
typedef enum
{
    GFSR_2000,
    GFSR_1000,
    GFSR_500,
    GFSR_250
} tGyroRange;

// I2C General Send and receive functions
extern void I2CGyroReceive(uint32_t ui32SlaveAddress, uint8_t ui32SlaveRegister,
                    uint8_t *pReceiveData, uint8_t ui8NumBytes);
extern void I2CGyroSend(uint8_t ui32SlaveAddress, uint8_t ui8NumArgs, ...);

// FXAS21002C functions
extern void GyroStandby(uint32_t ui32SlaveAddress);
extern void GyroActive(uint32_t ui32SlaveAddress);
extern void GyroReady(uint32_t ui32SlaveAddress);
extern void GyroRange(uint32_t ui32SlaveAddress, tGyroRange tGFSR);

//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* FXAS21002C_H_ */
