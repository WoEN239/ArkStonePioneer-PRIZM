#include <Arduino.h>
#include "WireNoFreeze.h"
#include "Prizm_Controller.h"

#define SERIAL_OUTPUT 115200

#define N_BYTE_COMMAND 0
#define N_BYTE_NCONTROLLER 1
#define N_BYTE_HIBYTE 2
#define N_BYTE_LOBYTE 3

enum CommandType {
    CMD_RESET,
    CMD_SETMOTORPOWER,
    CMD_SETMOTORPOWERS,
    CMD_READENCODER,
    CMD_RESETENCODER,
    CMD_SETMOTORDIRECTION,
    CMD_SETMOTORZEROPOWERBEHAVIOUR,
    CMD_READMOTORCURRENT,
    CMD_SETSERVOPOSITION,
    CMD_READDISTANCE
};

#define INVERTMOTOR 1
#define BRAKEMOTOR 1

//#define WAIT_FOR_BUTTON

/*
#include "NewPing.h"
*/

void establishConnection() {
    prizm.setGreenLED(LOW);
    Serial.flush();
    delay(100);
    Serial.end();
    delay(100);
    prizm.setGreenLED(HIGH);
    Serial.begin(SERIAL_OUTPUT);
    delay(100);
    prizm.setGreenLED(LOW);
}

void setup() {

    establishConnection();

    Prizm::prizmBegin(false);
    Prizm::setRedLED(HIGH);

#ifdef WAIT_FOR_BUTTON
    while (Prizm::readStartButton() == 0) {
        Prizm::setGreenLED(millis() % 200 < 100 ? HIGH : LOW);
    }        // wait for the program start (green_value) button pressed
#endif
    prizm.setGreenLED(LOW);

}

typeof(millis()) last_received_ms = 0;

void writeI32toByteBuffer(int32_t number, byte *buffer) {
    buffer[0] = (int8_t) ((number >> 24) & 0xFF);
    buffer[1] = (int8_t) ((number >> 16) & 0xFF);
    buffer[2] = (int8_t) ((number >> 8) & 0xFF);
    buffer[3] = (int8_t) ((number >> 0) & 0xFF);
}

void loop() {
    const size_t n_bytes_to_receive = 4;
    if (Serial.available() >= n_bytes_to_receive) {
        last_received_ms = millis();
        prizm.setGreenLED(HIGH);
        size_t n_bytes_received = Serial.available();
        byte *bytes = (byte *) (malloc(n_bytes_received * sizeof(byte)));
        for (int i = 0; i < n_bytes_received; i++)
            bytes[i] = Serial.read();

        const size_t n_bytes_respond = 4;
        byte respond_msg[n_bytes_respond] = {0, 0, 0, 0};

        switch (bytes[N_BYTE_COMMAND]) {
            case CMD_RESET:
                respond_msg[3] = bytes[N_BYTE_COMMAND];
                break;
            case CMD_READENCODER: {
                PrizmDCExpansion *expansion = bytes[N_BYTE_NCONTROLLER] ?
                                              new PrizmDCExpansion(bytes[N_BYTE_NCONTROLLER])
                                                                        : &prizm.integrated_DC;
                int32_t value = expansion->readEncoderCount(bytes[N_BYTE_HIBYTE]);
                if (bytes[N_BYTE_NCONTROLLER]) delete expansion;
                writeI32toByteBuffer(value, respond_msg);
                break;
            }
            case CMD_READMOTORCURRENT: {
                PrizmDCExpansion *expansion = bytes[N_BYTE_NCONTROLLER] ?
                                              new PrizmDCExpansion(bytes[N_BYTE_NCONTROLLER])
                                                                        : &prizm.integrated_DC;
                int16_t value = expansion->readMotorCurrent(bytes[N_BYTE_HIBYTE]);
                if (bytes[N_BYTE_NCONTROLLER]) delete expansion;
                writeI32toByteBuffer(value, respond_msg);
                break;
            }
            case CMD_SETMOTORPOWER: {
                PrizmDCExpansion *expansion = bytes[N_BYTE_NCONTROLLER] ?
                                              new PrizmDCExpansion(bytes[N_BYTE_NCONTROLLER])
                                                                        : &prizm.integrated_DC;
                expansion->setMotorPower(bytes[N_BYTE_HIBYTE] == 2 ? 2 : 1, (int8_t) bytes[N_BYTE_LOBYTE]);
                if (bytes[N_BYTE_NCONTROLLER]) delete expansion;
                respond_msg[3] = bytes[N_BYTE_COMMAND];
                break;
            }
        }

        Serial.write(respond_msg, n_bytes_respond);

        free(bytes);
    }

    if (millis() - last_received_ms > 1000) {
        prizm.integrated_DC.setMotorPowers(0, 0);
        establishConnection();
    }

}