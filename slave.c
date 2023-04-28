
// //=================================================================================//
// #include <stdio.h>
// #include "hardware/spi.h"
// #include "pico/binary_info.h"
// #include "pico/stdlib.h"
// //=================================================================================//
// #define BUF_LEN 128
// //=================================================================================//
// uint8_t in_buf;


// void sendData()
// {
//      uint8_t in_buf, data = in_buf+1;
//     spi_write_read_blocking (spi_default, &data, &in_buf, 1);
//     printf("command: %d, data sent to master: %d\n\n", in_buf,data);

// }
// int main() {
//   // Enable UART so we can print
//   stdio_init_all();
//   sleep_ms (2*1000);
//   printf ("SPI Peripheral Example\n");
//   // Enable SPI 0 at 1 MHz and connect to GPIOs
//   spi_init (spi_default, 1 * 1000000);
//   spi_set_slave (spi_default, true);
//   gpio_set_function (PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
//   gpio_set_function (PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
//   gpio_set_function (PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
//   gpio_set_function (PICO_DEFAULT_SPI_CSN_PIN, GPIO_FUNC_SPI);

 
//  while(1)
//  {
//     if (spi_is_readable (spi_default)) {
//       sleep_ms(1);
//       uint8_t in_buf=0;
//       spi_read_blocking (spi_default, 0, &in_buf, 1);
//       printf("data recived from master: %d\n", in_buf);
//       uint8_t data = in_buf + 1;
//       spi_write_blocking(spi_default, &data,1 );	
      
//       printf("command: %d, data sent to master: %d\n ", in_buf, data);

        
//     }
//   }

// }
//=================================================================================//