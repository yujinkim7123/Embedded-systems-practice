#include "hal_data.h"
#include <stdio.h>

#define ACCEL_XOUT_H 0x3B
#define PWR_MGMT_1 0x6B

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

volatile short ax, ay, az;

volatile i2c_master_event_t g_i2c_callback_event;
void sci_i2c_master_callback(i2c_master_callback_args_t *p_args)
{
    g_i2c_callback_event = p_args->event;
}

volatile i2c_master_event_t g_iic_callback_event;
void iic_callback(i2c_master_callback_args_t *p_args)
{
    g_iic_callback_event = p_args->event;
    /* TODO: add your own code here */
}

void delay(int ms) {
    R_BSP_SoftwareDelay(ms, BSP_DELAY_UNITS_MILLISECONDS);
}

void writeI2C(uint8_t addr, uint8_t val) {
    uint8_t buf[2] = {addr, val};

    R_IIC_MASTER_Write(&g_i2c_master0_ctrl, buf, 2, true);
    while(g_iic_callback_event != I2C_MASTER_EVENT_TX_COMPLETE);
}

void readI2C(uint8_t addr, uint8_t buf[], uint8_t size) {
    //select addr (by I2C_WRITE)
    R_IIC_MASTER_Write(&g_i2c_master0_ctrl, &addr, 1, true);
    while(g_iic_callback_event != I2C_MASTER_EVENT_TX_COMPLETE);
    delay(10);

    //read data
    memset(buf, 0, sizeof(buf));
    R_IIC_MASTER_Read(&g_i2c_master0_ctrl, buf, 6, false);
    while(g_iic_callback_event != I2C_MASTER_EVENT_RX_COMPLETE);
}