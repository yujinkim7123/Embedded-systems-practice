#include "hal_data.h"
#include <stdio.h>

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER
/* Callback function */
volatile i2c_master_event_t g_iic_callback_event;
void iic_callback(i2c_master_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    g_iic_callback_event = p_args -> event;

}

volatile i2c_master_event_t g_i2c_callback_event;
void sci_i2c_master_callback(i2c_master_callback_args_t *p_args)
{
    g_i2c_callback_event = p_args->event;
}

void delay(int ms) {
    R_BSP_SoftwareDelay(ms, BSP_DELAY_UNITS_MILLISECONDS);
}

void hal_entry(void)
{
    uint8_t addr = 0x0;
    uint8_t buf[100] = {0};
    uint8_t str[100] = {0};
    while(1) {
        //select addr (by I2C_WRITE)
        addr = 0x75;
        R_IIC_MASTER_Write(&g_i2c_master0_ctrl, &addr, 1, true);
        while(g_iic_callback_event != I2C_MASTER_EVENT_TX_COMPLETE);

        //read data
        memset(buf, 0, sizeof(buf));
        R_IIC_MASTER_Read(&g_i2c_master0_ctrl, buf, 1, false);
        while(g_iic_callback_event != I2C_MASTER_EVENT_RX_COMPLETE);

        //print
        sprintf(str, "WHO AM I : %X\r\n",buf[0]);
        printf("%s", str);
        delay(500);
    }
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open(&g_ioport_ctrl, g_ioport.p_cfg);
        R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
        R_SCI_I2C_Open(&g_i2c0_ctrl, &g_i2c0_cfg);
        R_IIC_MASTER_Open(&g_i2c_master0_ctrl, &g_i2c_master0_cfg);

    }
}
