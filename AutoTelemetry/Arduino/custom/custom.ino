#include <SPI.h>          //SPI is used to talk to the CAN Controller
#include <mcp_can.h>

#define CAN_ID_PID 0x7DF

MCP_CAN CAN(9);          //set SPI Chip Select to pin 9

unsigned char len = 0;
unsigned char buf[8];
unsigned int canID;
unsigned char temp;

void setup()
{
  Serial.begin(115200); // This is for communicating with the serial monitor

//tries to initialize, if failed --> it will loop here forever
START_INIT:

    if(CAN_OK == CAN.begin(CAN_500KBPS))      //setting CAN baud rate to 500Kbps
    {
        Serial.println("Init success!");
    }
    else
    {
        Serial.println("Init failed");
        delay(1000);
        goto START_INIT;
    }
}


void loop()
{
  sendPid();
  readResponse();
}

void readResponse()
{
  if(CAN_MSGAVAIL == CAN.checkReceive()) //check if data coming
  {
    CAN.readMsgBuf(&len, buf);    //read data,  len: data length, buf: data buffer
    canID = CAN.getCanId();       //getting the ID of the incoming message

    // 41 0C 0F A0
    // 0x0FA0 = 4000
    // 4000 / 4 = 1000 rpm
    
    if (canID == 0x7DF)           //reading only our beloved 0xF1 message
    {
      Serial.print(canID);
      Serial.print("\t");
      for (int i = 0; i < len; i++)
      {
        Serial.print(buf[i]);
        Serial.print("\t");
      }
      Serial.println();
    }
  }
}

void sendPid() 
{
  unsigned char tmp[8] = {0x02, 0x01, 0x0C, 0, 0, 0, 0, 0};
  Serial.print("SEND PID: 0x");
  Serial.println(0x0C, HEX);
  CAN.sendMsgBuf(CAN_ID_PID, 0, 8, tmp);
}
