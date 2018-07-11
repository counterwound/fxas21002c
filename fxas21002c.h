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
#define GYRO_OUT_Y_MSB      0x03
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
// Register commands
//*****************************************************************************
#define GYRO_RESET          0x40

//*****************************************************************************
// Functions
//*****************************************************************************

// Set initial input parameters
typedef enum
{
    GFSR_2000PS,
    GFSR_1000PS,
    GFSR_500PS,
    GFSR_250PS
} tGyroRange;

typedef enum 
{
	ODR_800HZ,
	ODR_400HZ,
	ODR_200HZ,
	ODR_100HZ,
	ODR_50HZ,
	ODR_25HZ,
	ODR_12_5HZ
} tOutputDataRate;

typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
} tRawData;

// I2C General Send and receive functions
extern void I2CGyroReceive(uint32_t ui32SlaveAddress, uint8_t ui32SlaveRegister,
                    uint8_t *pReceiveData, uint8_t ui8NumBytes);
extern void I2CGyroSend(uint32_t ui32SlaveAddress, uint8_t ui32SlaveRegister,
                    uint8_t *pTransmitData, uint8_t ui8NumBytes);

// FXAS21002C functions
void GyroStandby(uint32_t ui32SlaveAddress);
void GyroActive(uint32_t ui32SlaveAddress);
void GyroReset(uint32_t ui32SlaveAddress);
void GyroRange(uint32_t ui32SlaveAddress, tGyroRange tGFSR);
void GyroOutputDataRate(uint32_t ui32SlaveAddress,  tOutputDataRate tODR);
void GyroGetData(uint32_t ui32SlaveAddress, tRawData *tRD );
//void GyroReady(uint32_t ui32SlaveAddress);
//void GyroSelfTest(uint32_t ui32SlaveAddress, _Bool bState);
//void GyroTemp(uint32_t ui32SlaveAddress);

//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* FXAS21002C_H_ */
