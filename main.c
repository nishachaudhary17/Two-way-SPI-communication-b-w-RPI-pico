
//=================================================================================//
#include <stdio.h>
#include "hardware/spi.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"
//=================================================================================//
#define BUF_LEN 128
//=================================================================================//
int main() {
  // Enable UART so we can print
  stdio_init_all();
  sleep_ms (2 * 1000);
  printf ("SPI Peripheral Example\n");
  // Enable SPI 0 at 1 MHz and connect to GPIOs
  spi_init (spi_default, 1 * 1000000);
  spi_set_slave (spi_default, true);
  gpio_set_function (PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
  gpio_set_function (PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
  gpio_set_function (PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
  gpio_set_function (PICO_DEFAULT_SPI_CSN_PIN, GPIO_FUNC_SPI);
  uint8_t out_buf [BUF_LEN], in_buf [BUF_LEN];
  // Initialize output buffer
//   for (uint8_t i = 0; i < BUF_LEN; ++i) {
//     out_buf [i] = 0;
//     in_buf [i] = 0;
//   }

uint8_t rx;
// if (spi_is_readable (spi_default)) {
//       printf ("Reading data from SPI..\n");
//       // Write the output buffer to MOSI, and at the same time read from MISO.
//       spi_read_blocking (spi_default, 0, &rx, 1);
//       spi_read_blocking (spi_default, 0, &rx, 1);
//       spi_read_blocking (spi_default, 0, &rx, 1);
//       printf ("Data check: %d", rx);
//     }
bool flag =0;
   while (1) {
    if (spi_is_readable (spi_default)) {
      printf ("Reading data from SPI..\n");
      // Write the output buffer to MOSI, and at the same time read from MISO.
      spi_read_blocking (spi_default, 0, &rx, 1);
      printf ("Data received: %d\n", rx);
      while(rx==10)
      {
        uint8_t rx[3];
         uint8_t data ;    
        if( flag ==0)
        {
          data =7;
        }
        spi_write_read_blocking (spi_default, &data, rx, 1);
        data = rx[0]+1;
        printf("command: %d, data sent to master: %d\n\n", rx[0],  data);
        flag =1;
        if(rx[0]!=10)
        {
            break;
        }

      }
    }
  }
}
//=================================================================================//