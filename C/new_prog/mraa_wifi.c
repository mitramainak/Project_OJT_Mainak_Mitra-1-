#include <stdio.h>
#include "mraa/uart.h"
#include "mraa/gpio.h"
#include <unistd.h>

int main() {
    // Initialize UART
    mraa_uart_context uart;
    uart = mraa_uart_init(0); // Use the first UART device, /dev/ttyS0
    if (uart == NULL) {
        fprintf(stderr, "Failed to initialize UART\n");
        return 1;
    }

    // Set UART parameters
    if (mraa_uart_set_baudrate(uart, 38400) != MRAA_SUCCESS) {
        fprintf(stderr, "Failed to set baudrate\n");
        return 1;
    }
    mraa_uart_set_mode(uart, 8, MRAA_UART_PARITY_NONE, 1);
    mraa_uart_set_flowcontrol(uart, 0, 0);

    // Write and sleep
    const char* commands[] = {
        "CMD+RESET\r\n",
        "CMD+WIFIMODE=1\r\n",
        "CMD+CONTOAP=\"realme X7 Max\",\"0987654321\"\r\n",
        "CMD+MQTTNETCFG=dev.rightech.io,1883\r\n",
        "CMD+MQTTCONCFG=3,mqtt-koppubalaji-wduyjg,,,,,,,,,\r\n",
        "CMD+MQTTSTART=1\r\n",
        "CMD+MQTTSUB=base/relay/led1\r\n",
        "CMD+MQTTPUB=base/state/magnet\r\n"
    };

    for (int i = 0; i < 8; i++) {
        mraa_uart_write(uart, commands[i], strlen(commands[i));
        sleep(3);
    }

    // Read
    char buf[100];
    int rdlen = mraa_uart_read(uart, buf, sizeof(buf));
    if (rdlen > 0) {
        buf[rdlen] = '\0';
        printf("Received: %s\n", buf);

        // Transmit the received data back to "righttech"
        mraa_uart_write(uart, buf, rdlen);
    }

    // Close UART
    mraa_uart_stop(uart);
    mraa_deinit();

    return 0;
}

