//*****************************************************************************
// fxas21002c_proc.h - Prototypes for the FXAS21002C Peripheral
//
//  Created on: Jul 9, 2018
//      Author: Brandon Dixon
//
//*****************************************************************************

#ifndef FXAS21002C_PROC_H_
#define FXAS21002C_PROC_H_

//*****************************************************************************
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//*****************************************************************************

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
// Functions
//*****************************************************************************

// I2C General Send and receive functions
void I2CGyroReceive(uint32_t ui32SlaveAddress, uint8_t ui32SlaveRegister,
                    uint8_t *pReceiveData, uint8_t ui8NumBytes);
void I2CGyroSend(uint32_t ui32SlaveAddress, uint8_t ui32SlaveRegister,
                    uint8_t *pTransmitData, uint8_t ui8NumBytes);

//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* FXAS21002C_PROC_H_ */
