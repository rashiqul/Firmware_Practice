#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Problem Setup
 * Let's assume we have a simple frame format for communication:
 * - Frame Header: A fixed number of bytes to indicate the start of the frame (e.g., 2 bytes).
 * - Payload Length: A byte indicating the size of the payload.
 * - Payload: The actual data to be transmitted, which can be of variable size.
 * - Frame Footer: A fixed number of bytes to indicate the end of the frame (e.g., 2 bytes).
 * 
 * Our task is to write C code that:
 * - Serializes this data into a byte stream.
 * - Ensures that the byte stream follows the specified frame format.
 *
 * Assumptions:
 * - Header: 2 bytes, e.g., 0xAA 0xBB
 * - Footer: 2 bytes, e.g., 0xCC 0xDD
 * - Payload Length: 1 byte (maximum payload size is 255 bytes)
 * - Payload: Variable size data
 */

/* Define the frame header and footer */
#define FRAME_HEADER_1 0xAA
#define FRAME_HEADER_2 0xBB
#define FRAME_FOOTER_1 0xCC
#define FRAME_FOOTER_2 0xDD

/* Function to serialize the data */
void serializeData(uint8_t *payload, uint8_t payloadLength, uint8_t *byteStream, uint16_t *byteStreamLength)
{
    if (payloadLength > 255)
    {
        /* Payload length exceeds the maximum allowed size */
        printf("Payload length exceeds the maximum allowed size.\n");
        return;
    }

    /* Start constructing the byte stream */
    uint16_t index = 0;

    /* Add the frame header (2 bytes) */
    byteStream[index++] = FRAME_HEADER_1;
    byteStream[index++] = FRAME_HEADER_2;

    /* Add the payload length */
    byteStream[index++] = payloadLength;

    /* Add the payload data */
    memcpy(&byteStream[index], payload, payloadLength);
    index += payloadLength;

    /* Add the frame footer (2 bytes) */
    byteStream[index++] = FRAME_FOOTER_1;
    byteStream[index++] = FRAME_FOOTER_2;

    /* Update the byte stream length */
    *byteStreamLength = index;
}

/* Function to print the byte stream for debugging */
void printByteStream(const uint8_t *byteStream, uint16_t byteStreamLength) 
{
    printf("Serialized Byte Stream: ");
    for (uint16_t i = 0; i < byteStreamLength; ++i) {
        printf("%02X ", byteStream[i]);
    }
    printf("\n");
}


 void SerializeFragmentedDataMain()
 {
    /* Example payload data */
    uint8_t payload[]     = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint8_t payloadLength = sizeof(payload) / sizeof(payload[0]);

    /* 
     * Buffer to hold the serialized byte stream 
     * 255 bytes for the payload 
     * 5 byte for header, payload length and footer
     */
    uint8_t  byteStream[260];
    uint16_t byteStreamLength = 0;

    /* Serialize the data */
    serializeData(payload, payloadLength, byteStream, &byteStreamLength);

    /* Print the serialized byte stream */
    printByteStream(byteStream, byteStreamLength);
 } 