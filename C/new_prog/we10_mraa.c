#include <stdio.h>
#include <mraa/uart.h>
#include <mraa/initio.h>
#include <string.h>

int main() {
    char *portname = "/dev/ttyS3";  // UART port name
    mraa_uart_context uart;
    char buf[256];  // Buffer to store incoming data

    mraa_init();

    uart = mraa_uart_init_raw(portname);
    if (uart == NULL) {
        fprintf(stderr, "Error opening %s\n", portname);
        return 1;
    }

    if (mraa_uart_set_baudrate(uart, 115200) != MRAA_SUCCESS) {
        fprintf(stderr, "Error setting baud rate\n");
        return 1;
    }

    // Send the CMD+RESET command
    mraa_uart_write(uart, "CMD+RESET\r\n", 11);
    mraa_uart_flush(uart);

    // Wait for a response or some time (adjust the timeout as needed)
    usleep(1000000);  // Example: Wait for 1 second

    // Read and print the response
    int rdlen = mraa_uart_read(uart, buf, sizeof(buf));
    if (rdlen > 0) {
        buf[rdlen] = '\0';  // Null-terminate the received data
        printf("Received after CMD+RESET: %s\n", buf);
    }

    // Send the CMD+WIFIMODE command
    mraa_uart_write(uart, "CMD+WIFIMODE\r\n", 15);
    mraa_uart_flush(uart);

    // Wait for a response or some time (adjust the timeout as needed)
    usleep(1000000);  // Example: Wait for 1 second

    // Read and print the response
    rdlen = mraa_uart_read(uart, buf, sizeof(buf));
    if (rdlen > 0) {
        buf[rdlen] = '\0';  // Null-terminate the received data
        printf("Received after CMD+WIFIMODE: %s\n", buf);
    }

    // Send the CMD+CONTOAP command
    mraa_uart_write(uart, "CMD+CONTOAP\r\n", 14);
    mraa_uart_flush(uart);

    // Wait for a response or some time (adjust the timeout as needed)
    usleep(1000000);  // Example: Wait for 1 second

    // Read and print the response
    rdlen = mraa_uart_read(uart, buf, sizeof(buf));
    if (rdlen > 0) {
        buf[rdlen] = '\0';  // Null-terminate the received data
        printf("Received after CMD+CONTOAP: %s\n", buf);
    }

    mraa_deinit();
    return 0;
}

