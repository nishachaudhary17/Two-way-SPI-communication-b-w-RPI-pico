
//=================================================================================//
#include <stdio.h>
#include "hardware/spi.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"
//=================================================================================//
#define BUF_LEN 128
//=================================================================================//
uint8_t in_buf;


void sendData()
{
     uint8_t in_buf, data = in_buf+1;
    spi_write_read_blocking (spi_default, &data, &in_buf, 1);
    printf("command: %d, data sent to master: %d\n\n", in_buf,data);

}
int main() {
  // Enable UART so we can print
  stdio_init_all();
  sleep_ms (2*1000);
  printf ("SPI Peripheral Example\n");
  // Enable SPI 0 at 1 MHz and connect to GPIOs
  spi_init (spi_default, 1 * 1000000);
  spi_set_slave (spi_default, true);
  gpio_set_function (PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
  gpio_set_function (PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
  gpio_set_function (PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
  gpio_set_function (PICO_DEFAULT_SPI_CSN_PIN, GPIO_FUNC_SPI);
  if (spi_is_readable (spi_default)) {
        printf ("Reading data from SPI..\n");
        spi_read_blocking (spi_default, 0, &in_buf, 1);

    }
//     if (spi_is_readable (spi_default)) {
//       printf ("Reading data from SPI..\n");
//       uint8_t in_buf;
//       spi_read_blocking (spi_default, 0, &in_buf, 1);
//     // //   printf ("Data received: %d\n", in_buf [0]);
//     //   if(in_buf==10)
//     //   { 
//     //     uint8_t data = 11;
//     //     spi_write_blocking(spi_default, &data,1 );	\
//     //      printf("command: %d, data sent to master ", in_buf);
     
//     //   }

//         uint8_t data = 11;
//         spi_write_read_blocking (spi_default, &data, &in_buf, 1);
        
    
//   }
while(in_buf == 10)
{
  sendData();
}
}
//=================================================================================//